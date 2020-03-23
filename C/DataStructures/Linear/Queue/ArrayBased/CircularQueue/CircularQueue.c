#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int front = -1, rear = -1, queue[MAX];

int isEmpty(){
    return front = -1;
}

int isFull(){
    if( rear == MAX ) {
        if( front == rear )
            return 1;
        return 0;
    }
    else 
        return 0;
}

void insert( int value ){
    if( isEmpty() ) {
        front = rear = 0;
        queue[rear] = value;
    }

    else if( front != 0 && rear == MAX ) {
        rear = 0;
        queue[rear] = value;
    }
    else 
        queue[rear] = value;
    rear++;
}

void deQueue() {
    printf("THE DELETED ELEMENT IS %d", queue[front]);
    front++;
}

void display(){
    if( front < rear ){
        for( int i = front; i < rear; i++ )
            printf("->%d\t", queue[i]);
    }
    else{
        for( int i = front; i < MAX - 1; i++)
            printf("->%d\t", queue[i]);
        for( int i = 0; i < rear; i++ )
            printf("->%d\t", queue[i]);
    }
}

int size(){
    int count = 0;
    for( int i = front; i < rear; i++ )
        count++;
    return count;
}

int search( int value ){
    int search_variable = 0;
    for( int i = 0; i < MAX - 1; i++ ){
        if( value == queue[i]){
            search_variable = 1;
            break;
        }
    }
    return search_variable;
}

int main(){
    int input, choice;
    while(1){
        printf("\n\n\tCIRCULAR QUEUE\t\n\n");
        printf("\n1.ENTER TO INSERT INTO CIRCULAR QUEUE.");
        printf("\n2.ENTER TO DELETE AN ELEMENT FROM THE CIRCULAR QUEUE.");
        printf("\n3.ENTER TO DISPLAY ALL THE ELEMENTS IN THE CIRCULAR QUEUE.");
        printf("\n4.ENTER TO CHECK WHETHER THE QUEUE IS EMPTY OR NOT.");
        printf("\n5.ENTER TO CHECK WHETHER THE QUEUE IS FULL OR NOT.");
        printf("\n6.ENTER TO CHECK THE SIZE OF THE QUEUE.");
        printf("\n7.ENTER TO SEARCH FOR AN ELEMENT IN THE CIRCULAR QUEUE.");
        printf("\n8.EXIT");
        printf("\n\nENTER YOUR CHOICE :");
        scanf("%d", &choice);

        switch( choice ){

            case 1 :    printf("ENTER THE ELEMENT TO BE INSERTED :");
                        scanf("%d", &input );
                        insert( input );
            break;

            case 2 :    if( isEmpty() )
                            printf("THE CIRCULAR QUEUE IS EMPTY.");
                        else 
                            deQueue();
            break;

            case 3 :    if( isEmpty() )
                            printf("THE CIRCUALR QUEUE IS EMPTY.");
                        else 
                            display();
            break;

            case 4 :    if( isEmpty() )
                            printf("THE CIRCUALR QUEUE IS EMPTY.");
                        else 
                            printf("THE CIRCULAR QUEUE IS NOT EMPTY.");
            break;

            case 5 :    if( isFull() )
                            printf("THE CIRCULAR QUEUE IS FULL.");
                        else 
                            printf("THE CIRCULAR QUEUE IS NOT FULL.");
            break;

            case 6 :    if( isEmpty() )
                            printf("THE CIRCULAR QUEUE IS FULL.");
                        else
                            printf("THE SIZE OF THE CIRCULAR QUEUE IS %d", size() );
            break;

            case 7 :    if( isEmpty() )
                            printf("THE CIRCULAR QUEUE IS FULL.");
                        else{
                            if( search(input) )
                                printf("THE ELEMENT IS PRESENT IS THE CIRCULAR QUEUE.");
                            else
                                printf("THE ELEMENT IS NOT PRESENT IN THE CIRCULAR QUEUE.");
                        }
            break;

            case 8 :    exit(1);

            default :    printf("ENTER THE VALID CHOICE :");
        }
    }
    return 0;
}