#include <iostream.h>
#include "MyQueue.h"
/*
#define strInro "�������: \n\
1- ��� ���������� ������ �������� �������\n\
2- ��� ������ ������� �� �����\n\
3- ��� ���������� �������� ������������ ������\n\
0- ��� ������ �� ���������\n"
*/
void main()
{
	int z;
	Queue Queue_Start;
	Queue_Start = CreateQueue();
	while(true)
	{
		cout<<Rus("$ ");
		cin>>z;
		switch (z)
		{
			case (1): AddTask(Queue_Start); break;
			case (2): PrintQueue(Queue_Start); break;
		}
		
		if (z==0) break; //����� �� �������� �����
	}
	cout<<Rus("����� ������ ���������!");
}