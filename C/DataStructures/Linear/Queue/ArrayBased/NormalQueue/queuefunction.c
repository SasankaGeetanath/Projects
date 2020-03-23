#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int rear = -1, front = -1, queue[MAX];

int isEmpty(){
    return rear == front;
}

int isFull(){
    if(rear == MAX - 1){
        if(rear == front)
            return 0;
        return 1;
    }
    else
        return 0;
}

void insert( int x ){
        queue[rear] = x;
        rear++;
}

void deQueue(){
    printf("THE ELEMENT DELETED IS %d", queue[front] );
    front++;    
}

void display(){
    for( int i = front; i < rear; i++ )
        printf("->%d\t", queue[i] );
}

int size(){
    int count = 0;
    for( int i = front; i < rear; i++ )
        count++;
    return count;
}

int search( int x ){
    int search_variable = 0;
    for ( int i = 0; i < MAX; i++ ){
        if( x == queue[i]){
            search_variable = 1;
            break;
        }
    }
    return search_variable;
}

int main(){
    int choice, input;
    while(1){
        printf("\n\n\tQUEUE\t\n\n");
        printf("\n1.ENTER AN ELEMENT TO INSERT.");
        printf("\n2.ENTER AN ELEMENT TO DELETE.");
        printf("\n3.DISPLAY ALL ELEMENTS.");
        printf("\n4.CHECK IF THE QUEUE IS EMPTY.");
        printf("\n5.CHECK IF THE QUEUE IS FULL.");
        printf("\n6.ENTER TO CHECK THE SIZE OF THE QUEUE.");
        printf("\n7.ENTER TO SEARCH FOR AN ELEMENT.");
        printf("\n8.EXIT.");
        printf("\n\nENTER YOUR CHOICE :");
        scanf("%d",&choice);

        switch( choice ){

            case 1 :    if( isFull() )
                            printf("THE QUEUE IS FULL.");
                        else{
                            printf("ENTER THE ELEMENT TO BE INSERTED :");
                            scanf("%d", &input);
                            insert( input );
                        }
            break;

            case 2 :    if(isEmpty() )
                            printf("THERE ARE NO ELEMENT IN THE QUEUE.");
                        else
                            deQueue();
            break;

            case 3 :    if( isEmpty() )
                            printf("THE QUEUE IS EMPTY.");
                        else
                            display();
            break;

            case 4 :    if( isEmpty() )
                            printf("THE QUEUE IS EMPTY.");
                        else
                            printf("THE QUEUE IS NOT EMPTY.");
            break;

            case 5:     if( isFull() )
                            printf("THE QUEUE IS FULL.");
                        else
                            printf("THE QUEUE IS NOT FULL.");
            break;

            case 6 :    if( isEmpty() )
                            printf("THE SIZE OF THE QUEUE IS ZERO.");
                        else
                            printf("THE SIZE OF THE QUEUE IS %d", size() );
            break;

            case 7 :    if( isEmpty() )
                            printf("THE QUEUE IS EMPTY.");
                        else{
                            if( search( input ))
                                printf("THE ELEMENT IS PRESENT IN THE QUEUE.");
                            else 
                                printf("THE ELEMENT IS NOT PRESENT IN THE QUEUE.");
                        }
            break;
                            
            case 8 :    exit(1);

            default :   printf("ENTER THE VALID CHOICE.");
        }
    }   
    return 0;
}