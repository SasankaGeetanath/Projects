#include<stdio.h>
#include<stdlib.h>
#define MAX 100

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

typedef struct Node* node;

int front = -1, rear = -1;
node queue[MAX];

int isEmpty(){
    return front == rear;
}

node peek(){
    return queue[front];
}

void EnQueue( node ptr ){
    if( isEmpty() )
        front = rear = 0; 
    queue[ rear ] = ptr;
    rear++;
}

void DeQueue(){
    front++;
}

void FreeQueue() {
    for( int i = 0; i < rear; i++ )
        queue[i] = NULL;
    front = rear = -1;
}

node InsertNode( node ptr, int value ){
    node new_node = (node)malloc(sizeof(node));
    new_node -> data = value;
    new_node -> left = NULL;
    new_node -> right = NULL;
    if ( ptr == NULL )
        ptr = new_node;
    else {
        EnQueue(ptr);
        while( !isEmpty() ){
            node temp = peek();
            DeQueue();
            if( temp -> left == NULL ){
                temp -> left = new_node;
                break;
            }
            else 
                EnQueue( temp -> left );
            if( temp -> right == NULL ){
                temp -> right = new_node;
                break;
            }
            else 
                EnQueue( temp -> right );
        }
    }
    FreeQueue();
    return ptr;
}

void InorderTraversal( node ptr ){
    if( ptr != NULL ){
        InorderTraversal( ptr -> left );
        printf("->%d\t", ptr -> data );
        InorderTraversal( ptr -> right );
    }
}

void PreorderTraversal( node ptr ){
    if ( ptr != NULL ){
        printf("->%d\t", ptr -> data );
        PreorderTraversal( ptr -> left );
        PreorderTraversal( ptr -> right ); 
   }
}

void PostorderTraversal( node ptr  ){
    if( ptr != NULL ){
        PostorderTraversal( ptr -> left );
        PostorderTraversal( ptr -> right );
        printf("->%d\t", ptr -> data ); 
   }
}

void LevelorderTraversal( node ptr ){
    EnQueue(ptr);
    while( !isEmpty() ){
        node temp = peek();
        DeQueue();
        printf("->%d\t", temp -> data );
        if( temp -> left != NULL)
            EnQueue( temp -> left );
        if( temp -> right != NULL )
            EnQueue( temp -> right );
    }
}

int main(){
    int input, choice;
    node root = NULL;

    while(1){
        printf( "\n\n\tBINARY SEARCH TREE\t\n\n" );
        printf( "\n1.ENTER TO INSERT A NODE INTO THE TREE." );
        // printf( "\n2.ENTER TO DELETE A NODE FROM THE BINARY TREE." );
        printf( "\n2.ENTER TO FIND THE INORDER TRAVERSAL OF THE BINARY SEARCH TREE." );
        printf( "\n3.ENTER TO FIND THE PREORDER TRSVERSAL OF THE BINARY SEARCH TREE." );
        printf( "\n4.ENTER TO FIND THE POSTORDER TRAVERSAL OF THE BINARY SEARCH TREE." );
        // printf( "\n6.ENTER TO FIND THE HEIGHT OF THE BINARY SEARCH TREE." );
        // printf( "\n7.ENTER TO FIND THE MINIMUM NODE IN THE BINARY SEARCH TREE." );
        // printf( "\n8.ENTER TO FIND THE MAXIMUM NODE IN THE BINARY SEARCH TREE." );
        printf( "\n5.EXIT" );
        printf( "\n\nENTER YOUR CHOICE :" );
        scanf( "%d", &choice );

        switch( choice ){

            case 1 :    printf("ENTER THE ELEMENT TO BE INSERTED INTO THE TREE :");
                        scanf("%d", &input);
                        root = InsertNode( root, input );
            break;

            case 2 :    if( root == NULL )
                            printf("THE BINARY SEARCH TREE IS EMPTY.");
                        else{
                            printf("THE INORDER TRAVERSAL FOR THE BINARY SEARCH TREE IS:\n");
                            InorderTraversal( root );
                        }
            break;

            case 3 :    if( root == NULL )
                            printf("THE BINARY SEARCH TREE IS EMPTY.");
                        else{
                            printf("THE PREORDER TRAVERSAL OF THE BINARY SEARCH TREE IS:\n");
                            LevelorderTraversal( root );
                        }
            break;

            case 4 :    if( root == NULL )
                            printf("THE BINARY SEARCH TREE IS EMPTY.");
                        else{
                            printf("THE POSTORDER TRAVERSAL OF THE BINARY SEARCH TREE IS:\n");
                            PostorderTraversal( root );
                        }
            break;
                        
            case 9 :    exit(1);

            default :   printf("ENTER THE VALID CHOICE.");
        }
    }
    return 0;
}