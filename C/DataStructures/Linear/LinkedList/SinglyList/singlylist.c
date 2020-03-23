#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
}*head = NULL;

typedef struct Node* node;

int isEmpty(){
    return head == NULL;
}

int size(){
    int i = 0;
    node ptr = head;
    while(ptr != NULL){
        i++;
        ptr = ptr -> next;
    }
    return i;
}


void display( node ptr ){
    if( ptr != NULL ){
        printf("->%d\t", ptr -> data );
        display( ptr -> next );
    }
}

void displayReverse( node ptr ){
    if( ptr != NULL ){
        displayReverse( ptr -> next );
        printf("->%d\t", ptr -> data );
    }
}

void BubbleSort( node ptr ) {
    int N = size();
    int *arr = (int*)malloc(N * sizeof(int));

    for( int i = 0; i < N; ++i ) {
        arr[i] = ptr -> data;
        ptr = ptr -> next;
    }

    for ( int i = 0; i < N - 1; ++i ) {
        for( int j = 1; j < N; ++j )
            if( arr[j] < arr[j - 1] ) {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
    } 

    for( int i = 0; i < N; ++i ) 
        printf("->%d\t", arr[i]);
    
    free(arr);
}

void insertAsHead(int value){
    node  new_node = (node)malloc(sizeof(node));
    new_node -> data = value;
   if( isEmpty() ){
        new_node -> next = NULL;
   }
   else{
       new_node -> next = head;
   }   
   head = new_node;
}

node insertAsRear( node ptr, int value ) {            //used recursion for "insertAsRear()".
    if( ptr == NULL ) {
        node new_node = (node)malloc(sizeof(node));
        new_node -> data = value;
        ptr = new_node;
        new_node -> next = NULL;
    }
    else
        ptr -> next = insertAsRear( ptr -> next, value );
    return ptr;
}

void insertByPosition( int value, int pos ){
    int i = 1;
    node new_node = (node)malloc(sizeof(node));
    new_node -> data = value;
    node ptr = head, pre_ptr = NULL;
    while( i != pos ){
        i++;
        pre_ptr = ptr;
        ptr = ptr -> next;
    }
    if( pos == 1 ){
        new_node -> next = head;
        head = new_node;
    }
    else {
        new_node -> next = ptr;
        pre_ptr -> next = new_node;
    }
}

// void insert_by_position( int value, int pos ){
//     int i = 1;
//     node new_node = (node)malloc(sizeof(node));
//     new_node -> data = value;
//     node ptr = start;
//     while(ptr != NULL){
//         if( i == pos )
//             break;
//         else{
//             i++;
//             ptr = ptr -> next;
//         }
//     }
//     new_node -> next = ptr -> next;
//     ptr -> next = new_node;    
// }

// Iterative Function for "insertAsRear()".

// void insertAsRear(int value){     
//     node new_node = (node)malloc(sizeof(node));
//     new_node -> data = value;
//     node ptr = start;
//     if( isEmpty() ){
//         new_node -> next = NULL;
//         start = new_node;
//     }
//     else{
//         while( ptr -> next != NULL){
//             ptr = ptr -> next;
//         }
//         ptr -> next = new_node;
//         new_node -> next = NULL;
//     }
// }

void deleteAsHead(){
    node temp = head;
    printf("\nTHE DELETED IS ELEMENT IS %d", head -> data);
    head = head -> next;
    free(temp);
}

void deleteeByPosition( int pos ){
    node ptr = head;
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

// void deleteAsRear(){
//     node ptr = head, pre_ptr;
//     if( isEmpty() )
//         printf("THE SINGLY LINKED LIST IS EMPTY.");
//     else{
//         while( ptr -> next != NULL){
//             pre_ptr = ptr;
//             ptr = ptr -> next;
//         }
//         printf("\nTHE DELETED IS ELEMENT IS %d", ptr -> data);
//         pre_ptr -> next = NULL;
//         free(ptr);
//     }
// }

node deleteAsRear( node ptr ) {
    if( ptr == NULL ) 
        free( ptr );
    else 
        return ptr -> next = deleteAsRear( ptr -> next );
    return ptr;
}

// void display(){
//     if(isEmpty() )
//         printf("THE SINGLY LINKED LIST IS EMPTY.");
//     else{
//         node ptr = start;
//         while( ptr != NULL ){
//             printf("->%d\t", ptr -> data);
//             ptr = ptr -> next; 
//         }
//     }
// }

// void displayReverse(){
//     node ptr = start, pre_ptr = NULL;
//     pre_ptr = ptr;
//     ptr = ptr -> next;
//     pre_ptr -> next = NULL;

//     while( ptr != NULL){
//         pre_ptr = ptr;
//         ptr = ptr -> next;
//     }
//     start = pre_ptr;

//     while( pre_ptr != NULL){
//         printf("%d", pre_ptr -> data);
//         pre_ptr = pre_ptr -> next;
//     }
// }

int LinearSearch( int value ){
    int search_var = 0;
    node ptr = head;
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
        printf("\n12.ENTER TO SORT THE LINKED LIST.");
        printf("\n13.EXIT.");
        printf("\n\nENTER YOUR CHOICE :");
        scanf("%d",&choice);

        switch(choice){
            case 1 :        printf("ENTER THE ELEMENT TO BE INSERTED :");
                            scanf("%d",&input);
                            insertAsHead( input );
            break;
            
            case 2 :        printf("ENTER THE ELEMENT TO BE INSERTED : ");
                            scanf("%d",&input);
                            insertAsRear(head, input); 
            break; 

            case 3 :        printf("ENTER THE ELEMENT TO BE INSERTED :");
                            scanf("%d", &input);
                            printf("ENTER THE PARTICUALR POSITION :");
                            scanf("%d", &position);
                            insertByPosition(input, position);
            break;

            case 4 :    if( isEmpty() )
                            printf("THE LIST IS EMPTY...CAN'T DELETE ANY ELEMENT.");
                        else
                            deleteAsHead();
            break;

            case 5 :    if( isEmpty() )
                            printf("THERE ARE NO ELEMENTS IN THE LIST TO DELETE.");
                        else{
                            printf("ENTER THE POITION OF THE ELEMENT TO BE DELETED :");
                            scanf("%d", &position);
                            deleteeByPosition(position);
                        }
            break;
                
            case 6 :    if( isEmpty() )
                            printf("THE LIST IS EMPTY...CAN'T DELETE ANY ELEMENT.");
                        else
                            deleteAsRear( head );
            break;
            
            case 7 :    if( isEmpty() )
                            printf("NO ELEMENTS TO BE DISPLAYED.");
                        else
                            display(head);
            break;

            case 8 :    if( isEmpty() )
                            printf("THERE ARE NO ELEMENTS IN THE LINKED LIST.");
                        else
                            displayReverse(head);
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
                            if( LinearSearch( input ))
                                printf("THE ELEMENT IS PRESENT IN THE LINKED LIST.");
                            else
                                printf("THE ELEMENT IS NOT PRESENT IN THE LINKED LIST.");
                        }
            break;

            case 12 :    if( isEmpty() ) 
                            printf("THERE ARE NO ELEMENTS IN THE LINKED LIST.");
                        else 
                            BubbleSort( head );
            break;
            
            case 13 :    exit(1);
            
            default : printf("ENTER A VALID CHOICE.");
        }

    }
    return 0;
}
