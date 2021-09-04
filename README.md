# 新闻搜索引擎
使用 Python 和 C++ 结合实现的新闻搜索引擎系统，本系统主要包括数据爬取、根据 BM25 算法进行搜索排序以及热门搜索等功能。

## 效果展示
![](https://github.com/hiyoung123/NewsSearchEngine/blob/master/Resource/Sep-04-2021%2017-58-34.gif)
## 下载系统

使用 Scrapy 框架，爬取新浪新闻、网易新闻和搜狐新闻每日滚动新闻，进行增量爬取。通过 BloomFilter 进行网页 URL 过滤，保证爬取网页唯一。

### 依赖

* scrapy
* redis：代码依赖 redis 数据库，使用 BloomFilter 进行 URL 过滤，所以先安装好 Redis 数据库，并在使用中更改数据库配置（NewsSpider/utils/BloomFilter.py）。

### 使用

进入 NewsSpider 目录下，通过 main.py 文件执行操作，爬取对应网站的新闻，详细说明请参考[NewsSpider](https://github.com/hiyoung123/NewsSpider)



## 分析系统 

对爬取的到的新闻数据进行合并，并且进行一些列预处理，比如去除 html 标签等操作。并将处理后的数据建立倒排索引。

### 依赖

* pandas
* jieba
* numpy
* pymysql

### 使用

进入 NewsProcess 目录，执行对应操作。

* Merge_file：将爬取到的多个 csv 文件合并
* Process：处理 csv 文件中的新闻数据，包括去除 html 标记，中文分词等操作。
* statistics：统计新闻词频，文档长度等信息，并建立倒排索引文件 news.json，同时将新闻数据插入到 mysql 数据库中。 在该文件中配置数据库信息。

### mysql 数据库配置

* 创建数据库

  ``` bash
  create database webserver;
  ```

* 创建表

  ``` bash
  create table news(id int, title char(255), content text, url char(255), primary key(id));
  ```

  

## 搜索服务

本系统后端是由 brpc 搭建的多个服务相互调用的 rpc 服务。

* NLP Server：提供了分词、召回和排序服务。
* Search Server：作为搜索服务的统一入口服务，通过调用 NLP Server 提供的服务进行搜索处理。并且提供了热门查询搜索的服务。

### 依赖

* c++11
* cppjieba
* hiredis
* brpc
* protobuf
* mysqlclient
* nlohmann/json

### 使用

* 开启 NLP 相关服务

  ``` bash
  cd brpc_nlp_service
  make server
  ./bin/server
  ```

* 开启 Search 服务

  ```bash
  cd brpc_search_service
  make server
  ./bin/server
  ```

* 数据库相关配置在 brpc_search_service/code/service/search.hpp 文件中



## 前端展示

使用 Flask 框架，进行页面展示以及前端逻辑操作。

### 依赖

* Flask

### 使用

直接进入 NewsWeb 目录，执行 run.py 程序即可。

修改调用后台服务信息：NewsWeb/app/views.py 



## TODO

* 优化整体模块代码结构，目前代码模块整体流程不连续，无法自动化执行。
* 优化连接池代码，Mysql 和 Redis 连接池统一继承连接池类，减少重复代码
* 优化数据配置，改为由配置文件提供，减少代码修改。
* 添加搜索 Cache 机制
* 添加语义召回等召回策略
* 完善 README.md 文档
