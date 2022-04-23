#pragma once
#ifndef _VALUES_H
#define _VALUES_H

#include <string>
using namespace std;


/*****************************************************************************
* @author  : Jiajun Chang,Hongguang Zhao                                                             *
* @date    :
* @file    :
* @brief   : 储存id,string或数字字面量的值
*****************************************************************************/
class values {
public:
	/*****************************************************************************
	* @name    : values
	* @input   : 终结符类型，储存终结符属性的字符串
	* @output  : 
	* @brief   : 构造函数
	*****************************************************************************/
	values(int type,char* array);



	int getValueType();
	int getValueSize();
	string getStringValue();
	int getDigitsValue();
private:

	/*终结符的类型,1-id,2-string,3-digits*/
	int type;
	/*终结符的值*/
	string strval;
	int digitsval;
	/*值在内存中的长度*/
	int size;


};


#endif
