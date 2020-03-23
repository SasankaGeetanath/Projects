#include<stdio.h>
#include<stdlib.h>

void Merge( int *arr, int *left, int *right, int N, int TotalLeft, int TotalRight ){
    int i = 0 , j = 0, k = 0;
    while( i < TotalLeft && j < TotalRight ){
        if( left[i] < right[j] )
            arr[k++] = left[i++];
        else 
            arr[k++] = right[j++];
    }
    while( i < TotalLeft )
        arr[k++] = left[i++];
    while( j < TotalRight )
        arr[k++] = right[j++];    
}

void MergeSort( int *arr, int N ){
    int mid;
    
    if( N < 2)
        return;

    if( N % 2 == 0)
       mid = N/2;
    else 
        mid = ( N + 1 ) / 2;
    
    int *left = (int*)malloc( mid*sizeof(int));
    int *right = (int*)malloc((N - mid)* sizeof(int));

    for( int i = 0; i < mid; i++)
        left[i] = arr[i];
    for( int i = mid; i < N; i++)
        right[ i - mid ] = arr[i];
    MergeSort( left, mid );
    MergeSort( right, N - mid );
    Merge( arr, left, right, N, mid, N - mid );
    free( left );
    free( right );
}

int main(){

    int *arr = NULL, N;
    printf("\nENTER THE SIZE OF THE ARRAY :");
    scanf("%d", &N);

    arr = (int*)malloc(N*sizeof(int));

    printf("\nENTER THE ELEMENTS INTO THE ARRAY :");
    for( int i = 0 ; i < N; i++)
        scanf("%d", &arr[i]);

    MergeSort( arr, N );

    printf("\nTHE SORTED LIST IS :\n");
    for( int i = 0; i < N; i++ )
        printf("->%d\t", arr[i] );

    free( arr );
    return 0;  
}