#include "student_history_love.h"

#include <map>
#include <string>
#include <string>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include "love_history.h"
#include "Student_and_dorm_Infor.h"
#include "padding.h"

using namespace std;


typedef struct lover_info
{
	string name ;
	int wood_time ;
	double charm ;

} Lover_info;


bool lover_cmp_time(const Lover_info& x,const Lover_info& y);
bool lover_cmp_name(const Lover_info& x, const Lover_info& y);
bool lover_cmp_charm(const Lover_info& x, const Lover_info& y);

void loveHistorySearchIntroduce();

int search_love_history(map<string, MaleStudent> m_ss,map<string, FemaleStudent> f_ss,
	map<string, MaleStudent> Qm_ss,map<string, FemaleStudent> Qf_ss);

void show_lovers_list(vector<Lover_info> lovers);
void show_history_lovers(const vector<Lover_info>& lovers);
void show_HighestCharm_history_lover(const vector<Lover_info>& lovers);

int who_have_max_love_history(const map<string, MaleStudent>& m_ss,const map<string, FemaleStudent>& f_ss);

int who_have_highest_charm_lover(map<string, MaleStudent> m_ss, map<string, FemaleStudent> f_ss,
	map<string, MaleStudent> Qm_ss, map<string, FemaleStudent> Qf_ss);


/*****************************************************************************************************
Function: search_student_history_love_list
Description: ��ѧ������ʷ��ѯ�Ĺ���ѡ���б�
Calls: loveHistorySearchIntroduce() �Թ��ܵĽ���
	   search_love_history  ��ѯĳ����У��������ʷ
	   who_have_max_love_history ��ѯ˭��ӵ������ʷ���
	   who_have_highest_charm_lover ��ѯ˭
Called By: functionsList ��search.cpp�ļ���
Parameter : Qm_ss	��ѧ�˵�����ӳ���(Quit male students)
            Qf_ss	��ѧ�˵�Ů��ӳ���(Quit female students)
	        m_ss	��У������ӳ���(male students)
	        f_ss	��У��Ů��ӳ���(Quit female students)		
Return: ��
*******************************************************************************************************/
void search_student_history_love_list(const map<string, MaleStudent>& m_ss, const map<string, FemaleStudent>& f_ss,
	const map<string, MaleStudent>& Qm_ss, const map<string, FemaleStudent>& Qf_ss )
{
	loveHistorySearchIntroduce();

	
	int choose;
	cout << Left_Padding << "��ѡ��: ";
	while (cin >> choose)
	{
		if (choose < 0 || choose >2)
		{
			cout << Left_Padding << "��ȷ������0 - 2������!" << endl;
		}
		switch (choose)
		{
		case 1: search_love_history (m_ss,f_ss,Qm_ss,Qf_ss);
				break;
		case 2: who_have_max_love_history(m_ss, f_ss);
				break;
		case 0: return;
				break;
		}
		cout << Left_Padding;
		system("pause");
		system("cls");
		loveHistorySearchIntroduce();
		cout << Left_Padding << "��ѡ��: ";
	
	}
}


/*****************************************************************************************************
Function: search_student_history_love_list
Description: ѧ������ʷ��ѯ���ܽ���
Call: ��
Called By: search_student_history_love_list
Parameter : ��
Return: ��
*******************************************************************************************************/
void loveHistorySearchIntroduce()
{
	
	string head = "�� �� �� ��";
	string option_0 = "0. �˳�������";

	string option_1 = "1. �������ֲ�ѯһ��ѧ��������ʷ";
	string option_2 = "2. ��ѯ����ʷ����ѧ��";

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


/*****************************************************************************************************
Function: search_student_history_love_list
Description: ѧ������ʷ��ѯ���ܽ���
Call: ��
Called By: search_student_history_love_list
Parameter : 
Return: ��
*******************************************************************************************************/
int search_love_history(map<string, MaleStudent> m_ss, map<string, FemaleStudent> f_ss, map<string, MaleStudent> Qm_ss, map<string, FemaleStudent> Qf_ss)
{
	cout << Left_Padding << "������ѧ������(�м䲻�ܺ��ո�): ";
	string name;
	cin >> name;

	vector<Lover_info> lovers;  //���˵Ļ�����Ϣ
	Lover_info lover;           //������ʱ�����˵Ļ�����Ϣ
	Student record_0;
	//���Ҫ��ѯ��ѧ��Ϊ����
	if (m_ss.find(name) != m_ss.end())
	{
		record_0 = m_ss[name];
	 }
	else if (f_ss.find(name) != f_ss.end())
	{
		record_0 = f_ss[name];
	 }
	else if (Qm_ss.find(name) != Qm_ss.end())
	{
		record_0 = m_ss[name];
	 }
	else if (Qf_ss.find(name) != Qf_ss.end())
	{
		record_0 = f_ss[name];
	}

	//�����ѧ�����ڣ����ѯ��ѧ����������ʷ
	if (record_0.Name().size() != 0)
	{
		//����ʷ�����ݽṹΪ���ֺ�ʱ�䣬�����˵Ļ�����Ϣ�����ݽṹ����
		if (record_0.love_historys.size() == 0)
		{
			cout << endl << Left_Padding << "��ѧ��û������ʷ\n" << endl;
		}
		else
		{
			for (auto lov : record_0.love_historys)
			{
				if (m_ss.find(lov.name) != m_ss.end())
				{
					MaleStudent Mrecord_1;
					Mrecord_1 = m_ss[lov.name];
					lover.name = lov.name;
					lover.charm = Mrecord_1.Charm();
					lover.wood_time = Mrecord_1.wood_time;
					lovers.push_back(lover);
				}
				else if (f_ss.find(lov.name) != f_ss.end())
				{
					FemaleStudent Frecord_1;
					Frecord_1 = f_ss[lov.name];
					lover.name = lov.name;
					lover.charm = Frecord_1.Charm();
					lover.wood_time = Frecord_1.wood_time;
					lovers.push_back(lover);
				}
				else if (Qm_ss.find(lov.name) != m_ss.end())
				{
					MaleStudent Mrecord_1;
					Mrecord_1 = m_ss[lov.name];
					lover.name = lov.name;
					lover.charm = Mrecord_1.Charm();
					lover.wood_time = Mrecord_1.wood_time;
					lovers.push_back(lover);
				}
				else if (Qf_ss.find(lov.name) != f_ss.end())
				{
					FemaleStudent Frecord_1;
					Frecord_1 = f_ss[lov.name];
					lover.name = lov.name;
					lover.charm = Frecord_1.Charm();
					lover.wood_time = Frecord_1.wood_time;
					lovers.push_back(lover);
				}
			}
				show_lovers_list(lovers);
			}
		}
		else
		{
			cout << endl << Left_Padding << "��Ǹ����Ҫ��ѯ��ѧ��������\n" << endl;
		}

	return 0;
}


// Function: show_lovers_list
// Description : ��ʾ����ʷ
// Called By : search_love_history
// Parameter : �������˵Ļ�����Ϣ 
// Return : ��
void show_lovers_list(vector<Lover_info> lovers)
{
	cout << Left_Padding << "��ʾ����ʷ�ķ�ʽ:"<<endl ;
	cout << Left_Padding << string(3, ' ') << "1.�������ِ��P�S�ĕr�g�絽��˳����ʾ" << endl;
	cout <<Left_Padding  << string(3, ' ') << "2.��������������˳����ʾ" << endl;
	cout << Left_Padding << string(3, ' ') << "3.����������ֵ�ݼ�˳����ʾ" << endl;
	cout << Left_Padding << string(3, ' ') << "4.����ֵ��ߵ�������ʾ" << endl;
	cout << Left_Padding << string(3, ' ') << "0.������ʾ" << endl;
	int choose;
	cout << Left_Padding << "��ѡ��: ";
	cin >> choose;

	switch (choose)
	{
		case 1: sort(lovers.begin(),lovers.end(),lover_cmp_time);
				show_history_lovers(lovers);
				break;
		case 2: sort(lovers.begin(), lovers.end(), lover_cmp_name);
				show_history_lovers(lovers);
				break;
		case 3: sort(lovers.begin(), lovers.end(), lover_cmp_charm);
				show_history_lovers(lovers);
				break;
		case 4: sort(lovers.begin(), lovers.end(), lover_cmp_charm);
				show_HighestCharm_history_lover(lovers);
				break;
		default:break;
	}
	
}
void show_history_lovers(const vector<Lover_info>& lovers)
{
	for (auto lover : lovers)
	{
		cout << Left_Padding << string(3, ' ') << lover.name << endl;
	}
	cout << endl;
}

//���Ѷ�����ʷlovers�����˽��������ǰ����
void show_HighestCharm_history_lover(const vector<Lover_info>& lovers)
{
	cout << Left_Padding << "����ֵ��ߵ�������:\n" << endl;
	for (auto lover : lovers)
	{
		if (lover.charm == lovers[0].charm)
			cout << Left_Padding << string(3, ' ') << lover.name << string(10 - lover.name.size(), ' ') << lover.charm << endl;
		else
			break;
	}
	cout << endl;
}


// Function:  who_have_max_love_history
// Description : ��ʾӵ������ʷ����ѧ��
// Called By : search_student_history_love_list
// Parameter : ��Ů����map��������
// Return : ��
int who_have_max_love_history(const map<string, MaleStudent>& m_ss, const map<string, FemaleStudent>& f_ss)
{
	string::size_type max_love_historys=0;
	vector<string> name; //��¼ӵ������ʷ����ѧ��(�����ж��)

	for (auto s : m_ss)
	{
		if (s.second.love_historys.size() > max_love_historys)
		{
			
			max_love_historys = s.second.love_historys.size();
			name.resize(0);
			name.push_back(s.second.Name());
		}
		else if (s.second.love_historys.size() == max_love_historys)
		{
			
			name.push_back(s.second.Name());
		}
	}
	for (auto s : f_ss)
	{
		if (s.second.love_historys.size() > max_love_historys)
		{
			
			max_love_historys = s.second.love_historys.size();
			name.resize(0);
			name.push_back(s.second.Name());
		}
		else if (s.second.love_historys.size()== max_love_historys)
		{
			
			name.push_back(s.second.Name());
		}
	}

	cout << Left_Padding << "ӵ������ʷ��������:\n " <<endl;
	for (auto s : name)
	{
		cout << Left_Padding << string(3, ' ') << s << endl;
	}
	cout << endl;
	return 0;
}

int who_have_highest_charm_lover(map<string, MaleStudent> m_ss, map<string, FemaleStudent> f_ss, 
					map<string, MaleStudent> Qm_ss, map<string, FemaleStudent> Qf_ss)
{
	double highest_charm = 0; //��ʱ��¼����ֵ��ߵ�����
	vector<string> name; //��¼ӵ������ʷ����ѧ��(�����ж��)
	return 0;
}



bool lover_cmp_time(const Lover_info& x, const Lover_info& y)
{
	return x.wood_time < y.wood_time;
}
bool lover_cmp_name(const Lover_info& x, const Lover_info& y)
{
	return x.name < y.name;
}
bool lover_cmp_charm(const Lover_info& x, const Lover_info& y)
{
	return x.charm > y.charm;
}

