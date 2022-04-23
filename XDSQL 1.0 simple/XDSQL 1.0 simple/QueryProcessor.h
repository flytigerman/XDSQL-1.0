#pragma once
#ifndef _QUERYPROCESSOR_H
#define _QUERYPROCESSOR_H

#pragma comment(lib,"MetaDataManager.lib")
#pragma comment(lib,"StorageEngine.lib")
#pragma comment(lib,"StorageNode.lib")
#pragma comment(lib,"colinf.lib")
#pragma comment(lib,"colsvalue.lib")
#pragma comment(lib,"condition.lib")
#include "MetaDataManager.h"
#include "define.h"
#include "StorageEngine.h"
#include "StorageNode.h"
#include "colinf.h"
#include "colsvalue.h"
#include "condition.h"


/*****************************************************************************
* @author  : Jiajun Chang,Hongguang Zhao                                                             *
* @date    :
* @file    :
* @brief   : 查询处理层，直接为SQL引擎提供服务
*****************************************************************************/
class QueryProcessor {
public:

	/*****************************************************************************
	* @name    : init
	* @input   :
	* @output  :
	* @brief   : 初始化静态成员mdm
	*****************************************************************************/
	static void init(MetaDataManager* mdm);



	/*****************************************************************************
	* @name    : createDB
	* @input   : 数据库名称(不带路径)
	* @output  : 
	* @brief   : 创建一个新的数据库
	*****************************************************************************/
	void createDB(string dbname);



	/*****************************************************************************
	* @name    : dropDB
	* @input   : 数据库名称(不带路径)
	* @output  :
	* @brief   : 删除数据库
	*****************************************************************************/
	void dropDB(string dbname);




	/*****************************************************************************
	* @name    : useDB
	* @input   : 数据库名称(不带路径)
	* @output  :
	* @brief   : 切换当前使用的数据库为名为dbname的数据库
	*****************************************************************************/
	void useDB(string dbname);




	/*****************************************************************************
	* @name    : showDB
	* @input   :
	* @output  :
	* @brief   : 输出数据库系统中所有数据库的名称和数据库的数量
	*****************************************************************************/
	void showDB();


		

	/*****************************************************************************
	* @name    : createTable
	* @input   : 表名(不带路径),储存列元数据的动态数组
	* @output  :
	* @brief   : 在当前数据库中创建用户数据表
	*****************************************************************************/
	void createTable(string tablename,vector<colinf*> cols);





	/*****************************************************************************
	* @name    : dropTable
	* @input   : 表的名称(不带路径)
	* @output  :
	* @brief   : 删除当前数据库中名称为tablename的用户表
	*****************************************************************************/
	void dropTable(string tablename);




	/*****************************************************************************
	* @name    : showTable
	* @input   :
	* @output  :
	* @brief   : 输出当前数据库中所有用户表的表元数据和列元数据
	*****************************************************************************/
	void showTable();




	/*****************************************************************************
	* @name    : insertTable
	* @input   : 若pattern为1，则sql不带有列名，若pattern为2，则sql带有列名
	* @output  :
	* @brief   : 将一个元组插入当前数据库下的用户数据表
	*****************************************************************************/
	void insertTable(string tablename,colsvalue cols, int pattern);




	/*****************************************************************************
	* @name    : deleteTable
	* @input   : 表名,条件表达式对应的生成树的根节点。若root为NULL，则不使用条件查询
	* @output  : 
	* @brief   : 删除数据库中(满足条件)的行
	*****************************************************************************/
	void deleteTable(string tablename,condition* root);






	/*****************************************************************************
	* @name    : updateTable
	* @input   : 表名,列更新后的值,条件表达式的生成树
	* @output  :
	* @brief   : 更新元组。若root为NULL,更新所有的元组
	*****************************************************************************/
	void updateTable(string tablename,colsvalue setconf,condition* root);

	



	/*****************************************************************************
	* @name    : selectTable
	* @input   : 作为查询结果的列,被查询的表,条件表达式的生成树
	* @output  :
	* @brief   : 查询表。若root为NULL,则选择所有的元组
	*****************************************************************************/
	void selectTable(colsvalue tables,colsvalue tablecolsconf ,condition* root);



private:
	static MetaDataManager* mdm;		/*元数据管理器对象*/
	static string usedatabase;		/*当前正在使用的数据库的名称*/




	/*****************************************************************************
	* @name    :
	* @input   :
	* @output  :
	* @brief   : 将dataarray与表达式生成树的列名绑定起来
	*****************************************************************************/
	void conditionLinkData(vector<colvalue*>& dataarray,condition* root);





	/*****************************************************************************
	* @name    : tableJoin
	* @input   : 临时表中一行的长度
	* @output  :
	* @brief   : 为selectTable()提供服务
	*****************************************************************************/
	void tableJoin(vector<colvalue*> tables, int temp_rowlength);




	/*****************************************************************************
	* @name    :
	* @input   : index:表的顺序(从0开始)	row:储存临时表元组的字节数组
	*			 start:当前数据写入row的起始位置
	* @output  : 
	* @brief   : 将tables中的表按顺序进行笛卡尔积运算,并储存到临时表tamp.dat中
	*****************************************************************************/
	void tableJoin(vector<colvalue*> tables,int index,char* row, int start);
	




	/*****************************************************************************
	* @name    : dropTempTable
	* @input   :
	* @output  :
	* @brief   : 删除临时表的物理文件
	*****************************************************************************/
	void dropTempTable();

};



#endif