#include <iostream>
#include "MingOS.h"
#include "Process.h"
#include "Store.h"
#include "Dev.h"

#include<stdio.h>
#include<stdlib.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {


	while(1){
		cout <<"                                                                                                          " <<endl;
		cout <<"                                                                                                          " <<endl;
		cout <<"                                                                                                          " <<endl;
		cout <<"                                                                                                          " <<endl;
		cout <<"                                                                                                          " <<endl;
		cout <<"                                                                                                          " <<endl;
		cout <<"           |---------------------------------------------------------------------------------------------|" <<endl;
		cout <<"           |                                                                                             |" <<endl;
		cout <<"           |                                                                                             |" <<endl;
		cout <<"           |    ��ӭ������ϵͳ����ϵͳ֧���ļ��������̹����洢����,�豸�������ֹ���ģʽ����ѡ��    |" << endl;
		cout <<"           |                                     1�ļ�����                                               |" <<endl;
		cout <<"           |                                     2���̹���                                               |" <<endl;
		cout <<"           |                                     3�洢����                                               |" <<endl;
		cout <<"           |                                     4�豸����                                               |" <<endl;
		cout <<"           |                                                                                             |" <<endl;
		cout <<"           |---------------------------------------------------------------------------------------------|" <<endl;
		int in = 0 ;
		bool tag = true;
		while(tag){
			cin>>in;
			if(in>=1&&in<=4) tag = false;
			else cout<<"�����������������룡"<<endl;
		}
		switch(in){
		case 1: 
			file();
			break;
		case 2: 
			process();
			break;
		case 3:
			store();
			break;
		case 4:
		
			init();
			break;
	
		}
	}
    
	getchar();
	return 0;
}

