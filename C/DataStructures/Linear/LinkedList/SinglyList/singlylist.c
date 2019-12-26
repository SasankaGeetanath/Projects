#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
}*start = NULL;

typedef struct Node* node;

int isEmpty(){
    return start == NULL;
}
void insert_at_start(int value){
    node  new_node = (node)malloc(sizeof(node));
    new_node -> data = value;
   if( isEmpty() ){
        new_node -> next = NULL;
   }
   else{
       new_node -> next = start;
   }   
   start = new_node;
}

void insert_by_position( int value, int pos ){
    int i = 1;
    node new_node = (node)malloc(sizeof(node));
    new_node -> data = value;
    node ptr = start;
    while(ptr != NULL){
        if( i == pos )
            break;
        else{
            i++;
            ptr = ptr -> next;
        }
    }
    new_node -> next = ptr -> next;
    ptr -> next = new_node;    
}

void insert_at_end(int value){
    node new_node = (node)malloc(sizeof(node));
    new_node -> data = value;
    node ptr = start;
    if( isEmpty() ){
        new_node -> next = NULL;
        start = new_node;
    }
    else{
        while( ptr -> next != NULL){
            ptr = ptr -> next;
        }
        ptr -> next = new_node;
        new_node -> next = NULL;
    }
}

void delete_at_start(){
    node temp = start;
    printf("\nTHE DELETED IS ELEMENT IS %d", start -> data);
    start = start -> next;
    free(temp);
}

void delete_by_position( int pos ){
    node ptr = start;
    node pre_ptr = NULL;
    int i = 0;
    while( ptr != NULL){
        if( i == pos ){
            pre_ptr -> next = ptr -> next;
            free(ptr);
            break;
        }
        else{
            i++;
            pre_ptr = ptr;
            ptr = ptr -> next;
        }
    }
}

void delete_at_end(){
    node ptr = start, pre_ptr;
    if( isEmpty() )
        printf("THE SINGLY LINKED LIST IS EMPTY.");
    else{
        while( ptr -> next != NULL){
            pre_ptr = ptr;
            ptr = ptr -> next;
        }
        printf("\nTHE DELETED IS ELEMENT IS %d", ptr -> data);
        pre_ptr -> next = NULL;
        free(ptr);
    }
}

void display(){
    if(isEmpty() )
        printf("THE SINGLY LINKED LIST IS EMPTY.");
    else{
        node ptr = start;
        while( ptr != NULL ){
            printf("->%d\t", ptr -> data);
            ptr = ptr -> next; 
        }
    }
}

void displayReverse(){
    node ptr = start, pre_ptr = NULL;
    pre_ptr = ptr;
    ptr = ptr -> next;
    pre_ptr -> next = NULL;

    while( ptr != NULL){
        pre_ptr = ptr;
        ptr = ptr -> next;
    }
    start = pre_ptr;

    while( pre_ptr != NULL){
        printf("%d", pre_ptr -> data);
        pre_ptr = pre_ptr -> next;
    }
}

int size(){
    int i;
    node ptr = start;
    while(ptr != NULL){
        i++;
        ptr = ptr -> next;
    }
    return i;
}

int search( int value ){
    int search_var = 0;
    node ptr = start;
    while( ptr != NULL ){
        if( ptr -> data == value ){
            search_var = 1;
            break;
        }
        else 
            ptr = ptr -> next;
    }
    return search_var;
}

int main(){
    int choice,input,position;
    while(1){
        printf("\n\n\tSINGLY LINKED LIST.\t\n\n");
        printf("\n1.ENTER TO INSERT AT STARTING.");
        printf("\n2.ENTER TO INSERT AT ENDING.");
        printf("\n3.ENTER TO INSERT BY POSITION.");
        printf("\n4.ENTER TO DELETE AT STARTING.");
        printf("\n5.ENTER TO DELETE BY POSITION.");
        printf("\n6.ENTER TO DELETE AT ENDING.");
        printf("\n7.ENTER TO DISPLAY ALL THE ELEMENTS.");
        printf("\n8.ENTER TO DISPLAY ELEMENTS IN REVERSE ORDER.");
        printf("\n9.ENTER TO FIND THE SIZE OF THE LIST.");
        printf("\n10.ENTER TO CHECK IF EMPTY.");
        printf("\n11.ENTER TO SEARCH FOR AN ELEMENT.");
        printf("\n12.EXIT.");
        printf("\n\nENTER YOUR CHOICE :");
        scanf("%d",&choice);

        switch(choice){
            case 1 :        printf("ENTER THE ELEMENT TO BE INSERTED :");
                            scanf("%d",&input);
                            insert_at_start(input);
            break;
            
            case 2 :        printf("ENTER THE ELEMENT TO BE INSERTED : ");
                            scanf("%d",&input);
                            insert_at_end(input); 
            break; 

            case 3 :        printf("ENTER THE ELEMENT TO BE INSERTED :");
                            scanf("%d", &input);
                            printf("ENTER THE PARTICUALR POSITION :");
                            scanf("%d", &position);
                            insert_by_position(input, position);
            break;

            case 4 :    if( isEmpty() )
                            printf("THE LIST IS EMPTY...CAN'T DELETE ANY ELEMENT.");
                        else
                            delete_at_start();
            break;

            case 5 :    if( isEmpty() )
                            printf("THERE ARE NO ELEMENTS IN THE LIST TO DELETE.");
                        else{
                            printf("ENTER THE POITION OF THE ELEMENT TO BE DELETED :");
                            scanf("%d", &position);
                            delete_by_position(position);
                        }
            break;
                
            case 6 :    if( isEmpty() )
                            printf("THE LIST IS EMPTY...CAN'T DELETE ANY ELEMENT.");
                        else
                            delete_at_end();
            break;
            
            case 7 :    if( isEmpty() )
                            printf("NO ELEMENTS TO BE DISPLAYED.");
                        else
                            display();
            break;

            case 8 :    if( isEmpty() )
                            printf("THERE ARE NO ELEMENTS IN THE LINKED LIST.");
                        else
                            displayReverse();
            break;
            
            case 9 :    if( isEmpty() )
                            printf("THE SIZE OF THE LINKED LIST IS ZERO.");
                        else
                            printf("THE SIZE OF THE LINKED LIST IS %d", size());
            break;
            
            case 10 :     if( isEmpty() )
                            printf("THE LIST IS EMPTY.");
                        else
                            printf("THE LIST IS NOT EMPTY.");
            break;

            case 11 :    if( isEmpty() )
                            printf("THERE ARE NO ELEMENTS IN THE LINKED LIST.");
                        else{
                            printf("ENTER THE ELEMENT TO BE SERCHED FOR :");
                            scanf("%d", &input);
                            if( search( input ))
                                printf("THE ELEMENT IS PRESENT IN THE LINKED LIST.");
                            else
                                printf("THE ELEMENT IS NOT PRESENT IN THE LINKED LIST.");
                        }
            break;
            
            case 12 :    exit(1);
            
            default : printf("ENTER A VALID CHOICE.");
        }

    }
    return 0;
}