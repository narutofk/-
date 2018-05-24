#include<stdio.h>
#include<string.h>
#define n 2 /* �궨�壬�����޸��豸������Ŀ */
#define m 6 /* �궨�壬�����޸��豸��Ŀ */
typedef struct EquipT/* �ýṹ�����ڶ����豸������Ϣ */
{ 
	char type[10]; /* �豸������*/
	int count; /* ӵ�е��豸��̨�� */
	int remain; /* �ִ�Ŀ����豸̨�� */
	int address; /* �����豸���豸���е���ʼ��ַ */
};

typedef struct EquipM/* �ýṹ�����ڶ����豸�����Ϣ */
{
	int number; /* �豸���Ա�� */
	int status; /* �豸�û�״̬ */
	int remain; /* �豸�Ƿ��ѱ����� */
	char jobname[10]; /* ռ���豸����ҵ�� */
};

/********************** �� �� �� �� �� ҵ �� �� �� ��*****************************/

		void allocate(char jobname[30],char type[34]);
		void reclaim(char jobname[30],char type[34]);
        int init();


EquipT equiptype[n]={{"A",4,3,001},{"B",2,2,005}}; /* ϵ ͳ �� �� ����Ϊ n������2���豸*/
EquipM equipment[m]={{1,1,1,"job1"},{2,1,0,"0"},{3,1,0,"0"},{4,1,0,"0"},{5,1,1,"0"},{6,1,1,"0"}}; /* ϵͳ�豸��Ϊ m*/
void allocate(char jobname[30],char type[34])
{
	int i,t,t1;
	i=0;
	while(i<n&&strcmp(equiptype[i].type,type)!=0) /* ���������������豸���ͣ� strcmp �������ڱȽ� equiptype[i].type �� type �Ĵ�С��������򷵻� 0*/
		i++;
	if(i>=n) /* ��û���ҵ��������豸 */
	{		
		printf(" û���ҵ���������豸 ,����ʧ�� !");
		return;
	}
	if(equiptype[i].remain<1) /* �������豸�ִ����̨������ */
	{
		printf(" �����豸�������㣬����ʧ�� !");
		return;
	}
	t=equiptype[i].address;
	t1=equiptype[i].address; /* ȡ�������豸���豸���е���ʼ��ַ���� t*/
	while((t<t1+equiptype[i].count)&&!(equipment[t].status==1&&equipment[t].remain==0))
		t++;  /* ���豸������ʼ��ַ��һ */
		/*��д��ҵ����״̬��Ϊ�ѷ���*/
		if(t<t1+equiptype[i].count)
		{
			equiptype[i].remain--;  /* ʣ���豸����һ */
			equipment[t].remain=1;  /* ״̬��Ϊ�ѷ��� */
			strcpy(equipment[t].jobname,jobname); /*strcpy Ϊ �� �� �� �� ���������� J�е��ַ��������� equipment[t].jobname ��*/
		} 
		else
		{
			printf("is bad device,fail\n");
			return;
		}
		 
		/*equipment[t].lnumber=cc;  �豸��Ժ�д�� cc*/
}
/********************** �� �� �� �� �� ҵ �� �� �� ��*****************************/
void reclaim(char jobname[30],char type[34])
{
	int i,t,j,k,nn;
	i=0;
	while(i<n&&strcmp(equiptype[i].type,type)!=0) /* �� �� �� �� ��黹���豸���ͣ� strcmp �������ڱȽ� equiptype[i].type �� type �Ĵ�С��������򷵻� 0*/
		i++;
		if(i>=n)/* ��û���ҵ������豸 */
		{
			printf(" �޸����豸 ,�豸����ʧ�� !");
			return;
		}
		t=equiptype[i].address; /* ȡ�������豸���豸���е���ʼ��ַ���� t*/
		j=equiptype[i].count; /* ȡ�������豸���������� j*/
		k=0;
		nn=t+j;
		for(;t<nn;t++)
		{
			if(strcmp(equipment[t].jobname,jobname)==0&&equipment[t].remain==1)  /*��ռ��ĳ���豸����ҵ�������յ���ҵ��ͬ��״̬Ϊ�ѷ��� */
			{
				equipment[t].remain=0;
				strcpy(equipment[t].jobname,"0"); /*����״̬��Ϊδ���� */
				k++; /* �����豸���� */
			}
			equiptype[i].remain= equiptype[i].remain+k; /*�����豸ʣ���豸���� k*/
		}
		if(k==0) /* �������豸����ֵ k Ϊ 0,*/
		printf(" ����ҵû��ռ��������Դ !/n");
}
/********************** ������ *****************************/
int init()
{
	char jobname1[30];
	int i,t,a;
	char type1[20];
	i=0;
	t=0;
	printf(" δ����ǰ�豸���ࣺ \n ");
	printf("�豸��ӵ�и��豸̨���ִ�̨���豸���ַ\n");
	for(i=0;i<n;i++) /* �����豸����ʼ��Ϣ */
	{
		printf("%s\t\t%d\t\t%d\t\t%d\n",equiptype[i].type,equiptype[i].count,equiptype[i].remain,equiptype[i].address);
	}
	printf(" \nδ����ǰ�豸��:\n");
	printf(" ���Ժ�״̬ʹ�����ռ����ҵ��\n");
	for(i=0;i<m;i++)
	{
		printf("%d\t\t%d\t\t%d\t\t%s\n",equipment[i].number,equipment[i].status,equipment[i].remain,equipment[i].jobname);
	}
	while(1)
	{
		printf("\n0- �˳�,1-���� ,2-���� ,3-��ʾ "); /* �� �� ѡ �� ����*/
		scanf("%d",&a);
		switch(a)
		{		
			case 0 :
				return 0;
			case 1 :/*a=1 �����豸 */
				printf(" ��������ҵ�� \n");
				scanf("%s",jobname1);
				printf(" �������豸�������� \n");
				scanf("%s",type1);
				allocate(jobname1,type1); /*�����豸 */
				break;
			case 2 :/*a=2 �����豸 */
				printf(" ��������ҵ�� \n");
				scanf("%s",jobname1); /* ����Ҫ���յ���ҵ������Ӧ���豸�� */
				printf(" �������豸�������� \n");
				scanf("%s",type1); 
				reclaim(jobname1,type1); /* �����豸 */
				break;
			case 3 :/*a=3 ����豸�����豸������� */
				printf("\n ����豸��� !\n"); /* ����豸������� */
				printf(" �豸��ӵ�и��豸̨���ִ�̨���豸���ַ \n");
				for(i=0;i<n;i++)
				{
				printf("%s\t\t%d\t\t%d\t\t%d\n",equiptype[i].type,equiptype[i].count,equiptype[i].remain,equiptype[i].address);	
				} 
				printf("\n������豸��");
				printf("���Ժ�״̬ʹ�����ռ��ҵ��\n");
				for(i=0;i<m;i++)
				{
					printf("%d\t\t%d\t\t%d\t\t%s\n",equipment[i].number,equipment[i].status,equipment[i].remain,equipment[i].jobname);
				}
				break;
			default:
				printf("û�и�ѡ��\n"); 
		
		}//case
	}//while
	return 0;
}
