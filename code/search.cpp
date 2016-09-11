#include <iostream>
#include "search.h"
#include "search_attribute_list.h"
#include "student_history_love.h"
#include "search_dorm_info.h"


using namespace std;

void welcome()
{
	cout<< string(2,'\n') << endl;
	string welcome = "��ӭ����ѧ����Ϣ��ѯϵͳ !";
	cout << string(32, ' ') << string(50, '*') << endl;
	cout << string(32, ' ') << string(1, '*') << string(50 - 2, ' ') << string(1, '*') << endl;
	cout << string(32, ' ')<< "*" << string(11,' ') << welcome << string(50-11-welcome.size()-2,' ')<<"*" << endl;
	cout << string(32, ' ') << string(1, '*') << string(50 - 2, ' ') << string(1, '*') << endl;
	cout << string(32, ' ') << string(50, '*') << endl;
	
}

void welcomeAgain()
{
	cout << string(10,'\n') << endl;
	string welcome = "��ӭ�´�ʹ�ñ�ѧ����ѯϵͳ !";
	cout << string(32, ' ') << string(50, '*') << endl;
	cout << string(32, ' ') << string(1, '*') << string(50 - 2, ' ') << string(1, '*') << endl;
	cout << string(32, ' ') << "*" << string(11, ' ') << welcome << string(50 - 11 - welcome.size() - 2, ' ') << "*" << endl;
	cout << string(32, ' ') << string(1, '*') << string(50 - 2, ' ') << string(1, '*') << endl;
	cout << string(32, ' ') << string(50, '*') << endl;
	cout << string(15,'\n') << endl;
}
//====================================================================================
// Function:    introduce()
// Description: �׽��漰���ܽ���
// Parameter:	��
// Return:      ��
//====================================================================================
void introduce()
{
	string head="�� �� �� ��";
	string option_0 = "0. �� �� �� �� ϵ ͳ";
	
	string option_1 = "1. �� ѯ �� �� �� �� �� Ϣ";
	string option_2 = "2. �� ѯ ѧ �� �� �� ʷ";
	string option_3 = "3. �� ѯ ѧ �� �� �� �� ��";
	string pad_left(3,' ');
	string::size_type width=45;
	cout << "\n\n" << endl;

	cout << string(45, ' ') << string(20, '*') << endl;
	cout << string(45, ' ') << "*" << string(3, ' ') << head << string(20 - 3 - head.size() - 2, ' ') << "*" << endl;
	cout << string(45, ' ') << string(20, '*') << endl;


	cout << string(33, ' ') << "+" << string(width, '=') << "+" << endl;
	cout << string(33, ' ') << "+" << pad_left << option_1 <<string(width-pad_left.size()-option_1.size(),' ')<<"+"<<endl;
	cout << string(33, ' ') << "+" << string(width, '=') << "+" << endl;

	cout << string(33, ' ') << "+" << pad_left << option_2 << string(width - pad_left.size() - option_2.size(), ' ') << "+" << endl;
	cout << string(33, ' ') << "+" << string(width, '=') << "+" << endl;

	cout << string(33, ' ') << "+" << pad_left << option_3 << string(width - pad_left.size() - option_3.size(), ' ') << "+" << endl;
	cout << string(33, ' ') << "+" << string(width, '=') << "+" << endl;

	cout << string(33, ' ') << "+" << pad_left << option_0 << string(width - pad_left.size() - option_0.size(), ' ') << "+" << endl;
	cout << string(33, ' ') << "+" << string(width, '=') << "+" << endl;

	cout << endl;

}


//====================================================================================
// Function:    functionsList
// Description: ��ҳ�����б�
// Call:		search_dorm_info_list ��ѯѧ��������Ϣ�����б���
//				search_student_history_love_list ��ѯѧ������ʷ�����б���
//				search_student_attribute_list ��ѯѧ����������б�
//				
// Parameter:	building	һ��¥��
//				Qm_ss		��ѧ�˵�����ӳ���(Quit male students)
//              Qf_ss		��ѧ�˵�Ů��ӳ���(Quit female students)
//				m_ss		��У������ӳ���(male students)
//				f_ss		��У��Ů��ӳ���(Quit female students)		
// Return:      ��������������0
//====================================================================================
int functionsList(const Building& building,const map<string, MaleStudent>& m_ss,const map<string, FemaleStudent>& f_ss,
	const map<string, MaleStudent>& Qm_ss, const map<string, FemaleStudent>& Qf_ss)
{
	welcome();
	introduce();
	int choose;
	cout << string(40,' ');
	cout << "��ѡ��: " ;
	while (cin >> choose)
	{
		system("cls");
		if (choose < 0 || choose>3 )
		{
			cout << endl << endl;
			cout << string(40, ' ');
			cout <<"��ȷ������0-3����!" << endl;
			introduce();
			cout << string(40, ' ');
			cout << "��ѡ��: ";
			continue;
		}
		else
		{
			switch (choose)
			{
				case 1: search_dorm_info_list(building,m_ss,f_ss);
						break;
				case 2: search_student_history_love_list(m_ss,f_ss,Qm_ss,Qf_ss);
						break;
				case 3: search_attribute_list(m_ss, f_ss);
						break;
				default:system("cls");
					   welcomeAgain();
					   exit(0);
			}
		}
		system("cls");
		introduce();
		cout << string(40, ' ');
		cout << "��ѡ��: " ;
	}

	return 0;
}
