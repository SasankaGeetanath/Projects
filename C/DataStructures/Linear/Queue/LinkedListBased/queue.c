#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
} *start = NULL;

typedef struct Node* node;

int isEmpty(){
    return start == NULL;
}

void insert( int value ){
    node new_node = (node)malloc(sizeof(node));
    new_node -> data = value;
    new_node -> next = NULL;
    if( isEmpty() )
        start = new_node;
    else{
        node ptr = start;
        while( ptr -> next != NULL )
            ptr = ptr -> next;
        ptr -> next = new_node;
    }
}

void deQueue(){
    node ptr = start;
    if( isEmpty() )
        printf("THE QUEUE LIST IS EMPTY.");
    else{
        printf("THE DELETED ELEMENT IS %d", start -> data);
        start = start -> next;
        free(ptr);
    }
}

void display(){
    int i;
    node ptr;
    while( ptr -> next != NULL ){
        ptr = ptr -> next;
        i++;
    }
    printf("%d", i);
}

int search( int value){
    int search_var = 0;
    node ptr = start;
    while( ptr != NULL ){
        if( ptr == value ){
            search_var = 1;
            break;
        }
        else
            ptr = ptr -> next;
    return search_var == 1;
    }
}

int size( int count ){
    node ptr = start;
    while( ptr -> next != NULL ){
        count++;
        ptr = ptr -> next;
    }
    return count;
}
int main(){
    int choice, input;
    while(1){
        printf("\n\n\tQUEUE LINKED LIST.\t\n");
        printf("\n1.ENTER TO INSERT AN ELEMENT TO THE LINKED LIST.");
        printf("\n2.ENTER TO DELETE AN ELEMENT TO THE LINKED LIST.");
        printf("\n3.ENTER TO DISPLAY ALL ELEMNETS IN THE LINKED LIST.");
        printf("\n4.ENTER TO CHECK WHETHER THE LINKED LIST IS EMPTY OR NOT.");
        printf("\n5.ENTER TO SEARCH AN ELEMENT IN THE LINKED LIST.");
        printf("\n6.ENTER TO CHECK THE SIZE OF THE LINKED LIST.");
        printf("\n7.EXIT.");
        printf("\n\nENTER YOUR CHOICE :");
        scanf("%d", &choice);

        switch ( choice ){
            
            case 1 :        printf("ENTER THE ELEMENT TO BE INSERTED :");
                            scanf("%d", &input);
                            insert(input);
            break;

            case 2 :    if( isEmpty() )
                            printf("THE QUEUE IS EMPTY...CAN'T DELETE ANY ELEMENT.");
                        else
                            deQueue();
            break;

            case 3 :    if( isEmpty() )
                            printf("THERE ARE NO ELEMENSTS IN THE LINKED LIST.");
                        else
                            display();
            break;
            
            case 4 :    if( isEmpty() )
                            printf("THE QUEUE IS EMPTY.");
                        else
                            printf("THE QUEUE IS NOT EMPTY.");

            case 5 :        printf("ENTER THE ELEMENT TO BE SEARCHED FOR :");
                            scanf("%d", &input);
                            node ptr;
                        if( ptr -> data == input )
                            printf("THE ELEMRNT IS IN THE LIST.");
                        else
                            printf("THE ELEMENT IS NOT IN THE LIST.");
            break;

            case 6 :    if( isEmpty() )
                            printf("THE SIZE OF THE LIST IS ZERO.");
                        else
                            printf("THE SIZE OF THE LIST IS %d", size(input) );
            break;
            
            case 7 :    exit(1);

            default :   printf("ENTER THE VALID CHOICE.");
        }
    }
    return 0;
}