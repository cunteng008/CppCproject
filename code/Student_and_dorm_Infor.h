
/*=============================================================

Copyright: Call_Me_Why

Author: ������

Date:2016-5-2

Description: ѧ����Ϣ���������Ϣ

==============================================================*/
#ifndef GUARD_data_h
#define GUARD_data_h

#include <string>
#include <vector>
#include <fstream>
#include <map>
#include "love_history.h"
#include "config.h"

class Student
{
public:
	//lover("none")�����˵����ֳ�ʼ��Ϊnone������״̬Ϊfalse����ʾû������
	Student() :floorID(0), roomID(0), love_status(0), lover("none") { } 	
																		

	void read(const std::vector<std::string>& );

	//������ָ��������һ����ʱ�ĳ�ʼ��
	void orderRead(std::string n, std::string gen,int f,int r) { name = n; gender = gen; floorID = f; roomID = r; }

	std::string Name() { return name; }
	std::string Gender() { return gender; }
	double Charm() { return charm; }
	double Weight() { return weight; }
	double Knowledge() { return knowledge; }
	double Money() { return money; }

	int eat(int);
	int study(int);
	int work(int);
	int wood(std::string);  //��
	int wooded(std::string); //���󰮣�ֻ�Ƿ�����ʱ��ļ�¼
	int Break();
	
	bool ifLover(std::string n) { return n == lover; } //�ж��Ƿ�Ϊ���ˣ�����Ĳ���Ϊѧ������

	std::vector<LOVE_HISTORY> love_historys ;  //����ʷ
	               
	static int wood_time;  //�󰮵�ʱ���Ⱥ󣬱�������
	bool love_status;  //������״������������״̬�������򲻴��ڡ�
	int floorID;
	int roomID;
protected:
	std::string name;
	std::string gender;

	double money;
	double weight;
	double knowledge;
	double charm;

	std::string lover;  //�������˵����֣������ǰû��������Ϊnone
};

class MaleStudent : public Student
{
public:
	   MaleStudent() ;
	   double Charm(); 
	   double Health() { return health; }
	   
	   int exercise(int);
private:
	double health;
};

class FemaleStudent : public Student
{
public:
	FemaleStudent() ;
	double Charm();
	double Looks() { return looks; }

	int makeup(int);
private:
	double looks;
};


//����ǡ��ǌӡ����g�Ĕ����Y
class Room
{
public:
	Room():lived_ss(0), gender("none") { capacity = CAPACITY; }
	int capacity ;
	int lived_ss;
	std::string gender;     //�Ա��ʼ��Ϊnone����Ů��ס�Ǹ���Ϊ"Ů"���������෴
	                        //�Ա������ж���Ҫ���Ǹ����͵�����
	std::vector<std::string>  students;  //ѧ������
};

class Floor
{
public:
	Floor() { roomsNum = ROOM; rooms.resize(ROOM); }
	int roomsNum;
	std::vector<Room> rooms;

};

class Building
{
public:
	Building() { floorsNum = FLOOR; floors.resize(FLOOR); }
	int floorsNum;
	std::vector<Floor> floors;
};

void read(std::ifstream&,Building& ,std::map<std::string, MaleStudent>&,std::map<std::string,FemaleStudent>& );
#endif
