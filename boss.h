#pragma once
#include<iostream>
#include"worker.h"
using namespace std;

// �ϰ���
class Boss : public Worker {
public:
	// һ��Ҫ ��д ���캯���͸����еĴ��麯�� ����Ȼֻ�����н�������  ��cpp�ļ�����ʵ�� �������д�Ļ� ������Ҳ���ڳ�����
	Boss(int id, string name, int dId);
	virtual string getDeptName();		//virtul �ؼ��ֿ�ɾ�ɲ�ɾ
	virtual void showInfo();
};