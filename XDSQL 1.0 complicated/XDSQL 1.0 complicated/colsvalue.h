#pragma once
#ifndef _COLSVALUE_H
#define _COLSVALUE_H

#pragma comment(lib,"colvalue.lib")
#pragma comment(lib,"MetaDataManager.lib")

#include <vector>
#include "colvalue.h"
#include "MetaDataManager.h"

/*****************************************************************************
* @author  : Jiajun Chang,Hongguang Zhao                                                             *
* @date    :
* @file    :
* @brief   :
*****************************************************************************/
class colsvalue {
public:
	/*储存多个列的值*/
	std::vector<colvalue*> vec;


	/*用于select table,若为true，说明是select* from tbale */
	bool isALL;


	void setRowLength(int rowlength);

	

	/*****************************************************************************
	* @name    : colsvalue
	* @input   : 
	* @output  : 
	* @brief   : 无参构造函数
	*****************************************************************************/
	colsvalue();



	/*****************************************************************************
	* @name    : colsvalue
	* @input   :
	* @output  :
	* @brief   : 通过列元数据tablecol创建对应的colvalue(主要用在创建dataarray)
	*****************************************************************************/
	colsvalue(vector<colNode*> tablecol);





	/*****************************************************************************
	* @name    : addCols
	* @input   :
	* @output  :
	* @brief   : 根据列元数据增加对应的colvalue(用于多表连接和创建dataarray)
	*****************************************************************************/
	void addCols(vector<colNode*> tablecol);



	/*****************************************************************************
	* @name    : setIndex
	* @input   :
	* @output  :
	* @brief   : 根据元数据管理器设置cols中各个列数据的inedx成员
	*****************************************************************************/
	void setIndex(MetaDataManager* mdm,string dbname,string tablename);


	/*****************************************************************************
	* @name    : toByte
	* @input   :
	* @output  :
	* @brief   : 获取这些列对应的元组的字节数组(需要先把列元数据补充完整)
	*****************************************************************************/
	char* toByte();




	/*****************************************************************************
	* @name    : link2MetaData
	* @input   : 列元数据
	* @output  :
	* @brief   : 将列元数据绑定到vec中的colvalue对象上
	*****************************************************************************/
	void link2MetaData(vector<colNode*> tablecol);



	/*****************************************************************************
	* @name    : setCols
	* @input   :
	* @output  :
	* @brief   : 将从表中读取的字节数组转换为每一列的值,只能处理一个表
	*****************************************************************************/
	void setCols(char* row,MetaDataManager* mdm,string dbname,string tablename);




	/*****************************************************************************
	* @name    : toByte
	* @input   :
	* @output  :
	* @brief   : row为旧的行,使用vec中的更新值更新row
	*****************************************************************************/
	char* toByte(char* row, MetaDataManager* mdm, string dbname, string tablename);



	/*****************************************************************************
	* @name    : ~colsvalue
	* @input   :
	* @output  :
	* @brief   : 析构函数(取消释放内存了,改由使用该类的时候手动释放,否则在select table
				 模块会出现一块内存被多次释放的错误)
	*****************************************************************************/
	~colsvalue();


private:
	int rowlength;		/*完整元组的长度(不带标志位，字符串预留一位)*/

};

#endif

