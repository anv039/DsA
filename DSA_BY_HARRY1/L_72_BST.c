#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
void inorder(struct node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d",root->data);
        inorder(root->right);
    }
}

int isBST(struct node *root){
    static struct node *prev =NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data<=prev->data){
            return 0;
        }
        prev=root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
}
struct node *createnode(){
    int data;
    printf("Enter data (-1 for NULL) :");
    scanf("%d",&data);
    if(data==-1){
        return NULL;
        exit(-1);
    }
    struct node *n=(struct node*)malloc(sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    printf("Enter the left child of %d:\n",data);
    n->left=createnode();
    printf("Enter the right child of %d:\n",data);
    n->right=createnode();
}

int main(){
    struct node*root=createnode();
    printf("Elements in inordeer are : \n");
    inorder(root);
    printf("%d\n",isBST(root));
}