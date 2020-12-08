#include"boss.h"

Boss::Boss(int id, string name, int dId) {	//构造函数重写实现
	//参数初始化
	this->m_Id = id;
	this->m_name = name;
	this->m_DeptId = dId;
}

void Boss::showInfo() {
	cout << "职工编号： " << this->m_Id;
	cout << "\t职工姓名： " << this->m_name;
	cout << " \t岗位： " << this->getDeptName();
	cout << " \t岗位职责：发号施令" << endl;
}

string Boss::getDeptName() {
	return string("老板");	//如果只写"老板" 是const char* 类型 编译器会隐式转换成 string 类型
}