#pragma once
#include<iostream>
#include"worker.h"
using namespace std;

class Manager :public Worker {
public:			//һ��Ҫдpublic�ؼ��� û��Ĭ����private �ͷ��ʲ��˳�Ա������
	// ��д���캯���͸����еĴ��麯�� ����Ȼֻ�����н�������  ��cpp�ļ�����ʵ��
	Manager(int id, string name, int dId);
	virtual string getDeptName();		//virtul �ؼ��ֿ�ɾ�ɲ�ɾ
	virtual void showInfo();
};