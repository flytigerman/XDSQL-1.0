# XDSQL数据库简介

XDSQL目前仅支持两种数据类型：**正整数**与**定长字符串**。

XDSQL目前支持以下sql：

~~~sql
CREATE DATABASE dbname ;
DROP DATABASE dbname ;
SHOW DATABASES ;
USE DATABASE dbname ;
CREATE TABLE tablename ( colname coltype [ , colname coltype ]… ) ;
DROP TABLE tablename ;
SHOW TABLES ;
INSERT INTO tablename [ ( colname [ , colname]… ) ] VALUES ( value [, value]… ) ;
SELECT {* | [tablename . ] colname [ , [tablename . ] colname]… } FROM tablename [ , tablename]… [ WHERE conditions ] ;
UPDATE tablename SET colname = value [ , colname = value]… [WHERE conditions] ;
DELETE FROM table [WHERE conditions] ;
~~~

其中dbname指数据库名称，tablename指数据表名称，colname指数据列名称，coltype指数据列类型，value指数据值，conditions指条件判断语句。

目前数据库中conditions只支持AND、OR、NOT、<、>、<=、>=、=、!=、条件判断，支持比较数据列（类如colname = value），但不支持数据列运算（类如colname = colname+value），不支持对NULL值的比较。

