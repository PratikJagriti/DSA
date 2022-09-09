#include<iostream>
using namespace std;

class Array
{
private:
	int *A;
	int size;
	int length;
	void swap(int* x, int* y);


public:
	Array()
	{
		size = 10;
		A = new int[size];
		length = 0;
	}

	Array(int sz)
	{
		size = sz;
		A = new int[sz];
		length = 0;
	}

	~Array()
	{
		delete[]A;
	}

	void display();
	void append(int x);
	void insert(int index, int x);
	int Delete(int index);
	int linearsearch(int key);
	int BinarySearch(int key);
	int get(int index);
	void set(int index, int x);
	int max();
	int min();
	int sum();
	float avg();
	void reverse();
	void reverse2();
	void insertsort(int x);
	int issorted();
	void rearrange();
	Array* merge(Array arr2);
	Array* arrunion(Array arr2);
	Array* intersection(Array arr2);
	Array* difference(Array arr2);

};

void Array::display()
{
	int i;
	printf("The elements are:\n");
	for (i = 0; i < length; i++)
		cout << A[i] << " ";
	cout << endl;
}

void Array::append(int x)
{
	if (length < size)
		A[length++] = x;
}

void Array::insert(int index, int x)
{
	int i;
	if (index >= 0 && index <= length)
	{
		for (i = length; i > index; i--)
			A[i] = A[i - 1];
		A[index] = x;
		length++;
	}
}

int Array::Delete(int index)
{
	int x = 0, i;
	if (index >= 0 && index < length)
	{
		x = A[index];
		for (i = index; i < length - 1; i++)
			A[i] = A[i + 1];
		length--;
		return x;
	}
	return 0;
}

void Array::swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int Array::linearsearch(int key)
{
	int i;
	for (i = 0; i < length; i++)
	{
		if (key == A[i])
		{
			swap(&A[i], &A[0]);
			return 0;
		}
	}
	return -1;
}

int Array::BinarySearch(int key)
{
	int low = 0, high = length - 1, mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (key == A[mid])
			return mid;
		else if (key < A[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}

int Array::get(int index)
{
	if (index >= 0 && index < length)
		return A[index];
	return -1;
}

void Array::set(int index, int x)
{
	if (index >= 0 && index < length)
	{
		A[index] = x;
	}
}

int Array::max()
{
	int max, i;
	max = A[0];
	for (i = 1; i < length; i++)
	{
		if (A[i] > max)
			max = A[i];
	}
	return max;
}

int Array::min()
{
	int min, i;
	min = A[0];
	for (i = 1; i < length; i++)
	{
		if (A[i] < min)
			min = A[i];
	}
	return min;
}

int Array::sum()
{
	int sum = 0, i;
	for (i = 0; i < length; i++)
		sum = sum + A[i];
	return sum;
}

float Array::avg()
{
	return (float)sum() / length;
}

void Array::reverse()
{
	int i, j;
	int* B;
	B = new int[length];
	for (i = length - 1, j = 0; i >= 0; i--, j++)
		B[j] = A[i];
	for (i = 0; i < length; i++)
		A[i] = B[i];
}

void Array::reverse2()
{
	int i, j;
	for (i = 0, j = length - 1; i < j; i++, j--)
		swap(&A[i], &A[j]);
}

void Array::insertsort(int x)
{
	if (length < size)
	{
		int i;
		for (i = length - 1; A[i] > x && i >= 0; i--)
			A[i + 1] = A[i];
		A[i + 1] = x;
		length++;
	}
}

int Array::issorted()
{
	int i;
	for (i = 0; i < length - 1; i++)
	{
		if (A[i] > A[i + 1])
			return 0;
	}
	return 1;
}

void Array::rearrange()
{
	int i = 0;
	int j = length - 1;
	while (i < j)
	{
		while (A[i] < 0) { i++; }
		while (A[j] >= 0) { j--; }
		if (i < j)
			swap(&A[i], &A[j]);
	}
}

Array* Array::merge(Array arr2)
{
	int i = 0;
	int j = 0;
	int k = 0;
	Array* arr3 = new Array[length+arr2.length];
	while (i < length && j < arr2.length)
	{
		if (A[i] < arr2.A[j])
			arr3->A[k++] = A[i++];
		else
			arr3->A[k++] = arr2.A[j++];
	}
	for (; i < length; i++)
		arr3->A[k++] = A[i];
	for (; j < arr2.length; j++)
		arr3->A[k++] = arr2.A[j];
	arr3->length = length + arr2.length;
	arr3->size = 10;
	return arr3;
}

Array* Array::arrunion(Array arr2)
{
	int i = 0;
	int j = 0;
	int k = 0;
	Array* arr3 = new Array[length + arr2.length];
	while (i < length && j < arr2.length)
	{
		if (A[i] < arr2.A[j])
			arr3->A[k++] = A[i++];
		else if (arr2.A[j] < A[i])
			arr3->A[k++] = arr2.A[j++];
		else if (A[i] == arr2.A[j])
		{
			arr3->A[k++] = A[i++];
			j++;
		}
	}
	for (; i < length; i++)
		arr3->A[k++] = A[i];
	for (; j < arr2.length; j++)
		arr3->A[k++] = arr2.A[j];
	arr3->length = k;
	return arr3;
}

Array* Array::intersection(Array arr2)
{
	int i = 0;
	int j = 0;
	int k = 0;
	Array* arr3 = new Array[length+arr2.length];
	while (i < length && j < arr2.length)
	{
		if (A[i] < arr2.A[j])
			i++;
		else if (arr2.A[j] < A[i])
			j++;
		else if (A[i] == arr2.A[j])
		{
			arr3->A[k++] = A[i++];
			j++;
		}
	}
	arr3->length = k;
	return arr3;
}

Array* Array::difference(Array arr2)
{
	int i = 0;
	int j = 0;
	int k = 0;
	Array* arr3 = new Array[length+arr2.length];
	while (i < length && j < arr2.length)
	{
		if (A[i] < arr2.A[j])
			arr3->A[k++] = A[i++];
		else if (arr2.A[j] < A[i])
			j++;
		else if (A[i] == arr2.A[j])
		{
			i++;
			j++;
		}
	}
	for (; i < length; i++)
		arr3->A[k++] = A[i];
	arr3->length = k;
	return arr3;
}

int main()
{
	int sz, ch, x, n;
	Array* arr;
	cout << "Enter the array size:";
	cin >> sz;
	arr = new Array[sz];
	do {
		cout << "\n\nMenu\n";
		cout << "1.Insert\n";
		cout << "2.Delete\n";
		cout << "3.Search\n";
		cout << "4.Sum\n";
		cout << "5.Display\n";
		cout << "Enter your choice:";
		cin >> ch;

		switch (ch)
		{
		case 1:
			cout << "Enter index and element:";
			cin >> n;
			cin >> x;
			arr->insert(n, x);
			break;
		case 2:
			cout << "Enter the index:";
			cin >> n;
			cout << "Deleted element is " << arr->Delete(n);
			break;
		case 3:
			cout << "Enter the elemet to be searched:";
			cin >> x;
			cout << "Element found at index " << arr->BinarySearch(x);
			break;
		case 4:
			cout << "Sum of the array elements is " << arr->sum();
			break;
		case 5:
			arr->display();
			break;
		}
	} while (ch < 6);
	return 0;
}