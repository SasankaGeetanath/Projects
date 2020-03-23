#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
}*start = NULL;

typedef struct Node* node;

int size = 0;

int length(){
    return size;
}

int isEmpty(){
    return start == NULL;
}

int search(int value){
    int search_var = 0;
    node ptr = start;
    while( size-- ){
        if( ptr -> data == value ){
            search_var = 1;
            break;
        }
        else
            ptr = ptr -> next;
    }
    return search_var;
}

void display(){
    node ptr = start;
    while( size-- ){
        printf("->%d\t", ptr -> data);
        ptr = ptr -> next;
    }
}

void insert_at_start(int value){
    node new_node = (node)malloc(sizeof(node));
    new_node -> data = value;
    if( isEmpty() )
        new_node -> next = new_node;
    else{
        node ptr = start;
        new_node -> next = start;
        while( ptr -> next != start )
            ptr = ptr -> next;
        ptr -> next = new_node;
    }
    start = new_node;
    size++;
}
void insert_by_position(int value, int pos){
    node new_node = (node)malloc(sizeof(node));
    new_node -> data = value;
    node ptr = start;
    int i = 0;
    while( size--){
        if( i == pos )
            break;
        else{
            i++;
            ptr = ptr -> next;
        }
        ptr -> next = new_node; 
    }
    size++;
}

void insert_at_end( int value ){
    node new_node = (node)malloc(sizeof(node));
    new_node -> data = value;
    node ptr = start;
    new_node -> next = start;
    if( isEmpty() )
        start = new_node;
    else{
        while( ptr -> next != start )
            ptr = ptr -> next;
        ptr -> next = new_node;
    }
    size++;
}

void delete_at_start(){
    node ptr = start;
    printf("THE DELETED ELEMENT IS %d", ptr -> data);
    start = start -> next;
    size--;
    free(ptr);
}

void delete_by_position(int pos){
    node ptr = start;
    node pre_ptr = NULL;
    int i = 1;
    while( size-- ){
        if( i == pos)
            break;
        i++;
        pre_ptr = ptr;
        ptr = ptr -> next;
    }
    pre_ptr -> next = ptr -> next;
    size--;
    free( ptr );
}

void delete_at_end(){
    node ptr = start;
    node pre_ptr = NULL;
    while( ptr -> next != start){
        pre_ptr = ptr;
        ptr = ptr -> next;
    }
    printf("THE DELETED ELEMENT IS %d", ptr -> data);
    pre_ptr -> next = ptr -> next;
    size--;
    free(ptr);
}


int main(){
    int choice, input, pos;
    while(1){
        printf("\n\t\tCIRCULAR LINKED LIST.\n\t\t");
        printf("\n1.ENTER TO INSERT AT STARTING.");
        printf("\n2.ENTER TO INSERT BY POSITION.");
        printf("\n3.ENTER TO INSERT AT ENDING.");
        printf("\n4.ENTER TO DELETE AT STARTING.");
        printf("\n5.ENTER TO DELETE BY POSITION.");
        printf("\n6.ENTER TO DELETE AT ENDING.");
        printf("\n7.ENTER TO DISPLAY ALL ELEMENTS INT HE LINKED LIST.");
        printf("\n8.ENTER TO CHECK WHETHER THE LINKED LIST IS EMPTY OR NOT.");
        printf("\n9.ENTER TO KNOW THE LENGTH OF THE LINKED LIST.");
        printf("\n10.ENTER TO SEARCH FOR AN ELEMENT IN THE LINKED LIST.");
        printf("\n11.EXIT.");
        printf("\n\nENTER YOUR CHOICE :");

        scanf("%d", &choice);
        switch( choice ){
            
            case 1 :    printf("ENTER THE ELEMENT TO BE INSERTED : ");
                        scanf("%d", &input);
                        insert_at_start(input);
            break;

            case 2 :    printf("ENTER THE POSITION OF THE ELEMENT :");
                        scanf("%d", &pos);
                        printf("ENTER THE ELEMENT TO BE INSERTED :");
                        scanf("%d", &input);
                        insert_by_position(input, pos);
            break;

            case 3 :    printf("ENTER THE ELEMENT TO BE INSERTED : ");
                        scanf("%d", &input);
                        insert_at_end(input);
            break;

            case 4 :    if( isEmpty() )
                            printf("THE CIRCULAR LINKED LIST IS EMPTY.");
                        else
                            delete_at_start();
            break;

            case 5 :    if( isEmpty() )
                            printf("THE CIRCULAR LINKED LIST IS EMPTY.");
                        else{
                            printf("ENTER THE POSITION OF THE ELEMENT TO BE DELETED: ");
                            scanf("%d", &pos);
                            delete_by_position(pos);
                        }
            break;
                    
            case 6  :    if( isEmpty() )
                            printf("THE CIRCULAR LINKED LIST IS EMPTY.");
                        else
                            delete_at_end();
            break;

            case 7 :    if( isEmpty() )
                            printf("THE CIRCULAR LINKED LIST IS EMPTY.");
                        else
                            display();
            break;

            case 8 :    if( isEmpty() )
                            printf("THE CIRCULAR LINKED LIST IS EMPTY.");
                        else
                            printf("THE CIRCULAR LINKED LIST IS NOT EMPTY.");
            break;

            case 9 :    if( isEmpty() )
                            printf("THE SIZE OF THE LIST IS ZERO.");
                        else
                            printf("THE SIZE OF THE LIST IS %d", length());
            break;

            case 10 :    if( isEmpty() )
                            printf("THE CIRCULAR LINKED LIST IS EMPTY.");
                        else{
                            printf("ENTER THE ELEMENT TO BE SEARCHED FOR :");
                            scanf("%d", &input);
                            if( search(input))
                                printf("THE ELEMENT IS PRESENT IN THE LIST.");
                            else
                                printf("THE ELEMENT IS NOT PRESENT IN HE LINKED LIST.");
                        }
            break;

            case 11 :    exit(1);

            default :   printf("\n\nENTER THE VALID CHOICE :");
        }
    }
    return 0;
}