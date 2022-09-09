#include<iostream>
using namespace std;

class queue
{
private:
	int front;
	int rear;
	int size;
	int* Q;

public:
	queue()
	{
		front = rear = -1;
		size = 10;
		Q = new int[size];
	}

	queue(int size)
	{
		front = rear = -1;
		this->size = size;
		Q = new int[this->size];
	}

	void enqueue(int x);
	int dequeue();
	void display();
};

void queue::enqueue(int x)
{
	if (rear == size - 1)
		cout << "Queue Full\n";
	else
	{
		rear++;
		Q[rear] = x;
	}
}

int queue::dequeue()
{
	int x = -1;
	if (front == rear)
		cout << "Queue empty\n";
	else
	{
		front++;
		x = Q[front];
	}
	return x;
}

void queue::display()
{
	int i;
	for (i = front + 1; i <= rear; i++)
		cout << Q[i] << " ";
	cout << endl;
}

int main()
{
	queue q(5);
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);

	q.display();
	cout << q.dequeue();
	cout << endl;
	q.display();

	return 0;
}