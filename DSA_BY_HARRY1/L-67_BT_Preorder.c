#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createnode(int data){
    struct node *n=(struct node*)malloc(sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}

void preorder(struct node *root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node *root){
    if(root!=NULL){
        postorder(root->left);
        //printf("%d",root->left);
        postorder(root->right);
        //printf("%d",root->right);
        printf("%d ",root->data);
    }
}

void inorder(struct node *root){
    if(root!=NULL){
        
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

int main (){
    struct node *p=createnode(4);
    struct node *p1=createnode(1);
    struct node *p2=createnode(6);
    struct node *p3=createnode(5);
    struct node *p4=createnode(2);

    // Finally The tree looks like this:
    //      4
    //     / \
    //    1   6
    //   / \
    //  5   2 

    //Linking the node wuth the left and right child
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    preorder(p);
    postorder(p);
    inorder(p);
}

// This was just the practice to automate taking the node inputs and making them tree
// struct node* createtree(){
//     int data;
//     printf("ENter the data (-1 for NULL): ");
//     scanf("%d",&data);

//     if(data==-1){
//         return NULL;
//     }
//     struct node *n=(struct node*)malloc(sizeof(struct node));
//     if(n==NULL){
//         printf("MEmory not allocated\n");
//         exit(1);
//     }
//     else{
//         n->data=data;
//         n->left=NULL;
//         n->right=NULL;

//         printf("Enter the left child f %d\n",data);
//         n->left=createtree();

//         printf("Enter the left child f %d\n",data);
//         n->right=createtre();
//     }
//     return  n;
    
// }