#include<iostream>
#include"workerManager.h"
using namespace std;
#include"worker.h"
#include"manager.h"
#include"employee.h"
#include"boss.h"
int main() {

	//���Դ���
	//Worker* worker = new Employee(1, "����", 1);	//����ָ�������ָ���������  new�ǽ����󴴽��ڶ��� ���麯������ʵ�������� �����Դ���һ��ָ���������ָ��������Ķ���
	//worker->showInfo();
	//delete worker;

	//Manager a(2, "����", 2);	//Manager�಻����Ĭ�Ϲ��캯�� ��Ҫ������д�Ĺ��캯������ʼ���� Ҳ����˵Manager a; ����
	//Worker& b = a;				//��������ָ���������
	//b.showInfo();				//��̬�� ���������󶼵���showInfo��ʱ�� ��ʾ�������ǲ�һ���� ��Ϊ���������������඼��д�˸���Ĵ��麯��

	//worker = new Boss(3, "����", 3);	//����ָ�������ָ���������  new�ǽ����󴴽��ڶ��� ���麯������ʵ�������� �����Դ���һ��ָ���������ָ��������Ķ���
	//worker->showInfo();
	//delete worker;



	WorkerManager wm; //ʵ��������
	int choice = 0;	  //����ѡ���
	while (true)	 //��ѭ��
	{	
		wm.Show_Menu();	//����չʾ�˵��ĳ�Ա����
		cin >> choice;	//�����û���ѡ��
		switch (choice)
		{
		case 0: //�˳�ϵͳ
			wm.exitSystem();//�����˳�ϵͳ�ĳ�Ա����
			break;
		case 1: //���ְ��
			wm.Add_Emp();
			break;
		case 2: //��ʾְ��
			wm.Show_Emp();
			break;
		case 3: //ɾ��ְ��
			wm.Del_Emp();
			break;
		case 4: //�޸�ְ��
			wm.Mod_Emp();
			break;
		case 5: //����ְ��
			wm.Find_Emp();
			break;
		case 6: //����ְ��
			wm.Sort_Emp();
			break;
		case 7: //����ļ�
			wm.Clean_File();
			break;
		default:
			system("cls");//����
			break;
		}
	}


	system("pause");
	return 0;
}