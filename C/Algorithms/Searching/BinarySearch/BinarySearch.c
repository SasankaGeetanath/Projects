#include<stdio.h>
#include<stdlib.h>

int BinarySearch( int *arr, int N, int value ){
    int mid, flag = 0;
    if( N % 2 == 0)
        mid = N/2;
    else 
        mid = (N + 1)/2;
    if( arr[mid] == value )
        flag = 1;
    else if ( arr[mid] > value ){
        for ( int i = 0; i < mid; i++ ){
            if( arr[i] == value )
                flag = 1;
        }
    }
    else if ( arr[mid] < value ){
        for( int i = mid; i < N; i++ ){
            if( arr[i] == value )
                flag = 1;
        }
    }
    return flag;
}

int main(){
    int N, input;

    printf("\nENTER THE MAXIMUM LIMIT OF ARRAY :");
    scanf("%d", &N);

    int *arr = (int*)malloc(N * sizeof(int));

    printf("\nENTER THE ELEMENTS INTO THE ARRAY :");
    for( int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    printf("\nENTER THE ELEMENT TO BE SEARCHED FOR :");
    scanf("%d", &input );
    
    if(  BinarySearch( arr, N, input ) )
        printf("\nTHE ELEMENT IS PRESENT IN THE ARRAY.");
    else 
        printf("\nTHE ELEMENT IS NOT PRESENT IN THE ARRAY.");
    
    free( arr );
    return 0;
}