/********************************************************************************

Copyright:Call_Me_Why

Author:������

Date:2016-5-25

Description: ��ȡconfig.txt�ĳ�����������Ӧ��ȫ�ֱ�����ȫ�ֱ�������const�����Բ�Ҫ�Ķ�!

******************************************************************************************/

#include <fstream>
#include <map>
#include <string>
#include "config.h"
#include <iostream>

//std::map<std::string, double> config;


//��������ĳ���
int FLOOR;
int ROOM ;
int CAPACITY;

double FOOD_INC_WEIGHT;      // ÿ��λ����ʳ��������ӵ��w��
double FOOD_COST;            // ÿ��λ����ʳ��ăr��

double STUDY_DEC_WEIGHT;     // ÿ��λ�r�g�W���p�ٵ��w��
double STUDY_INC_KNOWLEDGE;  // ÿ��λ�r�g�W�����ӵ�֪�R

double MAKEUP_INC_LOOKS;     // ÿ��λ�r�g���y�������ӵ���ò
double MAKEUP_COST;          // ÿ��λ�r�g���y���ĵĽ��X

double EXERCISE_INC_HEALTH;  // ÿ��λ�r�g�\�ӿ������ӵĽ���

double WORK_DEC_WEIGHT;      // ÿ��λ�r�g�򹤜p�ٵ��w��
double WORK_INC_MONEY;       // ÿ��λ�r�g��ٍȡ�Ľ��X

double LOVER_CHARM_DELTA;    // ���Խ����ِ��P�S��������������ֵ

// �����Ġ�B��ʼֵ�����Ξ飺�w�ء����X��֪�R������������
double MALE_WEIGHT;
double MALE_MONEY;
double MALE_KNOWLEDG;
double MALE_HEALTH;
double MALE_CHARM;

// Ů���Ġ�B��ʼֵ�����Ξ飺�w�ء����X��֪�R����ò������
double FEMALE_WEIGHT;
double FEMALE_MONEY;
double FEMALE_KNOWLEDGE;
double FEMALE_LOOKS;
double FEMALE_CHARM;

void ReadConfig()
{
	std::map<std::string, double> config;
	std::string str;
	double t;
	std::ifstream configin("config.txt");
	if (!configin)
	{
		std::cout << "config.txt������" << std::endl;
		exit(1);  
	}
	while (configin >> str)
	{
		if (str == "//")
			getline(configin, str);
		else
		{
			configin >> t;
			config[str] = t;
		}
	}

	//��������ĳ�������Ϊ���������������ﲻ�õ��ľ�������
	FLOOR = config["FLOOR"];
	ROOM = config["ROOM"];
	CAPACITY = config["CAPACITY"];


	FOOD_INC_WEIGHT = config["FOOD_INC_WEIGHT"];			// ÿ��λ����ʳ��������ӵ��w��
	FOOD_COST = config["FOOD_COST"];						// ÿ��λ����ʳ��ăr��

	STUDY_DEC_WEIGHT = config["STUDY_DEC_WEIGHT"];			// ÿ��λ�r�g�W���p�ٵ��w��
	STUDY_INC_KNOWLEDGE = config["STUDY_INC_KNOWLEDGE"];	// ÿ��λ�r�g�W�����ӵ�֪�R

	MAKEUP_INC_LOOKS = config["MAKEUP_INC_LOOKS"];			// ÿ��λ�r�g���y�������ӵ���ò
	MAKEUP_COST = config["MAKEUP_COST"];					// ÿ��λ�r�g���y���ĵĽ��X

	EXERCISE_INC_HEALTH = config["EXERCISE_INC_HEALTH"];	// ÿ��λ�r�g�\�ӿ������ӵĽ���

	WORK_DEC_WEIGHT = config["WORK_DEC_WEIGHT"];			// ÿ��λ�r�g�򹤜p�ٵ��w��
	WORK_INC_MONEY = config["WORK_INC_MONEY"];				// ÿ��λ�r�g��ٍȡ�Ľ��X

	LOVER_CHARM_DELTA = config["LOVER_CHARM_DELTA"];		// ���Խ����ِ��P�S��������������ֵ


	// �����Ġ�B��ʼֵ�����Ξ飺�w�ء����X��֪�R������������
	MALE_WEIGHT = config["MALE_WEIGHT"];
	MALE_MONEY = config["MALE_MONEY"];
	MALE_KNOWLEDG = config["MALE_KNOWLEDG"];
	MALE_HEALTH = config["MALE_HEALTH"];
	MALE_CHARM = config["MALE_CHARM"];

	// Ů���Ġ�B��ʼֵ�����Ξ飺�w�ء����X��֪�R����ò������
	FEMALE_WEIGHT = config["FEMALE_WEIGHT"];
	FEMALE_MONEY = config["FEMALE_MONEY"];
	FEMALE_KNOWLEDGE = config["FEMALE_KNOWLEDGE"];
	FEMALE_LOOKS = config["FEMALE_LOOKS"];
	FEMALE_CHARM = config["FEMALE_CHARM"];
}



