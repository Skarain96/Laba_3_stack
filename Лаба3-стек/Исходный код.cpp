/**
@class stack
@brief  
Класс, реализующий стек элементов.
@note
Содержит методы добавления элемента в вершину стека, удаления вершины, получения значения вершины и вывода всех элементов стека на экран.
*/

#include <iostream>
using namespace std;

class stack
{
private:
	class item
	{
	private:
		int info;
	public:
		item* next;
		item(int info_, item* next_)
		{
			this->info = info_;
			this->next = next_;
		}
		~item()
		{
		}
		int get()
		{
			return this->info;
		}
	};
	item* head;
public:
	stack();
	~stack();
	void push(int a);
	void pop();
	int peek();
	void print();
};

/**
@brief
Конструктор.
*/

stack::stack()
{
	this->head = nullptr;
}

/**
@brief
Деструктор.
*/

stack::~stack()
{
	while (this->head != nullptr)
	{
		this->pop();
	}
}

/**
@brief
Добавление элемента в вершину.
@param a
Значение элемента.
@brief  p
Вспомогательный указатель.
*/

void stack::push(int a)
{
	item * p = new item(a, this->head);
	this->head = p;
}

/**
@brief
Удаление элемента вершины.
*/

void stack::pop()
{
	item* p = this->head;
	this->head = p->next;
	p->~item();
}

/**
@brief
Получение элемента вершины.
*/

int stack::peek()
{
	return this->head->get();
}

/**
@brief
Вывод на экран всех элементов стека.
*/

void stack::print()
{
	while (this->head != nullptr)
	{
		std::cout << this->peek() << " ";
		this->pop();
	}
}

void main()
{
	int N, ak;
	std::cin >> N;
	stack A = stack();
	for (int i = 0; i < N; i++)
	{
		std::cin >> ak;
		A.push(ak);
	}
	A.print();
}