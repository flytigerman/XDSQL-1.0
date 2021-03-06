#pragma once
#ifndef _TABLENODE_H
#define _TABLENODE_H

#pragma comment(lib,"StorageNode.lib")
#pragma comment(lib,"colNode.lib")
#include "define.h"
#include "StorageNode.h"
#include "colNode.h"
#include<map>
#include<vector>






/*****************************************************************************
* @author  : Jiajun Chang,Hongguang Zhao                                                             *
* @date    :
* @file    :
* @brief   : 表元数据类
*****************************************************************************/
class tableNode {
public:

	/*****************************************************************************
	* @name    : tableNode
	* @input   : 
	* @output  : 
	* @brief   : 构造函数
	*****************************************************************************/
	tableNode(string tableName, int colNum, int rowLength);


	/*****************************************************************************
	* @name    : tableNode
	* @input   :
	* @output  :
	* @brief   : 根据从文件中获取的字节数组构造一个表元数据对象
	*****************************************************************************/
	tableNode(char* bytearray);




	/*****************************************************************************
	* @name    : toByte
	* @input   :
	* @output  :
	* @brief   : 将表元数据对象中的数据转换为字节数组
	*****************************************************************************/
	char* toByte();




	/*****************************************************************************
	* @name    : addCol
	* @input   :
	* @output  : 
	* @brief   : 将一个列的列元信息加入map容器
	*****************************************************************************/
	void addCol(colNode* node);



	/*****************************************************************************
	* @name    : getTableName
	* @input   :
	* @output  :
	* @brief   : 获取用户表的名称
	*****************************************************************************/
	string getTableName();



	/*****************************************************************************
	* @name    : getColNum
	* @input   :
	* @output  :
	* @brief   : 获取该表的列数
	*****************************************************************************/
	int getColNum();




	/*****************************************************************************
	* @name    : getRowLength
	* @input   :
	* @output  :
	* @brief   : 获取一行的长度
	*****************************************************************************/
	int getRowLength();





	/*****************************************************************************
	* @name    : findCol
	* @input   : 列名
	* @output  : 
	* @brief   : 找到该表中此列名对应的列元数据,若colname==null,返回所有列的列元数据
	*****************************************************************************/
	vector<colNode*> findCol(string colname);





	/*****************************************************************************
	* @name    : ~tableNode
	* @input   :
	* @output  :
	* @brief   : 析构函数，回收内存
	*****************************************************************************/
	~tableNode();


	



private:
	string tableName;	/*表名*/
	int colNum;			/*表中列的数量*/
	int rowLength;		/*一行的长度(没有算入标志位)*/
	/*该表中所有列的列元信息,用map容器储存
	  key为列名，value为列元数据对象的指针*/
	map<string, colNode*> sys_col;
};


#endif

