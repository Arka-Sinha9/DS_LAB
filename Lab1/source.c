#include<stdio.h>
	#include<stdlib.h>
	

	struct Student
	{
	    int age;
	    int marks;
	};
	int validateAge(int age)
	{
	    if(age<0)
	        return -1;
	    else
	        return 1;
	}
	int validateMarks(int marks)
	{
	    if(marks<0 || marks>100)
	        return -1;
	    else
	        return 1;
	}
	int qualify(int age,int marks)
	{
	    if(age>20 && marks>=65)
	        return 1;
	    else
	        return 0;
	}
	int main()
	{
	    struct Student s;
	    int checkAge,checkMarks,qualified;
	    printf("Enter age and marks:\n");
	    scanf("%d%d",&s.age,&s.marks);
	    checkAge=validateMarks(s.age);
	    checkMarks=validateMarks(s.marks);
	    if(checkAge==1 && checkMarks==1){
	        qualified=qualify(s.age,s.marks);
	        if (qualified==1)
	            printf("Qualified!!");
	        else
	            printf("Not Qualified");
	    }
	    else
	        printf("Invalid age or marks");
	    return 0;
	}
