#include"workerManager.h"  //包含自己写的头文件是用双引号



//在这里将头文件WorkerManger类的构造函数和析构函数补全 暂时是空实现
WorkerManager::WorkerManager() {
	//1.文件不存在
	ifstream ifs;	//读文件流对象
	ifs.open(FILENAME, ios::in);	//以读的方式打开文件
	if (!ifs.is_open()) {		//如果文件不存在 也就打不开了
		//cout << "文件不存在" << endl;
		//初始化属性
		this->m_EmpNum = 0;
		this->m_EmpArray = nullptr;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}	

	//2.文件存在 数据为空
	char ch;
	ifs >> ch;	//读入一个字符
	if (ifs.eof()) {	//如果读完了  如果读一个字符就读完了 文件就为空：）
		//文件为空
		//cout << "文件为空" << endl;
		//初始化属性
		this->m_EmpNum = 0;
		this->m_EmpArray = nullptr;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//3.文件存在，并且记录数据
	int num = this->get_EmpNum();
	//cout << "职工人数为： " << num << endl;
	this->m_EmpNum = num;

	this->m_EmpArray = new Worker * [this->m_EmpNum];	//开辟空间

	this->init_Emp();//将文件中的数据更新到我们维护的数组中

	// 测试代码 看看是否更新到维护的数组中了
	//for (int i = 0; i < this->m_EmpNum; ++i) {
	//	//cout << "职工编号： " << this->m_EmpArray[i]->m_Id
	//	//	<< " 姓名： " << this->m_EmpArray[i]->m_name
	//	//	<< " 部门编号： " << this->m_EmpArray[i]->m_DeptId << endl;
	//	this->m_EmpArray[i]->showInfo();
	//}
}

void WorkerManager::init_Emp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = nullptr;
		if (dId == 1) {	//普通职工
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2) {	//经理
			worker = new Manager(id, name, dId);
		}
		else {	//老板
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close(); 
}

void WorkerManager::Show_Menu() {  //菜单展示具体实现

	cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void WorkerManager::exitSystem() {	//退出功能具体实现
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0); //只要调用这个函数 程序直接退出
}

//我自己写的增加职工 不知道哪里错了 访问错误

//void WorkerManager::Add_Emp() {		
//	cout << "请输入添加职工的数量： " << endl;
//	int addNum = 0; //保存用户接受数量
//	cin >> addNum;
//	if (addNum > 0) {
//		//添加
//		int newSize = this->m_EmpNum + addNum; //计算需要的 新空间的人数 = 原来记录人数 + 新增人数  
//		Worker** newSpace = new Worker * [newSize]; //开辟新空间
//		if (this->m_EmpArray != nullptr) {		//拷贝原来的数据到新空间
//			for (int i = 0; i < this->m_EmpNum; ++i) {
//				newSpace[i] = this->m_EmpArray[i];
//			}
//		}
//		//批量添加新的数据
//		for (int i = 0; i < addNum; ++i) {
//			int id;  //职工编号
//			string name; //姓名
//			int dSelect; //部门选择
//
//			cout << "请输入第" << i + 1 << "个新职工的编号： " << endl;
//			cin >> id;
//			cout << "请输入第" << i + 1 << "个新职工的姓名： " << endl;
//			cin >> name;
//			cout << "请选择该职工的岗位： " << endl;
//			cout << "1、普通员工" << endl;
//			cout << "2、经理" << endl;
//			cout << "3、老板" << endl;
//			cin >> dSelect;
//
//			Worker* worker = nullptr;
//			switch (dSelect)
//			{
//			case1:
//				worker = new Employee(id, name, 1);	//	在workerManager头文件里面包含 Emloyee的头文件即可 cpp文件不需要重复包含
//				break;
//			case2:
//				worker = new Manager(id, name, 2);	//	在workerManager头文件里面包含 Manager的头文件即可 cpp文件不需要重复包含
//				break;
//			case3:
//				worker = new Boss(id, name, 3);	//	在workerManager头文件里面包含 Boss的头文件即可 cpp文件不需要重复包含
//				break;
//			default:
//				break;
//			}
//			//将创建的职工信息 保存到数组里面
//			newSpace[this->m_EmpNum + i] = worker;		//这里的i是从0开始的 所以不需要i-1  而且this要加 不然会产生缓冲区溢出警告 因为m_EempNum可能在其他地方会被修改
//		}
//		delete[] this->m_EmpArray; //释放原有空间	因为原有空间是一个数组 所以需要加[]
//		this->m_EmpArray = newSpace;//更改新空间指向
//		this->m_EmpNum = newSize;	//更新新的职工人数
//
//		this->m_FileIsEmpty = false;
//
//		cout << "成功添加" << addNum << "名新职工" << endl;
//
//		this->save();	//保存数据到文件中
//	}
//	else {
//		cout << "输入有误" << endl;
//	}
//	//按任意键清屏回到上级目录
//	system("pause");	//按任意键继续
//	system("cls");		//清屏
//	
//}

//增加职工		复制老师的就是对的 但是我感觉两者完全一样啊
void WorkerManager::Add_Emp()
{
	cout << "请输入增加职工数量： " << endl;

	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		//计算新空间大小
		int newSize = this->m_EmpNum + addNum;

		//开辟新空间
		Worker** newSpace = new Worker * [newSize];

		//将原空间下内容存放到新空间下
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//输入新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;

			cout << "请输入第 " << i + 1 << " 个新职工编号：" << endl;
			cin >> id;


			cout << "请输入第 " << i + 1 << " 个新职工姓名：" << endl;
			cin >> name;


			cout << "请选择该职工的岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;


			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1: //普通员工
				worker = new Employee(id, name, 1);
				break;
			case 2: //经理
				worker = new Manager(id, name, 2);
				break;
			case 3:  //老板
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}


			newSpace[this->m_EmpNum + i] = worker;
		}

		//释放原有空间
		delete[] this->m_EmpArray;

		//更改新空间的指向
		this->m_EmpArray = newSpace;

		//更新新的个数
		this->m_EmpNum = newSize;

		//提示信息
		cout << "成功添加" << addNum << "名新职工！" << endl;
		this->save();
	}
	else
	{
		cout << "输入有误" << endl;
	}

	system("pause");
	system("cls");
}

void WorkerManager::save() {	//保存文件
	ofstream ofs; //文件输入输出也是以对象的形式运行的 构建文件输出流对象ofs
	ofs.open(FILENAME, ios::out);	// 打开文件 open函数（指定文件路径， 打开方式）in 是读 out是写 以PC为主体理解 以输出的方式打开文件
	for (int i = 0; i < this->m_EmpNum; ++i) {
		ofs << m_EmpArray[i]->m_Id << " "
			<< m_EmpArray[i]->m_name << " "
			<< m_EmpArray[i]->m_DeptId << endl;	//把每一个人的信息写进文件中
	}
	ofs.close();	//关闭文件
}

int WorkerManager::get_EmpNum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in); //读文件
	int id;
	string name;
	int dId;
	
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId) {	//读入一行表示是一个人
		num++;
	}
	ifs.close();
	return num;	
}

void WorkerManager::Show_Emp() {
	//判断文件是否为空
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或者记录为空" << endl;
	}
	else {
		for (int i = 0; i < this->m_EmpNum; ++i) {
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");	//按任意键清屏
	system("cls");
}

int WorkerManager::IsExit(int id) {		//判断该id的职工是否存在 如果存在 返回id 如果不存在 返回 -1
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; ++i) {
		if (this->m_EmpArray[i]->m_Id == id) {
			index = i;
			break;
		}
	}
	return index;
}

void WorkerManager::Del_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或者记录为空" << endl;
	}
	else {
		//按照职工编号删除职工
		cout << "请输入想要删除的职工编号" << endl;
		int id;
		cin >> id;
		int index = this->IsExit(id);
		if (index != -1) {	//说明职工存在，并且要删除掉index上职员
			for (int i = index; i < this->m_EmpNum; ++i) {		//删除某一位置的数据 说明就是要把后面的数据前移一位
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];	//数据迁移
			}
			this->m_EmpNum--;	//更新记录人员数目

			//同步更新到文件中
			this->save();
			cout << "删除成功" << endl;
		}
		else {
			cout << "删除失败，未找到该职工" << endl;

		}
	}
	//按任意键清屏
	system("pause");
	system("cls");
}

void WorkerManager::Mod_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或者记录为空" << endl;
	}
	else {
		cout << "请输入需要修改的职工的编号" << endl;
		int id;
		cin >> id;
		int ret = this->IsExit(id);
		if (ret != -1) {
			//查找到该编号的职工
			delete this->m_EmpArray[ret];	//数据栈区 不能直接替代 需要先置空
			int newId = 0;
			string newName = "";
			int dSelect = 0;
			
			cout << "查到：" << id << "号职工， 请输入新职工号： " << endl;
			cin >> newId;
			cout << "请输入新的名字: " << endl;
			cin >> newName;

			cout << "请选择该职工的岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;


			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1: //普通员工
				worker = new Employee(newId,newName, 1);
				break;
			case 2: //经理
				worker = new Manager(newId, newName, 2);
				break;
			case 3:  //老板
				worker = new Boss(newId, newName, 3);
				break;
			default:
				break;
			}
			//更新数据到数组中
			this->m_EmpArray[ret] = worker;
			cout << "修改成功" << endl;
			//保存到文件中
			this->save();

		}
		else {
			cout << "修改失败，查无此人" << endl;
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::Find_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或者记录为空" << endl;
	}
	else {
		cout << "请输入查找方式： " << endl;
		cout << "1、按照职工编号查找" << endl;
		cout << "2、按照姓名查找" << endl;
		int select;
		cin >> select;
		if (select == 1) {
			cout << "请输入职工编号" << endl;
			int id;
			cin >> id;
			int ret = this->IsExit(id);
			if (ret != -1) {			//这里为什么不可以 (int ret = this->isexit(id) != -1)?  奥 懂了 =  和 ！= 同级 计算顺序的我
				cout << "查找成功，信息如下：" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else {
				cout << "查找失败， 查无此人" << endl;
			}
		}
		else if (select == 2) {
			cout << "请输入职工姓名" << endl;
			bool flag = false; //查找成功的标志
			string name;
			cin >> name;
			for (int i = 0; i < this->m_EmpNum; ++i) {
				if (this->m_EmpArray[i]->m_name == name) {
					cout << "查找成功，信息如下：" << endl;
					this->m_EmpArray[i]->showInfo();
					flag = true;
				}
			}
			if (!flag) {
				cout << "查找失败，查无此人" << endl;
			}
		}
		else {
			cout << "输入选项有误" << endl;
		}

	}
	system("pause");
	system("cls");
}

void WorkerManager::Sort_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或者记录为空" << endl;
		system("pause");
		system("cls");

	}
	else {		//这里用的是选择排序
		cout << "请选择排序方法： " << endl;
		cout << "1、按职工号进行升序" << endl;
		cout << "2、按职工号进行降序" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < this->m_EmpNum; ++i) {
			int minOrMax = i;	//先记录一个最小或者最大值
			for (int j = i + 1; j < this->m_EmpNum; ++j) {
				if (select == 1) {	//升序
					if (this->m_EmpArray[j]->m_Id < this->m_EmpArray[minOrMax]->m_Id) {
						minOrMax = j;
					}
				}
				else
				{
					if (this->m_EmpArray[j]->m_Id > this->m_EmpArray[minOrMax]->m_Id) {
						minOrMax = j;
					}
				}
			}
			if (i != minOrMax) {	//如果不一样 说明需要交换数据了
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = temp;
			}
		}
	}
	cout << "排序成功，结果为： " << endl;
	this->save();
	this->Show_Emp();
}

void WorkerManager::Clean_File() {
	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;

	int select = 0;
	cin >> select;
	if (select == 1) {
		ofstream ofs(FILENAME, ios::trunc);	// 如果存在文件 则删除文件重新创建
		ofs.close();
		if (this->m_EmpArray != nullptr) {
			for (int i = 0; i < this->m_EmpNum; ++i) {
				if (this->m_EmpArray[i] != nullptr) {
					delete this->m_EmpArray[i];	//删除每一个指针 必须注意 不然会内存泄漏
				}
			}
			this->m_EmpNum = 0;
			delete[] this->m_EmpArray;
			this->m_EmpArray = nullptr;
			this->m_FileIsEmpty = true;
		}
		cout << "清空成功" << endl;
	}
	system("pause");
	system("cls");
}

WorkerManager::~WorkerManager() {	//堆区的数据 手动开辟 手动释放
	if (this->m_EmpArray != nullptr) {
		for (int i = 0; i < this->m_EmpNum; ++i) {
			if (this->m_EmpArray[i] != nullptr) {
				delete this->m_EmpArray[i];	//删除每一个指针 必须注意 不然会内存泄漏
			}
		}
		delete[] this->m_EmpArray; //删除数组要加上[]
		this->m_EmpArray = nullptr;
	}
}