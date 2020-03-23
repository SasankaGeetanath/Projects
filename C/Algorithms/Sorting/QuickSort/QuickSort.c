#include<stdio.h>
#include<stdlib.h>

void swap( int &a, int &b ) {
    int temp = a;
    a = b;
    b = temp;
}

int Partition( int *arr, int start, int end ) {
    int PIndex = start, Pivot = arr[end];
    for( int i = start; i < end; ++i )
        if( arr[i] < Pivot ){
            swap( arr[i], arr[PIndex] );
            PIndex++;
        }
    swap( arr[PIndex], arr[end] );
    return PIndex;
}

void QuickSort( int *arr, int start, int end ) {
    if( start < end ){
        int PIndex = Partition( arr, start, end );
        QuickSort( arr, start , PIndex - 1);
        QuickSort( arr, PIndex + 1, end );
    }
}

int main(){
    int N;
    
    printf("\nENTER THE MAXIMUM LIMIT OF ARRAY :");
    scanf("%d", &N);

    int *arr = (int*)malloc(N * sizeof(int));

    printf("\nENTER THE ELEMENTS INTO THE ARRAY :");
    for( int i = 0; i < N; i++)
        scanf("%d", &arr[i] );
    
    QuickSort( arr, 0, N - 1);

    printf("\nTHE SORTED ARRAY IS :\n");
    for( int i = 0 ; i < N; i++ )
        printf( "->%d\t", arr[i] );

    free( arr );

    return 0;
}