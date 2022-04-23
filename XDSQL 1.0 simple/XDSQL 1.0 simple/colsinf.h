#pragma once
#ifndef _COLSINF_H
#define _COLSINF_H

#pragma comment(lib,"colinf.lib")
#include <vector>
#include "colinf.h"




/*****************************************************************************
* @name    : colsinf
* @input   :
* @output  :
* @brief   : 使用动态数组储存多列的列元数据
*****************************************************************************/
class colsinf {
public:

	/*****************************************************************************
	* @name    : ~colsinf
	* @input   :
	* @output  :
	* @brief   : 析构函数
	*****************************************************************************/
	~colsinf();



	std::vector<colinf*> vec;
};

#endif

