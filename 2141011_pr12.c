#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>

#define SIZE 100

int S[SIZE+1];
int top = 0;

struct node {
    int data;
    struct node *next;
}*top1 = NULL;


int temp1=0;
int main() 
{
    system("cls");
    printf("\n\tStack Operations - Program 12\n\n");
    char tempinput[50];
    int num,choice,temp,num1,val,a,i,eternal_choice,choice1;
    eternal:
    printf("\nWhere do You want to Create Stack In ? \n 1. Array \n 2. Linked List \n 3. Exit \n Choice : ");
     while(scanf("%d", &eternal_choice)==0) 
    {
        printf("Invalid input. Try again : ");
        int c;
        while((c=getchar())!='\n' && c!=EOF);
    } 

    switch(eternal_choice)
    {
        case 1 :
        error:
            printf("Enter the Limit Size OF the Stack : ");
            while(scanf("%d", &num)==0) 
            {
                printf("Invalid input. Try again : ");
                int c;
                while((c=getchar())!='\n' && c!=EOF);
            }    
              if(num<1 || num > 100)
                {
                    printf("\n\tINVALID INPUT !! Input data between 1 and 100 ( Inclusive )\n");
                    goto error;
                }
            re:
            printf("\n\t -=-=-=-MENU-=-=-=-\n");
            printf("\n 1.) Insert Element (PUSH) \n 2.) Remove the Top Most Element(POP) \n 3.) Check Underflow \n 4.) Print The Present Stack \n 5.) Peek/Top \n 6.) Exit To Outer Menu \n Choice : ");
                while(scanf("%d", &choice)==0) 
            {
                printf("Invalid input. Try again : ");
                int c;
                while((c=getchar())!='\n' && c!=EOF);
            } 

            switch(choice)
            {
                case 1 : 
                        if(temp1<num)
                        {
                        printf("Enter the Number Of element you want to Push to the Stack : ");
                            while(scanf("%d", &num1)==0) 
                            {
                                printf("Invalid input. Try again : ");
                                int c;
                                while((c=getchar())!='\n' && c!=EOF);
                            } 
                        }
                        temp1=num1+temp1;
                        if(temp1>num)
                        {
                            printf("\nThe Input Data Is Greter Than the Stack Size (Stack Overflow) , Re-input !\n");
                            temp1=temp1-num1;
                            goto re;
                        }
                        for(int i=0;i<num1;i++)
                            {
                            printf("Enter the Element to be pushed : ");
                            while(scanf("%d", &temp)==0) 
                                {
                                    printf("Invalid input. Try again : ");
                                    int c;
                                    while((c=getchar())!='\n' && c!=EOF);
                                }         
                            array_push(temp);
                            }
                        goto re;
                case 2 :
                        a=array_pop();
                        if(a!=-1000)
                        {
                            printf("The Poped Element : %d",a);
                            
                        }
                        goto re;
                case 3 :
                        a=array_is_empty();
                        if(a==1)
                            printf("\nStackUnderflow !!\n");
                        else
                            printf("No StackUnderFlow :) \n");
                        goto re;
                case 4 :
                        printf("\nTOP\n\n");
                        for(i=top;i!=0;i--)
                            {
                            printf("%d\n",S[i]); 
                            }
                            printf("\nBottom\n");
                        goto re;
                case 5 :
                        val = peek(S);
                        if(val != -1)
                        printf("\n The value stored at top of stack is %d", val);
                        goto re;
                case 6 :
                        goto eternal;
                        
            }
        case 2 :
            printf("Enter the Limit Size OF the Stack : ");
            while(scanf("%d", &num)==0) 
            {
                printf("Invalid input. Try again : ");
                int c;
                while((c=getchar())!='\n' && c!=EOF);
            }
            temp1=0;
            rere:
            printf("\n\t -=-=-=-MENU-=-=-=-\n");
            printf("\n 1.) Insert Element (PUSH) \n 2.) Remove the Top Most Element(POP) \n 3.) Print The Present Stack \n 4.) Peek/Top \n 5.) Exit To Outer Menu \n Choice : ");
            while(scanf("%d", &choice1)==0) 
            {
                printf("Invalid input. Try again : ");
                int c;
                while((c=getchar())!='\n' && c!=EOF);
            } 
            switch(choice1)
            {
                case 1 :
                        if (temp1<num)
                        {
                        printf("Enter the Number Of element you want to Push to the Stack : ");
                        while(scanf("%d", &num1)==0) 
                            {
                                printf("Invalid input. Try again : ");
                                int c;
                                while((c=getchar())!='\n' && c!=EOF);
                            } 
                        }
                        temp1=num1+temp1;
                        if(temp1>num)
                        {
                            printf("\nThe Input Data Is Greter Than the Stack Size (Stack Overflow) , Re-input !\n");
                            temp1=temp1-num1;
                            goto rere;
                        }

                        for(int i=0;i<num1;i++)
                        {
                            printf("Enter the Element to be pushed : ");
                            while(scanf("%d", &temp)==0) 
                            {
                                printf("Invalid input. Try again : ");
                                int c;
                                while((c=getchar())!='\n' && c!=EOF);
                            }                            
    
                            linked_push(temp);
                        }
                    goto rere;
                case 2 : 
                        linked_pop();
                        goto rere;

                case 3 :
                        printStack(top1);
                        goto rere;
                case 4 : 
                        a=linked_peek();
                        printf("The Element On the Top is : %d ",a);
                        goto rere;
                case 5 :
                        goto eternal;
                default :
                        printf("\nInvalid Input !! \n");
                        goto rere;
            }

        case 3 :
                break;

        default :
                printf("\n Invalid Choice !! \n");
                goto eternal;
    }
    printf("\n Program Ended ! \n");
    return 0;
}

int array_is_empty() 
{
    if(top == 0)
      return 1;
    return 0;
}

void array_push(int x) 
{
    top = top+1;
    if(top > SIZE) 
        {
        printf("Stack Overflow\n");
        }
    else 
        {
        S[top] = x;
        }
}

int array_pop() 
{
    if(array_is_empty()) 
    {
        printf("Stack Underflow\n");
        return -1000;
    }
    else 
    {
        top = top-1;
        temp1--;
        return S[top+1];
    }
}

int peek(int stack[])
{
    if(top == -1)
    {
    printf("\n STACK IS EMPTY");
    return -1;
    }
    else
    return (stack[top]);
}

void linked_push(int num) {
    struct node *temp;
    temp =(struct node *)malloc(1*sizeof(struct node));
    temp->data = num;
     
    if (top1 == NULL) {
        top1 = temp;
        top1->next = NULL;
    } else {
        temp->next = top1;
        top1 = temp;
    }
}
 
void linked_pop() {
    struct node *temp;
    if (isEmpty(top1)) 
    {
        printf("\nStackUnderflow\n");
        return;
    } 
    else 
    {
        temp = top1;
        top1 = top1->next;
        printf("Removed  Element : %d\n", temp->data);   
        free(temp); 
        temp1--;
    }
}
 
void printStack(struct node *nodePtr) {
  while (nodePtr != NULL) 
  {
     printf("%d", nodePtr->data);
     nodePtr = nodePtr->next;
     if(nodePtr != NULL)
         printf("-->");
  }
  printf("\n");
}

int linked_peek() 
{
    return top1->data;
}

int getStackSize(struct node *head)
{

    if (head == NULL) { 
       printf("Error : Invalid stack pointer !!!\n");       
       return -1;  
    }
      
    int length = 0;
    while(head != NULL){
        head = head->next;
        length++;
    }
    return length;
}

int isEmpty() 
{
    if (top1 == NULL) 
        return 1;
    else
        return 0;
}

//colour defining

void red () 
{
  printf("\033[1;31m");
}
void yellow() 
{
  printf("\033[1;33m");
}
void reset () 
{
  printf("\033[0m");
}
void green()
{
    printf("\033[0;32m");
}
void purple()
{
    printf("\033[0;35m");
}
void cyan()
{
    printf("\033[0;36m");
}
