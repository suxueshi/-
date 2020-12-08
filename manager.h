#pragma once
#include<iostream>
#include"worker.h"
using namespace std;

class Manager :public Worker {
public:			//一定要写public关键字 没有默认是private 就访问不了成员函数了
	// 重写构造函数和父类中的纯虚函数 ，依然只在类中进行声明  在cpp文件进行实现
	Manager(int id, string name, int dId);
	virtual string getDeptName();		//virtul 关键字可删可不删
	virtual void showInfo();
};