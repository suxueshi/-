#include<iostream>
#include"workerManager.h"
using namespace std;
#include"worker.h"
#include"manager.h"
#include"employee.h"
#include"boss.h"
int main() {

	//测试代码
	//Worker* worker = new Employee(1, "张三", 1);	//父类指针或引用指向子类对象  new是将对象创建在堆区 纯虚函数不能实例化对象 但可以创建一个指针或者引用指向它子类的对象
	//worker->showInfo();
	//delete worker;

	//Manager a(2, "李四", 2);	//Manager类不存在默认构造函数 需要调用重写的构造函数（初始化） 也就是说Manager a; 不行
	//Worker& b = a;				//父类引用指向子类对象
	//b.showInfo();				//多态： 当三个对象都调用showInfo的时候 显示的内容是不一样的 因为三个对象所属的类都重写了父类的纯虚函数

	//worker = new Boss(3, "王五", 3);	//父类指针或引用指向子类对象  new是将对象创建在堆区 纯虚函数不能实例化对象 但可以创建一个指针或者引用指向它子类的对象
	//worker->showInfo();
	//delete worker;



	WorkerManager wm; //实例化对象
	int choice = 0;	  //操作选择符
	while (true)	 //死循环
	{	
		wm.Show_Menu();	//调用展示菜单的成员函数
		cin >> choice;	//接受用户的选择
		switch (choice)
		{
		case 0: //退出系统
			wm.exitSystem();//调用退出系统的成员函数
			break;
		case 1: //添加职工
			wm.Add_Emp();
			break;
		case 2: //显示职工
			wm.Show_Emp();
			break;
		case 3: //删除职工
			wm.Del_Emp();
			break;
		case 4: //修改职工
			wm.Mod_Emp();
			break;
		case 5: //查找职工
			wm.Find_Emp();
			break;
		case 6: //排序职工
			wm.Sort_Emp();
			break;
		case 7: //清空文件
			wm.Clean_File();
			break;
		default:
			system("cls");//清屏
			break;
		}
	}


	system("pause");
	return 0;
}