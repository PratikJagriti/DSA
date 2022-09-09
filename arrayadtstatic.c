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

int BinarySearch(struct array arr, int key)
{
	int low = 0, high = arr.length - 1, mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (key == arr.A[mid])
			return mid;
		else if (key < arr.A[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}

int RBinSearch(int a[], int low, int high, int key)
{
	int mid;
	
	if (low <= high)
	{
		mid = (low + high) / 2;
		if (key == a[mid])
			return mid;
		else if (key < a[mid])
			return RBinSearch(a, low, mid - 1, key);
		else
			return RBinSearch(a, mid + 1, high, key);
	}
	return -1;
}

int get(struct array arr,int index)
{
	if (index >= 0 && index < arr.length)
		return arr.A[index];
	return -1;
}

void set(struct array* arr, int index, int x)
{
	if (index >= 0 && index < arr->length)
	{
		arr->A[index] = x;
	}
}

int max(struct array arr)
{
	int max, i;
	max = arr.A[0];
	for (i = 1; i < arr.length; i++)
	{
		if (arr.A[i] > max)
			max = arr.A[i];
	}
	return max;
}

int min(struct array arr)
{
	int min, i;
	min = arr.A[0];
	for (i = 1; i < arr.length; i++)
	{
		if (arr.A[i] < min)
			min = arr.A[i];
	}
	return min;
}

int sum(struct array arr)
{
	int sum = 0, i;
	for (i = 0; i < arr.length; i++)
		sum = sum + arr.A[i];
	return sum;
}

float avg(struct array arr)
{
	return (float)sum(arr) / arr.length;
}

void reverse(struct array *arr)
{
	int i, j;
	int* B;
	B = (int*)malloc(arr->length * sizeof(int));
	for (i = arr->length - 1, j = 0; i >= 0; i--, j++)
		B[j] = arr->A[i];
	for (i = 0; i < arr->length; i++)
		arr->A[i] = B[i];
}

void reverse2(struct array* arr)
{
	int i, j;
	for (i = 0, j = arr->length - 1; i < j; i++, j--)
		swap(&arr->A[i], &arr->A[j]);
}

void insertsort(struct array* arr, int x)
{
	if (arr->length < arr->size)
	{
		int i;
		for (i = arr->length - 1; arr->A[i] > x && i>=0; i--)
			arr->A[i + 1] = arr->A[i];
		arr->A[i + 1] = x;
		arr->length++;
	}
}

int issorted(struct array arr)
{
	int i;
	for (i = 0; i < arr.length - 1; i++)
	{
		if (arr.A[i] > arr.A[i + 1])
			return 0;
	}
	return 1;
}

void rearrange(struct array* arr)
{
	int i = 0;
	int j = arr->length - 1;
	while (i < j)
	{
		while (arr->A[i] < 0) { i++; }
		while (arr->A[j] >= 0) { j--; }
		if (i < j)
			swap(&arr->A[i], &arr->A[j]);
	}
}

struct array* merge(struct array* arr, struct array* arr2)
{
	int i = 0;
	int j = 0;
	int k = 0;
	struct array* arr3 = (struct array*)malloc(sizeof(struct array));
	while (i < arr->length && j< arr2->length)
	{
		if (arr->A[i] < arr2->A[j])
			arr3->A[k++] = arr->A[i++];
		else
		    arr3->A[k++] = arr2->A[j++];
	}
	for (; i < arr->length; i++)
		arr3->A[k++] = arr->A[i];
	for (; j < arr2->length; j++)
		arr3->A[k++] = arr2->A[j];
	arr3->length = arr->length + arr2->length;
	arr3->size = 10;
	return arr3;
}

struct array* arrunion(struct array* arr, struct array* arr2)
{
	int i = 0;
	int j = 0;
	int k = 0;
	struct array* arr3 = (struct array*)malloc(sizeof(struct array));
	while (i < arr->length && j < arr2->length)
	{
		if (arr->A[i] < arr2->A[j])
			arr3->A[k++] = arr->A[i++];
		else if (arr2->A[j] < arr->A[i])
			arr3->A[k++] = arr2->A[j++];
		else if (arr->A[i] == arr2->A[j])
		{
			arr3->A[k++] = arr->A[i++];
			j++;
		}
	}
	for (; i < arr->length; i++)
		arr3->A[k++] = arr->A[i];
	for (; j < arr2->length; j++)
		arr3->A[k++] = arr2->A[j];
	arr3->length = k;
	arr3->size = 10;
	return arr3;
}

struct array* intersection(struct array* arr, struct array* arr2)
{
	int i = 0;
	int j = 0;
	int k = 0;
	struct array* arr3 = (struct array*)malloc(sizeof(struct array));
	while (i < arr->length && j < arr2->length)
	{
		if (arr->A[i] < arr2->A[j])
			i++;
		else if (arr2->A[j] < arr->A[i])
			j++;
		else if (arr->A[i] == arr2->A[j])
		{
			arr3->A[k++] = arr->A[i++];
			j++;
		}
	}
	arr3->length = k;
	arr3->size = 10;
	return arr3;
}

struct array* difference(struct array* arr, struct array* arr2)
{
	int i = 0;
	int j = 0;
	int k = 0;
	struct array* arr3 = (struct array*)malloc(sizeof(struct array));
	while (i < arr->length && j < arr2->length)
	{
		if (arr->A[i] < arr2->A[j])
			arr3->A[k++] = arr->A[i++];
		else if (arr2->A[j] < arr->A[i])
			j++;
		else if (arr->A[i] == arr2->A[j])
		{
			i++;
			j++;
		}
	}
	for (; i < arr->length; i++)
		arr3->A[k++] = arr->A[i];
	arr3->length = k;
	arr3->size = 10;
	return arr3;
}

int main()
{
	struct array arr={{1,2,7,9,12},20,5};
	struct array arr2 = { {2,6,8,9,16},10,5 };
	struct array* arr3;
	append(&arr, 10);
	insert(&arr, 2, 8);
	printf("%d\n", delete(&arr, 2));
	printf("%d\n", linearsearch(&arr, 3));
	printf("%d\n", BinarySearch(arr, 4));
	printf("%d\n", RBinSearch(arr.A, 0, arr.length - 1, 4));
	printf("%d\n", get(arr, 4));
	set(&arr, 3, 12);
	printf("%d\n", max(arr));
	printf("%d\n", min(arr));
	printf("%d\n", sum(arr));
	printf("%f\n", avg(arr));
	reverse(&arr);
	reverse2(&arr);
	insertsort(&arr, 34);
	printf("%d\n", issorted(arr));
	rearrange(&arr);
	arr3 = merge(&arr, &arr2);
	display(arr);
	arr3 = arrunion(&arr, &arr2);
	arr3 = intersection(&arr, &arr2);
	arr3 = difference(&arr, &arr2);
	display(*arr3);
    return 0;
}