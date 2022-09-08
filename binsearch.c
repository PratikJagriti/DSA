#include<stdio.h>

struct array
{
	int A[20];
	int size;
	int length;
};

void display(struct array arr)
{
	int i;
    printf("The elements are:\n");
	for (i = 0; i < arr.length; i++)
		printf("%d ", arr.A[i]);
}

void append(struct array* arr, int x)
{
	if (arr->length < arr->size)
		arr->A[arr->length++] = x;
}

void insert(struct array* arr, int index, int x)
{
	int i;
	if (index >= 0 && index <= arr->length)
	{
		for (i = arr->length; i > index; i--)
			arr->A[i] = arr->A[i - 1];
		arr->A[index] = x;
		arr->length++;
	}
}

int delete(struct array* arr, int index)
{
	int x = 0, i;
	if (index >= 0 && index < arr->length)
	{
		x = arr->A[index];
		for (i = index; i < arr->length - 1; i++)
			arr->A[i] = arr->A[i + 1];
		arr->length--;
		return x;
	}
	return 0;
}

void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int linearsearch(struct array* arr, int key)
{
	int i;
	for (i = 0; i < arr->length; i++)
	{
		if (key == arr->A[i])
		{
			swap(&arr->A[i], &arr->A[0]);
			return 0;
		}
	}
	return -1;
}

int BinSearch(struct array arr, int key)
{
	int low = 0, high = arr.length - 1, mid;
	mid = (low + high) / 2;
	while (low <= high)
	{
		if (key == arr.A[mid])
			return mid;
		else if (key < arr.A[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}

int main()
{
	struct array arr={{1,2,3,4,5},20,5};
	
	printf("%d\n", BinSearch(arr, 4));
	display(arr);
    return 0;
}