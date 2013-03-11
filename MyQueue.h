#include <windows.h>
#include <string.h>

#define maxLength 25
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

//Функция создания очереди
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

//Извлечение элемента с наивысшим приорететом
void PeekAtNext(Queue &head)
{
	int maxPrior = 0;
	Queue taget;
	Queue curr = head;
	if (curr->next == NULL) {cout<<Rus("В очереди нет задач!\n"); return;}
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
	cout<<Rus("Задача с высшим приорететом: ")<<taget->task<<endl;
	cout<<Rus("Приоретет: ")<<taget->priority<<endl;
}

/*
Queue Find(Queue &head, int n) //Поиск элемента
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

void ReplaceNode(Queue &head) //Замена элементов в списке
{
	Queue a,b;
	int n1,n2,c;
	cout<<Rus("Какие элементы поменять местами? \n");
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