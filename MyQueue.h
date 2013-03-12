#include <windows.h>
#include <string.h>

//#define maxLength 25
#define maxPriority 100

//Функция для коректного отображения кирилицы
char*Rus(const char* text);
char bufRus[256];
char* Rus(const char* text)
	{
	CharToOem(text, bufRus);
	return bufRus;
	}
//Структура списка-очереди
struct List
{
	int priority;
	string task;
	List *next;
};
typedef List *Queue;

//Функция создания очереди и возврощение указателя на головной элемент
Queue CreateQueue()
{
	string strInput = "start"; 
	Queue head = new List;
	head->priority = 0;	
	head->task = strInput;
	head->next = NULL;
	return head;
}
//Функция вывода очереди на экран
void PrintQueue(Queue &Start)
{
	Queue curr = Start;
	if (curr->next == NULL) {cout<<Rus("В очереди нет задач!\n"); return;}
		else curr = curr->next;
	cout<<Rus("Имя задачи\t Приоретет\n");
	while(true) //Вывод поочередно элементов списка
	{
		cout<<curr->task;
		cout<<"\t\t\t";
		cout<<curr->priority;
		cout<<"\n";
		if (curr->next == NULL) break; //Выход из цикла перебора списка
			else curr = curr->next;
	}
	cout<<"**************************\n";
}

//Функция добавления элемента в очередь
void AddTask(Queue &head)
{
	int z;
	string strInput;
	//Считывание данных
	cout<<Rus("Введите приоретет задания: ");
	cin>>z;
	if (z<=0 || z>maxPriority) //Приверка правильности ввода
		{
		cout<<Rus("Приоретет не может быть меньше или равен нулю и больше 100 \n");
		return;
		}
	cout<<Rus("Введите описание задачи: ");
	cin>>strInput;
	/*
	if (strlen(strInput) > maxLength) //Приверка правильности ввода //(всегда возврощает 25, нужна строка)
		{
		cout<<Rus("Слишком длинное описание \n");
		return;
		}
	*/
	// Поиск конца спика
	Queue curr = head;
	for(;curr->next!=NULL;)
		curr=curr->next;
	//Создание нового экземпляра списка
	curr->next = new List;
	curr = curr->next;
	//Ввод полученных данных
	curr->priority = z;
	curr->task = strInput;
	curr->next = NULL;
}

//Поиск указателя на элемент с наиболее высоким приорететом
Queue GetMaxPriority_Pointer(Queue &head)
{	
	Queue taget;
	int maxPrior = 0;
	Queue curr = head;
	if (curr->next == NULL) return NULL;
		else curr = curr->next;
	//Поиск максимальной по приоретету задачи
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

//Вывод элемента с наивысшим приорететом без извлечения
void PeekAtNext(Queue &head)
{
	Queue taget = GetMaxPriority_Pointer(head);
	if (taget == NULL) //Проверка возрощаймого значения
	{
		cout<<Rus("В очереди нет задач!\n");
		return;
	}
	cout<<Rus("Задача с высшим приорететом: ")<<taget->task<<endl;
	cout<<Rus("Приоретет задачи: ")<<taget->priority<<endl;
}

//Извлечение элемента с наивысшим приорететом
void GetNext(Queue &head)
{
	Queue a,b;
	a = GetMaxPriority_Pointer(head); //Получение ссылки на приорететный элемент
	if (a == NULL) //Проверка возрощаймого значения
	{
		cout<<Rus("В очереди нет задач!\n");
		return;
	}
	b = head; //Ссылка на первый элемент списка
	for(;b->next!=a;) //Поиск элемента перед приорететным
		b = b->next;
	cout<<Rus("Извлечённая задача: ")<< a->task <<endl;
	cout<<Rus("Приоретет задачи: ")<< a->priority <<endl;
	b->next = a->next; //Перенос указателя
	delete(a); //Освобождение памяти
}

