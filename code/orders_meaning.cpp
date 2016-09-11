/*=============================================================

Copyright: Call_Me_Why

Author: ������

Date:2016-5-26

Description: ����������(QUIT��STUDY ��)

==============================================================*/

#include <string>
#include <vector>
#include <iostream>
#include <cstdio> //�ַ���ת������������
#include <map>
#include <algorithm>
#include <iterator>
#include <math.h>
#include <string>
#include "Student_and_dorm_Infor.h"
#include "config.h"

using namespace std;


//===========================================================================================
// function:   ADD
// Description: ʵ�ַ��䡢¥�㡢��λ������
// parameter:   i�ǲ������λ�ã������������һ������ʱ�����������صĵ���Ҫ����
//				words һ��ָ�����еĵ���(��������ݵȲ����ո���ַ���)��
//						�磬ADD 5 FLOOR(s)ָ����ADD,5,3FLOOR(s)����
//Called:		ordersImplement ��analyze_orders.cpp�ļ�
//Call:			��
// Return:		�����������ý�������0
//===========================================================================================
int ADD(int&i,const vector<string>& words, Building& building)
{
	
	if (words[i + 2] == "FLOOR(s)")
	{
		char str[9];  //��ʱ���������ڽ������ַ�ת������
		strcpy_s(str, words[i+1].c_str());
		int add_floors = atoi(str);  //�������ַ���ת��������

		building.floorsNum += add_floors;
		building.floors.resize( building.floorsNum );  //����¥�㣬�õ��µ�¥��

		i += 2;  //��ADD...FLOOR(s)��ص�����ѱ�ִ��
	}
	else if (words[i + 2] == "ROOM(s)")
	{
		char str[9];  
		strcpy_s(str, words[i + 1].c_str());
		int add_rooms = atoi(str); //�����ķ�����Ŀ

		strcpy_s(str, words[i + 4].c_str());
		int floor_id = atoi(str);  //����������Ŀ��¥��

		building.floors[floor_id-1].roomsNum += add_rooms; 
		//����floor_id��ķ���
		building.floors[floor_id - 1].rooms.resize(building.floors[floor_id - 1].roomsNum);
		

		i += 5; //��ADD ... ROOM(s) ��ص�����ѱ�ִ��  
	}
	else if (words[i + 2] == "BED(s)")
	{
		char str[9];
		strcpy_s(str, words[i + 1].c_str());
		int add_beds = atoi(str); //�����Ĵ���Ŀ

		//Ҫ���Ӵ�λ�ľ��巿��λ��
		strcpy_s(str, words[i + 4].c_str());
		int floor_id = atoi(str);  
		strcpy_s(str, words[i + 6].c_str());
		int room_id = atoi(str);  
		building.floors[floor_id - 1].rooms[room_id - 1].capacity += add_beds;

		i += 6; //ADD ... BED(s) ��ص�����ѱ�ִ�� 
	}
	
	return 0;
}

//===========================================================================================
// function:   EAT
// Description: ʵ�ֳԵĻ
// parameter:   i�ǲ������λ�ã������������һ������ʱ�����������صĵ���Ҫ����
//				words һ��ָ�����еĵ���(��������ݵȲ����ո���ַ���)��
//						�磬ADD 5 FLOOR(s)ָ����ADD,5,3FLOOR(s)����
//				m_ss	��У������(male students)
//				f_ss	��У��Ů��(Quit female students)
//Called:		ordersImplement ��analyze_orders.cpp�ļ�
//Call:			��
// Return:		�����������ý�������0
//===========================================================================================
int EAT(int&i,const vector<string>& words, map<string, MaleStudent>& m_ss, map<string, FemaleStudent>& f_ss)
{
	
	char str[9];  //��ʱ���������ڽ������ַ�ת������
	strcpy_s(str, words[i + 1].c_str());
	int consume_food = atoi(str);  //�������ַ���ת��������
	const string  name = words[0];

	//��ѧ�����ڲ�ִ��
	if ( m_ss.find(name) != m_ss.end() )
	{
		m_ss[name].eat(consume_food);
	}
	else if(f_ss.find(name)!=f_ss.end())
	{
		f_ss[name].eat(consume_food);
	}
	
	i += 1;  //EAT�������ѱ�ִ��
	
	return 0;
}
 
//===========================================================================================
// function:   EAT
// Description: ʵ�ֳԵĻ
// parameter:   i�ǲ������λ�ã������������һ������ʱ�����������صĵ���Ҫ����
//				words һ��ָ�����еĵ���(��������ݵȲ����ո���ַ���)��
//						�磬ADD 5 FLOOR(s)ָ����ADD,5,3FLOOR(s)����
//				m_ss	��У������(male students)
//				f_ss	��У��Ů��(Quit female students)
//Called:		ordersImplement ��analyze_orders.cpp�ļ�
//Call:			��
// Return:		�����������ý�������0
//===========================================================================================
int MAKEUP(int&i, const vector<string>& words, map<string, FemaleStudent>& f_ss)
{
	
	char str[9];  //��ʱ���������ڽ������ַ�ת������
	strcpy_s(str, words[i + 1].c_str());
	int makeup_time = atoi(str);  //�������ַ���ת��������
	const string  name = words[0];
	
	//������Ů����������ִ��
	if (f_ss.find(name) != f_ss.end())
	{
		f_ss[name].makeup(makeup_time);
	}
	
	i += 1;  //MAKEUP��������ִ��
	
	return 0;
	
}

//===========================================================================================
// function:   STUDY
// Description: ʵ��ѧϰ�Ļ
// parameter:   i�ǲ������λ�ã������������һ������ʱ�����������صĵ���Ҫ����
//				words һ��ָ�����еĵ���(��������ݵȲ����ո���ַ���)��
//						�磬ADD 5 FLOOR(s)ָ����ADD,5,3FLOOR(s)����
//				m_ss	��У������(male students)
//				f_ss	��У��Ů��(Quit female students)
//Called:		ordersImplement ��analyze_orders.cpp�ļ�
//Call:			��
// Return:		�����������ý�������0
//===========================================================================================
int STUDY(int& i, const vector<string>& words, map<string, MaleStudent>& m_ss, map<string, FemaleStudent>& f_ss)
{
	
	char str[9];  //��ʱ���������ڽ������ַ�ת������
	strcpy_s(str, words[i + 1].c_str());
	int study_time = atoi(str);  //�������ַ���ת��������
	const string  name = words[0];
	
	//��ѧ�����ڲ�ִ��
	if (m_ss.find(name) != m_ss.end())
	{
		m_ss[name].study(study_time);
	}
	else if (f_ss.find(name) != f_ss.end())
	{
		f_ss[name].study(study_time);
	}
	
	i += 1;  //STUDY��������ִ��
	
	return 0;
	
}

//===========================================================================================
// function:  EXERCISE
// Description: ʵ���˶��Ļ
// parameter:   i�ǲ������λ�ã������������һ������ʱ�����������صĵ���Ҫ����
//				words һ��ָ�����еĵ���(��������ݵȲ����ո���ַ���)��
//						�磬ADD 5 FLOOR(s)ָ����ADD,5,3FLOOR(s)����
//				m_ss	��У������(male students)
//				f_ss	��У��Ů��(Quit female students)
//Called:		ordersImplement ��analyze_orders.cpp�ļ�
//Call:			��
// Return:		�����������ý�������0
//===========================================================================================
int EXERCISE(int&i, const vector<string>& words, map<string, MaleStudent>& m_ss)
{
	
	char str[9];  //��ʱ���������ڽ������ַ�ת������
	strcpy_s(str, words[i + 1].c_str());
	int exercise_time = atoi(str);  //�������ַ���ת��������
	string name = words[0];
	
	//������������������ִ��
	if (m_ss.find(name) != m_ss.end())
	{
		m_ss[name].exercise(exercise_time);
	}
	
	i += 1;  //EXERCISE
	
	return 0;
	
}

//===========================================================================================
// function:   MOVE
// Description: ʵ�ְ�Ǩ�Ļ
// parameter:   i�ǲ������λ�ã������������һ������ʱ�����������صĵ���Ҫ����
//				words һ��ָ�����еĵ���(��������ݵȲ����ո���ַ���)��
//						�磬ADD 5 FLOOR(s)ָ����ADD,5,3FLOOR(s)����
//				һ�������ѧ����Ϣ
//				m_ss	��У������(male students)
//				f_ss	��У��Ů��(Quit female students)
//				buiding	����¥����Ϣ
//Called:		ordersImplement ��analyze_orders.cpp�ļ�
//Call:			��
// Return:		�����������ý�������0
//===========================================================================================
int MOVE(int&i, const vector<string>& words, Building& building,
	map<string, MaleStudent>& m_ss , map<string, FemaleStudent>& f_ss)
{
	
	
	string const name = words[0];
	
	char str[9];  //��ʱ���������ڽ������ַ�ת������
	strcpy_s(str, words[i + 2].c_str());   //��֮ǰ��(previous)����
	int pre_f = atoi(str);  //�������ַ���ת��������
	strcpy_s(str, words[i + 4].c_str());
	int pre_r = atoi(str);

	strcpy_s(str, words[i + 6].c_str());   //��֮�����ڵ�(current)����
	int cur_f = atoi(str);
	strcpy_s(str, words[i + 8].c_str());
	int cur_r = atoi(str);
	
	//���������᲻����
	if (cur_f > building.floorsNum || cur_f <= 0 || cur_r > building.floors[cur_r - 1].roomsNum || cur_r <= 0)
	{
		i += 8;
		return 1;
	}

	else if (m_ss.find(name) != m_ss.end())
	{

		//��Ůͬס����
		if (building.floors[cur_f - 1].rooms[cur_r - 1].gender == "Ů")
		{
			i += 8;
			return 1;
		}

		//�����Ƿ���ס����
		else if (building.floors[cur_f - 1].rooms[cur_r - 1].lived_ss
			== building.floors[cur_f - 1].rooms[cur_r - 1].capacity)
		{
			i += 8;
			return 1;
		}

		else if (building.floors[cur_f - 1].rooms[cur_r - 1].lived_ss == 0 ||
			building.floors[cur_f - 1].rooms[cur_r - 1].gender == "��")
		{

			//���,Ҫ���������������Ƿ���ƥ��
			vector<string>::iterator pos = find(building.floors[pre_f - 1].rooms[pre_r - 1].students.begin(),
				building.floors[pre_f - 1].rooms[pre_r - 1].students.end(), name);

			//����Ƿ���������
			if (pos != building.floors[pre_f - 1].rooms[pre_r - 1].students.end())
			{
				building.floors[pre_f - 1].rooms[pre_r - 1].students.erase(pos);
			}
			else
			{
				i += 8;
				return 1;
			}

			building.floors[pre_f - 1].rooms[pre_r - 1].lived_ss--;
			//��������û�ˣ�Ҫ���Ա�ȥ��
			if (building.floors[pre_f - 1].rooms[pre_r - 1].lived_ss == 0)
				building.floors[pre_f - 1].rooms[pre_r - 1].gender == "none";

			building.floors[cur_f - 1].rooms[cur_r - 1].students.push_back(name);
			building.floors[cur_f - 1].rooms[cur_r - 1].lived_ss++;
			//���ȥ�󣬱�Ϊ��������
			if (building.floors[cur_f - 1].rooms[cur_r - 1].lived_ss == 1)
				building.floors[cur_f - 1].rooms[cur_r - 1].gender = "��";

			//�޸�����ӳ���
			m_ss[name].floorID = cur_f;
			m_ss[name].roomID = cur_r;


		}


	}

	else if (f_ss.find(name) != f_ss.end())
	{

		if (building.floors[cur_f - 1].rooms[cur_r - 1].gender == "��")
		{
			i += 8;
			return 1;
		}
		else if (building.floors[cur_f - 1].rooms[cur_r - 1].lived_ss
			== building.floors[cur_f - 1].rooms[cur_r - 1].capacity)
		{
			i += 8;
			return 1;
		}
		else if (building.floors[cur_f - 1].rooms[cur_r - 1].lived_ss == 0 ||
			building.floors[cur_f - 1].rooms[cur_r - 1].gender == "Ů")
		{
			//���,Ҫ���������������Ƿ���ƥ��
			vector<string>::iterator pos = find(building.floors[pre_f - 1].rooms[pre_r - 1].students.begin(),
				building.floors[pre_f - 1].rooms[pre_r - 1].students.end(), name);
			if (pos != building.floors[pre_f - 1].rooms[pre_r - 1].students.end())
				building.floors[pre_f - 1].rooms[pre_r - 1].students.erase(pos);
			else
			{
				i += 8;
				return 1;
			}
			building.floors[pre_f - 1].rooms[pre_r - 1].lived_ss--;
			if (building.floors[pre_f - 1].rooms[pre_r - 1].lived_ss == 0)
				building.floors[pre_f - 1].rooms[pre_r - 1].gender = "none";

			//����
			building.floors[cur_f - 1].rooms[cur_r - 1].students.push_back(name);
			building.floors[cur_f - 1].rooms[cur_r - 1].lived_ss++;
			//֮ǰ����û�ˣ����ȥ��ΪŮ������
			if (building.floors[cur_f - 1].rooms[cur_r - 1].lived_ss == 1)
				building.floors[cur_f - 1].rooms[cur_r - 1].gender = "Ů";

			//�޸�Ů��ӳ���
			f_ss[name].floorID = cur_f;
			f_ss[name].roomID = cur_r;
		}

	}

	i += 8;  //MOVE�������ѱ�ִ��
	
	return 0;
	
}

//===========================================================================================
// function:   QUIT
// Description: ʵ����ѧ�Ļ
// parameter:   i�ǲ������λ�ã������������һ������ʱ�����������صĵ���Ҫ����
//				words һ��ָ�����еĵ���(��������ݵȲ����ո���ַ���)��
//						�磬ADD 5 FLOOR(s)ָ����ADD,5,3FLOOR(s)����
//				m_ss	��У������(male students)
//				f_ss	��У��Ů��(Quit female students)
//				Qm_ss	��ѧ�˵�����(Quit male students)
//              Qf_ss	��ѧ�˵�Ů��(Quit female students)
//				buiding	����¥����Ϣ			
//Called:		ordersImplement ��analyze_orders.cpp�ļ�
//Call:			��
// Return:		�����������ý�������0
//===========================================================================================
int QUIT( int&i, const vector<string>& words, Building& building,
	map<string, MaleStudent>& m_ss, map<string, FemaleStudent>& f_ss,
	map<string, MaleStudent>& Qm_ss, map<string, FemaleStudent>& Qf_ss)
{
	
	string name = words[0];
	
	if (m_ss.find(name) != m_ss.end())
	{
		MaleStudent record = m_ss[name];
		int r = record.roomID;
		int f = record.floorID;
		Qm_ss[name] = record;
		m_ss.erase(name);

		//���
		vector<string>::iterator pos = find(building.floors[f - 1].rooms[r - 1].students.begin(),
			building.floors[f - 1].rooms[r - 1].students.end(), name);
		if (pos != building.floors[f - 1].rooms[r - 1].students.end())
			building.floors[f - 1].rooms[r - 1].students.erase(pos);
			
		building.floors[f - 1].rooms[r - 1].lived_ss--;
		//��������û�ˣ�Ҫ���Ա�ȥ��
		if (building.floors[f - 1].rooms[r - 1].lived_ss == 0)
			building.floors[f - 1].rooms[r - 1].gender = "none";

	
	}
	else if (f_ss.find(name) != f_ss.end())
	{
		FemaleStudent record = f_ss[name];
		int r = record.roomID;
		int f = record.floorID;
		Qf_ss[name] = record;
		f_ss.erase(name);

		//���
		vector<string>::iterator pos = find(building.floors[f - 1].rooms[r - 1].students.begin(),
			building.floors[f - 1].rooms[r - 1].students.end(), name);
		if (pos != building.floors[f - 1].rooms[r - 1].students.end())
			building.floors[f - 1].rooms[r - 1].students.erase(pos);
		building.floors[f - 1].rooms[r - 1].lived_ss--;
		//��������û�ˣ�Ҫ���Ա�ȥ��
		if (building.floors[f - 1].rooms[r - 1].lived_ss == 0)
			building.floors[f - 1].rooms[r - 1].gender = "none";
	}
	
	return 0;
}



//===========================================================================================
// function:   ENTER
// Description: ʵ����ѧ�Ļ
// parameter:   i�ǲ������λ�ã������������һ������ʱ�����������صĵ���Ҫ����
//				words һ��ָ�����еĵ���(��������ݵȲ����ո���ַ���)��
//						�磬ADD 5 FLOOR(s)ָ����ADD,5,3FLOOR(s)����
//				m_ss	��У������(male students)
//				f_ss	��У��Ů��(Quit female students)
//				Qm_ss	��ѧ�˵�����(Quit male students)
//              Qf_ss	��ѧ�˵�Ů��(Quit female students)
//				buiding	����¥����Ϣ			
//Called:		ordersImplement ��analyze_orders.cpp�ļ�
//Call:			��
// Return:		�����������ý�������0
//===========================================================================================
int ENTER(int&i, const vector<string>& words, Building& building,
	map<string, MaleStudent>& m_ss, map<string, FemaleStudent>& f_ss,
	map<string, MaleStudent>& Qm_ss, map<string, FemaleStudent>& Qf_ss)
{
	
	string name = words[0];  //��ѧ��ѧ��
	string gender = words[1];  //��ѧ��ѧ���Ա�

	//��ѧ�����������
	char str[9];  //��ʱ���������ڽ������ַ�ת������
	strcpy_s(str, words[i + 1].c_str()); 
	int f = atoi(str);  //�������ַ���ת��������
	strcpy_s(str, words[i + 3].c_str());
	int r = atoi(str);
	
	//��������᲻����
	if (f > building.floorsNum ||f<=0|| r > building.floors[r - 1].roomsNum||r<=0)
	{
		i += 3;
		return 1;
	}

	
	if (building.floors[f - 1].rooms[r - 1].lived_ss
		== building.floors[f - 1].rooms[r - 1].capacity)
	{
		i += 3;
		return 1;
	}

	else if (building.floors[f - 1].rooms[r - 1].lived_ss == 0 ||
		building.floors[f - 1].rooms[r - 1].gender == gender)
	{
		building.floors[f - 1].rooms[r - 1].students.push_back(name);
		building.floors[f - 1].rooms[r - 1].lived_ss++;
		//���֮ǰû��ס����Ҫ�ı�������Ա�
		if (building.floors[f - 1].rooms[r - 1].lived_ss == 1)
			building.floors[f - 1].rooms[r - 1].gender = gender;

		if (gender == "��")
		{
			if (Qm_ss.find(name) != Qm_ss.end())
			{
				m_ss[name] = Qm_ss[name];
			}
			else
			{
				MaleStudent record;
				record.orderRead(name, gender, f, r);
				m_ss[name] = record;
			}
		}
		else if(gender=="Ů")
		{
			if (Qm_ss.find(name) != Qm_ss.end())
			{
				m_ss[name] = Qm_ss[name];
			}

			else
			{
				MaleStudent record;
				record.orderRead(name, gender, f, r);
				m_ss[name] = record;
			}

		}
	}
	
	i += 3;
	return 0;
}


//===========================================================================================
// function:   WORK
// Description: ʵ�ֹ����Ļ
// parameter:   i�ǲ������λ�ã������������һ������ʱ�����������صĵ���Ҫ����
//				words һ��ָ�����еĵ���(��������ݵȲ����ո���ַ���)��
//						�磬ADD 5 FLOOR(s)ָ����ADD,5,3FLOOR(s)����
//				m_ss	��У������(male students)
//				f_ss	��У��Ů��(Quit female students)
//Called:		ordersImplement ��analyze_orders.cpp�ļ�
//Call:			��
// Return:		�����������ý�������0
//===========================================================================================
int WORK( int&i, const vector<string>& words, map<string, MaleStudent>& m_ss, map<string, FemaleStudent>& f_ss)
{
	
	char str[9];  //��ʱ���������ڽ������ַ�ת������
	strcpy_s(str, words[i + 1].c_str());
	int work_time = atoi(str);  //�������ַ���ת��������
	string name = words[0];
	
	//��ѧ�����ڲ�ִ��
	if (m_ss.find(name) != m_ss.end())
	{
		m_ss[name].work(work_time);
	}
	else if (f_ss.find(name) != f_ss.end())
	{
		f_ss[name].work(work_time);
	}
	
	i += 1;
	
	return 0;
}


//===========================================================================================
// function:   WOO
// Description: ʵ���󰮵Ļ
// parameter:   i�ǲ������λ�ã������������һ������ʱ�����������صĵ���Ҫ����
//				words һ��ָ�����еĵ���(��������ݵȲ����ո���ַ���)��
//						�磬ADD 5 FLOOR(s)ָ����ADD,5,3FLOOR(s)����
//				m_ss	��У������(male students)
//				f_ss	��У��Ů��(Quit female students)
//Called:		ordersImplement ��analyze_orders.cpp�ļ�
//Call:			��
// Return:		�����������ý�������0
//===========================================================================================
int WOO( int&i, const vector<string>& words, map<string, MaleStudent>& m_ss, map<string, FemaleStudent>& f_ss)
{
	
	string name_1 = words[0];
	string name_2 = words[i+1];
	
	//��ѧ��������˫������û�����˻���˫����������Բ����ʱ��ִ��
	if (m_ss.find(name_1) != m_ss.end() && f_ss.find(name_2) != f_ss.end())
	{
		if (!m_ss[name_1].love_status && !f_ss[name_2].love_status)
		{

			double charm_1 = m_ss[name_1].Charm();
			double charm_2 = f_ss[name_2].Charm();
			double Delta = fabs(charm_1-charm_2)/ max(charm_1,charm_2);  //����ֵ��Բ�
			
			//����ֵ��Բ�С�����ֵ�ſ��Խ���������ϵ
			if (Delta < LOVER_CHARM_DELTA)
			{
				m_ss[name_1].wood(name_2);  //��
				f_ss[name_2].wooded(name_1);  //���󰮣�ֻ��Ϊ�˱��ڼ�¼����ʱ��
			}
		}
	}
	else if (m_ss.find(name_1) != m_ss.end() && m_ss.find(name_2) != m_ss.end())
	{
		if (!m_ss[name_1].love_status && !m_ss[name_2].love_status)
		{
			double charm_1 = m_ss[name_1].Charm();
			double charm_2 = m_ss[name_2].Charm();
			double Delta = fabs(charm_1 - charm_2) / max(charm_1, charm_2);
			
			if (Delta < LOVER_CHARM_DELTA)
			{
				m_ss[name_1].wood(name_2);
				m_ss[name_2].wooded(name_1);
			}
		}
	}

	else if (f_ss.find(name_1) != f_ss.end() && m_ss.find(name_2) != m_ss.end())
	{
		if (!f_ss[name_1].love_status && !m_ss[name_2].love_status)
		{
			double charm_1 = f_ss[name_1].Charm();
			double charm_2 = m_ss[name_2].Charm();
			double Delta = fabs(charm_1 - charm_2) / max(charm_1, charm_2);
		
			if (Delta < LOVER_CHARM_DELTA)
			{
				f_ss[name_1].wood(name_2);
				m_ss[name_2].wooded(name_1);
			}
		}
	}
	else if (f_ss.find(name_1) != f_ss.end() && f_ss.find(name_2) != f_ss.end())
	{
		if (!f_ss[name_1].love_status && !f_ss[name_2].love_status)
		{
			double charm_1 = f_ss[name_1].Charm();
			double charm_2 = f_ss[name_2].Charm();
			double Delta = fabs(charm_1 - charm_2) / max(charm_1, charm_2);
			
			if (Delta < LOVER_CHARM_DELTA)
			{
				f_ss[name_1].wood(name_2);
				f_ss[name_2].wooded(name_1);
			}
		}
	}
	
	i += 1; //WOO������һ��ִ��
	
	return 0;
}


//===========================================================================================
// function:   BREAK
// Description: ʵ��������ϵ���ѵĻ
// parameter:   i�ǲ������λ�ã������������һ������ʱ�����������صĵ���Ҫ����
//				words һ��ָ�����еĵ���(��������ݵȲ����ո���ַ���)��
//						�磬ADD 5 FLOOR(s)ָ����ADD,5,3FLOOR(s)����
//				m_ss	��У������(male students)
//				f_ss	��У��Ů��(Quit female students)
//Called:		ordersImplement ��analyze_orders.cpp�ļ�
//Call:			��
// Return:		�����������ý�������0
//===========================================================================================
int BREAK( int&i, const vector<string>& words, map<string, MaleStudent>& m_ss, map<string, FemaleStudent>& f_ss)
{
	
	string name_1 = words[0];
	string name_2 = words[1];
	
	//��ѧ����������������ϵ��ִ��
	if (m_ss.find(name_1) != m_ss.end() && f_ss.find(name_2) != f_ss.end())
	{
		if (m_ss[name_1].ifLover(name_2))
		{
			m_ss[name_1].Break();
			f_ss[name_2].Break();
		}
	}
	else if (m_ss.find(name_1) != m_ss.end() && m_ss.find(name_2) != m_ss.end())
	{
		if (m_ss[name_1].ifLover(name_2))
		{
			m_ss[name_1].Break();
			m_ss[name_2].Break();
		}
	}
	else if (f_ss.find(name_1) != f_ss.end() && m_ss.find(name_2) != m_ss.end())
	{
		if (f_ss[name_1].ifLover(name_2))
		{
			f_ss[name_1].Break();
			m_ss[name_2].Break();
		}
	}
	else if (f_ss.find(name_1) != f_ss.end() && f_ss.find(name_2) != f_ss.end())
	{
		if (f_ss[name_1].ifLover(name_2))
		{
			f_ss[name_1].Break();
			f_ss[name_2].Break();
		}
	}
	
	i += 1;  //��BREAK��ص�����ѱ�ִ��
	return 0;
}

