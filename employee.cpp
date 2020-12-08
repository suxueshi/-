#include"employee.h"

Employee::Employee(int id, string name, int dId) {	//构造函数重写实现
	//参数初始化
	this->m_Id = id;	//每次指的是对象的成员变量或者函数 都建议加上this
	this->m_name = name;
	this->m_DeptId = dId;
}

void Employee::showInfo() {
	cout << "职工编号： " << this->m_Id;
	cout << "\t职工姓名： " << this->m_name;
	cout << " \t岗位： " << this->getDeptName();
	cout << " \t岗位职责：完成经理交给的任务" << endl;
}

string Employee::getDeptName() {
	return string("员工");	//如果只写"员工" 是const char* 类型 编译器会隐式转换成 string 类型
 }