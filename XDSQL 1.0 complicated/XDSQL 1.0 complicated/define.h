#pragma once
#ifndef _DEFINE_H
#define _DEFINE_H

/* 说明：此头文件用于提供通用的宏定义 */


/* 存储物理文件的文件夹位置 */
#define SQLFILE "../SQLFile/"

/*元数据表名称*/
#define SYS_DB "system_db.dat"
#define SYS_TABLE "/system_table.dat"
#define SYS_COL "/system_col.dat"
/*元数据表中元组的长度与各个属性的长度(以数据库逻辑模式来看的长度，内模式存储引擎
操作时可能要再留出'\0'的位置)*/
#define SYS_DB_TUPLE 24
#define SYS_DB_COL1 20
#define SYS_DB_COL2 4
#define SYS_TABLE_TUPLE 28
#define SYS_TABLE_COL1 20
#define SYS_TABLE_COL2 4
#define SYS_TABLE_COL3 4
#define SYS_COL_TUPLE 49
#define SYS_COL_COL1 20
#define SYS_COL_COL2 20
#define SYS_COL_COL3 1
#define SYS_COL_COL4 4
#define SYS_COL_COL5 4



#endif
