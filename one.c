#include<stdio.h>
#define MAX_SIZE 4

char s[MAX_SIZE];
int top = -1;

void main()
{
	int ch;
	void PUSH();
	void POP();
	void DISPLAY();

	while (1)
	{
		printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n\nenter your choice\n");
		scanf_s("%d", &ch);

		switch (ch)
		{
		case 1:PUSH();
			break;
		case 2:POP();
			break;
		case 3:DISPLAY();
			break;
		case 4: printf("bye!!see you later.\n");
			exit(0);
		default:
			printf("invalid choice, try again\n\n");
		}
		printf("enter any key to continue...");
		getch();
	}

}

void PUSH()
{
	int x;
	if (top >= MAX_SIZE-1)
		printf("stack overflow\n");
	else
	{
		printf("enter the element to be inserted\n\n");
		scanf_s("%d",&x);
		top++;
		s[top] = x;
		printf("inserted element is %d", x);
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
		printf("element deleted is %d\n", temp);
	}
}

void DISPLAY()
{
	int i;
	if (top == -1)
		printf("no items to display\n");
	else
	{
		for (i = 0; i <= top; i++)
			printf("%d ", s[i]);
	}
}