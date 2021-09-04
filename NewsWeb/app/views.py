#!usr/bin/env python
#-*- coding:utf-8 -*-

import json
import requests
from flask import Flask, request, render_template


app = Flask(__name__)


@app.route('/')
def index():
    res = post_hot_api()
    if not res:
        data = []
    else:
        data = res['result']
    return render_template('index.html', data=data)


@app.route('/suggest/')
def suggest():
    return 'suggest'


@app.route('/search', methods=['POST', 'GET'])
def search():
    if request.method == 'POST':
        query = request.form['search']
    else:
        query = request.args.get('query', None)
    res = post_search_api(query)
    if not res:
        data = []
    else:
        data = res['result']
    return render_template('result.html', query=query, data=data)


@app.route('/detail/<nid>')
def detail(nid=None):
    return 'detail'


@app.route('/about')
def about():
    return render_template('about.html')


@app.errorhandler(400)
def page_not_found(error):
    return render_template('errors/400.html'), 400


@app.errorhandler(403)
def page_not_found(error):
    return render_template('errors/403.html'), 403


@app.errorhandler(404)
def page_not_found(error):
    return render_template('errors/404.html'), 404


@app.errorhandler(405)
def page_not_found(error):
    return render_template('errors/405.html'), 405


def post_search_api(query):
    # headers = {
    #     'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/70.0.3538.110 Safari/537.36',
    #     'X-Requested-With': 'XMLHttpRequest',
    #     'Content-Type': 'application/json',
    # }
    try:
        response = requests.post(
            url="http://10.77.200.63:8004/SearchService/query",
            # headers=headers,
            data=json.dumps({'query': query})
        )
        if response.status_code == 200:
            return response.json()
    except requests.ConnectionError as e:
        print('Error', e.args)


def post_hot_api():
    try:
        response = requests.post(
            url="http://10.77.200.63:8004/SearchService/hot",
            # headers=headers,
            # data=json.dumps({'query': query})
        )
        if response.status_code == 200:
            return response.json()
    except requests.ConnectionError as e:
        print('Error', e.args)