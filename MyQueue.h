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
	cout<<"*********\n";

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
		cout<<Rus("��������� �� ����� ���� ������  ��� ����� ���� � ������ 100 \n");
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




/*
Queue CreatNode(int n) //�������� ������
{
	int i;
	Queue curr;
	Queue Head;
	Head=new List;
	curr=Head;
	cout<<Rus("������� ������: \n");
	for(i=0;i<n;i++)
		{
		cin>>curr->priority;
		curr->next=new(List);
		if (i == n-1) curr->next=NULL;
			else curr=curr->next;
		}
	return Head;
}

void ShowStack(Queue &head)	//�������� c�����
{	
	cout<<Rus("����� ������ �� �����: ");
	Queue curr;
	curr=head;
	for(;curr!=NULL;) 
		{
		cout<<curr->priority<<" ";
		curr=curr->next;
		}
	cout<<endl;
}

Queue Find(Queue &head, int n) //����� ��������
{
	int i;
	Queue curr,temp;
	curr=head;
	for(i=0;i!=n;i++) 
		{
		temp=curr;
		curr=curr->next;
		}
	return temp;
}

void ReplaceNode(Queue &head) //������ ��������� � ������
{
	Queue a,b;
	int n1,n2,c;
	cout<<Rus("����� �������� �������� �������? \n");
	cin>>n1;
	a=Find(head,n1); 
	cout<< "a=" << a->priority <<endl;
	cin>>n2;
	b=Find(head,n2); 
	cout<< "b=" << b->priority <<endl;
	c=a->priority;
	a->priority=b->priority;
	b->priority=c;	
}
*/