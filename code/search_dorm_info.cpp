#include "search_dorm_info.h"
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include "padding.h"

using namespace std;

bool compare_name(const string& x, const string& y);
void dormSearchIntroduce();
int search_room_by_name(const map<string, MaleStudent>& m_ss, const map<string, FemaleStudent>& f_ss);
int search_students_by_room(const Building & building);

//====================================================================================
// Function:    search_dorm_info_list
// Description: ����ѧ��������Ϣ�Ĳ�ѯ
// call:		
// Parameter:	const Building& building				һ��¥��ѧ��������Ϣ
//				const map<string, MaleStudent>& m_ss	��У������(male students)
//				const map<string, FemaleStudent>& f_ss	��У��Ů��(Quit female students)
// Return:      ����������������0
//====================================================================================
int search_dorm_info_list(const Building& building, const map<string, MaleStudent>& m_ss, 
					const map<string, FemaleStudent>& f_ss)
{
	
	dormSearchIntroduce();

	cout << Left_Padding;
	cout << "��ѡ��: ";
	int choose;
	while (cin>>choose)
	{
		
		if (choose < 0 || choose >2)
		{
			cout << Left_Padding;
			cout << "��ȷ������0-2������!" <<endl<< endl;
			cout << Left_Padding;
			cout << "��ѡ��: ";
			continue;
			
		}
		switch (choose)
		{
			case 1: search_room_by_name(m_ss,f_ss);
					break;
			case 2: search_students_by_room(building);
					break;
			case 0: system("cls");
					return 0;
					break;
		}
		cout <<endl<< Left_Padding;
		system("pause");
		system("cls");
		dormSearchIntroduce();
		cout << string(40, ' ');
		cout << "��ѡ��: " ;
	}

	return 0;
}


//====================================================================================
// Function:    dormSearchIntroduce()
// Description: ����ѧ��������Ϣ�Ĳ�ѯ��Ϣ�Ĺ���
// Parameter:	��
// Return:      ��
//====================================================================================
void dormSearchIntroduce()
{
	
	string head = "�� �� �� ��";
	string option_0 = "0. �˳�������";
	string option_1 = "1. ����������ѯѧ������";
	string option_2 = "2. ���ݷ���Ų�ѯ��ס��ȫ��ѧ��";
	string pad_left(3, ' ');
	string::size_type width = 45;
	cout << "\n\n" << endl;

	cout << string(45, ' ') << string(20, '*') << endl;
	cout << string(45, ' ') << "*" << string(3, ' ') << head << string(20 - 3 - head.size() - 2, ' ') << "*" << endl;
	cout << string(45, ' ') << string(20, '*') << endl;


	cout << string(33, ' ') << "+" << string(width, '=') << "+" << endl;
	cout << string(33, ' ') << "+" << pad_left << option_1 << string(width - pad_left.size() - option_1.size(), ' ') << "+" << endl;
	cout << string(33, ' ') << "+" << string(width, '=') << "+" << endl;

	cout << string(33, ' ') << "+" << pad_left << option_2 << string(width - pad_left.size() - option_2.size(), ' ') << "+" << endl;
	cout << string(33, ' ') << "+" << string(width, '=') << "+" << endl;

	cout << string(33, ' ') << "+" << pad_left << option_0 << string(width - pad_left.size() - option_0.size(), ' ') << "+" << endl;
	cout << string(33, ' ') << "+" << string(width, '=') << "+" << endl;

	cout << endl;
}

//====================================================================================
// Function:    search_room_by_name
// Description: ����ѧ�����ֲ�ѯ����ʾѧ�������
// Parameter:	��У��Ů����ӳ��� m_ss(male studets),��f_ss(female students)
// Return:      ��������������0
//====================================================================================
int search_room_by_name(const map<string, MaleStudent>& m_ss,const map<string, FemaleStudent>& f_ss)
{
	string name;
	string ifcontinue;
	cout << Left_Padding;
	cout << "������ѧ��������(�м䲻�ܺ��ո�):\n" << endl;

	cout << Left_Padding;
	std::cin >> name;
	if (m_ss.find(name) != m_ss.end())
		{
			map<string, MaleStudent>::const_iterator pos;
			MaleStudent record;
			pos = m_ss.find(name);
			record = pos->second;

			cout << Left_Padding;
			printf("%02d - %02d\n",record.floorID, record.roomID);         //���ʹǰ�����0������
		}
		else if (f_ss.find(name) != f_ss.end())
		{
			map<string, FemaleStudent>::const_iterator pos;
			FemaleStudent record;
			pos = f_ss.find(name);
			record = pos->second;

			cout << Left_Padding;
			printf("%02d - %02d\n", record.floorID, record.roomID);      //���ʹǰ�����0������
		}
		else
		{
			cout << Left_Padding;
			cout << "��Ǹ�������ڸ�ѧ��" << endl;
		}
	
	return 0;
}


//====================================================================
// function:    search_students_by_room
// Description: ���ݷ���Ų�ѯ��ס��ѧ��
// Parameter:	const Building & building һ������¥��ѧ��������Ϣ
// Return:      ��������������0
//=====================================================================
int search_students_by_room(const Building & building)
{
	cout << Left_Padding;
	cout << "�����뷿��š��ǌ�̖�� - ��ĳһ���еķ��g̖��: " ;

	
	char ch; //¥��źͷ����֮����ַ���ָ���� - �Ϳո�
	int f;  //¥��ţ�floor
	int r;  //����ţ�room

	std::cin >> f >> ch >> r;

	
	if (f <= building.floorsNum && f>0)
	{
		
		if (r <= building.floors[f - 1].roomsNum && r>0)
		{
			if (building.floors[f - 1].rooms[r - 1].lived_ss>0)
			{
				vector<string> students= building.floors[f - 1].rooms[r - 1].students;
				cout << Left_Padding;
				printf("%02d - %02d������ס��ѧ����:\n",f,r);
				sort(students.begin(),students.end(), compare_name);
				for (auto s :students)
					cout <<Left_Padding<<s << endl;
				cout << endl;
			}
			else
			{
					cout << Left_Padding;
					printf("%02d - %02d����û��ѧ����ס:\n\n", f, r);
			}
		}
		else
		{
				cout << Left_Padding;
				cout << "������ķ��������" << endl;
		}
	}
	else
	{
		cout << Left_Padding;
		cout << "�������¥�������" << endl;
	}
	
	return 0;
}

//====================================================================================
// Function:    cmpare_name
// Description: �����ַ����Ƚ�
// Parameter:	����const string���͵�����x,y
// Return:      x<y�Ĳ���ֵ
//====================================================================================
bool compare_name(const string& x, const string& y)
{
	return x < y;
}