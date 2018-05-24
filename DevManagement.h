
#include<stdio.h>
#include<string.h>
#define n 2 /* 宏定义，用于修改设备类型数目 */
#define m 6 /* 宏定义，用于修改设备数目 */
typedef struct EquipT/* 该结构体用于定义设备类表各信息 */
{ 
	char type[10]; /* 设备类型名*/
	int count; /* 拥有的设备总台数 */
	int remain; /* 现存的可用设备台数 */
	int address; /* 该类设备在设备表中的起始地址 */
};

typedef struct EquipM/* 该结构体用于定义设备表各信息 */
{
	int number; /* 设备绝对编号 */
	int status; /* 设备好坏状态 */
	int remain; /* 设备是否已被分配 */
	char jobname[10]; /* 占有设备的作业名 */
};

/********************** 子 函 数 ： 作 业 设 备 分 配*****************************/
class DevManagement
{
    public:
		void allocate(char jobname[30],char type[34]);
		void reclaim(char jobname[30],char type[34]);
        int init();

};


