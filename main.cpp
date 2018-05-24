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
		cout <<"           |    欢迎来到本系统，泵系统支持文件管理，进程管理，存储管理,设备管理三种管理模式，请选择：    |" << endl;
		cout <<"           |                                     1文件管理                                               |" <<endl;
		cout <<"           |                                     2进程管理                                               |" <<endl;
		cout <<"           |                                     3存储管理                                               |" <<endl;
		cout <<"           |                                     4设备管理                                               |" <<endl;
		cout <<"           |                                                                                             |" <<endl;
		cout <<"           |---------------------------------------------------------------------------------------------|" <<endl;
		int in = 0 ;
		bool tag = true;
		while(tag){
			cin>>in;
			if(in>=1&&in<=4) tag = false;
			else cout<<"输入有误，请重新输入！"<<endl;
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

