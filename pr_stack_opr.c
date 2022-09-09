#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 4

int s[MAX_SIZE], top = -1;

void main()
{
	int ch;

	void PUSH();
	void POP();
	void DISPLAY();

	system("clear");

	printf("1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
	while (1)
	{
		printf("\n\nENTER YOUR CHOICE\n\n");
		scanf_s("%d", &ch);
		switch (ch)
		{
		case 1: PUSH();
			break;
		case 2: POP();
			break;
		case 3: DISPLAY();
			break;
		case 4: printf("\n\nBye!!See you next time\n\n");
			exit(0);
		default:
			printf("Invalid choice, try again \n");
		}
	}
}
void PUSH()
{
	int x;
	if (top >= MAX_SIZE-1)
		printf("stack overflow\n");
	else
	{
		printf("enter the element to be inserted\n");
		scanf_s("%d", &x);
		top++;
		s[top] = x;
		printf("element inserted in the stack is %d", x);
	}
}
void POP()
{
	int temp;
	if (top == -1)
		printf("stack underflow\n");
	else
	{
		temp = s[top];
		top--;
		printf("element deleted from the stack is %d", temp);
	}
}
void DISPLAY()
{
	int i;
	if (top == -1)
		printf("no elements to display\n");
	else
	{
		for (i = 0; i <= MAX_SIZE - 1; i++)
			printf("%d ", s[i]);
	}
}