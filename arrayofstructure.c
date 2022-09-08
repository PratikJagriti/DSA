#include<stdio.h>
#include<string.h>

struct student
{
    /* data */
    int rollno,marks;
    char name[20];
    char grade;
}s[20];

int main()
{
    int n,i,found=0;
    char temp[20];
    printf("Enter the number of students:");
    scanf("%d",&n);
    printf("Enter the details of students\n");

    for(i=0;i<n;i++)
    {
        printf("For student number %d\n",i+1);
        printf("Roll number:");
        scanf("%d",&s[i].rollno);
        printf("Name:");
        scanf("%s",s[i].name);
        printf("Marks:");
        scanf("%d",&s[i].marks);
        printf("Grade:");
        scanf("%s",&s[i].grade);
        printf("\n");
    }

    printf("Student details are:\n");
    for(i=0;i<n;i++)
    {
        printf("Roll number:%d\n",s[i].rollno);
        printf("Name:%s\n",s[i].name);
        printf("Marks:%d\n",s[i].marks);
        printf("Grade:%c\n",s[i].grade);
        printf("\n");
    }

    printf("Enter the name of the student to find marks:");
    scanf("%s",temp);
    for(i=0;i<n;i++)
    {
        if(strcmp(temp,s[i].name)==0)
        {
            printf("Marks of student is:%d",s[i].marks);    
            found=1;
        }
    }
    if(found==0)
    printf("Name not found.");
    return 0;
}
