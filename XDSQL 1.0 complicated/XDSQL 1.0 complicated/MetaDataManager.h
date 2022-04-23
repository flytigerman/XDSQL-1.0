#pragma once
#ifndef _METADATAMANAGER_H
#define _METADATAMANAGER_H


#pragma comment(lib,"dbNode.lib")
#pragma comment(lib,"tableNode.lib")
#pragma comment(lib,"StorageNode.lib")
#pragma comment(lib,"StorageEngine.lib")
#include "define.h"
#include "dbNode.h"
#include "tableNode.h"
#include "StorageNode.h"
#include "StorageEngine.h"
#include<vector>
#include<map>
using namespace std;



/*****************************************************************************
* @author  : Jiajun Chang,Hongguang Zhao                                                             *
* @date    : 
* @file    :
* @brief   : 元数据管理器
*****************************************************************************/
class MetaDataManager {
public:


	MetaDataManager(int);



	/*****************************************************************************
	* @name    : MetaDataManager
	* @input   :
	* @output  :
	* @brief   : 构造函数，使用元数据表构造各个容器
	*****************************************************************************/
	MetaDataManager();



	/*****************************************************************************
	* @name    : insertDB
	* @input   : 指向新的库元数据对象的指针
	* @output  : 写入文件成功返回true，否则返回false
	* @brief   : 将一个数据库的信息加入库元数据表和对应的map容器中
	*****************************************************************************/
	bool insertDB(dbNode* node);



	/*****************************************************************************
	* @name    : deleteDB
	* @input   : 要被删除的数据库的名称(不带路径)
	* @output  : 删除成功返回true，若数据库不存在或删除失败返回false
	* @brief   : 将指定名称的数据库的记录从库元数据表和map容器中删除
	*****************************************************************************/
	bool deleteDB(string dbname);



	/*****************************************************************************
	* @name    : selectDB 
	* @input   : 要查询的数据库名称(不带路径)
	* @output  : 查询值组成的动态数组
	* @brief   : 在库元数据表中查询名称为dbname的数据库，并获得该数据库的信息。
	*			 若dbname为空，则返回所有数据库的信息
	*****************************************************************************/
	vector<dbNode*> selectDB(string dbname);




	/*****************************************************************************
	* @name    : updateDB
	* @input   :
	* @output  :
	* @brief   : 将dbname数据库在库元数据表中的记录更新为容器中对应对象的数据
	*****************************************************************************/
	bool updateDB(string dbname);




	/*****************************************************************************
	* @name    : createDBTable
	* @input   : 数据库名称(不带路径)
	* @output  : 创建成功返回true，否则返回false
	* @brief   : 在指定的数据库目录下创建表元数据表
	*****************************************************************************/
	bool createDBTable(string dbname);



	/*****************************************************************************
	* @name    : insertDBTable
	* @input   : 数据库名称(不带路径)，表元数据节点的指针
	* output  : 文件写入成功返回true，否则返回false
	* @brief   : 将一个表的表元数据加入元数据管理器的sys_table容器，并将对应的数据写入
	*			 表元数据表的物理文件中
	*****************************************************************************/
	bool insertDBTable(string dbname, tableNode* node);



	/*****************************************************************************
	* @name    : deleteDBTable
	* @input   : 数据库名称(不带路径)，表名称(不带路径)
	* @output  : 删除成功返回true，若删除失败或不存在该表返回false
	* @brief   : 将指定的表的数据从表元数据表中删除，同时对元数据管理器中的sys_table
	*			 容器做修改
	*****************************************************************************/
	bool deleteDBTable(string dbname,string tablename);




	/*****************************************************************************
	* @name    : selectDBTable
	* @input   : 数据库名称(不带路径),表名称(不带路径)
	* @output  : 储存查询结果的动态数组
	* @brief   : 查询给定的表的信息。若tablename为空，返回该数据库中所有表的信息
	*****************************************************************************/
	vector<tableNode*> selectDBTable(string dbname,string tablename);




	/*****************************************************************************
	* @name    : createTableCol
	* @input   : 数据库名称(不带路径)
	* @output  : 
	* @brief   : 在指定数据库的目录下创建列元数据表
	*****************************************************************************/
	bool createTableCol(string daname);




	/*****************************************************************************
	* @name    : insertTableCol
	* @input   : 数据库名称(不带路径)，列所属表的名称(不带路径)，指向列元数据对象的指针
	* @output  : 
	* @brief   : 将列元数据写入文件，同时更新元数据管理器中对应的容器
	*****************************************************************************/
	bool insertTableCol(string dbname,string tablename,colNode* colnode);





	/*****************************************************************************
	* @name    : deleteTableCol
	* @input   : 数据库名称(不带路径)，列所属表的名称(不带路径)
	* @output  : 删除成功返回true,若删除失败或不存在这样的数据行返回false
	* @brief   : 删除列元数据表中所有属于所给表的列的列元数据,元数据管理器中容器的修改
	*			 放在tableNode的析构函数中做
	*****************************************************************************/
	bool deleteTableCol(string dbname,string tablename);




	/*****************************************************************************
	* @name    : selectTableCol
	* @input   : 数据库名称(不带路径),列所属表的名称(不带路径),列名
	* @output  : 
	* @brief   : 查询所给列名对应的列元数据。若列名为空，返回表中所有列的数据
	*****************************************************************************/
	vector<colNode*> selectTableCol(string dbname,string tablename,string colname);






	




	/*****************************************************************************
	* @name    :
	* @input   :
	* @output  :
	* @brief   : 析构函数
	*****************************************************************************/
	~MetaDataManager();


private:
	/* 储存所有库元数据,使用map容器，key为数据库名称，value为指向库元数据对象的指针 */
	map<string,dbNode*> sys_db;
	/* 储存所有表元数据，使用map容器，key为pair<数据库名称,用户表名称>
	   value为指向表元数据对象的指针 */
	map<pair<string, string>, tableNode*> sys_table;

};


#endif

