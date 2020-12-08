#pragma once
#include<iostream>
#include<string>
using namespace std;

class Worker {		//抽象类

public:
	virtual void showInfo() = 0; //显示个人信息。 纯虚函数 不做任何实现 也无法实例化该类的对象 只在子类中实现
	virtual string getDeptName() = 0; //获取岗位信息

	int m_Id; //职工编号
	string m_name; //职工姓名
	int m_DeptId; //职工所在部门编号
};
