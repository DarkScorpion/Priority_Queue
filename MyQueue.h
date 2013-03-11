#include <windows.h>
#include <string.h>

#define maxLength 25
#define maxPriority 100

//������� ��� ���������� ����������� ��������
char*Rus(const char* text);
char bufRus[256];
char* Rus(const char* text)
	{
	CharToOem(text, bufRus);
	return bufRus;
	}
//��������� ������-�������
struct List
{
	int priority;
	string task;
	List *next;
};
typedef List *Queue;

//������� �������� �������
Queue CreateQueue()
{
	string strInput = "start"; 
	Queue head = new List;
	head->priority = 0;	
	head->task = strInput;
	head->next = NULL;
	return head;
}
//������� ������ ������� �� �����
void PrintQueue(Queue &Start)
{
	Queue curr = Start;
	if (curr->next == NULL) {cout<<Rus("� ������� ��� �����!\n"); return;}
		else curr = curr->next;
	cout<<Rus("��� ������\t ���������\n");
	while(true) //����� ���������� ��������� ������
	{
		cout<<curr->task;
		cout<<"\t\t\t";
		cout<<curr->priority;
		cout<<"\n";
		if (curr->next == NULL) break; //����� �� ����� �������� ������
			else curr = curr->next;
	}
	cout<<"**************************\n";

}

//������� ���������� �������� � �������
void AddTask(Queue &head)
{
	int z;
	string strInput;
	//���������� ������
	cout<<Rus("������� ��������� �������: ");
	cin>>z;
	if (z<=0 || z>maxPriority) //�������� ������������ �����
		{
		cout<<Rus("��������� �� ����� ���� ������ ��� ����� ���� � ������ 100 \n");
		return;
		}
	cout<<Rus("������� �������� ������: ");
	cin>>strInput;
	/*
	if (strlen(strInput) > maxLength) //�������� ������������ ����� //(������ ���������� 25, ����� ������)
		{
		cout<<Rus("������� ������� �������� \n");
		return;
		}
	*/
	// ����� ����� �����
	Queue curr = head;
	for(;curr->next!=NULL;)
		curr=curr->next;
	//�������� ������ ���������� ������
	curr->next = new List;
	curr = curr->next;
	//���� ���������� ������
	curr->priority = z;
	curr->task = strInput;
	curr->next = NULL;
}

//����� ��������� �� ������� � �������� ������� �����������
Queue GetMaxPriority_Pointer(Queue &head)
{	
	Queue taget;
	int maxPrior = 0;
	Queue curr = head;
	if (curr->next == NULL) return NULL;
		else curr = curr->next;
	//����� ������������ �� ���������� ������
	while(true)
	{
		if(curr->priority > maxPrior)
		{
			taget = curr;
			maxPrior = curr->priority;
		}
	if (curr->next == NULL) break;
		else curr = curr->next;
	}
	return taget;
}

//����� �������� � ��������� �����������
void PeekAtNext(Queue &head)
{
	Queue taget = GetMaxPriority_Pointer(head);
	if (taget == NULL) 
	{
		cout<<Rus("� ������� ��� �����!\n");
		return;
	}
	cout<<Rus("������ � ������ �����������: ")<<taget->task<<endl;
	cout<<Rus("���������: ")<<taget->priority<<endl;
}
/*
//���������� �������� � ��������� �����������
void GetNext(Queue &head)
{



}
*/
