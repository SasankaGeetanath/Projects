#include<stdio.h>
#include<stdlib.h>
#define MAX 7

int top = -1, stack[MAX];

int isEmpty(){
    return top == -1;
}

int isFull(){
    return top == MAX -1;
}

void push( int x ){
   top++;
   stack[top] = x;

}

void pop(){
    if( isEmpty() ){
    printf("-> THE STACK IS EMPTY...CAN'T POP AN ELEMENT.");
    }
    else{
    printf("-> THE POPPED ELEMENT IS %d.", stack[top] );
    top--;
    }
}

void display(){
    for( int i=0; i <= top ; i++ )
        printf("\t->%d", stack[i]);
}

int size() {
    return top - 1;
}

int search(int value ){
	int search_variable = 0;
	for( int i = 0; i <= top; i++){
		if( value == stack[i] )
			search_variable = 1;
	}
	return search_variable;
}

int main(){
    int choice, x;
    while(1){
        printf("\n\n\tSTACK MENU\t\n\n");
        printf("\n1.ENTER AN ELEMENT TO PUSH.");
        printf("\n2.ENTER AN ELEMENT TO POP.");
        printf("\n3.DISPLAY ALL ELEMENTS.");
        printf("\n4.CHECK WHETHER THE STACK ISEMPTY.");
        printf("\n5.CHECK WHETHER THE STACK ISFULL.");
        printf("\n6.ENTER TO CHECK THE SIZE OF THE STACK.");
        printf("\n7.ENTER TO SEARCH FOR AN ELEMENT IN THE STACK.");
        printf("\n\nENTER YOUR CHOICE:");
        scanf("%d", &choice);
       
         switch(choice){

            case 1 :    if( isFull() )
                            printf("-> THE STACK IS FULL....CAN'T PUSH ANY ELEMENT.");
                        else{
                            printf("ENTER AN ELEMENT TO BE PUSHED :");
                            scanf("%d", &x);
                            push(x);
                        }
            break;

            case 2 :    pop();
            break;

            case 3 :    if( isEmpty() )
                            printf("-> THE STACK IS EMPTY...NO ELEMENTS TO BE DISPLAYED.");
                        else
                            display();
            break;

            case 4 :    if( isEmpty() )
                            printf("-> THE STACK IS EMPTY.");
                        else
                            printf("-> THE STACK S NOT EMPTY.");
            break;

            case 5 :    if( isFull() )
                            printf("-> THE STACK IS FULL.");
                        else
                            printf("-> THE STACK IS NOT FULL.");
            break;

            case 6 :    if( isEmpty() )
                            printf("THE SIZE OF THE STACK IS ZERO.");
                        else
                            printf("THE SIZE OF THE STACK IS %d", size() );
            break;

            case 7 :    if( isEmpty() )
                            printf("THE STACK IS EMPTY.");
                        else{
                            printf("ENTER THE ELEMENT TO BE SEARCHED FOR :");
                            scanf("%d", &x);
                            if( search( x ) )
                                printf("THE ELEMENT IS PRESENT IN THE STACK.");
                            else
                                printf("THE ELEMENT IS NOT PRESENT IN THE STACK.");
                        }
            break;

            case 8 :	exit(1);

            default : printf("ENTER A VALID CHOICE...!");

        }
    }
    return 0;
}
