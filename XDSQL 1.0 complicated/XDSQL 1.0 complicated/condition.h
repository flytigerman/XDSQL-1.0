#pragma once
#ifndef _CONDITION_H
#define _CONDITION_H

#include "conditiontype.h"
#include "MetaDataManager.h"


/*****************************************************************************
* @author  : Jiajun Chang,Hongguang Zhao
* @date    :
* @file    :
* @brief   : 储存条件表达式的数据
*****************************************************************************/
class condition {
public:
	/* 左，右部的数据类型和值 */
	conditiontype left;
	conditiontype right;

	/*true表示该表达式运算符为逻辑运算符，否则为算术运算符*/
	bool iscond;

	/*比较运算符,1:<   2:>  3:<=  4:>=  5:=  6:!=*/
	int comp_op;

	/*逻辑运算符 1--AND  2--OR  3--NOT  */
	int comp_cond;

	/*该表达式的逻辑值*/
	bool result;
	/*补充三态逻辑的unknown*/
	bool isunknown;



	/*****************************************************************************
	* @name    : dealConditions
	* @input   :
	* @output  : pair的first是子树的result值,second是子树的isunknown值
	* @brief   : 计算以当前对象为根节点的生成树的逻辑值，设置自身的result成员并返回
	*****************************************************************************/
	pair<bool, bool> dealConditions();




	/*****************************************************************************
	* @name    : condition
	* @input   :
	* @output  :
	* @brief   : 无参构造函数
	*****************************************************************************/
	condition();





	/*****************************************************************************
	* @name    : addTableName
	* @input   :
	* @output  :
	* @brief   : 在delete和update中可能从SQL引擎获取的colvalue对象中没有tablename成员
	*			 所以手动加上
	*****************************************************************************/
	void addTableName(string tablename);





	/*****************************************************************************
	* @name    : addTableName
	* @input   :
	* @output  :
	* @brief   : 用于多表连接,根据元数据管理器,遍历整棵树,补充condition节点中的
				 tablename数据
	*****************************************************************************/
	void addTableName(MetaDataManager* mdm,
		string dbname,
		vector<colvalue*> tables);







	/*****************************************************************************
	* @name    : ~condition
	* @input   :
	* @output  :
	* @brief   : 递归的释放一个生成树的内存
	*****************************************************************************/
	~condition();

};


#endif
