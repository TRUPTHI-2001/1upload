#include<stdio.h>
#include <stdlib.h>
	struct student
	{
		int roll;
		char name[20];
		char address[20];
		int age;
		
	};
	typedef struct student s;
	s a[200];
	int i,n;	
void age(s a[],int n)
{
	int i,agee,count=0;
	printf("enter the age number of students whose name is required\n\n");
	scanf("%d",&agee);
	count=0;
	for(i=0;i<n;i++)
	{
		if(a[i].age==agee)
		{
			printf("student of age %d\n\n",agee);
			printf("%s\n\n",a[i].name);
			count++;
		}
		
	}
	printf("total students registered for trip having age %d==%d\n",agee,count);
	return;
	
}
void roll(s a[],int n)

{
	int i,usnnumber,temp=0;
	printf("enter roll number of the student whose details are required\n");
	scanf("%d",&usnnumber);
	
	for(i=0;i<n;i++)
	{
		
		if(a[i].roll==usnnumber)
		{
				printf("the student details with follwed usn is\n");	
			printf("roll number=%d \nname= %s\n address=%s\nage= %d\n\n",a[i].roll,a[i].name,a[i].address,a[i].age);
			temp=temp+1;
		}
	
	}
	if(temp!=1)
	{
		printf("student not found\n\n");
	}
	return;
	
		
	
}
void display(s a[],int n)
{
	int j=1;
	printf("the details are\n");
	for(i=0;i<n;i++,j++)
	{
		
		printf("%d]roll number=%d \nname= %s\n address=%s\nage= %d\n\n",j,a[i].roll,a[i].name,a[i].address,a[i].age);
	}
	printf("/n");
}
void add(s a[],int *n)
{
	int i,pos,poss,j,k;
	s temp;
	printf("enter position to add candidate\n");
	scanf("%d",&pos);
	
	if(pos>*n+1)
	{
		printf("invalid postion to add\n");
		return;
	}
	
	for(i=*n-1;i>=pos-1;i--)
	{
		a[i+1]=a[i];
		
	}
	printf("enter the details of rollnumber\t name\t address\tage\n");
	scanf("%d %s %s %d",&a[pos-1].roll,a[pos-1].name,a[pos-1].address,&a[pos-1].age);
	*n=*n+1;
	for(j=0;j<*n-1;j++)
	{
		poss=j;
		for(k=j+1;k<*n;k++)
		{
			if(a[poss].roll>a[k].roll)
			{
				poss=k;
				
			}
		}
		temp=a[j];
		a[j]=a[poss];
		a[poss]=temp;
	}
	
	
}
void delet(s a[],int *n)
{
	int pos,i;
	printf("enter postion to enter\n");
	scanf("%d",&pos);
	if(pos>*n)
	{
		printf("invalid postion\n");
		return;
	}
	for(i=pos-1;i<*n-1;i++)
	{
		a[i]=a[i+1];
	}
	*n=*n-1;
}
main()
{

	int choice,j,k,pos;
	s temp;
	printf("enter the number of students\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		
		printf("enter student details of rollnumber\tname\taddress\tageregistering for the trip\n");
		scanf("%d %s %s %d",&a[i].roll,a[i].name,a[i].address,&a[i].age);
		
	}
	for(j=0;j<n-1;j++)
	{
		pos=j;
		for(k=j+1;k<n;k++)
		{
			if(a[pos].roll>a[k].roll)
			{
				pos=k;
				
			}
		}
		temp=a[j];
		a[j]=a[pos];
		a[pos]=temp;
	}
	
	for(;;)
	{
		
		printf("press 1:display 2::age\n 3::roll\n4::enter additinal candidate\n5::delete\n");
		printf("enter your choice\n\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:display(a,n);
					break;
			case 2:age(a,n);
					break;
			case 3:roll(a,n);
					break;
			case 4:add(a,&n);
					break;
			case 5:delet(a,&n);
					break;
					
		}
	}
	
	
}
