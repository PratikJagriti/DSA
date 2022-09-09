#include<iostream>
using namespace std;

class lowtrimatrix_c
{
private:
	int* a;
	int n;

public:
	lowtrimatrix_c()
	{
		n = 2;
		a = new int[2 * (2 + 1) / 2];
	}

	lowtrimatrix_c(int n)
	{
		this->n = n;
		a = new int[n * (n + 1) / 2];
	}

	~lowtrimatrix_c()
	{
		delete[]a;
	}

	void set(int i, int j, int x);
	int get(int i, int j);
	void display();
	int getdimention()
	{
		return n;
	}
};

void lowtrimatrix_c::set(int i, int j, int x)
{
	if (i >= j)
	{
		a[i * (i - 1) / 2 + j - 1] = x;
	}
}

int lowtrimatrix_c::get(int i, int j)
{
	if (i >= j)
		return a[i * (i - 1) / 2 + j - 1];
	else
		return 0;
}

void lowtrimatrix_c::display()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i >= j)
				cout << a[i * (i - 1) / 2 + j - 1] << " ";
			else
				cout << "0 ";
		}
		cout << endl;
	}
}

int main()
{
	int d;
	cout << "Enter the dimention:";
	cin >> d;

	lowtrimatrix_c lm(d);
	cout << "Enter all the elements:\n";
	int x;
	for (int i = 1; i <= d; i++)
	{
		for (int j = 1; j <= d; j++)
		{
			cin >> x;
			lm.set(i, j, x);
		}
	}

	lm.display();
}
