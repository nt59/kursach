struct Client
{
	int clientID;
	char C_name[100];
	bool type;
};

struct Information
{
	int informationID;
	char A_V[100];
	char Cd_DvD[100];

};

struct Check
{
	int checkId;
	int Revenue;
	int RentTime;
	int Data;
};

struct CaI   //связь информации и клиента
{
	int caiID;
	int clientID;
	int informationID;
};

struct CaC   //связь клиента и проверки
{
	int cacID;
	int clientID;
	int checkId;
	int value_b; // колличество покупок
};

struct List_Client
{
	Client client;
	List_Client *next;
};

struct List_Information
{
	Information information;
	List_Information *next;
};

struct List_Check
{
	Check check;
	List_Check *next;
};


struct List_CaI
{
	CaI cai;
	List_CaI *next;
};

struct List_CaC
{
	CaC cac;
	List_CaC  *next;
};