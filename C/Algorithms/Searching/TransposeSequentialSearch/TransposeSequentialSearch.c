#include<stdio.h>
#include<stdlib.h>

int swap( int *x, int *y ){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int TransposeSequentialSearch( int *arr, int N, int value ){
    int i;
    for( i = 0; i < N; i++){
        if( arr[i] == value )
            swap( &arr[i], &arr[i - 1] );
    }
}

int main(){
    int N, input;

    printf("\nENTER THE MAXIMUM LIMIT OF THE ARRAY :");
    scanf("%d", &N);

    int *arr = (int*)malloc(N * sizeof(int));

    printf("\nENTER THE EEMENTS INTO THE ARRAY :");
    for( int i = 0; i < N; i++ )
        scanf("%d", &arr[i] );

    printf("\nENTER THE ELEMENT TO BE SEARCHED FOR :");
    scanf("%d", &input);

    if( TransposeSequentialSearch( arr, N, input ) ){
        printf("\nTHE ELEMENT IS PRESENT IN THE ARRAY.\n");
        printf("\nTHE REARRANGED ARRAY IS :\n");
        for( int i = 0; i < N; i++ )
            printf("->%d\t", arr[i]);
    }
    else{ 
        printf("\nTHE ELEMENT IS NOT PRESENT IN THE ARRAY.");
        for( int i = 0; i < N; i++ )
            printf("->%d\t", arr[i]);
    }
    
    free( arr );

    return 0;
}