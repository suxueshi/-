#include"boss.h"

Boss::Boss(int id, string name, int dId) {	//���캯����дʵ��
	//������ʼ��
	this->m_Id = id;
	this->m_name = name;
	this->m_DeptId = dId;
}

void Boss::showInfo() {
	cout << "ְ����ţ� " << this->m_Id;
	cout << "\tְ�������� " << this->m_name;
	cout << " \t��λ�� " << this->getDeptName();
	cout << " \t��λְ�𣺷���ʩ��" << endl;
}

string Boss::getDeptName() {
	return string("�ϰ�");	//���ֻд"�ϰ�" ��const char* ���� ����������ʽת���� string ����
}