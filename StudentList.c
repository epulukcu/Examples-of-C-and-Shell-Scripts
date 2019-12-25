#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include <stdlib.h>
int hashing_method(long);
void opfile(void);
FILE *file;

 void opfile(void)
 {
	 if ((file=fopen("StudentLists.txt","r+"))==NULL)
	 {
		 file=fopen("StudentLists.txt","w+");
		 fclose(file);
		 file=fopen("StudentLists.txt","r+");
	 }
}
	 
 int hashing_method(long number)
 {
	 int top=0,snc;long kln,i;
	 snc=number/1000000;
	 kln=number-(snc*1000000);
	  for (i=100000;i>9;i=i/10)
	  {
	  top+=kln/i;
	  kln=kln-((kln/i)*i);
	  }
	 top+=kln;
	  if (top<10) snc*=10;
	  else snc*=100;
	 snc+=top;
	 return(snc);
 }

int main(void)
{
	char choice;
	int listOfRegistration();
	struct Student
	{
	
	char name[10];
	char surname[10];
	char address[50];
	char mobileNumber[11];
	char faculty[20];
	char term[5];
	long number;
	}registration;
	
	while(1)
	{
	b:
	printf("                         \n");
	printf("                         \n");
	printf("                         \n");
	printf("         MAIN MENU       \n");
	printf("_________________________\n");
	printf("                         \n");
	printf("  1-Student Registration\n");
	printf("  2-Student Search\n");
	printf("  3-Exit\n");
	printf("                         \n");
	printf("_________________________\n");
	printf("              \n");
	printf("  Your Choice: ");scanf("%s",&choice);
	
	 switch (choice)
	 {
	  case '1':
	  {
		  printf("Enter Student No:"); scanf("%ld",&registration.number);
		  printf("Enter Name:"); scanf("%s",&registration.name);
		  printf("Enter Surname:"); scanf("%s",&registration.surname);
		  printf("Enter Address:"); scanf("%s",&registration.address);
		  printf("Enter Telephone:"); scanf("%s",&registration.mobileNumber);
		  printf("Enter Deparment:"); scanf("%s",&registration.faculty);
		  printf("Enter Class:"); scanf("%s",registration.term);
		  opfile();
		  fseek(file,sizeof(registration.number)*hashing_method(registration.number),SEEK_SET);
		  fwrite(&registration,sizeof(registration.number),1,file);
		  fclose(file);
		  printf("%s has been recorded.",registration.name);
		  goto b;
	  }
	  case '2':
	  {
		  printf("Enter Student No:"); scanf("%ld",&registration.number);
		  opfile();
		  fseek(file,sizeof(registration.number)*hashing_method(registration.number),SEEK_SET);
		  fread(&registration,sizeof(registration.number),1,file);
		  //printf("Number:%ld\n",registration.number);
		  printf("Name:%s\n",registration.name);
		  printf("Surname:%s\n",registration.surname);
		  printf("Address:%s\n",registration.address);
		  printf("Telephone No:%s\n",registration.mobileNumber);
		  printf("Department:%s\n",registration.faculty);
		  printf("Class:%s\n",registration.term);
		  fclose(file);
		  goto b;
	  }
	

	  case '3': exit(0);
	 }
	}

}
