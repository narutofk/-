#include<stdio.h>
#include<stdlib.h>

#define n 10 
#define m 10 

int uflag;//分配表标志
int fflag;//空闲表标志
float uend_address;
float fend_address;
float send_address;
//已分配
struct{
    int number;
    float address; 
    float length; 
    int flag; 
}used_table[n]; 

//空闲区表
struct{
    int number;
    float address; 
    float length; 
    int flag; 
}free_table[m]; 

void allocate(int str,float leg);//分配主存空间函数
void reclaim(int str);//回收主存函数

int store( ){
    int i,a;  
    float xk;
    int J;
    /*空闲分区表初始化：*/
    for(i=0;i<m;i++)
    {
      free_table[i].number=i;
      free_table[i].flag=1;
    }
    free_table[0].address=20;
    free_table[0].length=30;
    free_table[1].address=100;
    free_table[1].length=20;
    free_table[2].address=200;
    free_table[2].length=40;
    for(i=0;i<n;i++)
    {
      used_table[i].number=i;
      used_table[i].flag=0;
    }
    /*已分配表初始化：*/
    used_table[0].address=50;
    used_table[0].length=50; 
    used_table[0].flag=1;
    used_table[1].address=120;
    used_table[1].length=80;
    used_table[1].flag=2;
    while(1){
        printf("\n选择功能项（0-退出,1-分配主存,2-回收主存,3-显示主存）\n");
        printf("选择功项(0~3) :");
        scanf("%d",&a);
        switch(a) {
            case 0: exit(0); 
            case 1: 
                printf("输入作业名str和作业所需长度leg: ");
                scanf("%d%f",&J,&xk);
                allocate(J,xk);
                break;
            case 2: 
                printf("输入要回收分区的作业名");
                scanf("%d",&J);reclaim(J);
                break;
            case 3: 
                printf("输出空闲区表：\n编号 起始地址 分区长度   标志\n");
                for(i=0;i<m;i++)
                printf(" %d%9.0f%9.0f%9d\n",free_table[i].number,free_table[i].address,free_table[i].length, free_table[i].flag);
                printf(" 按任意键,输出已分配区表\n");
                getchar();
                   printf(" 输出已分配区表：\n编号 起始地址 分区长度   标志\n");
                for(i=0;i<n;i++)
               
                 printf(" %d%9.0f%9.0f%9d\n",used_table[i].number,used_table[i].address,used_table[i].length, used_table[i].flag);
              
                break;
            default:printf("没有该选项\n");
        }
    }
    return 0;
}

void allocate(int str,float leg){
    uflag=0;fflag=0;
    int k=0,i=0,j,p=0,q;
    float ressize;
    while(i<m){
        if(free_table[i].flag==1 && free_table[i].length>=leg)          
        {       
	   if(free_table[i+1].flag==1 && free_table[i+1].length>=leg &&free_table[i+1].length<free_table[i].length)
	{		
            fflag=1;
	    j=i+1;
            break;
        }
	else {
	   fflag=1;
	    j=i;
            break;
	}

    }
   i++;
}
    if(fflag==0)
    {
    	printf("空闲区不够，采用紧凑技术\n");
        float hh = 0,kk = 0;

        //计算所有空闲区的大小之和
        for(i= 0; i <10;i++)
		{
			if(free_table[i].flag==1)
			{
				hh=hh+free_table[i].length;
				q=i;
            }
		}

        //计算有几个执行的程序
        i=0;
        while(i<n)
		{
	        if(used_table[i].flag !=0)
	        {
	             p++;
	        }
        i++;
       }
        int x;
        //计算已分配区长度
        for(x =1;x <p;x++)
        {
            used_table[x].address=used_table[x-1].address+used_table[x-1].length;
        } 
        //修改已分配区 
        used_table[0].address=free_table[0].address;
	    for(i=1;i<p;i++)
        {
        	used_table[i].address =used_table[i-1].address+used_table[i-1].length;
        	if(used_table[i].flag==0)
        	{
        		used_table[i].length=used_table[i+1].length;
        	    used_table[i].flag=used_table[i+1].flag;
			}	
		}
        free_table[0].length = hh; //hh为所有空闲区的长度之和
        for(i=0;i<q-1;i++)
        {
			free_table[0].address = used_table[p-1].address+used_table[p-1].length-free_table[i].length;  //空闲区的起始地址
		}
	    free_table[0].flag = 1;
        for(i=1;i<n;i++)
        {
            free_table[i].address=0;
            free_table[i].flag=0;
            free_table[i].length=0;
        }
       
        //判断能否装入
        if(free_table[0].length < leg)
            printf("空间不够");
        else
        {
            free_table[0].length=free_table[0].length-leg;
            used_table[p].address=used_table[p-1].address+used_table[p-1].length;
            used_table[p].length=leg;
            used_table[p].flag=str;
            free_table[0].address=used_table[p].address+used_table[p].length;
        }
	}
    else {
        ressize=free_table[j].length-leg;
        for(k=0;k<n;k++){
            if(used_table[k].flag==0) {
                
                     used_table[k].address=free_table[j].address;
                     used_table[k].flag=str;
                     used_table[k].length=leg;
                     free_table[j].address=free_table[j].address+leg;
                     free_table[j].length=ressize;
                     break;
                
            }
        }
    }
}
void reclaim(int str){
    uflag=0;fflag=0;
    int k,i,j;
    for(k=0;k<n;k++){
        if(used_table[k].flag==str){
            uflag=1;break;
        }
    }
    if(uflag==0)
        printf("\n找不到该作业!\n");
    else{
        for(i=0;i<m;i++){
            uend_address=used_table[k].address+used_table[k].length;
            fend_address=free_table[i].address+free_table[i].length;
	    
            if(used_table[k].address==fend_address && free_table[i+1].address==uend_address){
		     fflag=1;
                     free_table[i].length=free_table[i].length+used_table[k].length+free_table[i+1].length;
                     free_table[i].flag=1;
		     free_table[i+1].address=0;
		     free_table[i+1].length=0;
		     free_table[i+1].flag=1;
                     used_table[k].flag=0;
                     used_table[k].length=0;
                     used_table[k].address=0;
		     printf("\n已回收!\n");
		   break;
                     
		   }
		
            if(used_table[k].address==fend_address){//上邻
                fflag=1;
                free_table[i].length=free_table[i].length+used_table[k].length;
                free_table[i].flag=1;
                used_table[k].flag=0;
                used_table[k].length=0;
                used_table[k].address=0;
                printf("\n已回收!\n");		
               break; 
            }
	   if(free_table[i].address==uend_address){//下邻
                     fflag=1;
                     free_table[i].address=used_table[k].address;
                     free_table[i].length=free_table[i].length+used_table[k].length;
                     free_table[i].flag=1;
                     used_table[k].flag=0;
                     used_table[k].length=0;
                     used_table[k].address=0;
                     printf("\n已回收!\n");
                     break;
                 }
	

         }
        if(fflag==0){
            i=0;
            for(i=0;i<m;i++){
                if(free_table[i].flag==0){
                     free_table[i].address=used_table[k].address;
                     free_table[i].length=used_table[k].length;
                     free_table[i].flag=1;
                     used_table[k].length=0;
                     used_table[k].flag=0;
                     used_table[k].address=0;
                     break;
                }
            }
            printf("\n已回收!\n");
        }
    }
}
