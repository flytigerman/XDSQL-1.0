#pragma once
#ifndef _CONDITION_H
#define _CONDITION_H

#include "conditiontype.h"
#include "MetaDataManager.h"


/*****************************************************************************
* @author  : Jiajun Chang,Hongguang Zhao
* @date    :
* @file    :
* @brief   : �����������ʽ������
*****************************************************************************/
class condition {
public:
	/* ���Ҳ����������ͺ�ֵ */
	conditiontype left;
	conditiontype right;

	/*true��ʾ�ñ��ʽ�����Ϊ�߼������������Ϊ���������*/
	bool iscond;

	/*�Ƚ������,1:<   2:>  3:<=  4:>=  5:=  6:!=*/
	int comp_op;

	/*�߼������ 1--AND  2--OR  3--NOT  */
	int comp_cond;

	/*�ñ��ʽ���߼�ֵ*/
	bool result;
	/*������̬�߼���unknown*/
	bool isunknown;



	/*****************************************************************************
	* @name    : dealConditions
	* @input   :
	* @output  : pair��first��������resultֵ,second��������isunknownֵ
	* @brief   : �����Ե�ǰ����Ϊ���ڵ�����������߼�ֵ�����������result��Ա������
	*****************************************************************************/
	pair<bool, bool> dealConditions();




	/*****************************************************************************
	* @name    : condition
	* @input   :
	* @output  :
	* @brief   : �޲ι��캯��
	*****************************************************************************/
	condition();





	/*****************************************************************************
	* @name    : addTableName
	* @input   :
	* @output  :
	* @brief   : ��delete��update�п��ܴ�SQL�����ȡ��colvalue������û��tablename��Ա
	*			 �����ֶ�����
	*****************************************************************************/
	void addTableName(string tablename);





	/*****************************************************************************
	* @name    : addTableName
	* @input   :
	* @output  :
	* @brief   : ���ڶ������,����Ԫ���ݹ�����,����������,����condition�ڵ��е�
				 tablename����
	*****************************************************************************/
	void addTableName(MetaDataManager* mdm,
		string dbname,
		vector<colvalue*> tables);







	/*****************************************************************************
	* @name    : ~condition
	* @input   :
	* @output  :
	* @brief   : �ݹ���ͷ�һ�����������ڴ�
	*****************************************************************************/
	~condition();

};


#endif
