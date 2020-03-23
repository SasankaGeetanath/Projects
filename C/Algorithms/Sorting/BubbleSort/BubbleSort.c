#include<stdio.h>
#include<stdlib.h>

void BubbleSort( int *arr, int N ){
    for ( int i = 0; i < N - 1; ++i ){
        for( int j = 1; j < N; ++j )
            if( arr[j] < arr[j - 1] ){
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
    }
}

int main(){
    int N;

    printf("\nENTER THE MAXIMUM LIMIT OF THE ARRAY :");
    scanf("%d", &N);

    int *arr = (int*)malloc(N * sizeof(int));

    printf("\nENTER THE ELEMENTS INTO THE ARRAY :");
    for ( int i = 0; i < N; i++ )
        scanf("%d", &arr[i]);
    
    BubbleSort( arr, N );

    printf("\nTHE SORTED LIST IS : \n");
    for( int i = 0; i < N; i++ )
        printf("->%d\t", arr[i]);

    free(arr);

    return 0;
}