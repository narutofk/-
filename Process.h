#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define getpch(type) (type*)malloc(sizeof(type)) 
#define nll 0 //����nll��ֵΪ0
struct pcb { /* ������̿��ƿ�PCB */ 
char name[10]; //���̵����� 
char state; //���̵�״̬
int super; //���̵����ȼ�
int atime; //���̵ĵ���ʱ��
int ntime; //������Ҫ����ʱ�� 
int rtime; //��������CPUʱ��
struct pcb* link; 
}*ready=nll,*p; 
typedef struct pcb PCB; 
char sort() /* �����Խ��̽������ȼ����к���*/ 
{ 
    PCB *first, *second; 
    int insert=0; 
    if((ready==nll)||((p->super)<(ready->super))||(((p->super)==(ready->super))&&((p->atime)<(ready->atime))))
 /*���ȼ������,�������*/ 
    { 
        p->link=ready; 
        ready=p; 
    } 
    else /* ���̱Ƚ����ȼ�,�����ʵ���λ����*/ 
    { 
    first=ready; 
    second=first->link; 
    while(second!=nll) 
    { 
        if((p->super)<(second->super)) /*��������̱ȵ�ǰ�������ȼ���,*/ 
        { /*���뵽��ǰ����ǰ��*/ 
            p->link=second; 
            first->link=p; 
            second=nll; 
            insert=1; 
        } 
        
        
	    else /* ����������ȼ����,����뵽��β*/ 
        { 
        first=first->link; 
        second=second->link; 
        } 

       } 
        if(insert==0) first->link=p; 
 }
} 
char input() /* �������̿��ƿ麯��*/ 
{ 
	int i,num; 
	printf ("\n �����뱻���ȵĽ�����Ŀ��"); //����\n��ʾ����
	scanf ("%d",&num); 
	for(i=1;i<=num;i++) 
	{ 
		printf ("\n ���̺�No.%d:\n",i); 
		p=getpch(PCB); 
		printf ("\n ���������:"); 
		scanf ("%s",p->name); 
		printf ("\n �������������:"); 
		scanf ("%d",&p->super); 
		printf ("\n ������̵���ʱ��:"); 
		scanf ("%d",&p->atime); 
		printf ("\n ���������Ҫ����ʱ��:"); 
		scanf ("%d",&p->ntime); 
		printf ("\n"); 
		p->rtime=0;
		p->state='w'; 
		p->link=nll; 
		sort(); /* ����sort����*/ 
	} 
} 
int space() 
{ 
	int l=0; PCB* pr=ready; 
	while(pr!=nll) 
	{ 
		l++; 
		pr=pr->link; 
	} 
	return(l); 
} 
char disp(PCB * pr) /*����������ʾ����,������ʾ��ǰ����*/ 
{ 
	printf ("\nqname  state  super  adtime  ndtime  runtime \n"); 
	printf ("%s\t",pr-> name); 
	printf ("%c\t",pr-> state); 
	printf ("%d\t",pr-> super); 
	printf ("%d\t",pr-> atime);
	printf ("%d\t",pr-> ntime);
	if(pr-> state=='R') 
		printf ("%d\t",pr-> rtime+1); 
	else
		printf ("%d\t",pr-> rtime);
	printf ("\n"); 
	}
char check() /* �������̲鿴���� */ 
{ 
	PCB* pr; 
	printf ("\n **** ��ǰ�������еĽ�����:%s",p->name);
 /*��ʾ��ǰ���н���*/ 
	disp(p); 
	pr=ready; 
	printf ("\n ****��ǰ��������״̬Ϊ:\n"); /*��ʾ��������״̬*/ 
	while(pr!=nll) 
	{ 
	disp(pr); 
	pr=pr->link; 
	} 
} 
char destroy() /*�������̳�������(�������н���,��������)*/ 
{ 
	printf ("\n ���� [%s] �����.\n",p->name); 
	free(p); 
} 
char running() /* �������̾�������(��������ʱ�䵽,�þ���״̬*/ 
{ 
	(p->rtime)++; 
	if(p->rtime==p->ntime) 
		destroy(); /* ����destroy����*/ 
	else 
	{ 
		(p->super)--; 
		p->state='w'; 
		sort(); /*����sort����*/ 
	} 
} 
int process() /*������*/ 
{ 
	int len,h=0; 
	char ch; 
	input(); 
	len=space(); 
	while((len!=0)&&(ready!=nll)) 
	{ 
		ch=getchar(); 
		h++; 
		printf ("\n The execute number:%d \n",h); 
		p=ready; 
		ready=p->link; 
		p->link=nll; 
		p->state='R'; 
		check();
		running(); 
		printf ("\n ����һ������......"); 
		ch=getchar(); 
	} 
	printf ("\n\n �����Ѿ����.\n"); 
	ch=getchar(); 
}
