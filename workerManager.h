#pragma once	//防止头文件重复包含  
#include<iostream>
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<fstream>
#define FILENAME "empFile.txt"

using namespace std;

	
class WorkerManager		//WokerManager的类  头文件中的类一般只做声明 在cpp文件里面具体实现
{
public:
	WorkerManager();	//构造函数声明

	void Show_Menu();	//展示菜单声明

	void exitSystem();  // 退出功能声明

	int m_EmpNum;		//记录职工人数

	Worker** m_EmpArray;//职工数组指针  利用抽象类的worker*这个指针指向不同类的雇员 因为数组内部是Worker*类型的数据 所以需要一个Worker** 类型的指针维护该Worker*数组

	void Add_Emp();		//添加职工

	void save();		//保存文件

	bool m_FileIsEmpty;	//判断文件是否为空

	int get_EmpNum();	//统计人数

	void init_Emp();   //初始化函数	把文件中的数据更新到维护的数组中

	void Show_Emp();	//显示职工

	int IsExit(int id);		//判断职工是否存在

	void Del_Emp();   //删除员工

	void Mod_Emp();		//修改职工

	void Find_Emp();   //查找职工

	void Sort_Emp();	//排序职工

	void Clean_File();	//清空文件

	~WorkerManager();	//析构函数声明

};



