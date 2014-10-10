// ��������.cpp : Defines the entry point for the console application.
//
#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include "conio.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include "Structs.h"
#include "functions.h"

using namespace std;

class Shop
{

private:
	//��������� �� ������
	List_Client *head_client;
	List_Information *head_information;
	List_Check *head_check;
	List_CaI *head_cai;
	List_CaC *head_cac;

public:
	Shop()
	{
		head_information = NULL;
		head_client = NULL;
		head_check = NULL;
		head_cai = NULL;
		head_cac = NULL;
	}
	ifstream in_stream;
	ofstream out_stream;

	Client push_Client(int i)											//�������� �������� � ������ � ����������
	{
		Client t;
		char c;
		cout << "\n ������� ������  " << i + 1 << " �������.\n ";
		List_Client *node1 = head_client;
		int counter = 0;
		while (node1 != NULL)
		{
			counter++;
			node1 = node1->next;
		}
		t.clientID = counter + 1;
		cout << "������� ��� �������: ";
		cin.getline(t.C_name, 40);
		cout << "������ ������ �������� ����������? (+/-) : ";
		cin.get(c);
		if (c == '+')
			t.type = true;
		else
			t.type = false;

		List_Client *node = new List_Client;
		node->client = t;
		node->next = head_client;
		head_client = node;

		return t;
	}

	void Delete_Client(int id)
	{
		List_Client *temp = head_client;
		if (head_client->client.clientID == id)
		{
			head_client = head_client->next;
			return;
		}
		while (temp->next != NULL)
		{
			if (temp->next->client.clientID == id)
			{
				temp->next = temp->next->next;
				break;
			}
			temp = temp->next;
		}
	}

	Client EditClient(int id)
	{
		List_Client *node = head_client;
		while (node->next != NULL && node->client.clientID != id)
		{
			node = node->next;
		}
		Client t;
		char c;
		cout << "\n������� ����� ������ �������:\n ";
		t.clientID = id;
		cout << "������� ��� �������: ";
		cin.getline(t.C_name, 40);
		cout << "������ ������ �������� ����������? (+/-) : ";
		cin.get(c);
		if (c == '+')
			t.type = true;
		else
			t.type = false;
		node->client = t;
		return t;
	}

	void Write_into_file_client()
	{
		List_Client *node = head_client;
		char file1[200];
		while (true){
			cout << "������� ���� ������������ �����: ";
			char c;
			cin.getline(file1, 200);
			cin.get(c);
			out_stream.open(file1);
			if (!out_stream){
				cout << "������ ��� �������� �����!\n";
			}
			else{
				break;
			}
		}
		while (node != NULL)
		{
			out_stream << node->client.clientID << " " << node->client.C_name << " " << ((node->client.type)?("+"):("-")) << endl;
			node = node->next;
		}
		out_stream.close();
	}

	void print_Client()											//����� ������ �� �����
	{
		List_Client *node = head_client;
		printf("\n %15s! %30s", "ID Client!			 Client's name         !        type ");
		while (node != NULL)
		{
			printf("\n %3d ! %30s! %10s", node->client.clientID, node->client.C_name, node->client.type);
			node = node->next;
		}
	}
	/*---------------------------------------------------------------------------------------------*/
	Information push_information()
	{
		Information inf;
		char c;
		cout << "\n������� ����������:\n";
		List_Information *node1 = head_information;
		int counter = 0;
		while (node1 != NULL)
		{
			counter++;
			node1 = node1->next;
		}
		inf.informationID = counter + 1;
		while (true){
			cout << "������� ��� ����� ��� ����� (1 - audio, 2 - video): ";
			
			cin.getline(inf.A_V, 100);
			if (inf.A_V == "1"){
				strcpy_s(inf.A_V, "audio");
				break;
			}
			if (inf.A_V == "2"){
				strcpy_s(inf.A_V, "video");
				break;
			}
		}

		cout << "Enter CD or DVD" << endl;
		cin.getline(inf.Cd_DvD, 100);


		List_Information *node = new List_Information;
		node->information = inf;
		node->next = head_information;
		head_information= node;

		return inf;
	}

	void Delete_Information(int id)
	{
		if (head_information == NULL)

			return;
		List_Information *temp = head_information;
		if (head_information->information.informationID == id)
		{
			head_information = head_information->next;
		}
		while (temp->next != NULL)
		{
			if (temp->next->information.informationID == id)
			{
				temp->next = temp->next->next;
				break;
			}
			temp = temp->next;
		}
	}

	Information EditInformation(int id)
	{
		List_Information *node = head_information;
		while (node->next != NULL && node->information.informationID != id)
		{
			node = node->next;
		}
		Information inf;
		char c;
		cout << "\n Enter date information's type.\n ";
		cin.get(c);
		inf.informationID = id;
		cout << "Enter audio or video" << endl;
		cin.getline(inf.A_V, 100);
		cout << "Enter CD or DVD" << endl;
		cin.getline(inf.Cd_DvD, 100);
		node->information = inf;
		return inf;
	}

	void Write_into_Information_file()
	{
		List_Information *node = head_information;
		char file3[200];
		cout << "Show way of saving file" << endl;
		char c;
		cin.get(c);
		cin.getline(file3, 200);
		out_stream.open(file3);
		while (node != NULL)
		{
			out_stream << node->information.informationID << " " << node->information.informationID << endl;
			node = node->next;
		}
		out_stream.close();
	}

	void print_Information()
	{
		List_Information *node = head_information;
		printf("\n %15s! %30s", "Information's ID!			 A_V         !          CD_DvD");
		while (node != NULL)
		{
			printf("\n %3d ! %30s! %30s", node->information.informationID, node->information.A_V, node->information.Cd_DvD);
			node = node->next;
		}
	}
	/*---------------------------------------------------------------------------------------------*/
	Check push_check(int i)											//�������� �������� � ������ � ����������
	{
		Check ch;
		char c;
		cout << "\n Enter data " << i + 1 << " check.\n ";
		cout << "ID of new type was determined automatically" << endl;
		
		List_Check *node1 = head_check;
		
		cout << "Enter revenue's value" << endl;
		cin >> ch.Revenue;
		cout << "Enter rent time" << endl;
		cin >> ch.RentTime;
		cout << "Enter data" << endl;
	    ch.Data = getData();


		List_Check *node = new List_Check;
		node->check = ch;
		node->next = head_check;
		head_check = node;

		return ch;
	}

	void Delete_Check(int id)					//������� ������
	{	
		List_Check *temp = head_check;
		if (head_check->check.checkId == id)
		{
			head_check = head_check->next;
		}
		while (temp->next != NULL)
		{
			if (temp->next->check.checkId == id)
			{
				temp->next = temp->next->next;
				break;
			}
			temp = temp->next;
		}
		
	}

	Check EditCheck(int id)
	{
		List_Check *node = head_check;
		while (node->next != NULL && node->check.checkId != id)
		{
			node = node->next;
		}
		Check ch;
		char c;
		cout << "\n Enter data of changing check.\n ";
		cin.get(c);
		cout << "Enter ID of check" << endl;
		cin >> ch.checkId;
		cout << "Enter revenue if this ID" << endl;
		cin >> ch.Revenue;
		cout << "Enter rent time if this ID" << endl;
		cin >> ch.RentTime;
		cout << "Enter data if this ID" << endl;
		ch.Data = getData();
		node->check = ch;
		return ch;
	}

	void Write_into_file_check()
	{
		List_Check *node = head_check;
		char file3[200];
		cout << "������� ���� ������������ �����" << endl;
		char c;
		cin.get(c);
		cin.getline(file3, 200);
		out_stream.open(file3);
		while (node != NULL)
		{
			out_stream << node->check.checkId << " " << node->check.Revenue << "  " << node->check.RentTime << "  " << node->check.Data << endl;
			node = node->next;
		}
		out_stream.close();
	}

	void print_Check()											//����� ������ �� �����
	{
		printf("\n %10s! %15s! %10s! %10s!", "ID ������!  ������������!    ���� �� �������!  ID �����!");
		List_Check *node = head_check;
		while (node != NULL)
		{
			printf("\n %3d ! %30s! %4d! %4d ", node->check.checkId, node->check.Revenue, node->check.RentTime, node->check.Data);
			node = node->next;
		}
	}

	CaI push_CaI(int i)											//�������� �������� � ������ � ����������
	{
		CaI cai;
		char c;
		cout << "\n ������� ������ " << i + 1 << " ��������.\n ";
		cout << "�� �������� ��� �������� �������������" << endl;
		/*cin >> mov.id;*/
		List_CaI *node1 = head_cai;

		if (head_cai == NULL)
		{
			int counter = 0;
			while (node1 != NULL)
			{
				counter++;
				node1 = node1->next;
			}
			cai.caiID = counter + 1;
		}
		else
		{
			cai.caiID = node1->cai.clientID;
			cai.caiID = cai.caiID + 1;
		}
		cin.get(c);
		cout << "������� ID ���������� " << endl;
		string clientID;
		getline(cin, clientID);
		while (isNumber(clientID) == false)
		{
			cout << "�������� ������ ������" << endl;
			getline(cin, clientID);
		}
		/*mov.TovarID = atoi(tovid.c_str());*/
		cout << "������� ID ������" << endl;
		string informationID;
		getline(cin, informationID);
		while (isNumber(informationID) == false)
		{
			cout << "�������� ������ ������" << endl;
			getline(cin, informationID);
		}

		bool flag1 = false;
		bool flag2 = false;

		List_Client *temp3 = head_client;
		List_Information *temp4 = head_information;
		while (temp3 != NULL)
		{
			if (temp3->client.clientID == atoi(clientID.c_str()))
			{
				flag1 = true;
				break;
			}
			temp3 = temp3->next;
		}
		while (temp4 != NULL)
		{
			if (temp4->information.informationID == atoi(informationID.c_str()))   //��� ������
			{
				flag2 = true;
				break;
			}
			temp4 = temp4->next;
		}
		if (flag1 == true && flag2 == true)
		{
			cai.clientID = atoi(clientID.c_str());    // ��� ��� ������!
			cai.informationID = atoi(informationID.c_str());
			List_CaI *node = new List_CaI;
			node->cai = cai;
			node->next = head_cai;
			head_cai = node;

			return cai;
		}
		else
		{
			cout << "Danger!������� ������ � ��������!!!������ �� ���� ��������� � ������" << endl;
		}

	}
	      
	void Delete_CaI(int id)					//������� ������
	{
		List_Client *temp = head_client;
		List_Information *temp2 = head_information;
		List_CaI *temp3 = head_cai;
		//	ListMoving *temp5 = head5;
		//���� �������� �������� �� ������ �������
		if (head_cai->cai.caiID == id)
		{
			head_cai = head_cai->next;
		}
		while (temp3->next != NULL)
		{
			if (temp3->next->cai.caiID == id)
			{
				temp3->next = temp3->next->next;
				break;
			}
			temp3 = temp3->next;
		}
	}

	CaI EditCaI(int id)
	{
		List_CaI *node = head_cai;
		while (node->next != NULL && node->cai.caiID != id)
		{
			node = node->next;
		}
		CaI cai;
		char c;
		cout << "\n ������� ������ cai .\n "; // ��� ������ ���������
		cai.caiID = id;
		cin.get(c);
		cout << "������� ID  ������� " << endl;
		cin >> cai.clientID;
		cout << "������� ID ����������" << endl;
		cin >> cai.informationID;
		node->cai = cai;    // ������ ����� ���������
		return cai;
	}

	void Write_CaI_into_file()
	{
		List_CaI *node = head_cai;
		char file2[200];
		cout << "������� ���� ������������ �����" << endl;
		char c;
		cin.get(c);
		cin.getline(file2, 200);
		out_stream.open(file2);
		while (node != NULL)
		{
			out_stream << node->cai.caiID<< " " << node->cai.clientID << "  " << node->cai.informationID << "  " << endl;
			node = node->next;
		}
		out_stream.close();
	}

	void print_CaI()											//����� ������ �� �����
	{
		List_CaI *node = head_cai;
		cout << "ID ��������!  ID ����������!    ID ������! ";
		while (node != NULL)
		{
			printf("\n %3d!        %5d!       %10d!   ", node->cai.caiID, node->cai.clientID, node->cai.informationID);
			node = node->next;
		}
	}

	CaC push_CaC(int i)											//�������� �������� � ������ � ����������
	{
		CaC cac;
		char c;
		cout << "\n ������� ������ " << i + 1 << " �������� .\n ";
		cout << "�� �������� ��� �������� �������������" << endl;
		/*cin >> mov.id;*/
		List_CaC *node1 = head_cac;
		/*mov.id = node1->moves_goods.id;
		mov.id = mov.id + 1;*/
		if (head_cac == NULL)
		{
			int counter = 0;
			while (node1 != NULL)
			{
				counter++;
				node1 = node1->next;
			}
			cac.cacID = counter + 1;
		}
		else
		{
			cac.cacID = node1->cac.cacID;
			cac.cacID = cac.cacID + 1;
		}
		cin.get(c);
		cout << "������� ID ���������� " << endl;
		string clientID;
		getline(cin, clientID);
		while (isNumber(clientID) == false)
		{
			cout << "�������� ������ ������" << endl;
			getline(cin, clientID);
		}
		/*mov.TovarID = atoi(tovid.c_str());*/
		cout << "������� ID �������" << endl;
		string checkId;
		getline(cin, checkId);
		while (isNumber(checkId) == false)
		{
			cout << "�������� ������ ������" << endl;
			getline(cin, checkId);
		}
		/*mov.statusID = atoi(statid.c_str());*/
		cout << "������� ���������� ���������� ����� ������������ �������" << endl;
		string value_b;
		getline(cin, value_b);
		while (isNumber(value_b) == false)
		{
			cout << "�������� ������ ������" << endl;
			getline(cin, value_b);
		}
		/*mov.number = atoi(numb.c_str());
		cout << "������� ���� ���������� ��������" << endl;
		cout << "������� ���������� ���������� ����� ���������� �������" << endl;
		string time_l;
		getline(cin, time_l);
		while (isNumber(time_l) == false)
		{
			cout << "�������� ������ ������" << endl;
			getline(cin, time_l);
		}*/
		bool flag1 = false;
		bool flag2 = false;

		List_Client *temp3 = head_client;
		List_Check *temp4 = head_check;
		while (temp3 != NULL)
		{
			if (temp3->client.clientID == atoi(clientID.c_str()))   //������ ���
			{
				flag1 = true;
				break;
			}
			temp3 = temp3->next;
		}
		while (temp4 != NULL)
		{
			if (temp4->check.checkId == atoi(checkId.c_str()))  //��� ������
			{
				flag2 = true;
				break;
			}
			temp4 = temp4->next;
		}
		if (flag1 == true && flag2 == true)
		{
			cac.checkId = atoi(checkId.c_str());   //��� �������
			cac.clientID = atoi(clientID.c_str());
			List_CaC *node = new List_CaC;
			node->cac = cac;
			node->next = head_cac;
			head_cac = node;

			return cac;
		}
		else
		{
			cout << "Danger!������� ������ � ��������!!!������ �� ���� ��������� � ������" << endl;
		}

	}

	void Delete_CaC(int id)					//������� ������
	{
		List_Client *temp = head_client;
		List_Check *temp2 = head_check;
		List_CaC *temp3 = head_cac;
		if (head_cac->cac.cacID == id)
		{
			head_cac = head_cac->next;
		}
		while (temp3->next != NULL)
		{
			if (temp3->next->cac.cacID == id)
			{
				temp3->next = temp3->next->next;
				break;
			}
			temp3 = temp3->next;
		}
	}

	CaC EditCaC(int id)
	{
		List_CaC *node = head_cac;
		while (node->next != NULL && node->cac.cacID != id)
		{
			node = node->next;
		}
		CaC cac;
		char c;
		cout << "\n ������� ������ �������� .\n ";
		cac.cacID = id;
		cin.get(c);
		cout << "������� ID ����������" << endl;
		cin >> cac.checkId;
		cout << "������� ID �������" << endl;
		cin >> cac.clientID;
		cout << "������� ���������� ���������� �����" << endl;
		cin >> cac.value_b;
		node->cac = cac;                       //������
		return cac;
	}

	void Write_CaC_into_file()
	{
		List_CaC *node = head_cac;
		char file3[200];
		cout << "������� ���� ������������ �����" << endl;
		char c;
		cin.get(c);
		cin.getline(file3, 200);
		out_stream.open(file3);
		while (node != NULL)
		{
			out_stream << node->cac.cacID << " " << node->cac.checkId << "  " << node->cac.clientID << "  " << node->cac.value_b << "  " << endl;
			node = node->next;
		}
		out_stream.close();
	}

	void print_CaC()											//����� ������ �� �����
	{
		List_CaC *node = head_cac;
		cout << "ID ��������!  ID ����������!    ID �������!  ���������� ���������� �����! ���������� ������������ �����!";
		while (node != NULL)
		{
			printf("\n %3d!        %5d!       %10d!   %10d!    %10d! ", node->cac.cacID, node->cac.checkId, node->cac.clientID, node->cac.value_b);
			node = node->next;
		}
	}
	//-----------------------------------
	Client load_client_files(char(&file_dir)[100])
	{
		{
			Client t;
			char name[20];
			/*cout << "������� �������� ����� � ������" << endl;
			cin.getline(name, 20);*/
			strcat_s(file_dir, "Client.txt");
			in_stream.open(file_dir);
			if (!in_stream)
			{
				cout << "���� ��  ����������!" << endl;
			}
			if (in_stream)
			{
				while (!in_stream.eof())
				{
					in_stream >> t.clientID;
					in_stream >> t.C_name;
					in_stream >> t.type;
					List_Client *node = new List_Client;
					node->client= t;
					node->next = head_client;
					head_client = node;
				}
				in_stream.close();
				return t;
			}
		}

	}
	//--------------------------------------
	Information load_information_files(char(&file_dir)[100])
	{
		{
			Information inf;
			char name[20];
			/*cout << "������� �������� ����� � ������" << endl;
			cin.getline(name, 20);*/
			strcat_s(file_dir, "Information.txt");
			in_stream.open(file_dir);
			if (!in_stream)
			{
				cout << "���� ��  ����������!" << endl;
			}
			if (in_stream)
			{
				while (!in_stream.eof())
				{
					in_stream >> inf.informationID;
					in_stream >> inf.A_V;
					in_stream >> inf.Cd_DvD;
					List_Information *node = new List_Information;
					node->information = inf;
					node->next = head_information;
					head_information = node;
				}
				in_stream.close();
				return inf;
			}
		}

	}
	//---------------------------------------
	Check load_check_files(char(&file_dir)[100])
	{
		{
			Check ch;
			char name[20];
			/*cout << "������� �������� ����� � ������" << endl;
			cin.getline(name, 20);*/
			strcat_s(file_dir, "Check.txt");
			in_stream.open(file_dir);
			if (!in_stream)
			{
				cout << "���� ��  ����������!" << endl;
			}
			if (in_stream)
			{
				while (!in_stream.eof())
				{
					in_stream >> ch.checkId;
					in_stream >> ch.Data;
					in_stream >> ch.RentTime;
					in_stream >> ch.Revenue;
					List_Check *node = new List_Check;
					node->check = ch;
					node->next = head_check;
					head_check = node;
				}
				in_stream.close();
				return ch;
			}
		}

	}
	//------------------------------------------
	CaI load_cai_files(char(&file_dir)[100])
	{
		{
			CaI cai;
			char name[20];
			/*cout << "������� �������� ����� �� ������� �������" << endl;
			cin.getline(name, 20);*/
			strcat_s(file_dir, "CaI.txt");
			in_stream.open(file_dir);
			if (!in_stream)
			{
				cout << "���� ��  ����������!" << endl;
			}
			if (in_stream)
			{
				while (!in_stream.eof())
				{
					in_stream >> cai.caiID;
					in_stream >> cai.clientID;
					in_stream >> cai.informationID;
					List_CaI *node = new List_CaI;
					node->cai = cai;
					node->next = head_cai;
					head_cai = node;
				}
				in_stream.close();
				return cai;
			}
		}
	}
	//------------------------------------------
	CaC load_cac_files(char(&file_dir)[100])
	{
		{
			CaC cac;
			char name[20];
			/*cout << "������� �������� ����� �� ������� �������" << endl;
			cin.getline(name, 20);*/
			strcat_s(file_dir, "CaC.txt");
			in_stream.open(file_dir);
			if (!in_stream)
			{
				cout << "���� ��  ����������!" << endl;
			}
			if (in_stream)
			{
				while (!in_stream.eof())
				{
					in_stream >> cac.cacID;
					in_stream >> cac.checkId;
					in_stream >> cac.clientID;
					in_stream >> cac.value_b;
					List_CaC *node = new List_CaC;
					node->cac = cac;
					node->next = head_cac;
					head_cac = node;
				}
				in_stream.close();
				return cac;
			}
		}
	}
	//--------------------------------------
	//--------------------------------------
	void ReportOfDebt()
	{
		cout << "----------------------------------------------------------------------------\n";
		cout << "����� �� ������������ ��������\n\n";
		cout << "������� ����������� ����: " << endl;
		int Today = getData();
		cout << "\n������ ���������:\n";
		List_Client *node = head_client;
		while (node != NULL)
		{
			List_CaC * nodeCaC = head_cac;
			while (nodeCaC != NULL && (node->client.clientID != nodeCaC->cac.clientID))
			{
				nodeCaC = nodeCaC->next;
			}
			List_Check *nodecheck = head_check;
			while (nodecheck != NULL && (nodeCaC->cac.checkId != nodecheck->check.checkId))
			{
				nodecheck = nodecheck->next;
			}
			if ((Today - nodecheck->check.Data) > nodecheck->check.RentTime){
				cout << node->client.C_name << "\n";
			}
			node = node->next;
		}
		cout << "\n----------------------------------------------------------------------------\n";
	}
};





int main()
{
	setlocale(LC_ALL, "Russian");
	system("mode con cols=200 lines=59");
	Shop mas[5];
main_menu:
	int menu_lvl1;
	cout << "______________________________" << endl;
	cout << "�������� �������             |" << endl;
	cout << "1-������� 1..................|" << endl;
	cout << "2-������� 2..................|" << endl;
	cout << "3-������� 3..................|" << endl;
	cout << "4-������� 4..................|" << endl;
	cout << "5-������� 5..................|" << endl;
	cout << "0-�����......................|" << endl;
	cout << "_____________________________|" << endl;
	cout << "--> ������� ����� ���� " << endl;
	cout << "-->";
	cin >> menu_lvl1;
	while (!cin.good())
	{
		cin.clear();
		_flushall();
		cout << "������� ���������� ������" << endl;
		cin >> menu_lvl1;
	}
	switch (menu_lvl1)
	{
	case 1:

	sub_menu1 :
		cout << " _________������� 1___________________________________" << endl;
			  cout << "|1-��� �������                                       |" << endl;
			  cout << "|2-����������                                      |" << endl;
			  cout << "|3-����                                             |" << endl;
			  cout << "|4-����� ���������� � �������                                     |" << endl;
			  cout << "|5-����� ������� � �����                                |" << endl;
			  cout << "|-----------------------------------------------------|" << endl;
			  cout << "|6-��������� �� �� ������                             |" << endl;
			  cout << "|7-����� �1 - �� ���� ���������� �������� � �������   |" << endl;// �������!!!!!
			  cout << "|0-�����                                              |" << endl;
			  cout << "|_____________________________________________________|" << endl;
			  int sub_menu1_choise;
			  cout << "������� ����� ����" << endl;
			  cin >> sub_menu1_choise;
			  while (!cin.good())
			  {
				  cin.clear();
				  _flushall();
				  cout << "������� ���������� ������" << endl;
				  cin >> sub_menu1_choise;
			  }
			  switch (sub_menu1_choise)
			  {
			  case 1:
			  sub_menu1_t :
				  cout << "______________������______________________" << endl;
						  cout << "|1-�������� ������� � ����������           |" << endl;
						  cout << "|2-�������� ��� �������                   |" << endl;
						  cout << "|3-������� ������ � �������                |" << endl;
						  cout << "|4-������� ��� ������� �� �����            |" << endl;
						  cout << "|5-������� ��������� � ����                      |" << endl;
						  cout << "|6-�����                                         |" << endl;
						  cout << "|________________________________________________|" << endl;
						  int sub_menu1_t_choise;
						  cout << "������� ����� ����" << endl;
						  cin >> sub_menu1_t_choise;
						  while (!cin.good())
						  {
							  cin.clear();
							  _flushall();
							  cout << "������� ���������� ������" << endl;
							  cin >> sub_menu1_t_choise;
						  }
						  switch (sub_menu1_t_choise)
						  {
						  case 1:
							  int number_add_t;
							  cout << "������� ���������� ����������� �������" << endl;
							  cout << "-->";
							  cin >> number_add_t;
							  for (int i = 0; i < number_add_t; i++)
							  {
								  mas[0].push_Client(i);
							  }
							  cout << endl;
							  goto sub_menu1_t;
							  break;
						  case 2:
							  int id_editable_t;
							  cout << "������� ID ���������� ������ �������������" << endl;
							  cout << "-->";
							  cin >> id_editable_t;
							  mas[0].EditClient(id_editable_t);
							  cout << endl;
							  goto sub_menu1_t;
							  break;
						  case 3:
							  int id_delete_t;
							  cout << "������� ID ��������� ������ �������������" << endl;
							  cout << "-->";
							  cin >> id_delete_t;
							  mas[0].Delete_Client(id_delete_t);
							  cout << endl;
							  goto sub_menu1_t;
							  break;
						  case 4:
							  mas[0].print_Client();
							  cout << endl;
							  goto sub_menu1_t;
							  break;
						  case 5:
							  mas[0].Write_into_file_client();
							  cout << endl;
							  goto sub_menu1_t;
							  break;
						  case 6:
							  goto sub_menu1;
							  break;
						  default:
							  goto sub_menu1_t;
							  break;

						  }
						  break;
			  case 2:
			  sub_menu1_inf :
				  cout << "______________����������___________________________" << endl;
							cout << "|1-�������� ���������� � ����������                |" << endl;
							cout << "|2-�������� ����������                             |" << endl;
							cout << "|3-������� ����������                              |" << endl;
							cout << "|4-������� ����������  �� �����                     |" << endl;
							cout << "|5-������� ��������� � ����                        |" << endl;
							cout << "|6-�����                                           |" << endl;
							cout << "|__________________________________________________|" << endl;
							int sub_menu1_inf_choise;
							cout << "������� ����� ����" << endl;
							cin >> sub_menu1_inf_choise;
							while (!cin.good())
							{
								cin.clear();
								_flushall();
								cout << "������� ���������� ������" << endl;
								cin >> sub_menu1_inf_choise;
							}
							switch (sub_menu1_inf_choise)
							{
							case 1:
								int number_add_inf;
								cout << "������� ���������� ����������� ����������" << endl;
								cout << "-->";
								cin >> number_add_inf;
								for (int i = 0; i < number_add_inf; i++)
								{
									mas[0].push_information();
								}
								cout << endl;
								goto sub_menu1_inf;
								break;
							case 2:
								int id_editable_inf;
								cout << "������� ID ���������� ����������" << endl;
								cout << "-->";
								cin >> id_editable_inf;
								mas[0].EditInformation(id_editable_inf);
								cout << endl;
								goto sub_menu1_inf;
								break;
							case 3:
								int id_delete_inf;
								cout << "������� ID ��������� ���������� " << endl;
								cout << "-->";
								cin >> id_delete_inf;
								mas[0].Delete_Information(id_delete_inf);
								cout << endl;
								goto sub_menu1_inf;
								break;
							case 4:
								mas[0].print_Information();
								cout << endl;
								goto sub_menu1_inf;
								break;
							case 5:
								mas[0].Write_into_Information_file();
								cout << endl;
								goto sub_menu1_inf;
								break;
							case 6:
								goto sub_menu1;
								break;
							default:
								goto sub_menu1_inf;
								break;
							}
							//--------------------------------------------------------------------------------------
							break;
			  case 3:
			  sub_menu1_ch :
				  cout << "______________����______________________________" << endl;
						  cout << "|1-�������� ���� � ����������                    |" << endl;
						  cout << "|2-�������� ������ �� �����                        |" << endl;
						  cout << "|3-������� ������ �� �����                         |" << endl;
						  cout << "|4-������� ������ �� �����  �� �����                |" << endl;
						  cout << "|5-������� ��������� � ����                        |" << endl;
						  cout << "|6-�����                                           |" << endl;
						  cout << "|__________________________________________________|" << endl;
						  int sub_menu1_ch_choise;
						  cout << "������� ����� ����" << endl;
						  cin >> sub_menu1_ch_choise;
						  while (!cin.good())
						  {
							  cin.clear();
							  _flushall();
							  cout << "������� ���������� ������" << endl;
							  cin >> sub_menu1_choise;
						  }

						  switch (sub_menu1_ch_choise)
						  {
						  case 1:
							  int number_add_ch;
							  cout << "������� ���������� ����������� ������" << endl;
							  cout << "-->";
							  cin >> number_add_ch;
							  for (int i = 0; i < number_add_ch; i++)
							  {
								  mas[0].push_check(i);
							  }
							  cout << endl;
							  goto sub_menu1_ch;
							  break;
						  case 2:
							  int id_editable_ch;
							  cout << "������� ID ����������� �����" << endl;
							  cout << "-->";
							  cin >> id_editable_ch;
							  mas[0].EditCheck(id_editable_ch);
							  cout << endl;
							  goto sub_menu1_ch;
							  break;
						  case 3:
							  int id_delete_ch;
							  cout << "������� ID ���������� �����" << endl;
							  cout << "-->";
							  cin >> id_delete_ch;
							  mas[0].Delete_Check(id_delete_ch);
							  cout << endl;
							  goto sub_menu1_ch;
							  break;
						  case 4:
							  mas[0].print_Check();
							  cout << endl;
							  goto sub_menu1_ch;
							  break;
						  case 5:
							  mas[0].Write_into_file_check();
							  cout << endl;
							  goto sub_menu1_ch;
							  break;
						  case 6:
							  goto sub_menu1;
							  break;
						  default:
							  goto sub_menu1_ch;
							  break;
						  }


						  //--------------------------------------------------------------------------------------
						  break;
			  case 4:
			  sub_menu1_cai :
				  cout << "________����� ���������� � ������� _________________" << endl;
							cout << "|1-�������� ����� � ����������                     |" << endl;
							cout << "|2-�������� ������ �����                           |" << endl;
							cout << "|3-������� ������ � �����                          |" << endl;
							cout << "|4-������� ������ � ���������� �� �����            |" << endl;
							cout << "|5-������� ��������� � ����                        |" << endl;
							cout << "|6-�����                                           |" << endl;
							cout << "|__________________________________________________|" << endl;
							int sub_menu1_cai_choise;
							cout << "������� ����� ����" << endl;
							cin >> sub_menu1_cai_choise;
							while (!cin.good())
							{
								cin.clear();
								_flushall();
								cout << "������� ���������� ������" << endl;
								cin >> sub_menu1_cai_choise;
							}

							switch (sub_menu1_cai_choise)
							{

							case 1:
								int number_add_cai;
								cout << "������� ���������� ����������� ������" << endl;
								cout << "-->";
								cin >> number_add_cai;
								for (int i = 0; i < number_add_cai; i++)
								{
									mas[0].push_CaI(i);
								}
								cout << endl;
								goto sub_menu1_cai;
								break;
							case 2:
								int id_editable_cai;
								cout << "������� ID ����������� ���� �����" << endl;
								cout << "-->";
								cin >> id_editable_cai;
								mas[0].EditCaI(id_editable_cai);
								cout << endl;
								goto sub_menu1_cai;
								break;
							case 3:
								int id_delete_cai;
								cout << "������� ID ���������� ���� ������" << endl;
								cout << "-->";
								cin >> id_delete_cai;
								mas[0].Delete_CaI(id_delete_cai);
								cout << endl;
								goto sub_menu1_cai;
								break;
							case 4:
								mas[0].print_CaI();
								cout << endl;
								goto sub_menu1_cai;
								break;
							case 5:
								mas[0].Write_CaI_into_file();
								cout << endl;
								goto sub_menu1_cai;
								break;
							case 6:
								goto sub_menu1;
								break;
							default:
								goto sub_menu1_cai;
								break;
							}

							//-------------------------------------------------------------------------------------
							break;
			  case 5:
			  sub_menu1_cac :
				  cout << "_________����� ������� � �����_________" << endl;
							cout << "|1-�������� �������� � ����������                  |" << endl;
							cout << "|2-�������� ������ �� ��������                     |" << endl;
							cout << "|3-������� ������ �� ��������                      |" << endl;
							cout << "|4-������� ������ �� ��������� �� �����            |" << endl;
							cout << "|5-������� ��������� � ����                        |" << endl;
							cout << "|6-�����                                           |" << endl;
							cout << "|__________________________________________________|" << endl;
							int sub_menu1_cac_choise;
							cout << "������� ����� ����" << endl;
							cin >> sub_menu1_cac_choise;

							switch (sub_menu1_cac_choise)
							{
							case 1:
								int number_add_cac;
								cout << "������� ���������� ����������� ��������" << endl;
								cout << "-->";
								cin >> number_add_cac;
								for (int i = 0; i < number_add_cac; i++)
								{
									mas[0].push_CaC(i);
								}
								cout << endl;
								goto sub_menu1_cac;
								break;
							case 2:
								int id_editable_cac;
								cout << "������� ID ���������� ��������" << endl;
								cout << "-->";
								cin >> id_editable_cac;
								mas[0].EditCaC(id_editable_cac);
								cout << endl;
								goto sub_menu1_cac;
								break;
							case 3:
								int id_delete_cac;
								cout << "������� ID ��������� �������� " << endl;
								cout << "-->";
								cin >> id_delete_cac;
								mas[0].Delete_CaC(id_delete_cac);
								cout << endl;
								goto sub_menu1_cac;
								break;
							case 4:
								mas[0].print_CaC();
								cout << endl;
								goto sub_menu1_cac;
								break;
							case 5:
								mas[0].Write_CaC_into_file();
								cout << endl;
								goto sub_menu1_cac;
								break;
							case 6:
								goto sub_menu1;
								break;
							default:
								goto sub_menu1_cac;
								break;
							}


							//-------------------------------------------------------------------------------------
							break;

			  case 6:
				  char c, file_dir[100];
				  cout << "������� ���� �� ������" << endl;
				  cin.get(c);
				  cin.getline(file_dir, 100);
				  char file_dir_m[100];
				  strcpy_s(file_dir_m, file_dir);
				  char file_dir_g[100];
				  strcpy_s(file_dir_g, file_dir);
				  char file_dir_mt[100];
				  strcpy_s(file_dir_mt, file_dir);
				  char file_dir_mov[100];
				  strcpy_s(file_dir_mov, file_dir);
				  mas[0].load_client_files(file_dir);
				  mas[0].load_information_files(file_dir_m);
				  mas[0].load_check_files(file_dir_g);
				  mas[0].load_cai_files(file_dir_mt);
				  mas[0].load_cac_files(file_dir_mov);
				  goto sub_menu1;
				  break;
			  case 7:
				  mas[0].ReportOfDebt();
				  goto sub_menu1;
				  break;
			  case 0:
				  cout << "exit" << endl;
				  goto main_menu;
				  break;
			  default:
				  goto sub_menu1;
				  break;
			  }

		  sub_menu2:
			  cout << " _________������� 2___________________________________" << endl;
			  cout << "|1-��� �������                                       |" << endl;
			  cout << "|2-����������                                      |" << endl;
			  cout << "|3-����                                             |" << endl;
			  cout << "|4-����� ���������� � �������                                     |" << endl;
			  cout << "|5-����� ������� � �����                                |" << endl;
			  cout << "|-----------------------------------------------------|" << endl;
			  cout << "|6-��������� �� �� ������                             |" << endl;
			  cout << "|7-����� �1 - �� ���� ���������� �������� � �������   |" << endl;// �������!!!!!
			  cout << "|0-�����                                              |" << endl;
			  cout << "|_____________________________________________________|" << endl;
			  int sub_menu2_choise;
			  cout << "������� ����� ����" << endl;
			  cin >> sub_menu1_choise;
			  while (!cin.good())
			  {
				  cin.clear();
				  _flushall();
				  cout << "������� ���������� ������" << endl;
				  cin >> sub_menu2_choise;
			  }
			  switch (sub_menu2_choise)
			  {
			  case 1:
			  sub_menu2_t :
				  cout << "______________������______________________" << endl;
						  cout << "|1-�������� ������� � ����������           |" << endl;
						  cout << "|2-�������� ��� �������                   |" << endl;
						  cout << "|3-������� ������ � �������                |" << endl;
						  cout << "|4-������� ��� ������� �� �����            |" << endl;
						  cout << "|5-������� ��������� � ����                      |" << endl;
						  cout << "|6-�����                                         |" << endl;
						  cout << "|________________________________________________|" << endl;
						  int sub_menu2_t_choise;
						  cout << "������� ����� ����" << endl;
						  cin >> sub_menu2_t_choise;
						  while (!cin.good())
						  {
							  cin.clear();
							  _flushall();
							  cout << "������� ���������� ������" << endl;
							  cin >> sub_menu2_t_choise;
						  }
						  switch (sub_menu2_t_choise)
						  {
						  case 1:
							  int number_add_t;
							  cout << "������� ���������� ����������� �������" << endl;
							  cout << "-->";
							  cin >> number_add_t;
							  for (int i = 0; i < number_add_t; i++)
							  {
								  mas[0].push_Client(i);
							  }
							  cout << endl;
							  goto sub_menu2_t;
							  break;
						  case 2:
							  int id_editable_t;
							  cout << "������� ID ���������� ������ �������������" << endl;
							  cout << "-->";
							  cin >> id_editable_t;
							  mas[0].EditClient(id_editable_t);
							  cout << endl;
							  goto sub_menu2_t;
							  break;
						  case 3:
							  int id_delete_t;
							  cout << "������� ID ��������� ������ �������������" << endl;
							  cout << "-->";
							  cin >> id_delete_t;
							  mas[0].Delete_Client(id_delete_t);
							  cout << endl;
							  goto sub_menu2_t;
							  break;
						  case 4:
							  mas[0].print_Client();
							  cout << endl;
							  goto sub_menu2_t;
							  break;
						  case 5:
							  mas[0].Write_into_file_client();
							  cout << endl;
							  goto sub_menu2_t;
							  break;
						  case 6:
							  goto sub_menu2;
							  break;
						  default:
							  goto sub_menu2_t;
							  break;

						  }
						  break;
			  case 2:
			  sub_menu2_inf :
				  cout << "______________����������___________________________" << endl;
							cout << "|1-�������� ���������� � ����������                |" << endl;
							cout << "|2-�������� ����������                             |" << endl;
							cout << "|3-������� ����������                              |" << endl;
							cout << "|4-������� ����������  �� �����                     |" << endl;
							cout << "|5-������� ��������� � ����                        |" << endl;
							cout << "|6-�����                                           |" << endl;
							cout << "|__________________________________________________|" << endl;
							int sub_menu2_inf_choise;
							cout << "������� ����� ����" << endl;
							cin >> sub_menu2_inf_choise;
							while (!cin.good())
							{
								cin.clear();
								_flushall();
								cout << "������� ���������� ������" << endl;
								cin >> sub_menu2_inf_choise;
							}
							switch (sub_menu2_inf_choise)
							{
							case 1:
								int number_add_inf;
								cout << "������� ���������� ����������� ����������" << endl;
								cout << "-->";
								cin >> number_add_inf;
								for (int i = 0; i < number_add_inf; i++)
								{
									mas[0].push_information();
								}
								cout << endl;
								goto sub_menu2_inf;
								break;
							case 2:
								int id_editable_inf;
								cout << "������� ID ���������� ����������" << endl;
								cout << "-->";
								cin >> id_editable_inf;
								mas[0].EditInformation(id_editable_inf);
								cout << endl;
								goto sub_menu2_inf;
								break;
							case 3:
								int id_delete_inf;
								cout << "������� ID ��������� ���������� " << endl;
								cout << "-->";
								cin >> id_delete_inf;
								mas[0].Delete_Information(id_delete_inf);
								cout << endl;
								goto sub_menu2_inf;
								break;
							case 4:
								mas[0].print_Information();
								cout << endl;
								goto sub_menu2_inf;
								break;
							case 5:
								mas[0].Write_into_Information_file();
								cout << endl;
								goto sub_menu2_inf;
								break;
							case 6:
								goto sub_menu2;
								break;
							default:
								goto sub_menu2_inf;
								break;
							}
							//--------------------------------------------------------------------------------------
							break;
			  case 3:
			  sub_menu2_ch :
				  cout << "______________����______________________________" << endl;
						   cout << "|1-�������� ���� � ����������                    |" << endl;
						   cout << "|2-�������� ������ �� �����                        |" << endl;
						   cout << "|3-������� ������ �� �����                         |" << endl;
						   cout << "|4-������� ������ �� �����  �� �����                |" << endl;
						   cout << "|5-������� ��������� � ����                        |" << endl;
						   cout << "|6-�����                                           |" << endl;
						   cout << "|__________________________________________________|" << endl;
						   int sub_menu2_ch_choise;
						   cout << "������� ����� ����" << endl;
						   cin >> sub_menu2_ch_choise;
						   while (!cin.good())
						   {
							   cin.clear();
							   _flushall();
							   cout << "������� ���������� ������" << endl;
							   cin >> sub_menu2_choise;
						   }

						   switch (sub_menu2_ch_choise)
						   {
						   case 1:
							   int number_add_ch;
							   cout << "������� ���������� ����������� ������" << endl;
							   cout << "-->";
							   cin >> number_add_ch;
							   for (int i = 0; i < number_add_ch; i++)
							   {
								   mas[0].push_check(i);
							   }
							   /*mas[0].print_goods();*/
							   cout << endl;
							   goto sub_menu2_ch;
							   break;
						   case 2:
							   int id_editable_ch;
							   cout << "������� ID ����������� �����" << endl;
							   cout << "-->";
							   cin >> id_editable_ch;
							   mas[0].EditCheck(id_editable_ch);
							   cout << endl;
							   goto sub_menu2_ch;
							   break;
						   case 3:
							   int id_delete_ch;
							   cout << "������� ID ���������� �����" << endl;
							   cout << "-->";
							   cin >> id_delete_ch;
							   mas[0].Delete_Check(id_delete_ch);
							   cout << endl;
							   goto sub_menu2_ch;
							   break;
						   case 4:
							   mas[0].print_Check();
							   cout << endl;
							   goto sub_menu2_ch;
							   break;
						   case 5:
							   mas[0].Write_into_file_check();
							   cout << endl;
							   goto sub_menu2_ch;
							   break;
						   case 6:
							   goto sub_menu2;
							   break;
						   default:
							   goto sub_menu2_ch;
							   break;
						   }


						   //--------------------------------------------------------------------------------------
						   break;
			  case 4:
			  sub_menu2_cai :
				  cout << "________����� ���������� � ������� _________________" << endl;
							cout << "|1-�������� ����� � ����������                     |" << endl;
							cout << "|2-�������� ������ �����                           |" << endl;
							cout << "|3-������� ������ � �����                          |" << endl;
							cout << "|4-������� ������ � ���������� �� �����            |" << endl;
							cout << "|5-������� ��������� � ����                        |" << endl;
							cout << "|6-�����                                           |" << endl;
							cout << "|__________________________________________________|" << endl;
							int sub_menu2_cai_choise;
							cout << "������� ����� ����" << endl;
							cin >> sub_menu2_cai_choise;
							while (!cin.good())
							{
								cin.clear();
								_flushall();
								cout << "������� ���������� ������" << endl;
								cin >> sub_menu2_cai_choise;
							}

							switch (sub_menu2_cai_choise)
							{

							case 1:
								int number_add_cai;
								cout << "������� ���������� ����������� ������" << endl;
								cout << "-->";
								cin >> number_add_cai;
								for (int i = 0; i < number_add_cai; i++)
								{
									mas[0].push_CaI(i);
								}
								cout << endl;
								goto sub_menu2_cai;
								break;
							case 2:
								int id_editable_cai;
								cout << "������� ID ����������� ���� �����" << endl;
								cout << "-->";
								cin >> id_editable_cai;
								mas[0].EditCaI(id_editable_cai);
								cout << endl;
								goto sub_menu2_cai;
								break;
							case 3:
								int id_delete_cai;
								cout << "������� ID ���������� ���� ������" << endl;
								cout << "-->";
								cin >> id_delete_cai;
								mas[0].Delete_CaI(id_delete_cai);
								cout << endl;
								goto sub_menu2_cai;
								break;
							case 4:
								mas[0].print_CaI();
								cout << endl;
								goto sub_menu2_cai;
								break;
							case 5:
								mas[0].Write_CaI_into_file();
								cout << endl;
								goto sub_menu2_cai;
								break;
							case 6:
								goto sub_menu2;
								break;
							default:
								goto sub_menu2_cai;
								break;
							}

							//-------------------------------------------------------------------------------------
							break;
			  case 5:
			  sub_menu2_cac :
				  cout << "_________����� ������� � �����_________" << endl;
							cout << "|1-�������� �������� � ����������                  |" << endl;
							cout << "|2-�������� ������ �� ��������                     |" << endl;
							cout << "|3-������� ������ �� ��������                      |" << endl;
							cout << "|4-������� ������ �� ��������� �� �����            |" << endl;
							cout << "|5-������� ��������� � ����                        |" << endl;
							cout << "|6-�����                                           |" << endl;
							cout << "|__________________________________________________|" << endl;
							int sub_menu2_cac_choise;
							cout << "������� ����� ����" << endl;
							cin >> sub_menu2_cac_choise;

							switch (sub_menu2_cac_choise)
							{
								/*case 1:
								char c, file_dir[100];
								cout << "������� ���� �� ������" << endl;
								cin.get(c);
								cin.getline(file_dir, 100);
								mas[0].ReadMovesFromFile(file_dir);
								cout << endl;
								goto sub_menu1_moves;
								break;*/
							case 1:
								int number_add_cac;
								cout << "������� ���������� ����������� ��������" << endl;
								cout << "-->";
								cin >> number_add_cac;
								for (int i = 0; i < number_add_cac; i++)
								{
									mas[0].push_CaC(i);
								}
								cout << endl;
								goto sub_menu2_cac;
								break;
							case 2:
								int id_editable_cac;
								cout << "������� ID ���������� ��������" << endl;
								cout << "-->";
								cin >> id_editable_cac;
								mas[0].EditCaC(id_editable_cac);
								cout << endl;
								goto sub_menu2_cac;
								break;
							case 3:
								int id_delete_cac;
								cout << "������� ID ��������� �������� " << endl;
								cout << "-->";
								cin >> id_delete_cac;
								mas[0].Delete_CaC(id_delete_cac);
								cout << endl;
								goto sub_menu2_cac;
								break;
							case 4:
								mas[0].print_CaC();
								cout << endl;
								goto sub_menu2_cac;
								break;
							case 5:
								mas[0].Write_CaC_into_file();
								cout << endl;
								goto sub_menu2_cac;
								break;
							case 6:
								goto sub_menu2;
								break;
							default:
								goto sub_menu2_cac;
								break;
							}


							//-------------------------------------------------------------------------------------
							break;

			  case 6:
				  char c, file_dir[100];
				  cout << "������� ���� �� ������" << endl;
				  cin.get(c);
				  cin.getline(file_dir, 100);
				  char file_dir_m[100];
				  strcpy_s(file_dir_m, file_dir);
				  char file_dir_g[100];
				  strcpy_s(file_dir_g, file_dir);
				  char file_dir_mt[100];
				  strcpy_s(file_dir_mt, file_dir);
				  char file_dir_mov[100];
				  strcpy_s(file_dir_mov, file_dir);
				  mas[0].load_client_files(file_dir);
				  mas[0].load_information_files(file_dir_m);
				  mas[0].load_check_files(file_dir_g);
				  mas[0].load_cai_files(file_dir_mt);
				  mas[0].load_cac_files(file_dir_mov);
				  goto sub_menu1;
				  break;
			  case 7:
				  mas[0].ReportOfDebt();
				  goto sub_menu2;
				  break;
			  case 0:
				  cout << "exit" << endl;
				  goto main_menu;
				  break;
			  default:
				  goto sub_menu2;
				  break;
			  }

			  break;

						case 3:
							cout << "3" << endl;
							break;
						case 4:
							cout << "4" << endl;
							break;
						case 5:
							cout << "5" << endl;
							break;
						case 0:
							cout << "����� �� ���������..." << endl;
							exit(EXIT_SUCCESS);
							break;
						default:
							goto main_menu;
							break;
			  }
			  system("pause");
}

