#!usr/bin/env python
# -*- coding:utf-8 -*-

import re
import jieba
import numpy as np
import pandas as pd
from preprocess.rule import (HTML_TAG_PATTERN, URL_PATTERN,
                             EMAIL_PATTERN, CELL_PHONE_PATTERN,
                             LANDLINE_PHONE_PATTERN, REDUNDANT_PATTERN)

dr = DuplicateRemove(128, 4)


def update_news_type(item):
    news_type = item['news_type']
    if news_type in ['财经', '股票', '美股', '商业', '基金', '房产', '理财']:
        return '财经'
    if news_type in ['体育', 'NBA', 'CBA', '国内足球', '国际足球']:
        return '体育'
    if news_type in ['娱乐', '综艺', '电视剧', '电影', '音乐', '明星']:
        return '娱乐'
    if news_type in ['时政', '国际', '国内', '社会', '要闻']:
        return '时政'
    return news_type


def remove_html(item):
    text = item['news_content']
    pattern = re.compile(HTML_TAG_PATTERN)
    return re.sub(pattern, '', text)


def remove_url(item):
    text = item['news_content']
    pattern = re.compile(URL_PATTERN)
    text = ''.join(['￥', text, '￥'])
    return re.sub(pattern, '', text)[1:-1]


def remove_email(item):
    text = item['news_content']
    pattern = re.compile(EMAIL_PATTERN)
    text = ''.join(['￥', text, '￥'])
    return re.sub(pattern, '', text)[1:-1]


def remove_cell_phone(item):
    text = item['news_content']
    pattern = re.compile(CELL_PHONE_PATTERN)
    text = ''.join(['￥', text, '￥'])
    return re.sub(pattern, '', text)[1:-1]


def remove_landline_phone(item):
    text = item['news_content']
    pattern = re.compile(LANDLINE_PHONE_PATTERN)
    text = ''.join(['￥', text, '￥'])
    return re.sub(pattern, '', text)[1:-1]


def remove_redundant_char(item):
    text = item['news_content']
    pattern_list = list()
    for char in REDUNDANT_PATTERN:
        pattern_tmp = '(?<={char}){char}+'.format(
            char=re.escape(char))
        pattern_list.append(pattern_tmp)
    redundant_pattern = '|'.join(pattern_list)
    pattern = re.compile(redundant_pattern)
    return re.sub(pattern, '', text)


def remove_dup(item):
    text = item['news_content']
    if dr.contains(text):
        return 'is_dup'
    else:
        dr.insert(text, item['news_link'])
        return 'no_dup'


def format_content(item):
    text = item['news_content']
    return ''.join([x.strip() for x in text])


def format_time(item):
    time_str = item['news_time']


def compute_char_len(item):
    text = item['news_content']
    return len(text)


def segment(item):
    text = item['news_content']
    return ' '.join([x for x in jieba.cut(text)])


def compute_word_len(item):
    text = item['news_segment_content']
    return len(text.split())


def show_info(df):

    print(df.head())

    print(df.isna().any())  # 查看是否有缺失值
    print(df.isna().sum(axis=0))  # 查看列缺失值数量
    # print(df.isna().sum(axis=1))  # 查看行缺失值数量

    print(df['news_type'].value_counts())
    print(df['news_time'].value_counts())
    print(df['news_site'].value_counts())
    # print(df['is_dup'].value_counts())

    print(df.info())
    print(df.describe())


if __name__ == '__main__':  

    df = pd.read_csv('../data/data1.csv')
    # 删除空值数据
    df.replace(to_replace=r'^\s*$', value=np.nan, regex=True, inplace=True)
    # show_info(df)
    df = df.dropna(how='any')

    # 更新新闻类型
    df['news_type'] = df.apply(update_news_type, axis=1)
    # 计算原始数据字符长度
    df['origin_char_len'] = df.apply(compute_char_len, axis=1)
    # 格式化原始文本
    df['news_content'] = df.apply(format_content, axis=1)
    # 删除HTML标签
    df['news_content'] = df.apply(remove_html, axis=1)
    # 删除URL
    df['news_content'] = df.apply(remove_url, axis=1)
    # 删除Email
    df['news_content'] = df.apply(remove_email, axis=1)
    # 删除移动电话
    df['news_content'] = df.apply(remove_cell_phone, axis=1)
    # 删除固定电话
    df['news_content'] = df.apply(remove_landline_phone, axis=1)
    # 删除冗余字符
    df['news_content'] = df.apply(remove_landline_phone, axis=1)
    # 计算处理后的字符长度
    df['new_char_len'] = df.apply(compute_char_len, axis=1)
    # 分词
    df['news_segment_content'] = df.apply(segment, axis=1)
    # 计算词长度
    df['word_len'] = df.apply(compute_word_len, axis=1)
    # # 删除重复数据
    # df['is_dup'] = df.apply(remove_dup, axis=1)
    show_info(df)

    df.to_csv('../data/process_data.csv')
