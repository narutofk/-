
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
class DevManagement
{
    public:
		void allocate(char jobname[30],char type[34]);
		void reclaim(char jobname[30],char type[34]);
        int init();

};


