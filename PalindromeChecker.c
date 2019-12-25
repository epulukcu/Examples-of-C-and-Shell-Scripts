#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
  
// A structure to represent a stack 
struct Stack 
{ 
    int top; 
    unsigned capacity; 
    char* array; 
}; 
  
// Function to create a stack of given capacity, initializes size of stack as 0  
struct Stack* createStack(unsigned capacity) 
{ 
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack)); 
    stack->capacity = capacity; 
    stack->top = -1; 
    stack->array = (char*) malloc(stack->capacity * sizeof(char)); 
    return stack; 
} 
  
// Stack is full when top is equal to the last index 
int isFull(struct Stack* stack) 
{ return stack->top == stack->capacity - 1; } 
  
// Stack is empty when top is equal to -1 
int isEmpty(struct Stack* stack) 
{ return stack->top == -1; } 
  
// Function to add an item to stack. It increases top by 1 
void push(struct Stack* stack, char item) 
{ 
    if (isFull(stack)) 
        return; 
    stack->array[++stack->top] = item; 
} 
 
// Function to remove an item from stack. It decreases top by 1  
char pop(struct Stack* stack) 
{ 
    if (isEmpty(stack)) 
        return 1; 
    return stack->array[stack->top--]; 
} 

// A stack based function to reverse a string 
void reverse(char str[]) 
{ 
    // Create a stack of capacity equal to length of string.
    int n = strlen(str); 
    struct Stack* stack = createStack(n); 
    
    // Push all characters of string to stack 
    int i; 
    for (i = 0; i < n; i++) 
        push(stack, str[i]); 
          
    // Pop all characters of string and put them back to str 
   
    for (i = 0; i < n; i++) 
        str[i] = pop(stack);
} 
// Function check the string if palindrome
int checkpalindrome(char *str)
{
    int i,c=0,n;
    n=strlen(str);
	for(i=0;i<n/2;i++)  
    {
    	if(str[i]==str[n-i-1])
    	c++;
 
 	}
 	if(c==i)
        return 1;
    else
        return 0;		  
 }
// Test function 
int main() 
{     	
    char str[100]; 
    printf("Enter the string: ");
    scanf("%s", str);
    reverse(str);   
    printf("Reverse of string: %s", str);
    if(checkpalindrome(str))
 	    printf("\nString is palindrome");
    else
        printf("\nString is not palindrome");
    return 0; 
} 

