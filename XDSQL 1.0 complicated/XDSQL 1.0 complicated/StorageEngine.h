#pragma once
#ifndef _STORAGEENGINE_H
#define _STORAGEENGINE_H

#include "define.h"
#include<string>
#include<vector>
//#include<Windows.h>
#include<stdio.h>

using namespace std;


/*****************************************************************************
* @author  : Jiajun Chang,Hongguang Zhao                                                             *
* @date    : 2022/3/30
* @file    : 
* @brief   : 存储引擎类，提供对文件系统的操作
*****************************************************************************/
class StorageEngine
{
public:	
	/*****************************************************************************
	* @name    : createDBDir
	* @input   : 文件夹名(带有路径)
	* @output  : 创建成功返回true，否则返回flase
	* @brief   : 创建文件夹
	*****************************************************************************/
	static bool createDBDir(string dirname);



	/*****************************************************************************
	* @name    : deleteDBDir
	* @input   : 文件夹名(带有路径)
	* @output  : 删除成功返回true，否则返回flase
	* @brief   : 删除指定的文件夹
	*****************************************************************************/
	static bool deleteDBDir(string dirname);



	/*****************************************************************************
	* @name    : create
	* @input   : 文件名(带有路径)
	* @output  : 创建成功返回true，否则返回flase
	* @brief   : 创建物理文件
	*****************************************************************************/
	static bool create(string filename);


	/*****************************************************************************
	* @name    : drop
	* @input   : 文件名(带有路径)
	* @output  : 删除成功返回true，否则返回false
	* @brief   : 删除物理文件
	*****************************************************************************/
	static bool drop(string filename);
};







#endif

