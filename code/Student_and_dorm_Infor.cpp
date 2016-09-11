#include <string>
#include <iostream>
#include <vector>
#include <cstdio> //�ַ���ת������������
#include <map>
#include "Student_and_dorm_Infor.h"
#include "split.h"
#include "config.h"

using namespace std;

int Student::wood_time = 0;   //�󰮵�ʱ���Ⱥ󣬱�������

//======================================================================================================
// function:    read
// Description: ����ѧ�����ֲ�ѯ����ʾѧ�������
// parameter:   m_ss	��У������(male students)
//				f_ss	��У��Ů��(Quit female students)
//				buiding	����¥����Ϣ
//Called:		mian.cpp���main()
//Calls:		split  ��split�ļ�
// Return:		��
//======================================================================================================							
void read(ifstream& infile, Building& building,map<string,MaleStudent>& m_ss, map<string,FemaleStudent>& f_ss)
{
	static int count = 0;
	string str;
	vector<string> strs;
	MaleStudent m_s; 
	FemaleStudent f_s;
	
	if (!infile)
	{
		cout << "infile�޷���" << endl;
		exit(1);
	}
	while (getline(infile, str))
	{
		if (str.size() == 0)     //Ī������
			break;
		strs = split(str);       //��ÿһ����Ϣ�ֽ�ɵ��ʱ��ڽ����͸�ֵ
		if (strs[1] == "��")
		{
			string name=strs[0];
			m_s.read(strs); //������Ϣ      
			m_ss[name]= m_s;
			building.floors[m_s.floorID-1].rooms[m_s.roomID-1].students.push_back(name);
			building.floors[m_s.floorID-1].rooms[m_s.roomID-1].lived_ss++;
			if (building.floors[m_s.floorID-1].rooms[m_s.roomID-1].lived_ss == 1)
				building.floors[m_s.floorID-1].rooms[m_s.roomID-1].gender = "��";
		}
		else
		{
			string name = strs[0];
			f_s.read(strs); //������Ϣ      
			f_ss[name] = f_s;
			building.floors[f_s.floorID-1].rooms[f_s.roomID-1].students.push_back(name);
			building.floors[f_s.floorID-1].rooms[f_s.roomID-1].lived_ss++;
			if (building.floors[f_s.floorID-1].rooms[f_s.roomID-1].lived_ss == 1)
				building.floors[f_s.floorID-1].rooms[f_s.roomID-1].gender = "Ů";
		}
	}
	
}


void Student::read(const std::vector<std::string>& strs )
{
	name = strs[0];
	if (strs[1] == "��")
		gender = "��";
	else
		gender = "Ů";

	char str[9];
	strcpy_s(str, strs[2].c_str());   
	floorID = atoi(str);   //�������ַ���ת������������
	strcpy_s(str, strs[4].c_str());
	roomID = atoi(str);
}

//===============================================
//����������캯���ֱ��ѧ�����������Ϣ�ĳ�ʼ��
//===============================================

MaleStudent::MaleStudent()
{
	extern map<string, int> config;

	health = MALE_HEALTH;
	money =MALE_MONEY;
	weight = MALE_WEIGHT;
	knowledge = MALE_KNOWLEDG;
	charm = MALE_CHARM;

}

FemaleStudent::FemaleStudent()
{
	extern map<string, int> config;
	
	looks = FEMALE_LOOKS;
	money = FEMALE_MONEY;
	weight = FEMALE_WEIGHT;
	knowledge = FEMALE_KNOWLEDGE;
	charm = FEMALE_CHARM;
}

//==================================================================================
//����ֵ���㣬ÿ����һ�Σ���һ��
//=================================================================================
double MaleStudent::Charm()
{
	charm = MALE_CHARM + (knowledge - MALE_KNOWLEDG) / 5 + (health - MALE_HEALTH) / 10 - (weight - MALE_WEIGHT) / 5;
	if (charm > 100)
		charm = 100;
	return charm;
}

double FemaleStudent::Charm()
{
	charm = FEMALE_CHARM +(knowledge- FEMALE_KNOWLEDGE) / 5 + (looks- FEMALE_LOOKS)/ 20 - (weight- FEMALE_WEIGHT)/ 4;
	if (charm > 100)
		charm = 100;
	return charm;
}


//===============================
//ѧ���ĸ�����Ϊ�����
//===============================
int Student::eat(int x)
{
	double cost = x * FOOD_COST;
	if (cost < money)
	{
		money -= (x * FOOD_COST);
		weight += (x * FOOD_INC_WEIGHT);
	}
	
	return 0;
}

int Student::study(int x)
{
	double new_weight = weight - x * STUDY_DEC_WEIGHT;
	if (new_weight > 0)
		weight = new_weight;

	knowledge += (x* STUDY_INC_KNOWLEDGE);
	if (knowledge > 100)
		knowledge = 100;
	
	return 0;
}

int Student::work(int x)
{
	double new_weight = weight - x * WORK_DEC_WEIGHT;
	if(new_weight > 0)
		weight = new_weight;

	money += (x * WORK_INC_MONEY);

	return 0;
}

int Student::wood(std::string n )
{
	wood_time++;
	LOVE_HISTORY record;
	record.time= wood_time;  //��������ʱ��
	record.name = n;
	love_historys.push_back(record);
	lover = n;
	return 0;
}

int Student::wooded(std::string n)
{
	LOVE_HISTORY record;
	record.time = wood_time;  //����������ʱ��
	record.name = n;
	love_historys.push_back(record);
	lover = n;
	return 0;
}

int Student::Break()
{
	love_status = false;
	lover = "none";
	return 0;
}

int MaleStudent::exercise(int x)
{
	double new_health = x* EXERCISE_INC_HEALTH + health;

	//����ֵ���ӵ�100����Ȼ�����˶���

	if (new_health <=  100)
	{
		health = new_health;
	}
	else if (health<100 && new_health > 100)
	{
		health = 100;
	}
		
	return 0;
}

int FemaleStudent::makeup(int x)
{
	double cost = x* MAKEUP_COST;
	double new_looks = x* MAKEUP_INC_LOOKS + looks;

	if (cost < money && new_looks <= 100)
	{
		money -= cost;
		looks = new_looks;
	}
	else if (cost < money && new_looks > 100)
	{
		money -= cost;
		looks = 100;
	}
	
	return 0;
}