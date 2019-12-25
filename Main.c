#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "PalindromeChecker.h"
#include "StudentList.h"

int main(int argc, char *argv[]) {
	printf("Welcome the our terminal \n");
	printf("In the terminal you can do the following:\n");
	printf("1) Freword : look up the word frequency in a file\n");
	printf("2) SortArray : create an array with the elements that you want, sort the elements and give the position of the desired elements\n");
	printf("3) PalindromeChecker : find the reverse of word and check if word has palindrome\n");
	printf("4) StudentList : create a management for add and search students in the text file\n");
	
	while(1) {
		printf("\nEnter a command: ");
		char * input = (char *) malloc(100*sizeof(char));  
		gets(input);               //gets the input from user
		char *inputs[15];
		for(int i = 0; i < 15; i++)
		    inputs[i] = NULL;
		char * temp;               //keep the split piece
		temp = strtok(input," ");  //breaks string str into a series of tokens using the delimiter delim
		int index=0;
		while(temp != NULL){
			inputs[index]=temp;    //char pointer array with siplit pieces
			temp=strtok(NULL," "); //split new part
			index++;		
		}
		int argument=index;        //number of argument for each function
		char Freword[]="Freword";
		char SortArray[]="SortArray";
		char PalindromeChecker[]="PalindromeChecker";
		
		if(strcmp(inputs[0],Freword)==0){
	
	      char *cmdargs[] = {"/bin/bash","./Freword.sh","input.txt",NULL };
		        if(argument==1) {
		          printf("Please enter command with filename");
		        }
		        else if(argument==2) {
					if(!fork())
					   execv(cmdargs[0], cmdargs); 
					wait(NULL);
				}
				else{
					printf("Freword can take only 1 inputs.\n");
				}	        
		         
        }
        else if(strcmp(inputs[0],SortArray)==0){
			char *cmdargs2[] = {"/bin/bash","./SortArray.sh",NULL,NULL };
			if(argument==1) {
		          if(!fork())
					   execv(cmdargs2[0], cmdargs2); 
		        }
		    else
		        printf("SortArray don't need any arguments.\n");
						
			}
        else if(strcmp(inputs[0],PalindromeChecker)==0){
			if(argument==1){
				if(!fork())
				   PalindromeChecker(inputs[0]);
				}
			}
		
			return 0;
    } 
 }
