#pragma once
#include<iostream>
#include<string>
using namespace std;

class Worker {		//������

public:
	virtual void showInfo() = 0; //��ʾ������Ϣ�� ���麯�� �����κ�ʵ�� Ҳ�޷�ʵ��������Ķ��� ֻ��������ʵ��
	virtual string getDeptName() = 0; //��ȡ��λ��Ϣ

	int m_Id; //ְ�����
	string m_name; //ְ������
	int m_DeptId; //ְ�����ڲ��ű��
};
