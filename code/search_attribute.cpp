#include "search_attribute.h"
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include "Student_and_dorm_Infor.h"
#include "padding.h"
#include "attribute_name.h"

using namespace std;


void weitht_rang_search(const vector<attributeName>& );
void weight_min(const vector<attributeName>& );
void weight_max(const vector<attributeName>& );
void weight_search_by_name(const vector<attributeName>& );

void money_rang_search(const vector<attributeName>& );
void money_min(const vector<attributeName>& );
void money_max(const vector<attributeName>& );
void money_search_by_name(const vector<attributeName>& );

void knowledge_rang_search(const vector<attributeName>& );
void knowledge_min(const vector<attributeName>& );
void knowledge_max(const vector<attributeName>& );
void knowledge_search_by_name(const vector<attributeName>& );

void charm_rang_search(const vector<attributeName>&);
void charm_min(const vector<attributeName>&);
void charm_max(const vector<attributeName>& );
void charm_search_by_name(const vector<attributeName>&);

void health_rang_search(const vector<attributeName>&);
void health_min(const vector<attributeName>&);
void health_max(const vector<attributeName>&);
void health_search_by_name(const vector<attributeName>&);

void looks_rang_search(const vector<attributeName>&);
void looks_min(const vector<attributeName>&);
void looks_max(const vector<attributeName>&);
void looks_search_by_name(const vector<attributeName>&);


void attribute_rang_search(const vector<attributeName>& attribute_names ,const string note);
void attribute_min(const vector<attributeName>& attribute_names, const string note);
void attribute_max(const vector<attributeName>& attribute_names, const string note);
void attribute_search_by_name(const vector<attributeName>& attribute_names, const string& name,const string note);


//====================================================================================
// Function:    search_attribute_options
// Called:      search_weight�����Բ�ѯ����
// Description: �����ԵĲ�ѯѡ��ӿ���ʾ
// Parameter:	����˵��ѡ������ʣ������ز�ѯ����ò��ѯ��
// Return:      ��
//====================================================================================
void search_attribute_options(const string& head)
{
	//�ظ��Եĵ�����ͬ���ݣ��ÿ���staticһ�������ͺ�
	static string option_0 = "0.   ��      ��";
	static string option_1 = "1.   ��  Χ  ��  ѯ";
	static string option_2 = "2.   ��  С  ֵ  ��  ѯ";
	static string option_3 = "3.   ��  ��  ֵ  ��  ѯ";
	static string option_4 = "4.   ��  ��  ��  ��  ��  ѯ";
	static string pad_left(3, ' ');

	string::size_type width = 45;
	cout << "\n\n" << endl;

	cout << string(33, ' ') << "+" << string(width, '=') << "+" << endl;
	cout << string(33, ' ') << "+ "<< head << string(width - 1 - head.size(), ' ') << "+" << endl;

	cout << string(33, ' ') << "+" << string(width, '=') << "+" << endl;
	cout << string(33, ' ') << "+" << pad_left << option_1 << string(width - pad_left.size() - option_1.size(), ' ') << "+" << endl;
	cout << string(33, ' ') << "+" << string(width, '=') << "+" << endl;

	cout << string(33, ' ') << "+" << pad_left << option_2 << string(width - pad_left.size() - option_2.size(), ' ') << "+" << endl;
	cout << string(33, ' ') << "+" << string(width, '=') << "+" << endl;

	cout << string(33, ' ') << "+" << pad_left << option_3 << string(width - pad_left.size() - option_3.size(), ' ') << "+" << endl;
	cout << string(33, ' ') << "+" << string(width, '=') << "+" << endl;

	cout << string(33, ' ') << "+" << pad_left << option_4 << string(width - pad_left.size() - option_4.size(), ' ') << "+" << endl;
	cout << string(33, ' ') << "+" << string(width, '=') << "+" << endl;

	cout << string(33, ' ') << "+" << pad_left << option_0 << string(width - pad_left.size() - option_0.size(), ' ') << "+" << endl;
	cout << string(33, ' ') << "+" << string(width, '=') << "+" << endl;
}


//====================================================================================
// Function:    search_weight
// Called:      search_attribute_list.cpp�ļ����search_attribute_list
// Description: weight��ѯ��ѡ������
// Parameter:	����_���� ���ݽṹ������
// Return:      ��
//====================================================================================
void search_weight(const vector<attributeName>& weight_names)
{
	string head = "��ѧ�����ز�ѯ��ѡ����:";
	system("cls");
	search_attribute_options(head);
	int choose;
	cout << Left_Padding << "��ѡ��: ";
	while (cin>>choose)
	{
		//�������ѡ������Ҫ������
		if (choose < 0 || choose>4)
		{
			cout << Left_Padding <<"������0 - 4������: " << endl;
			continue;
		}
		switch (choose)
		{
		case 1: weitht_rang_search(weight_names);
			break;
		case 2: weight_min(weight_names);
			break;
		case 3:weight_max(weight_names);
			break;
		case 4:weight_search_by_name(weight_names);
			break;
		default:return;
			break;
		}

		//�����Ļ����ʾ��һ��
		system("cls");
		search_attribute_options(head);
		cout << Left_Padding << "��ѡ��: ";
	}
}
void weitht_rang_search(const vector<attributeName>& weight_names)
{
	string note = "����";
	attribute_rang_search(weight_names, note);
}
void weight_min(const vector<attributeName>& weight_names)
{
	string note = "����";
	attribute_min(weight_names, note);
}
void weight_max(const vector<attributeName>& weight_names)
{
	string note = "����";
	attribute_max(weight_names, note);
}
void weight_search_by_name(const vector<attributeName>& weight_names)
{
	string note = "����";
	string name;
	cout << Left_Padding << "������ѧ������(�м䲻�ܺ��ո�): ";
	cin >> name;
	attribute_search_by_name(weight_names, name, note);
}


//====================================================================================
// Function:    search_money
// Called:      search_attribute_list.cpp�ļ����search_attribute_list
// Description: money��ѯ��ѡ������
// Parameter:	����_���� ���ݽṹ������
// Return:      ��
//====================================================================================
void search_money(const vector<attributeName>& money_names)
{
	string head = "��ѧ��ӵ�н�Ǯ״����ѯ��ѡ����:";
	system("cls");
	search_attribute_options(head);
	int choose;
	cout << Left_Padding << "��ѡ��: ";
	while (cin >> choose)
	{
		if (choose < 0 || choose>4)
		{
			cout << Left_Padding << "������0 - 4������: " << endl;
			continue;
		}
		switch (choose)
		{
		case 1: money_rang_search(money_names);
			break;
		case 2: money_min(money_names);
			break;
		case 3:money_max(money_names);
			break;
		case 4:money_search_by_name(money_names);
			break;
		default:return;
			break;
		}

		system("cls");
		search_attribute_options(head);
		cout << Left_Padding << "��ѡ��: ";
	}
}
void money_rang_search(const vector<attributeName>& money_names)
{
	string note = "ӵ�н�Ǯ��Ŀ";
	attribute_rang_search(money_names, note);
}
void money_min(const vector<attributeName>& money_names)
{
	string note = "ӵ�н�Ǯ��Ŀ";
	attribute_min(money_names, note);
}
void money_max(const vector<attributeName>& money_names)
{
	string note = "ӵ�н�Ǯ��Ŀ";
	attribute_max(money_names, note);
}
void money_search_by_name(const vector<attributeName>& money_names)
{
	string note = "��Ǯ";
	string name;
	cout << Left_Padding << "������ѧ������(�м䲻�ܺ��ո�): ";
	cin >> name;
	attribute_search_by_name(money_names, name, note);
}



//====================================================================================
// Function:    knowledge
// Called:      search_attribute_list.cpp�ļ����search_attribute_list
// Description: knowledge��ѯ��ѡ������
// Parameter:	����_���� ���ݽṹ������
// Return:      ��
//====================================================================================
void search_knowledge(const vector<attributeName>& knowledge_names)
{
	string head = "��ѧ��֪ʶ����ѯ��ѡ����:";
	system("cls");
	search_attribute_options(head);
	int choose;
	cout << Left_Padding << "��ѡ��: ";
	while (cin >> choose)
	{
		if (choose < 0 || choose>4)
		{
			cout << Left_Padding << "������0 - 4������: " << endl;
			continue;
		}
		switch (choose)
		{
		case 1: knowledge_rang_search(knowledge_names);
			break;
		case 2: knowledge_min(knowledge_names);
			break;
		case 3:knowledge_max(knowledge_names);
			break;
		case 4:knowledge_search_by_name(knowledge_names);
			break;
		default:return;
			break;
		}

		system("cls");
		search_attribute_options(head);
		cout << Left_Padding << "��ѡ��: ";
	}
}
void knowledge_rang_search(const vector<attributeName>& knowledge_names)
{
	string note = "֪ʶ��";
	attribute_rang_search(knowledge_names, note);
}
void knowledge_min(const vector<attributeName>& knowledge_names)
{
	string note = "֪ʶ��";
	attribute_min(knowledge_names, note);
}
void knowledge_max(const vector<attributeName>& knowledge_names)
{
	string note = "֪ʶ��";
	attribute_max(knowledge_names, note);
}
void knowledge_search_by_name(const vector<attributeName>& knowledge_names)
{
	string note = "֪ʶ��";
	string name;
	cout << Left_Padding << "������ѧ������(�м䲻�ܺ��ո�): ";
	cin >> name;
	attribute_search_by_name(knowledge_names, name, note);
}


//====================================================================================
// Function:    search_charm
// Called:      search_attribute_list.cpp�ļ����search_attribute_list
// Description: charm��ѯ��ѡ������
// Parameter:	����_���� ���ݽṹ������
// Return:      ��
//====================================================================================
void search_charm(const vector<attributeName>& charm_names)
{
	string head = "��ѧ������ֵ��ѯ��ѡ����:";
	system("cls");
	search_attribute_options(head);
	int choose;
	cout << Left_Padding << "��ѡ��: ";
	while (cin >> choose)
	{
		if (choose < 0 || choose>4)
		{
			cout << Left_Padding << "������0 - 4������: " << endl;
			continue;
		}
		switch (choose)
		{
		case 1: charm_rang_search(charm_names);
			break;
		case 2: charm_min(charm_names);
			break;
		case 3:charm_max(charm_names);
			break;
		case 4:charm_search_by_name(charm_names);
			break;
		default:return;
			break;
		}

		system("cls");
		search_attribute_options(head);
		cout << Left_Padding << "��ѡ��: ";
	}
}
void charm_rang_search(const vector<attributeName>& charm_names)
{
	string note = "����ֵ";
	attribute_rang_search(charm_names, note);
}
void charm_min(const vector<attributeName>& charm_names)
{
	string note = "����ֵ";
	attribute_min(charm_names, note);
}
void charm_max(const vector<attributeName>& charm_names)
{
	string note = "����ֵ";
	attribute_max(charm_names, note);
}
void charm_search_by_name(const vector<attributeName>& charm_names)
{
	string note = "����ֵ";
	string name;
	cout << Left_Padding << "������ѧ������(�м䲻�ܺ��ո�): ";
	cin >> name;
	attribute_search_by_name(charm_names, name, note);
}



//====================================================================================
// Function:    search_health
// Called:      search_attribute_list.cpp�ļ����search_attribute_list
// Description: health��ѯ��ѡ������
// Parameter:	����_���� ���ݽṹ������
// Return:      ��
//====================================================================================
void search_health(const vector<attributeName>& health_names)
{
	string head = "��ѧ������ֵ��ѯ��ѡ����:";
	system("cls");
	search_attribute_options(head);
	int choose;
	cout << Left_Padding << "��ѡ��: ";
	while (cin >> choose)
	{
		if (choose < 0 || choose>4)
		{
			cout << Left_Padding << "������0 - 4������: " << endl;
			continue;
		}
		switch (choose)
		{
		case 1: health_rang_search(health_names);
			break;
		case 2: health_min(health_names);
			break;
		case 3:health_max(health_names);
			break;
		case 4:health_search_by_name(health_names);
			break;
		default:return;
			break;
		}

		system("cls");
		search_attribute_options(head);
		cout << Left_Padding << "��ѡ��: ";
	}
}
void health_rang_search(const vector<attributeName>& charm_names)
{
	string note = "ѧ������ֵ";
	attribute_rang_search(charm_names,note);
}
void health_min(const vector<attributeName>& charm_names)
{
	string note = "ѧ������ֵ";
	attribute_min(charm_names, note);
}
void health_max(const vector<attributeName>& charm_names)
{
	string note = "ѧ������ֵ";
	attribute_max(charm_names, note);
}
void health_search_by_name(const vector<attributeName>& health_names)
{
	string note = "ѧ������ֵ";
	string name;
	cout << Left_Padding << "������ѧ������(�м䲻�ܺ��ո�): ";
	cin >> name;
	attribute_search_by_name(health_names, name, note);
}


//====================================================================================
// Function:    search_looks
// Called:      search_attribute_list.cpp�ļ����search_attribute_list
// Description: looks��ѯ��ѡ������
// Parameter:	����_���� ���ݽṹ������
// Return:      ��
//====================================================================================
void search_looks(const vector<attributeName>& looks_names)
{
	cout << looks_names.size() << endl;
	system("pause");
	string head = "��ѧ����òֵ��ѯ��ѡ����:";
	system("cls");
	search_attribute_options(head);
	int choose;
	cout << Left_Padding << "��ѡ��: ";
	while (cin >> choose)
	{
		if (choose < 0 || choose>4)
		{
			cout << Left_Padding << "������0 - 4������: " << endl;
			continue;
		}
		switch (choose)
		{
		case 1: looks_rang_search(looks_names);
			break;
		case 2: looks_min(looks_names);
			break;
		case 3:looks_max(looks_names);
			break;
		case 4:looks_search_by_name(looks_names);
			break;
		default:return;
			break;
		}

		system("cls");
		search_attribute_options(head);
		cout << Left_Padding << "��ѡ��: ";
	}
}
void looks_rang_search(const vector<attributeName>& looks_names)
{
	string note = "��òֵ";
	attribute_rang_search(looks_names, note);
}
void looks_min(const vector<attributeName>& looks_names)
{
	string note = "��òֵ";
	attribute_min(looks_names, note);
}
void looks_max(const vector<attributeName>& looks_names)
{
	string note = "��òֵ";
	attribute_max(looks_names, note);
}
void looks_search_by_name(const vector<attributeName>& looks_names)
{
	string note = "��òֵ";
	string name;
	cout << Left_Padding << "������ѧ������(�м䲻�ܺ��ո�): ";
	cin >> name;
	attribute_search_by_name(looks_names, name, note);
}



//====================================================================================
// Function:    attribute_rang_search
// Called:      looks_rang_search�����Է�Χ��ѯ����
// Description: ���Է�Χ����
// Parameter:	����_���� ���ݽṹ������������˵����ע��note
// Return:      ��
//====================================================================================
void attribute_rang_search(const vector<attributeName>& attribute_names, const string note)
{
	double min;
	double max;
	char ch;
	string::size_type i = attribute_names.size()-1;

	cout << Left_Padding << "��ѡ��Χ: ";
	cin >> min >> ch >>max ;  //chֻ��������ʱ�м����ַ�
	

	int count = 0;
	system("cls");

	//note��˵����ע�����ã�˵����ʾ����ʲô��Ϣ
	cout << "\n\n" << Left_Padding <<note<<"Ϊ"<< min << " �� " << max << "��ѧ����:" << endl << endl;
	
	if (min > attribute_names[0].attribute || max < attribute_names[i].attribute)
		cout << endl << Left_Padding << "û���ҵ��ʺϵ�ѧ��" << endl;
	
	else
	{
		//attribute_names���ǽ���
		for (auto s : attribute_names)
		{
			cout << Left_Padding << string(3, ' ') << s.name << string(10 - s.name.size(), ' ') << s.attribute << endl;
			count++;
			if (count == 23)  //ÿҳ�����ʾ23����Ϣ
			{
				count = 0;
				system("pause");
				system("cls");
				cout << "\n\n" << Left_Padding << note << "Ϊ" << min << " �� " << max << "��ѧ����:" << endl << endl;
			}

		}
	}

	system("pause");
}




//====================================================================================
// Function:    attribute_min
// Called:      looks_min��������Сֵ��ѯ����
// Description: ��������Сֵ��ѯ
// Parameter:	����_���� ���ݽṹ������������˵����ע��note
// Return:      ��
//====================================================================================
void attribute_min(const vector<attributeName>& attribute_names, const string note)
{
	
	string::size_type i = attribute_names.size()-1;

	//��Ϊattribute_names���ǽ���
	double min= attribute_names[i].attribute;
	int count = 0;
	system("cls");

	//note��˵����ע�����ã�˵����ʾ����ʲô��Ϣ
	cout << "\n\n" << Left_Padding << note << "��С��ѧ����:" << endl << endl;

	for (; i >= 0; i--)
	{
		if (min != attribute_names[i].attribute)
			break;

		cout << Left_Padding << string(3, ' ') << attribute_names[i].name 
	      << string(10 - attribute_names[i].name.size(), ' ') << attribute_names[i].attribute << endl;
		count++;
		if (count == 23)  //ÿҳ�����ʾ23����Ϣ
		{
			count = 0;
			system("pause");
			system("cls");
			cout << "\n\n" << Left_Padding << note << "��С��ѧ����:" << endl << endl;
		}
	}
	
	system("pause");
}

//====================================================================================
// Function:    attribute_max
// Called:      looks_max���������ֵ��ѯ����
// Description: ���������ֵ��ѯ
// Parameter:	����_���� ���ݽṹ������������˵����ע��note
// Return:      ��
//====================================================================================
void attribute_max(const vector<attributeName>& attribute_names, const string note)
{
	string::size_type i = 0;

	//attribute_names���ǽ���
	double max = attribute_names[0].attribute;
	int count = 0;

	system("cls");

	//note��˵����ע�����ã�˵����ʾ����ʲô��Ϣ
	cout << "\n\n" << Left_Padding << note << "����ѧ����:" << endl << endl;

	for (; i <attribute_names.size(); i++)
	{
		if (max != attribute_names[i].attribute)
			break;
		cout << Left_Padding << string(3, ' ') << attribute_names[i].name
			<< string(10 - attribute_names[i].name.size(), ' ') << attribute_names[i].attribute << endl;
		count++;
		if (count == 23)  //���ÿҳ��ʾ23����Ϣ
		{
			count = 0;
			system("pause");
			system("cls");
			cout << "\n\n" << Left_Padding << note << "����ѧ����:" << endl << endl;
		}
	}

	system("pause");
}

//====================================================================================
// Function:    attribute_search_by_name
// Called:      looks_search_by_name���������ֵ��ѯ����
// Description: ������������
// Parameter:	����_���� ���ݽṹ���������������ַ��� name ����˵����ע��note
// Return:      ��
//====================================================================================
void attribute_search_by_name(const vector<attributeName>& attribute_names, 
	const string& name,const string note)
{
		for (auto s : attribute_names)
		{
			if (s.name == name)
			{
				cout << endl << Left_Padding << name << "��" << note << "Ϊ: " << s.attribute << endl;
				system("pause");
				return;
			}
				
		}
		cout << endl << Left_Padding << "��ѧ��������"<<endl;
		system("pause");
}