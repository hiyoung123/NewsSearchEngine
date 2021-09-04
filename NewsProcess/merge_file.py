#!usr/bin/env python
# -*- coding:utf-8 -*-

import os
import argparse
import pandas as pd


def main(args):

    if args.is_folder:
        file_list = [os.path.join(args.input_files[0], x) for x in os.listdir(args.input_files[0])]
    else:
        file_list = args.input_files
    merge_file(file_list, args.output_file)


def merge_file(file_list: list, output_file: str):
    if not file_list or len(file_list) == 0:
        return
    df = pd.read_csv(file_list[0])
    for file_name in file_list[1:]:
        df = df.append(pd.read_csv(file_name), ignore_index=True)
    df.to_csv(output_file, index=False)


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('-i', dest='input_files', nargs='+', required=True, help='input file list of merge')
    parser.add_argument('-f', type=bool, dest='is_folder', default=False, required=False, help='if is folder')
    parser.add_argument('-o', dest='output_file', required=True, help='output file')
    args = parser.parse_args()
    main(args)