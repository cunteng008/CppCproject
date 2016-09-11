#ifndef GUARD_config_h
#define GUARD_config_h

#include <fstream>
#include <map>
#include <string>

void ReadConfig();


//��������ĳ���
extern int FLOOR;
extern int ROOM;
extern int CAPACITY;


extern double FOOD_INC_WEIGHT;      // ÿ��λ����ʳ��������ӵ��w��
extern double FOOD_COST;            // ÿ��λ����ʳ��ăr��

extern double STUDY_DEC_WEIGHT;     // ÿ��λ�r�g�W���p�ٵ��w��
extern double STUDY_INC_KNOWLEDGE;  // ÿ��λ�r�g�W�����ӵ�֪�R

extern double MAKEUP_INC_LOOKS;     // ÿ��λ�r�g���y�������ӵ���ò
extern double MAKEUP_COST;          // ÿ��λ�r�g���y���ĵĽ��X

extern double EXERCISE_INC_HEALTH;  // ÿ��λ�r�g�\�ӿ������ӵĽ���

extern double WORK_DEC_WEIGHT;      // ÿ��λ�r�g�򹤜p�ٵ��w��
extern double WORK_INC_MONEY;       // ÿ��λ�r�g��ٍȡ�Ľ��X

extern double LOVER_CHARM_DELTA;    // ���Խ����ِ��P�S��������������ֵ

// �����Ġ�B��ʼֵ�����Ξ飺�w�ء����X��֪�R������������
extern double MALE_WEIGHT;
extern double MALE_MONEY;
extern double MALE_KNOWLEDG;
extern double MALE_HEALTH;
extern double MALE_CHARM;

// Ů���Ġ�B��ʼֵ�����Ξ飺�w�ء����X��֪�R����ò������
extern double FEMALE_WEIGHT;
extern double FEMALE_MONEY;
extern double FEMALE_KNOWLEDGE;
extern double FEMALE_LOOKS;
extern double FEMALE_CHARM;

#endif


	