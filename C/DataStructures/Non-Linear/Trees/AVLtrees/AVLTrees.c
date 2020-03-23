#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

typedef struct Node* node;

node LLrotate( node ptr ){
    node temp = ptr -> left;
    ptr -> left = temp -> left;
    temp -> right = ptr;
    return temp;
}

node RRrotate( node ptr ){
    node temp = ptr -> right;
    ptr -> right = temp -> right;
    temp -> left = ptr;
    return temp;
}

node LRrotate( node ptr ){
    ptr -> left = LLrotate( ptr -> left );
    return RRrotate( ptr );
}

node RLrotate( node ptr ){
    ptr -> right = RRrotate( ptr -> right );
    return LLrotate( ptr );
}

int Height( node ptr ){
    if( ptr == NULL )
        return -1;
    else{
        int LeftHeight, RightHeight;
        LeftHeight = Height( ptr -> left );
        RightHeight = Height( ptr -> right );
        if( LeftHeight > RightHeight )
            return LeftHeight + 1;
        else
            return RightHeight + 1;
    }
}

int CheckBalance( node ptr ){
    int Left = Height( ptr -> left );
    int Right = Height( ptr -> right );
    return Left - Right;
}

void InorderTraversal( node ptr ){
    if( ptr != NULL ){
        InorderTraversal( ptr -> left );
        printf("->%d\t", ptr -> data );
        InorderTraversal( ptr -> left );
    }
}

void PreorderTraversal( node ptr ){
    if( ptr != NULL ){
        printf("->%d\t", ptr -> data );
        PreorderTraversal( ptr -> left );
        PreorderTraversal( ptr -> right );
    }
}

void PostorderTraversal( node ptr ){
    if( ptr != NULL ){
        PostorderTraversal( ptr -> left );
        PostorderTraversal( ptr -> right );
        printf("->%d\t", ptr -> data );
    }
}

node InsertNode( node ptr, int value ){
    if( ptr == NULL ){
        node new_node = (node)malloc(sizeof(node));
        new_node -> data = value;
        new_node -> left = NULL;
        new_node -> right = NULL;
        ptr = new_node;
    }
    else if( value < ptr -> data  )
        ptr -> left = InsertNode( ptr -> left , value );
    else if( value > ptr -> data )
        ptr -> right = InsertNode( ptr -> right , value );

    if( CheckBalance( ptr ) > 1 && value < ptr -> left -> data )
        return RRrotate( ptr );
    else if( CheckBalance( ptr ) < -1 && value > ptr -> right -> data )
        return LLrotate( ptr );
    else if( CheckBalance( ptr ) > 1 && value > ptr -> left -> data )
        return LRrotate( ptr );
    else if( CheckBalance( ptr ) < -1 && value < ptr -> right -> data )
        return RLrotate( ptr );
    
    return ptr;
}

int main(){
    int choice , input;
    node root = NULL;
    while(1){
        printf("\n\n\tAVL TREE\t\n\n");
        printf("\n1.ENTER TO INSERT AN NODE INTO THE TREE.");
        printf("\n2.ENTER TO FIND THE INORDER TRAVERSAL OF THE AVL TREE.");
        printf("\n3.ENTER TO FIND THE PREORDER TRAVERSAL OF THE AVL TREE.");
        printf("\n4.ENTER TO FIND THE POSTORDER TRAVERSAL OF THE AVL TREE.");
        printf("\n5.ENTER TO FIND THE HEIGHT OF THE AVL TREE.");
        printf("\n6.EXIT.");
        printf("\n\nENTER YOUR CHOICE : ");
        scanf("%d", &choice);

        switch( choice ){

            case 1 :    printf("ENTER THE NODE TO BE INSERTED : ");
                        scanf("%d", &input );
                        root = InsertNode( root, input );
            break;

            case 2 :    if( root == NULL )
                            printf("THE AVL TREE IS EMPTY.");
                        else 
                            InorderTraversal( root );
            break;

            case 3 :    if( root == NULL )
                            printf("THE AVL TREE IS EMPTY.");
                        else 
                            PreorderTraversal( root );
            break;

            case 4 :    if( root == NULL )
                            printf("THE AVL TREE IS EMPTY.");
                        else 
                            PostorderTraversal( root );
            break;

            case 5 :    if( root == NULL )
                            printf("THE AVL TRESS IS EMPTY.");
                        else
                            printf("THE HEIGHT OF THE AVL TREE IS : %d ", Height( root ) );
            break;

            case 6 :    exit(1);

            default :   printf("ENTER THE VALID CHOICE.");
        }
    }
    return 0;
}