#include<stdio.h>
#include<stdlib.h>

struct array
{
	int* A;
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

int main()
{
	int i, n;
	struct array arr;
	printf("Enter the size of array:");
	scanf("%d", &arr.size);
	arr.A = (int*)malloc(arr.size * sizeof(int));
	arr.length = 0;

	printf("Enter the number of elements:");
	scanf("%d", &n);
	printf("Enter the elements:\n");
	for (i = 0; i < n; i++)
		scanf("%d", &arr.A[i]);
	arr.length = n;
	display(arr);
}