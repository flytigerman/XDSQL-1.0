#pragma once
#ifndef _INITSQL_H
#define _INITSQL_H

#pragma comment(lib,"colNode.lib")
#pragma comment(lib,"dbNode.lib")
#pragma comment(lib,"tableNode.lib")
#pragma comment(lib,"MetaDataManager.lib")
#pragma comment(lib,"StorageEngine.lib")
#pragma comment(lib,"StorageNode.lib")
#include "colNode.h"
#include "dbNode.h"
#include "tableNode.h"
#include "define.h"
#include "MetaDataManager.h"
#include "StorageEngine.h"
#include "StorageNode.h"
#include <io.h>



/*****************************************************************************
* @author  : Jiajun Chang,Hongguang Zhao                                                             *
* @date    : 
* @file    : 
* @brief   : 初始化模块，负责初始化文件系统和元数据管理器
*****************************************************************************/
class initSQL {
public:
	/*****************************************************************************
	* @name    : init
	* @input   :
	* @output  :
	* @brief   : 初始化,创建文件系统,然后创建元数据管理器并用元数据表构造其中的容器
	*****************************************************************************/
	static MetaDataManager init();


private:
	/*****************************************************************************
	* @name    : mkDir
	* @input   :
	* @output  :
	* @brief   : 创建SQLFile文件夹和库元数据表
	*****************************************************************************/
	static bool mkDir();
};





#endif
