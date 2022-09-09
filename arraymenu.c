#include<stdio.h>
#include<stdlib.h>

struct array
{
	int *A;
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

int sum(struct array arr)
{
	int sum = 0, i;
	for (i = 0; i < arr.length; i++)
		sum = sum + arr.A[i];
	return sum;
}

int main()
{
	struct array arr;
	int ch;
	int index, n;
	int x;

	printf("Enter the size of the array:");
	scanf("%d", &arr.size);
    arr.A = (int*)malloc(arr.size * sizeof(int));
	arr.length = 0;

	do {
		printf("Menu\n");
		printf("1.Insert\n2.Delete\n3.Search\n4.Sum\n5.Display\nPress any other key to exit\n");
		printf("Enter your choice:");
		scanf("%d", &ch);

		switch (ch)
		{
		case 1:
			printf("Enter the index and element:");
			scanf("%d%d", &index, &n);
			insert(&arr, index, n);
			break;

		case 2:
			printf("Enter the index of the element to be deleted:");
			scanf("%d", &index);
			x = delete(&arr, index);
			printf("The deleted element is %d\n", x);
			break;

		case 3:
			printf("Enter the element to be searched:");
			scanf("%d", &n);
			x = BinarySearch(arr, n);
			printf("Element found at %d\n", x);
			break;

		case 4:
			printf("Sum of array elements are:%d", sum(arr));
			break;

		case 5:
			display(arr);
			break;
		}
	} while (ch < 6);
	return 0;
}