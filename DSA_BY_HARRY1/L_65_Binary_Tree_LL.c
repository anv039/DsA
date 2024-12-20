#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node* createnode(int data){
    struct node *n=(struct node*)malloc(sizeof(struct node)); //Creating a node pointer and allocating the memory in the heap
    n->data=data; // Inserting the data
    n->left=NULL;  // Setting the right and left children to NULL
    n->right=NULL;  // Setting the right and left children to NULL
    return n;   // FInally returning th created node
}

int main (){
    // Constructing the root node
    /*struct node *p=(struct node*)malloc(sizeof(struct node));
    p->left=NULL;
    p->right=NULL;
    p->data=2;
    // Ab ye upar k 3 lines se maine ek aisa nide bna lia hai jiska bas ek root node hai 

    //Constructing the first left node
    struct node *p1=(struct node*)malloc(sizeof(struct node));
    p1->left=NULL;
    p1->right=NULL;
    p1->data=1;

    //Constructing the first right node
    struct node *p2=(struct node*)malloc(sizeof(struct node));
    p2->left=NULL;
    p2->right=NULL;
    p2->data=4;

    //Linking the root node with left and right children
    p->left=p1;
    p->right=p2;
    */

   // Constructing the root node using the functions 
   struct node *p=createnode(2);
   struct node *p1=createnode(1);
   struct node *p2=createnode(4);

   //Linking the root node with left and right children
    p->left=p1;
    p->right=p2;
    return 0;
}