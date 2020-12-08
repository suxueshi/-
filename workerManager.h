#pragma once	//��ֹͷ�ļ��ظ�����  
#include<iostream>
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<fstream>
#define FILENAME "empFile.txt"

using namespace std;

	
class WorkerManager		//WokerManager����  ͷ�ļ��е���һ��ֻ������ ��cpp�ļ��������ʵ��
{
public:
	WorkerManager();	//���캯������

	void Show_Menu();	//չʾ�˵�����

	void exitSystem();  // �˳���������

	int m_EmpNum;		//��¼ְ������

	Worker** m_EmpArray;//ְ������ָ��  ���ó������worker*���ָ��ָ��ͬ��Ĺ�Ա ��Ϊ�����ڲ���Worker*���͵����� ������Ҫһ��Worker** ���͵�ָ��ά����Worker*����

	void Add_Emp();		//���ְ��

	void save();		//�����ļ�

	bool m_FileIsEmpty;	//�ж��ļ��Ƿ�Ϊ��

	int get_EmpNum();	//ͳ������

	void init_Emp();   //��ʼ������	���ļ��е����ݸ��µ�ά����������

	void Show_Emp();	//��ʾְ��

	int IsExit(int id);		//�ж�ְ���Ƿ����

	void Del_Emp();   //ɾ��Ա��

	void Mod_Emp();		//�޸�ְ��

	void Find_Emp();   //����ְ��

	void Sort_Emp();	//����ְ��

	void Clean_File();	//����ļ�

	~WorkerManager();	//������������

};



