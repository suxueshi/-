#include"manager.h"

Manager::Manager(int id, string name, int dId) {	//���캯����дʵ��
	//������ʼ��
	this->m_Id = id;
	this->m_name = name;
	this->m_DeptId = dId;
}

void Manager::showInfo() {
	cout << "ְ����ţ� " << this->m_Id;
	cout << "\tְ�������� " << this->m_name;
	cout << " \t��λ�� " << this->getDeptName();
	cout << " \t��λְ������ϰ彻�������񣬲��·������Ա��" << endl;
}

string Manager::getDeptName() {
	return string("����");	//���ֻд"����" ��const char* ���� ����������ʽת���� string ����
}