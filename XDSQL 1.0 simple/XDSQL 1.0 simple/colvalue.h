#pragma once
#ifndef _COLVALUE_H
#define _COLVALUE_H

#pragma comment(lib,"tableNode.lib")
#include "tableNode.h"
#include <string>



/*****************************************************************************
* @author  : Jiajun Chang,Hongguang Zhao                                                             *
* @date    :
* @file    :
* @brief   : 储存从SQL引擎获得的列的值(用于insert table),继承自tableNode类
*****************************************************************************/
class colvalue : public colNode{
public:


	/*****************************************************************************
	* @name    : getData
	* @input   :
	* @output  :
	* @brief   : 将字节数组转换为对应的string或digits
	*****************************************************************************/
	void getData(char* bytearray);




	/*****************************************************************************
	* @name    : getStringValue
	* @input   :
	* @output  :
	* @brief   : 获取字符串的值
	*****************************************************************************/
	string getStringValue();

	void setStringValue(string strval);



	/*****************************************************************************
	* @name    : getDigitsValue
	* @input   :
	* @output  :
	* @brief   : 获取整数的值
	*****************************************************************************/
	int getDigitsValue();

	void setDigitsValue(int digitsval);




	/*****************************************************************************
	* @name    : setIndex
	* @input   :
	* @output  :
	* @brief   : 设置index成员
	*****************************************************************************/
	void setIndex(int index);

	int getIndex();


	/*****************************************************************************
	* @name    : toByte
	* @input   :
	* @output  :
	* @brief   : 重写toByte()方法，返回列值对应的字节数组
	*****************************************************************************/
	char* toByte();


	/*记录元组中该列是否为NULL*/
	bool isNULL;


private:
	/*字符串的值*/
	string strval;
	/*整数的值*/
	int digitsval;
	/*该列在该表的字节数组中的起始位置*/
	int index;
	
};


#endif

