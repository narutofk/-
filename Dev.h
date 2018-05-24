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

		void allocate(char jobname[30],char type[34]);
		void reclaim(char jobname[30],char type[34]);
        int init();


EquipT equiptype[n]={{"A",4,3,001},{"B",2,2,005}}; /* 系 统 设 备 类型为 n假设有2个设备*/
EquipM equipment[m]={{1,1,1,"job1"},{2,1,0,"0"},{3,1,0,"0"},{4,1,0,"0"},{5,1,1,"0"},{6,1,1,"0"}}; /* 系统设备数为 m*/
void allocate(char jobname[30],char type[34])
{
	int i,t,t1;
	i=0;
	while(i<n&&strcmp(equiptype[i].type,type)!=0) /* 查找欲申请分配的设备类型， strcmp 函数用于比较 equiptype[i].type 与 type 的大小，若相等则返回 0*/
		i++;
	if(i>=n) /* 若没有找到欲申请设备 */
	{		
		printf(" 没有找到欲分配的设备 ,分配失败 !");
		return;
	}
	if(equiptype[i].remain<1) /* 欲申请设备现存可用台数不足 */
	{
		printf(" 该类设备数量不足，分配失败 !");
		return;
	}
	t=equiptype[i].address;
	t1=equiptype[i].address; /* 取出该类设备在设备表中的起始地址赋给 t*/
	while((t<t1+equiptype[i].count)&&!(equipment[t].status==1&&equipment[t].remain==0))
		t++;  /* 该设备类型起始地址加一 */
		/*填写作业名，状态改为已分配*/
		if(t<t1+equiptype[i].count)
		{
			equiptype[i].remain--;  /* 剩余设备数减一 */
			equipment[t].remain=1;  /* 状态改为已分配 */
			strcpy(equipment[t].jobname,jobname); /*strcpy 为 字 符 串 拷 贝函数，把 J中的字符串拷贝到 equipment[t].jobname 中*/
		} 
		else
		{
			printf("is bad device,fail\n");
			return;
		}
		 
		/*equipment[t].lnumber=cc;  设备相对号写入 cc*/
}
/********************** 子 函 数 ： 作 业 设 备 回 收*****************************/
void reclaim(char jobname[30],char type[34])
{
	int i,t,j,k,nn;
	i=0;
	while(i<n&&strcmp(equiptype[i].type,type)!=0) /* 查 找 欲 申 请归还的设备类型， strcmp 函数用于比较 equiptype[i].type 与 type 的大小，若相等则返回 0*/
		i++;
		if(i>=n)/* 若没有找到该类设备 */
		{
			printf(" 无该类设备 ,设备回收失败 !");
			return;
		}
		t=equiptype[i].address; /* 取出该类设备在设备表中的起始地址赋给 t*/
		j=equiptype[i].count; /* 取出该类设备的数量赋给 j*/
		k=0;
		nn=t+j;
		for(;t<nn;t++)
		{
			if(strcmp(equipment[t].jobname,jobname)==0&&equipment[t].remain==1)  /*若占用某个设备的作业与欲回收的作业相同且状态为已分配 */
			{
				equipment[t].remain=0;
				strcpy(equipment[t].jobname,"0"); /*则将其状态改为未分配 */
				k++; /* 回收设备计数 */
			}
			equiptype[i].remain= equiptype[i].remain+k; /*该类设备剩余设备数加 k*/
		}
		if(k==0) /* 若回收设备计数值 k 为 0,*/
		printf(" 本作业没有占用这类资源 !/n");
}
/********************** 主函数 *****************************/
int init()
{
	char jobname1[30];
	int i,t,a;
	char type1[20];
	i=0;
	t=0;
	printf(" 未分配前设备表类： \n ");
	printf("设备类拥有该设备台数现存台数设备表地址\n");
	for(i=0;i<n;i++) /* 输入设备类表初始信息 */
	{
		printf("%s\t\t%d\t\t%d\t\t%d\n",equiptype[i].type,equiptype[i].count,equiptype[i].remain,equiptype[i].address);
	}
	printf(" \n未分配前设备表:\n");
	printf(" 绝对号状态使用情况占用作业名\n");
	for(i=0;i<m;i++)
	{
		printf("%d\t\t%d\t\t%d\t\t%s\n",equipment[i].number,equipment[i].status,equipment[i].remain,equipment[i].jobname);
	}
	while(1)
	{
		printf("\n0- 退出,1-分配 ,2-回收 ,3-显示 "); /* 功 能 选 择 界面*/
		scanf("%d",&a);
		switch(a)
		{		
			case 0 :
				return 0;
			case 1 :/*a=1 分配设备 */
				printf(" 请输入作业名 \n");
				scanf("%s",jobname1);
				printf(" 请输入设备类型名： \n");
				scanf("%s",type1);
				allocate(jobname1,type1); /*分配设备 */
				break;
			case 2 :/*a=2 回收设备 */
				printf(" 请输入作业名 \n");
				scanf("%s",jobname1); /* 输入要回收的作业名及对应的设备类 */
				printf(" 请输入设备类型名： \n");
				scanf("%s",type1); 
				reclaim(jobname1,type1); /* 回收设备 */
				break;
			case 3 :/*a=3 输出设备类表和设备表的内容 */
				printf("\n 输出设备类表 !\n"); /* 输出设备类表内容 */
				printf(" 设备类拥有该设备台数现存台数设备表地址 \n");
				for(i=0;i<n;i++)
				{
				printf("%s\t\t%d\t\t%d\t\t%d\n",equiptype[i].type,equiptype[i].count,equiptype[i].remain,equiptype[i].address);	
				} 
				printf("\n分配后设备表");
				printf("绝对号状态使用情况占作业名\n");
				for(i=0;i<m;i++)
				{
					printf("%d\t\t%d\t\t%d\t\t%s\n",equipment[i].number,equipment[i].status,equipment[i].remain,equipment[i].jobname);
				}
				break;
			default:
				printf("没有该选项\n"); 
		
		}//case
	}//while
	return 0;
}
