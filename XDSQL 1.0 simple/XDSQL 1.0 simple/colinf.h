#pragma once
#ifndef _COLINF_H
#define _COLINF_H
#include <string>
using namespace std;


/*****************************************************************************
* @author  : Jiajun Chang,Hongguang Zhao                                                             *
* @date    :
* @file    :
* @brief   : 储存sql引擎中获取的列元数据
*****************************************************************************/
class colinf {
public:

	/*****************************************************************************
	* @name    : colinf
	* @input   :
	* @output  :
	* @brief   : 默认构造函数
	*****************************************************************************/
	colinf();

	

	/*****************************************************************************
	* @name    : colinf
	* @input   :
	* @output  :
	* @brief   : 构造函数
	*****************************************************************************/
	colinf(std::string colname,int coltype,int collength);

	


	/*****************************************************************************
	* @name    : getColName
	* @input   :
	* @output  :
	* @brief   :
	*****************************************************************************/
	string  getColName();

	void setColName(string colname);



	/*****************************************************************************
	* @name    : getColType
	* @input   :
	* @output  :
	* @brief   :
	*****************************************************************************/
	int getColType();

	void setColType(int coltype);


	/*****************************************************************************
	* @name    : getColLength
	* @input   :
	* @output  :
	* @brief   :
	*****************************************************************************/
	int getColLength();

	void setColLength(int collength);

private:
	std::string colname;	/*列名*/
	int coltype;			/*列的数据类型,2--string,3--digits*/
	int collength;			/*列的长度(以逻辑模式来看)*/
};


#endif

