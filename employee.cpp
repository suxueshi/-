#include"employee.h"

Employee::Employee(int id, string name, int dId) {	//���캯����дʵ��
	//������ʼ��
	this->m_Id = id;	//ÿ��ָ���Ƕ���ĳ�Ա�������ߺ��� ���������this
	this->m_name = name;
	this->m_DeptId = dId;
}

void Employee::showInfo() {
	cout << "ְ����ţ� " << this->m_Id;
	cout << "\tְ�������� " << this->m_name;
	cout << " \t��λ�� " << this->getDeptName();
	cout << " \t��λְ����ɾ�����������" << endl;
}

string Employee::getDeptName() {
	return string("Ա��");	//���ֻд"Ա��" ��const char* ���� ����������ʽת���� string ����
 }