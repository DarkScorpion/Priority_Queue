#include <iostream.h>
#include "MyQueue.h"

#define strIntro "�������: \n\
1 - ��� ���������� ������ �������� �������\n\
2 - ��� ������ ������� �� �����\n\
3 - ��� ������ �� ����� �������� ����������� ������ ��� ����������\n\
4 - ��� ���������� �������� ������������ ������\n\
0 - ��� ������ �� ���������\n"

void main()
{
	int z;
	Queue Queue_Start;
	Queue_Start = CreateQueue(); //�������� �������
	cout<<Rus(strIntro);
	while(true)
	{
		cout<<Rus("$> ");
		cin>>z;
		switch (z)
		{
			case (1): AddTask(Queue_Start); break;  //���������� �������� � �������
			case (2): PrintQueue(Queue_Start); break; //����� �� ����� ��������� �������
			case (3): PeekAtNext(Queue_Start); break; //����� �� ����� ������������ ��������
			case (4): GetNext(Queue_Start); break;	//���������� �� ������� ������������� ��������
			case (0): cout<<Rus("������ ��������� ��������!"); return; //����� �� ���������
			default: cout<<Rus("������������ ����, ���������� �����!\n");
		}
		//if (z==0) break; //����� �� �������� �����
	}
	//cout<<Rus("����� ������ ���������!");
}