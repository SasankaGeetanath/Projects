#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
} *start = NULL;

typedef struct Node* node;

int search( int value ){
    int search_var = 0;
    node ptr = start;
    while( ptr !=  NULL){
        if( ptr -> data == value ){
            search_var = 1;
            break;
        }
        else
            ptr = ptr -> next;
    }
    return search_var;
}

int isEmpty(){
    return start == NULL;
}

void insert_at_start( int value ){
    node new_node = (node)malloc(sizeof(node));
    new_node -> data = value;
    new_node -> prev = NULL;
    if( isEmpty() )
        new_node -> next = NULL;
    else
        new_node -> next = start;
    start = new_node;
}

void insert_by_position(int value, int pos ){
    node new_node = (node)malloc(sizeof(node));
    new_node -> data = value;
    if( isEmpty() ){
        new_node -> next = NULL;
        new_node -> prev = NULL;
        start = new_node;
    }
    else{
        int i = 1;
        node ptr = start;
        while( ptr != NULL){
            if (i == pos)
                break;
            i++;
            ptr = ptr -> next;
        }
        new_node -> next = ptr -> next;
        ptr -> next -> prev = new_node;
        ptr -> next = new_node;
        new_node -> prev = ptr;
    }
}
void insert_at_end( int value ){
    node new_node = (node)malloc(sizeof(node));
    new_node -> data = value;
     new_node -> next = NULL;
    if( isEmpty() ) {
        new_node -> prev = NULL;  
        start = new_node;
    }
    else{
        node ptr = start;
        while( ptr -> next != NULL)
            ptr = ptr -> next;
        ptr -> next = new_node;
        new_node -> prev = ptr;
    }
}

void delete_at_start(){
    node ptr = start;
    printf("THE ELEMENT TO BE DELETED IS %d", ptr -> data);
    start = start -> next;
    start -> prev = NULL;
    free(ptr);
}

void delete_at_end(){
    node ptr = start;
    while( ptr -> next != NULL)
        ptr = ptr -> next;
    printf("THE DELETED ELEMENT IS %d", ptr -> data );
    ptr -> prev -> next = NULL;
    free( ptr );
}

void delete_by_postion(int pos){
    node ptr = start;
    int i = 1;
    while( ptr != NULL){
        if( i == pos)
            break;
        i++;
        ptr = ptr -> next;
    }
    ptr -> prev -> next = ptr -> next;
    ptr -> next -> prev = ptr -> prev;
    free( ptr );
}

void display(){
    if( isEmpty() )
        printf("THE DOUBLY LINKED LIST IS EMPTY.");
    else{
        node ptr = start;
        while( ptr != NULL){
            printf("->%d\t", ptr -> data);
            ptr = ptr -> next;
        }
    }
}

int size(){
    int i = 0;
    node ptr = start;
    while( ptr != NULL){
        i++;
        ptr = ptr -> next;
    }
    return i;
}

int main(){
    int input, choice, pos;
    while(1){
        printf("\n\n\tDOUBLY LINKED LIST.\t\n\n");
        printf("\n1.ENTER AN ELEMENT TO INSERT AT STARTING.");
        printf("\n2.ENTER AN ELEMENT TO INSERT AT ENDING.");
        printf("\n3.ENTER THE ELEMENT BY POSITON.");
        printf("\n4.ENTER AN ELEMENT TO DELETE AT STARTING.");
        printf("\n5.ENTER AN ELEMENT TO DELETE AT END.");
        printf("\n6.ENTER AN ELEMENT TO DELETE BY POSTION.");
        printf("\n7.ENTER TO CHECK WHETHER THE DOUBLY LINKED LIST IS EMPTY OR NOT.");
        printf("\n8.ENTER TO DISPLAY ALL ELEMENTS IN THE DOUBLY LINKED LIST.");
        printf("\n9.ENTER TO CHECK THE SIZE OF THE DOUBLY LINKED LIST.");
        printf("\n10.ENTER TO SEARCH AN ELEMENT IN THE DOUBLY LINKED LIST.");
        printf("\n11.EXIT");
        printf("\n\nENTER YOUR CHOICE :");
        scanf("%d", &choice);

        switch( choice ) {

        case 1 :    printf("ENTER THE ELEMENT TO BE INSERTED :");
                    scanf("%d", &input);
                    insert_at_start( input );
        break;

        case 2 :    printf("ENTER THE ELEMENT TO BE INSERTED :");
                    scanf("%d", &input);
                    insert_at_end( input );
        break;

        case 3 :    printf("ENTER THE ELEMENT TO BE INSERTED : ");
                    scanf("%d", &input);
                    printf("ENTER THE POSITION OF THE ELEMENT :");
                    scanf("%d", &pos);
                    insert_by_position(input, pos);
        break;

        case 4 :    if( isEmpty() )
                        printf("THE DOUBLY LINKED LIST IS EMPTY.");
                    else
                        delete_at_start();
        break;
        
        case 5 :    if( isEmpty() )
                        printf("THE DOUBLY LINKED LIST IS EMPTY.");
                    else
                        delete_at_end();
        break;

        case 6 :    if( isEmpty() )
                        printf("THE DOUBLY LINKED LIST IS EMPTY.");
                    else{
                        printf("ENTER THE POSITION OF THE ELEMENT TO BE DELETED :");
                        scanf("%d", &pos);
                        delete_by_postion(pos);
                    }

        case 7 :    if( isEmpty() )
                        printf("THE DOUBLY LINKED LIST IS EMPTY.");
                    else
                        printf("THE DOUBLY LINKED LIST IS NOT EMTPY.");
        break;


        case 8 :    if( isEmpty() )
                        printf("THERE ARE NO ELEMENTS TO DISPLAY.");
                    else
                        display();
        break;

        case 9 :    if( isEmpty() )
                        printf("THE SIZE OF THE DOUBLY LINKED LIST IS ZERO.");
                    else
                        printf("THE SIZE OF THE DOUBLY LINKED LIST IS %d", size() );
        break;

        case 10 :   if( isEmpty() )
                        printf("THE DOUBLY LINKED LIST IS EMPTY.");
                    else{
                        printf("ENTER AN ELEMENT TO BE SEARCHED :");
                        scanf("%d", &input);
                        if( search(input) )
                            printf("THE ELEMENT IS PRESENT IN THE DOUBLY LINKED LIST.");
                        else
                            printf("THE ELEMENT IS NOT PRESENT IN THE DOUBLY LINKED LIST.");
                    }        
        break;

        case 11 :    exit(1);
        
        default :  printf("ENTER THE VALID CHOICE.");
        }
    }
    return 0;
}