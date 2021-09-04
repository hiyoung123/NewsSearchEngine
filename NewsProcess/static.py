#!usr/bin/env python
# -*- coding:utf-8 -*-

from tqdm import tqdm
import jieba
import json
import pandas as pd
import pymysql

stops = [x for x in open('../data/stopwords.txt', 'r', encoding='utf-8')]
conn = pymysql.connect(host="10.77.200.63", port=3306, db="webserver", user='root', password='liuhaiyang210')
cursor = conn.cursor(pymysql.cursors.DictCursor)


def build_word_dict_from_csv(data):
    word_dict = {}
    total_dl = 0
    data = tqdm(data, ncols=100)
    for item in data:
        id = item[0]
        title = item[6]
        content = item[10]
        dl = item[11]
        total_dl += dl
        text = [x for x in jieba.cut(title)]*10 + content.split()
        text = [x for x in text if x not in stops]
        for word in text:
            tf = text.count(word)
            word_dict[word] = word_dict.get(word, {})
            word_dict[word]['DF'] = 0
            word_dict[word]['index_item'] = word_dict[word].get('index_item', [])
            if word_dict[word]['index_item'].count({"TF": tf, "DocId": id, "dl": dl}) == 0:
                word_dict[word]['index_item'].append({"TF": tf, "DocId": id, "dl": dl})
        for word in word_dict.keys():
            word_dict[word]['DF'] = len(word_dict[word]['index_item'])

        try:
            cursor.execute("insert into news (id, content, title, url) values(%s, %s, %s, %s)", (item[0], item[2].strip(), item[6].strip(), item[3]))
            conn.commit()
        except Exception as e:
            print(e)
    print("avdl = %s" % (total_dl / len(data)))
    return word_dict


if __name__ == "__main__":
    data = pd.read_csv('../data/process_data.csv')
    data = data.values[0:1000]
    result = build_word_dict_from_csv(data)
    with open('../data/news.json', 'w', encoding='utf-8') as file_obj:
        json.dump(result, file_obj, ensure_ascii=False)
    # print(data[54])
    # print(data[92])
    # print(data[71])