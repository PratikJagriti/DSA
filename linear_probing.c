#include<stdio.h>
#define SIZE 10

int hash(int key)
{
	return key % SIZE;
}

void insert(int H[], int key)
{
	int index = hash(key);
	int i = 0;

	while (H[(index+i) % SIZE] != 0)
	{
		i++;
	}
	H[(index + i) % SIZE] = key;
}

int search(int H[], int key)
{
	int index = hash(key);
	int i = 0;

	while (H[(index + i) % SIZE] != key && H[(index + i) % SIZE] != 0)
	{
		i++;
	}

	if (H[(index + i) % SIZE] == 0)
		return -1;
	else
		return (index + i) % SIZE;
}


int main()
{
	int HT[10] = { 0 };

	insert(HT, 12);
	insert(HT, 25);
	insert(HT, 15);
	insert(HT, 26);
	insert(HT, 8);

	int key = 26;
	printf("Key %d found at index %d", key, search(HT, 26));

}