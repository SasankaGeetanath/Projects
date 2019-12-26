#include<stdio.h>
#include<stdlib.h>
#define MAX 100

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

int front = -1, rear = -1, queue[MAX];

typedef struct Node* node;

int isEmpty(){
    return front = rear;
}

void enQueue( node ptr ){
    if( isEmpty() )
        front = rear = 0;
    queue[rear] = ptr -> data;
    rear++;
}

void deQueue(){
    front++;
}

int peek(){
    return queue[front];
}

int MinNode( node ptr ){
    if ( ptr -> left == NULL )
        return ptr -> data;
    else
        return MinNode( ptr -> left);
}

int MaxNode( node ptr ){
    if ( ptr -> right == NULL )
        return ptr -> data;
    else 
        return MaxNode( ptr -> right );
}

int SearchNode( node ptr , int value ){
    int flag = 0;
    while( ptr != NULL ){
        if (ptr -> data == value )
            flag = 1;
        else if ( value < ptr -> data )
            SearchNode( ptr -> right , value );
        else 
            SearchNode( ptr -> left, value );
    }
    return flag;
}

void InorderTraversal( node ptr ){
    if ( ptr != NULL ){
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

void PostorderTraversal( node ptr ){
    if ( ptr != NULL){
        PostorderTraversal( ptr -> left );
        PostorderTraversal( ptr -> right );
        printf("->%d\t", ptr -> data );
    }
}

node InsertNode( node ptr , int value ){
    if ( ptr == NULL ){
        node new_node = (node)malloc(sizeof(node));
        new_node -> data = value;
        new_node -> left = NULL;
        new_node -> right = NULL;
        ptr = new_node;
    }
    else if ( value < ptr -> data )
        ptr -> left = InsertNode( ptr -> left , value );
    else if( value > ptr -> data )
        ptr -> right = InsertNode( ptr -> right, value );
    return ptr;
}

node DeleteNode( node ptr, int value ) {
    if ( ptr == NULL )
        return ptr;
    else if ( value < ptr -> data )
        ptr -> left = DeleteNode( ptr -> left , value);
    else if ( value > ptr -> data )
        ptr -> right = DeleteNode( ptr -> right , value);
    else {
        if ( ptr -> left == NULL && ptr -> right == NULL ){
            free ( ptr );
            ptr = NULL;
        }
        else if ( ptr -> left == NULL ){
            node temp = ptr;
            ptr = ptr -> right;
            free( temp );
        }
        else if ( ptr -> right == NULL ){
            node temp = ptr;
            ptr = ptr -> left;
            free ( temp );
        }
        else{
            int temp = MinNode( ptr -> right );
            ptr -> data = temp;
            ptr -> right = DeleteNode( ptr -> right, temp );
        }
        return ptr;
    }
}

int Height( node ptr ){
    int LeftHeight, RightHeight;
    if( ptr == NULL )
        return -1;
    else{
        LeftHeight = Height( ptr -> left );
        RightHeight = Height( ptr -> right );
        if( LeftHeight > RightHeight )
            return LeftHeight + 1;
        else 
            return RightHeight + 1;
    }
}

void LevelorderTraversal( node ptr ){
    enQueue(ptr);
    while( !isEmpty() ){
        node temp = peek();
        deQueue();
        printf("->%d\t", temp -> data );
        if( temp -> left != NULL )
            enQueue( temp -> left );
        if( temp -> right != NULL )
            enQueue( temp -> right );
    }
}


int main(){
    int input, choice;
    node root = NULL;

    while(1){
        printf( "\n\n\tBINARY SEARCH TREE\t\n\n" );
        printf( "\n1.ENTER TO INSERT A NODE INTO THE TREE." );
        printf( "\n2.ENTER TO DELETE A NODE FROM THE BINARY TREE." );
        printf( "\n3.ENTER TO FIND THE INORDER TRAVERSAL OF THE BINARY SEARCH TREE." );
        printf( "\n4.ENTER TO FIND THE PREORDER TRSVERSAL OF THE BINARY SEARCH TREE." );
        printf( "\n5.ENTER TO FIND THE POSTORDER TRAVERSAL OF THE BINARY SEARCH TREE." );
        printf( "\n6.ENTER TO FIND THE LEVELORDER TRAVERSAL OF THE BINARY SEARCH TREE.");
        printf( "\n7.ENTER TO FIND THE HEIGHT OF THE BINARY SEARCH TREE." );
        printf( "\n8.ENTER TO FIND THE MINIMUM NODE IN THE BINARY SEARCH TREE." );
        printf( "\n9.ENTER TO FIND THE MAXIMUM NODE IN THE BINARY SEARCH TREE." );
        printf( "\n10.EXIT" );
        printf( "\n\nENTER YOUR CHOICE :" );
        scanf( "%d", &choice );

        switch( choice ){

            case 1 :    printf( "ENTER THE NODE TO INSERT IN THE TREE :" );
                        scanf( "%d", &input );
                        root = InsertNode( root, input );
            break;

            case 2 :    printf( "ENTER THE NODE TO BE DELETED :" );
                        scanf( "%d", &input );
                        if( root == NULL )
                            printf("THE BINARY SEARCH TREE IS EMPTY.");
                        else{
                            if( SearchNode( root, input ) )
                                root = DeleteNode( root, input );
                            else 
                                printf("THE NODE IS NOT PRESENT IN THE BINARY SEARCH TREE.");
                        }
            break;

            case 3 :     if( root == NULL)
                            printf("THE BINARY SEARCH TREE IS EMPTY.");
                        else{
                            printf("THE INORDER TRAVERSAL FOR THE BINARY SEARCH TREE IS:\n");
                            InorderTraversal( root );
                        }
            break;

            case 4 :    if( root == NULL )
                            printf("THE BINARY SEARCH TREE IS EMPTY.");
                        else{
                            printf("THE PREORDER TRAVERSAL OF THE BINARY SEARCH TREE IS:\n");
                            PreorderTraversal( root );
                        }
            break;

            case 5 :    if( root == NULL )
                            printf("THE BINARY SEARCH TREE IS EMPTY.");
                        else{
                            printf("THE POSTORDER TRAVERSAL OF THE BINARY SEARCH TREE IS:\n");
                            PostorderTraversal( root );
                        }
            break;

            case 6 :    if( root == NULL )
                            printf("THE BINARY SEARCH TREE IS EMPTY.");
                        else{
                            printf("THE LEVELORDER TRAVERSAL OF THE BINARY SEARCH TREE IS :\n");
                            LevelorderTraversal( root );
                        }
            break;

            case 7 :    if( root == NULL && root -> left == NULL && root -> right == NULL )
                            printf("THE BINARY SEARCH TREE IS EMPTY.");
                        else
                            printf("%d IS THE HEIGHT IS THE BINARY SEARCH TREE.", Height( root ) );
            break;

            case 8 :    if( root == NULL )
                            printf("THE BINARY SEARCH TREE IS EMPTY.");
                        else
                            printf("%d IS THE MINIMUM NODE OF THE BINARY SEARCH TREE.", MinNode( root ) );
            break;

            case 9 :    if( root == NULL )
                            printf("THE BINARY SEARCH TREE IS EMPTY.");
                        else 
                            printf("%d IS THE MAXIMUM NODE OF THE BINARY SEARCH TREE.", MaxNode( root ) );
            break;

            case 10 :    exit(1);

            default :   printf("ENTER THE VALID CHOICE.");
        }
    }
    return 0;
}