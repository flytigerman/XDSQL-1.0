#pragma once
#ifndef _CONDITIONTYPE_H
#define _CONDITIONTYPE_H

#pragma comment(lib,"colvalue.lib")
#include "colvalue.h"
class condition;		/*声明这个类(不能直接引入头文件，否则会循环依赖)*/


/*****************************************************************************
* @author  : Jiajun Chang,Hongguang Zhao                                                             *
* @date    :
* @file    :
* @brief   : 储存条件表达式左/右部分的数据类型和值
*****************************************************************************/
class conditiontype {
public:
	/*左/右部分的数据类型,1--[表名.]列名,2--STRING,3--INT,4--条件表达式*/
	int type;
	colvalue* col;		/*[表名.]列名,从SQL引擎返回后还要负责绑定另一个数组*/
	string str;			/*字符串的值*/
	int digits;			/*数字的值*/
	condition* cond;	/*后代指针*/
};


#endif

