#include<stdio.h>
#include<stdlib.h>

int DecendingSearch( int *arr, int N , int value ){
    int i;
    for( i = 0; arr[i] > value; i++){
    }
    return arr[i] == value;
}

int AsscendingSearch( int *arr, int N, int value ){
    int i;
    for ( i = 0; arr[i] < value ; i++){
    }
    return arr[i] == value;
}

int UnSorted( int *arr, int N, int value ){
    int flag = 0, i;
    for( int i = 0; i < N ; i++ ){
        if( arr[i] == value ){
            flag = 1;
            break;
        }
    }
    return flag;
}

int main(){
    int choice, input, N;

    printf("\nENTER THE MAXIMUM LIMIT OF ARRAY :");
    scanf("%d", &N);

    int *arr = (int*)malloc(N * sizeof(int) );

    printf("\n1.FIND THE ELEMENT IN ASCCEDING SORTED LIST.");
    printf("\n2.FIND THE ELEMENT IN DECENDING SORTED LIST.");
    printf("\n3.FIND THE ELEMENT IN UNSORTED LIST.");
    printf("\n\nENTER YOUR CHOICE :");
    scanf( "%d", &choice );
    
    printf("\nENTER THE ELEMENTS INTO THE ARRAY :");
    for( int i = 0; i < N; i++)
        scanf( "%d", &arr[i] );
    printf("ENTER THE ELEMENT TO BE SEARHCED FOR :");
    scanf("%d", &input );

    switch( choice ){

        case 1 :    if( AsscendingSearch( arr, N, input ) ) 
                        printf("THE ELEMENT IS PRESENT IN THE ARRAY.");
                    else 
                        printf("THE ELEMENT IS NOT PRESENT IN THE ARRAY.");
        break;

        case 2 :    if( DecendingSearch( arr, N, input ) )
                        printf("THE ELEMENT IS PRESENT IN THE ARRAY.");
                    else 
                        printf("THE ELEMENT IS NOT PRESENT IN THE ARRAY.");
        break;

        case 3 :    if( UnSorted( arr, N, input ) )
                        printf("THE ELEMENT IS PRESENT IN THE ARRAY.");
                    else 
                        printf("THE ELEMENT IS NOT PRESENT IN THE ARRAY.");
        break;

        case 4 :   exit(1);

    }
    
    return 0;
}