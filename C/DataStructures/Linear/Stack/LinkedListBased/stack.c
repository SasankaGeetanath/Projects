#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
} *start = NULL;

typedef struct Node* node;

int size(){
    int count;
    node ptr = start;
    while( ptr -> next != NULL){
        count++;
        ptr = ptr -> next;
    }
    return count;
}

int isEmpty(){
    return start == NULL;
}

void insert( int value ){
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

void delete(){
    node ptr = start, pre_ptr;
    printf("THE POPPED ELEMENT IS %d", start -> data);
    while( ptr -> next != NULL){
        pre_ptr = ptr;
        ptr = ptr -> next;
    }
    pre_ptr -> next = NULL;
    free( ptr );
}

void display(){
    node ptr = start;
    while( ptr != NULL){
        printf("->%d\t", ptr -> data);
        ptr = ptr -> next;
    }

int search( int value ){
    node ptr = start;
    int search_var = 0;
    while( ptr != NULL){
        if( ptr -> data == value){
            search_var = 1;
            break;
        }
        else
            ptr = ptr -> next;
    }
    return search_var;
}

int main(){
    int choice, input;
    while(1){
        printf("\n\n\tSTACK LINKED LIST.\t\n");
        printf("\n1.ENTER TO PUSH AN ELEMENT.");
        printf("\n2.ENTER TO POP AN ELEMENT.");
        printf("\n3.ENTER TO DISPLAY ALL ELEMENTS IN THE LINKED LIST.");
        printf("\n4.ENTER TO CHECK WHETHER THE LINKED LIST IS EMPTY OR NOT.");
        printf("\n5.ENTER TO CHECK THE SIZE OF THE LINKED LIST.");
        printf("\n6.SEARCH FOR AN ELEMENT.");
        printf("\n7.EXIT.");
        printf("\n\nENTER YOUR CHOICE :");
        scanf("%d", &choice);

        switch( choice ){

            case 1 :        printf("ENTER AN ELEMENT TO BE PUSHED :");
                            scanf("%d", &input);
                            insert(input);
            break;

            case 2 :        if( isEmpty() )
                                printf("THE STACK IS EMPTY.");
                            else{
                                scanf("%d", &input);
                                delete();
                            }
            break;

            case 3 :    if( isEmpty() )
                            printf("THERE ARE NO ELEMENTS IN THE LINKED LIST.");
                        else
                            printf("THE ELEMENTS IN THE LINKED LIST ARE");
                            display();
            break;
                    
            case 4 :    if( isEmpty() )
                            printf("THE LINKED LIST IS EMPTY.");
                        else
                            printf("THE LINKED LIST IS NOT EMPTY.");
            break;
        
            case 5 :    if( isEmpty() )
                            printf("THE SIZE OF THE LINKED LIST IS ZERO.");
                        else
                            printf("THE SIZE OF THE LINKED LIST IS %d", size() );
            break;

            case 6 :    if( isEmpty() )
                            printf("THERE ARE NO ELEMENTS IN THE LINKED LIST.");
                        else{
                            printf("ENTER THE ELEMENT TO BE SEARCHED FOR :");
                            scanf("%d", &input);
                            if( search(input) )
                                printf("THE ELEMENT IS PRESENT IN THE LINKED LIST.");
                            else
                                printf("THE ELEMENT IS NOT PRESENT IN THE LINKED LIST.");
                        }
            break;

            case 7 : exit(1);

            default : printf("ENTER A VALID CHOICE.");
        }
    }
    return 0;
}