#include<iostream>
using namespace std;

class Diagonal
{
private:
	int* A;
	int n;

public:
	Diagonal()
	{
		n = 2;
		A = new int[2];
	}
	Diagonal(int n)
	{
		this->n = n;
		A = new int[n];
	}
	~Diagonal()
	{
		delete[]A;
	}
	void set(int i, int j, int x);
	int get(int i, int j);
	void display();
};

void Diagonal::set(int i, int j, int x)
{
	if (i == j)
		A[i - 1] = x;
}
int Diagonal::get(int i, int j)
{
	if (i == j)
		return A[i - 1];
	else
		return 0;
}
void Diagonal::display()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
				cout << A[i-1]<< " ";
			else
				cout << "0 ";
		}
		cout << endl;
	}
}

int main()
{
	int d;
	cout << "Enter the dimentions:";
	cin >> d;
	Diagonal dm(d);
	
	int x;
	cout << "Enter all elements\n";
	for (int i = 1; i <= d; i++)
	{
		for (int j = 1; j <= d; j++)
		{
			cin >> x;
			dm.set(i, j, x);
		}
	}

	dm.display();
	return 0;
}