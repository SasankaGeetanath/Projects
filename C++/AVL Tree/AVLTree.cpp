#include<iostream>
using namespace std;

class AVLTree {
    public:
        int data;
        Node *left;
        Nodde *right;
 };

 int BalanceFactor( Node ptr ) {
     int left = BalanceFactor( this -> ptr -> left );
     int right = BalanceFactor( this -> ptr -> right );
     return left - right;
 }

 void inorderTraversal( Node ptr ) {
     if( this -> ptr != NULL ) {
         inorderTraversal( this -> ptr -> left );
         printf("->%d\t", this -> ptr -> data );
         inorderTraversal( this -> ptr -> right );
     }
 }

 void preorderTraversal( Node ptr ) {
     if( this -> ptr != NULL ) {
         printf("->%d\t", this -> ptr -> data );
         preorderTraversal( this -> ptr -> left );
         preorderTraversal( this -> ptr -> right );
     }
 }

 void postorderTraversal( Node ptr ) {
     if( this -> ptr != NULL ) {
         postorderTraversal( this -> ptr -> left );
         postorderTraversal( this -> ptr -> right );
         printf("->%d\t", this -> ptr -> data );
     }
 }

 Node insertNode( Node ptr , int value ) {
     if( this -> ptr == NULL ) {
         Node *newnode = new Node;
         newnode -> left = NULL;
         newnode -> right = NULL;
         newnode -> data = value;
         ptr = newnode;
     }

    else if ( value < this -> ptr -> data ) 
        this -> ptr -> left = insertNode( this -> ptr -> left, value );
    else if ( value > this -> ptr -> data ) 
        this -> ptr -> right = insertNode( this -> ptr -> right, value );

    if ( BalanceFactor( this -> ptr ) > 1 && value < this -> ptr -> left -> data )
        return rrRotate( this -> ptr );
    else if ( BalanceFactor( this -> ptr ) < -1 && value > this -> ptr -> right -> data ) 
        return llRotate( this -> ptr );
    else if ( BalanceFactor( this -> ptr ) > 1 && value < this -> ptr -> left -> data ) 
        return lrRotate( this -> ptr );
    else if ( BalanceFactor( this -> ptr ) > -1 && value < this -> ptr -> left -> data )
        return rlRotate( this -> ptr );

    return ptr;
 }


