#include<iostream>
using namespace std;

class node
{
public:
	int data;
	node* next;
};

class stack
{
private:
	node* top;
public:
	stack();
	void push(int x);
	int pop();
	void display();
};

stack::stack()
{
	top = NULL;
}

void stack::push(int x)
{
	node* t = new node;
	if (t == NULL)
		cout << "Stack Overflow"<<endl;
	else
	{
		t->data = x;
		t->next = top;
		top = t;
	}
}

int stack::pop()
{
	int x = -1;
	node* t;

	if (top == NULL)
		cout << "Stack Underflow"<<endl;
	else
	{
		t = top;
		top = top->next;
		x = t->data;
		delete t;
	}
	return x;
}

void stack::display()
{
	node* p = top;
	while (p != 0)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

int main()
{
	stack st;
	st.push(10);
	st.push(20);
	st.push(30);
	st.push(40);
	st.push(50);
	st.display();
	cout << st.pop()<<endl;
	st.display();
}