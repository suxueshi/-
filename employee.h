#pragma once
#include<iostream>
#include"worker.h"
using namespace std;
	
//����Ա���� 
class Employee :public Worker {	//������ʽ�̳д�����Worker

public:
	// һ��Ҫ ��д ���캯���͸����еĴ��麯�� ����Ȼֻ�����н�������  ��cpp�ļ�����ʵ�� �������д�Ļ� ������Ҳ���ڳ�����
	Employee(int id, string name, int dId);
	virtual string getDeptName();		//virtul �ؼ��ֿ�ɾ�ɲ�ɾ
	virtual void showInfo();
};