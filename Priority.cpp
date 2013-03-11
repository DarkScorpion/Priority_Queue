#include <iostream.h>
#include "MyQueue.h"
/*
#define strInro "Нажмите: \n\
1 - Для добавления нового элемента очереди\n\
2 - Для вывода очереди на экран\n\
3 - Для вывода на экран наиболее приоретеной задачи без извлечения\n\
4 - Для извлечения наиболее приорететной задачи\n\
0 - Для выхода из программы\n"
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
			case (3): PeekAtNext(Queue_Start); break;
		}
		
		if (z==0) break; //Выход из главного цикла
	}
	cout<<Rus("Конец работы программы!");
}