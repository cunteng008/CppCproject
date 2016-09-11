#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include "split.h"
#include "order_meaning.h"
#include "Student_and_dorm_Infor.h"

using namespace std;

//=====================================================================================================
// function:    ordersImplement
// Description: ʵ��ָ��
// parameter:   i�ǲ������λ�ã������������һ������ʱ�����������صĵ���Ҫ����
//				words һ��ָ�����еĵ���(��������ݵȲ����ո���ַ���)���磬ADD 5 FLOOR(s)  ��3����
//				Qm_ss	��ѧ�˵�����(Quit male students)
//              Qf_ss	��ѧ�˵�Ů��(Quit female students)
//				m_ss	��У������(male students)
//				f_ss	��У��Ů��(Quit female students)
//				buiding	����¥����Ϣ
//Called:		executeOrders
//Call:			orders_meaning.cpp�ļ����ADD(),EAT()�ȣ������뺯������
// Return:		�����������ý�������0
//=====================================================================================================
int ordersImplement(int& i,const vector<string>& words, Building& buiding, map<string, MaleStudent>& m_ss,
	map<string, FemaleStudent>& f_ss, map<string, MaleStudent>& Qm_ss, map<string, FemaleStudent>& Qf_ss)
{
	
	if (words[i] == "ADD")
	{
		ADD(i, words, buiding);
	}
	else if (words[i] == "EAT")
	{
		EAT(i, words, m_ss, f_ss);
	}
	else if (words[i] == "MAKEUP")
	{
		MAKEUP(i, words, f_ss);
	}
	else if (words[i] == "STUDY")
	{
		STUDY(i, words, m_ss, f_ss);
	}
	else if (words[i] == "EXERCISE")
	{
		EXERCISE(i, words, m_ss);
	}
	else if (words[i] == "MOVE")
	{
		MOVE(i, words, buiding, m_ss, f_ss);
	}
	else if (words[i] == "QUIT")
	{
		QUIT(i, words, buiding, m_ss, f_ss, Qm_ss, Qf_ss);
	}

	else if (words[i] == "ENTER")
	{
		ENTER(i, words, buiding, m_ss, f_ss, Qm_ss, Qf_ss);
	}
	else if (words[i] == "WORK")
	{
		WORK(i, words, m_ss, f_ss);
	}
	else if (words[i] == "WOO")
	{
		WOO(i, words, m_ss, f_ss);
	}
	else if (words[i] == "BREAK")
	{
		BREAK(i, words, m_ss, f_ss);
	}
	
	return 0;
}


//======================================================================================================
// function:    executeOrders
// Description: ����ѧ�����ֲ�ѯ����ʾѧ�������
// parameter:   i�ǲ������λ�ã������������һ������ʱ�����������صĵ���Ҫ����
//				words һ��ָ�����еĵ���(��������ݵȲ����ո���ַ���)���磬ADD 5 FLOOR(s)  ��3����
//				Qm_ss	��ѧ�˵�����(Quit male students)
//              Qf_ss	��ѧ�˵�Ů��(Quit female students)
//				m_ss	��У������(male students)
//				f_ss	��У��Ů��(Quit female students)
//				buiding	����¥����Ϣ
//Called:		mian.cpp���main()
//Calls:		ordersImplement()
//				split  ��split.cpp
// Return:		��
//======================================================================================================
void executeOrders(Building& building, map<string,MaleStudent>& m_ss, map<string, FemaleStudent>& f_ss,
	                map<string, MaleStudent>& Qm_ss, map<string, FemaleStudent>& Qf_ss)
{
	ifstream infile("instructions.txt");
	string instruction;
	vector<string> words;
	
	while (getline(infile, instruction))
	{
		words = split(instruction);                //�������ָ��ֽ�ɲ����пո���ַ��������ڽ���
		for (int i = 0; i < words.size(); i++)
		{
			if (words[i][0] >= 'A' && words[i][0] <= 'Z')   //��Ϊ���ָ��Ǵ�д��ĸ
			{
				//��ÿ��������ʵ�ֺ���֮��ص��ַ�����Ҫ��������ʱҪ�ı�i��ֵ
				//ÿ��������ʵ��ʱ��building, m_ss, f_ss,Qm_ss,Qf_ss��ֵ������Ҫ��
				ordersImplement(i, words, building, m_ss, f_ss,Qm_ss,Qf_ss); 
			}
		}
	}

}

