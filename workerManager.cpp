#include"workerManager.h"  //�����Լ�д��ͷ�ļ�����˫����



//�����ｫͷ�ļ�WorkerManger��Ĺ��캯��������������ȫ ��ʱ�ǿ�ʵ��
WorkerManager::WorkerManager() {
	//1.�ļ�������
	ifstream ifs;	//���ļ�������
	ifs.open(FILENAME, ios::in);	//�Զ��ķ�ʽ���ļ�
	if (!ifs.is_open()) {		//����ļ������� Ҳ�ʹ򲻿���
		//cout << "�ļ�������" << endl;
		//��ʼ������
		this->m_EmpNum = 0;
		this->m_EmpArray = nullptr;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}	

	//2.�ļ����� ����Ϊ��
	char ch;
	ifs >> ch;	//����һ���ַ�
	if (ifs.eof()) {	//���������  �����һ���ַ��Ͷ����� �ļ���Ϊ�գ���
		//�ļ�Ϊ��
		//cout << "�ļ�Ϊ��" << endl;
		//��ʼ������
		this->m_EmpNum = 0;
		this->m_EmpArray = nullptr;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//3.�ļ����ڣ����Ҽ�¼����
	int num = this->get_EmpNum();
	//cout << "ְ������Ϊ�� " << num << endl;
	this->m_EmpNum = num;

	this->m_EmpArray = new Worker * [this->m_EmpNum];	//���ٿռ�

	this->init_Emp();//���ļ��е����ݸ��µ�����ά����������

	// ���Դ��� �����Ƿ���µ�ά������������
	//for (int i = 0; i < this->m_EmpNum; ++i) {
	//	//cout << "ְ����ţ� " << this->m_EmpArray[i]->m_Id
	//	//	<< " ������ " << this->m_EmpArray[i]->m_name
	//	//	<< " ���ű�ţ� " << this->m_EmpArray[i]->m_DeptId << endl;
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
		if (dId == 1) {	//��ְͨ��
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2) {	//����
			worker = new Manager(id, name, dId);
		}
		else {	//�ϰ�
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close(); 
}

void WorkerManager::Show_Menu() {  //�˵�չʾ����ʵ��

	cout << "********************************************" << endl;
	cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
	cout << "*************  0.�˳��������  *************" << endl;
	cout << "*************  1.����ְ����Ϣ  *************" << endl;
	cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
	cout << "*************  3.ɾ����ְְ��  *************" << endl;
	cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
	cout << "*************  5.����ְ����Ϣ  *************" << endl;
	cout << "*************  6.���ձ������  *************" << endl;
	cout << "*************  7.��������ĵ�  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void WorkerManager::exitSystem() {	//�˳����ܾ���ʵ��
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0); //ֻҪ����������� ����ֱ���˳�
}

//���Լ�д������ְ�� ��֪��������� ���ʴ���

//void WorkerManager::Add_Emp() {		
//	cout << "���������ְ���������� " << endl;
//	int addNum = 0; //�����û���������
//	cin >> addNum;
//	if (addNum > 0) {
//		//���
//		int newSize = this->m_EmpNum + addNum; //������Ҫ�� �¿ռ������ = ԭ����¼���� + ��������  
//		Worker** newSpace = new Worker * [newSize]; //�����¿ռ�
//		if (this->m_EmpArray != nullptr) {		//����ԭ�������ݵ��¿ռ�
//			for (int i = 0; i < this->m_EmpNum; ++i) {
//				newSpace[i] = this->m_EmpArray[i];
//			}
//		}
//		//��������µ�����
//		for (int i = 0; i < addNum; ++i) {
//			int id;  //ְ�����
//			string name; //����
//			int dSelect; //����ѡ��
//
//			cout << "�������" << i + 1 << "����ְ���ı�ţ� " << endl;
//			cin >> id;
//			cout << "�������" << i + 1 << "����ְ���������� " << endl;
//			cin >> name;
//			cout << "��ѡ���ְ���ĸ�λ�� " << endl;
//			cout << "1����ͨԱ��" << endl;
//			cout << "2������" << endl;
//			cout << "3���ϰ�" << endl;
//			cin >> dSelect;
//
//			Worker* worker = nullptr;
//			switch (dSelect)
//			{
//			case1:
//				worker = new Employee(id, name, 1);	//	��workerManagerͷ�ļ�������� Emloyee��ͷ�ļ����� cpp�ļ�����Ҫ�ظ�����
//				break;
//			case2:
//				worker = new Manager(id, name, 2);	//	��workerManagerͷ�ļ�������� Manager��ͷ�ļ����� cpp�ļ�����Ҫ�ظ�����
//				break;
//			case3:
//				worker = new Boss(id, name, 3);	//	��workerManagerͷ�ļ�������� Boss��ͷ�ļ����� cpp�ļ�����Ҫ�ظ�����
//				break;
//			default:
//				break;
//			}
//			//��������ְ����Ϣ ���浽��������
//			newSpace[this->m_EmpNum + i] = worker;		//�����i�Ǵ�0��ʼ�� ���Բ���Ҫi-1  ����thisҪ�� ��Ȼ������������������ ��Ϊm_EempNum�����������ط��ᱻ�޸�
//		}
//		delete[] this->m_EmpArray; //�ͷ�ԭ�пռ�	��Ϊԭ�пռ���һ������ ������Ҫ��[]
//		this->m_EmpArray = newSpace;//�����¿ռ�ָ��
//		this->m_EmpNum = newSize;	//�����µ�ְ������
//
//		this->m_FileIsEmpty = false;
//
//		cout << "�ɹ����" << addNum << "����ְ��" << endl;
//
//		this->save();	//�������ݵ��ļ���
//	}
//	else {
//		cout << "��������" << endl;
//	}
//	//������������ص��ϼ�Ŀ¼
//	system("pause");	//�����������
//	system("cls");		//����
//	
//}

//����ְ��		������ʦ�ľ��ǶԵ� �����Ҹо�������ȫһ����
void WorkerManager::Add_Emp()
{
	cout << "����������ְ�������� " << endl;

	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		//�����¿ռ��С
		int newSize = this->m_EmpNum + addNum;

		//�����¿ռ�
		Worker** newSpace = new Worker * [newSize];

		//��ԭ�ռ������ݴ�ŵ��¿ռ���
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//����������
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;

			cout << "������� " << i + 1 << " ����ְ����ţ�" << endl;
			cin >> id;


			cout << "������� " << i + 1 << " ����ְ��������" << endl;
			cin >> name;


			cout << "��ѡ���ְ���ĸ�λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dSelect;


			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1: //��ͨԱ��
				worker = new Employee(id, name, 1);
				break;
			case 2: //����
				worker = new Manager(id, name, 2);
				break;
			case 3:  //�ϰ�
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}


			newSpace[this->m_EmpNum + i] = worker;
		}

		//�ͷ�ԭ�пռ�
		delete[] this->m_EmpArray;

		//�����¿ռ��ָ��
		this->m_EmpArray = newSpace;

		//�����µĸ���
		this->m_EmpNum = newSize;

		//��ʾ��Ϣ
		cout << "�ɹ����" << addNum << "����ְ����" << endl;
		this->save();
	}
	else
	{
		cout << "��������" << endl;
	}

	system("pause");
	system("cls");
}

void WorkerManager::save() {	//�����ļ�
	ofstream ofs; //�ļ��������Ҳ���Զ������ʽ���е� �����ļ����������ofs
	ofs.open(FILENAME, ios::out);	// ���ļ� open������ָ���ļ�·���� �򿪷�ʽ��in �Ƕ� out��д ��PCΪ������� ������ķ�ʽ���ļ�
	for (int i = 0; i < this->m_EmpNum; ++i) {
		ofs << m_EmpArray[i]->m_Id << " "
			<< m_EmpArray[i]->m_name << " "
			<< m_EmpArray[i]->m_DeptId << endl;	//��ÿһ���˵���Ϣд���ļ���
	}
	ofs.close();	//�ر��ļ�
}

int WorkerManager::get_EmpNum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in); //���ļ�
	int id;
	string name;
	int dId;
	
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId) {	//����һ�б�ʾ��һ����
		num++;
	}
	ifs.close();
	return num;	
}

void WorkerManager::Show_Emp() {
	//�ж��ļ��Ƿ�Ϊ��
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	else {
		for (int i = 0; i < this->m_EmpNum; ++i) {
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");	//�����������
	system("cls");
}

int WorkerManager::IsExit(int id) {		//�жϸ�id��ְ���Ƿ���� ������� ����id ��������� ���� -1
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
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	else {
		//����ְ�����ɾ��ְ��
		cout << "��������Ҫɾ����ְ�����" << endl;
		int id;
		cin >> id;
		int index = this->IsExit(id);
		if (index != -1) {	//˵��ְ�����ڣ�����Ҫɾ����index��ְԱ
			for (int i = index; i < this->m_EmpNum; ++i) {		//ɾ��ĳһλ�õ����� ˵������Ҫ�Ѻ��������ǰ��һλ
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];	//����Ǩ��
			}
			this->m_EmpNum--;	//���¼�¼��Ա��Ŀ

			//ͬ�����µ��ļ���
			this->save();
			cout << "ɾ���ɹ�" << endl;
		}
		else {
			cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ��" << endl;

		}
	}
	//�����������
	system("pause");
	system("cls");
}

void WorkerManager::Mod_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	else {
		cout << "��������Ҫ�޸ĵ�ְ���ı��" << endl;
		int id;
		cin >> id;
		int ret = this->IsExit(id);
		if (ret != -1) {
			//���ҵ��ñ�ŵ�ְ��
			delete this->m_EmpArray[ret];	//����ջ�� ����ֱ����� ��Ҫ���ÿ�
			int newId = 0;
			string newName = "";
			int dSelect = 0;
			
			cout << "�鵽��" << id << "��ְ���� ��������ְ���ţ� " << endl;
			cin >> newId;
			cout << "�������µ�����: " << endl;
			cin >> newName;

			cout << "��ѡ���ְ���ĸ�λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dSelect;


			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1: //��ͨԱ��
				worker = new Employee(newId,newName, 1);
				break;
			case 2: //����
				worker = new Manager(newId, newName, 2);
				break;
			case 3:  //�ϰ�
				worker = new Boss(newId, newName, 3);
				break;
			default:
				break;
			}
			//�������ݵ�������
			this->m_EmpArray[ret] = worker;
			cout << "�޸ĳɹ�" << endl;
			//���浽�ļ���
			this->save();

		}
		else {
			cout << "�޸�ʧ�ܣ����޴���" << endl;
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::Find_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	else {
		cout << "��������ҷ�ʽ�� " << endl;
		cout << "1������ְ����Ų���" << endl;
		cout << "2��������������" << endl;
		int select;
		cin >> select;
		if (select == 1) {
			cout << "������ְ�����" << endl;
			int id;
			cin >> id;
			int ret = this->IsExit(id);
			if (ret != -1) {			//����Ϊʲô������ (int ret = this->isexit(id) != -1)?  �� ���� =  �� ��= ͬ�� ����˳�����
				cout << "���ҳɹ�����Ϣ���£�" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else {
				cout << "����ʧ�ܣ� ���޴���" << endl;
			}
		}
		else if (select == 2) {
			cout << "������ְ������" << endl;
			bool flag = false; //���ҳɹ��ı�־
			string name;
			cin >> name;
			for (int i = 0; i < this->m_EmpNum; ++i) {
				if (this->m_EmpArray[i]->m_name == name) {
					cout << "���ҳɹ�����Ϣ���£�" << endl;
					this->m_EmpArray[i]->showInfo();
					flag = true;
				}
			}
			if (!flag) {
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else {
			cout << "����ѡ������" << endl;
		}

	}
	system("pause");
	system("cls");
}

void WorkerManager::Sort_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
		system("pause");
		system("cls");

	}
	else {		//�����õ���ѡ������
		cout << "��ѡ�����򷽷��� " << endl;
		cout << "1����ְ���Ž�������" << endl;
		cout << "2����ְ���Ž��н���" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < this->m_EmpNum; ++i) {
			int minOrMax = i;	//�ȼ�¼һ����С�������ֵ
			for (int j = i + 1; j < this->m_EmpNum; ++j) {
				if (select == 1) {	//����
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
			if (i != minOrMax) {	//�����һ�� ˵����Ҫ����������
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = temp;
			}
		}
	}
	cout << "����ɹ������Ϊ�� " << endl;
	this->save();
	this->Show_Emp();
}

void WorkerManager::Clean_File() {
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;

	int select = 0;
	cin >> select;
	if (select == 1) {
		ofstream ofs(FILENAME, ios::trunc);	// ��������ļ� ��ɾ���ļ����´���
		ofs.close();
		if (this->m_EmpArray != nullptr) {
			for (int i = 0; i < this->m_EmpNum; ++i) {
				if (this->m_EmpArray[i] != nullptr) {
					delete this->m_EmpArray[i];	//ɾ��ÿһ��ָ�� ����ע�� ��Ȼ���ڴ�й©
				}
			}
			this->m_EmpNum = 0;
			delete[] this->m_EmpArray;
			this->m_EmpArray = nullptr;
			this->m_FileIsEmpty = true;
		}
		cout << "��ճɹ�" << endl;
	}
	system("pause");
	system("cls");
}

WorkerManager::~WorkerManager() {	//���������� �ֶ����� �ֶ��ͷ�
	if (this->m_EmpArray != nullptr) {
		for (int i = 0; i < this->m_EmpNum; ++i) {
			if (this->m_EmpArray[i] != nullptr) {
				delete this->m_EmpArray[i];	//ɾ��ÿһ��ָ�� ����ע�� ��Ȼ���ڴ�й©
			}
		}
		delete[] this->m_EmpArray; //ɾ������Ҫ����[]
		this->m_EmpArray = nullptr;
	}
}