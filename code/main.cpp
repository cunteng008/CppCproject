#include <iostream>
#include <fstream>
#include <map>
#include "config.h"
#include "analyze_orders.h"
#include "search.h"


using namespace std;

int main()
{
	//�Ƚ�����config���ݣ���ʼ����ȫ�ֱ�������!!!
	ReadConfig();

	Building building;
	map<string,MaleStudent> male_students;         //������ѧ����Ϣ��ӳ���
	map<string,FemaleStudent> female_students;

	map<string, MaleStudent> Qmale_students;         //��ѧ�˵�ѧ����������ѧ����Ϣ��ӳ���
	map<string, FemaleStudent> Qfemale_students;

	ifstream dispatch("dispatch.txt");
	if (!dispatch)
	{
		cout << "dispatch.txt������" << endl;
		exit(1);
	}
		
	read(dispatch,building, male_students, female_students);

	
	//ִ������
	executeOrders(building, male_students, female_students,Qmale_students, Qfemale_students);

	functionsList(building, male_students, female_students, Qmale_students, Qfemale_students);
	
	return 0;
}


