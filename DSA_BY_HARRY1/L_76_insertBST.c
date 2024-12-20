#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};

void inorder(struct node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d",root->data);
        inorder(root->right);
    }
}

void insert(struct node *root,int key){
    struct node*prev=NULL;
    while(root!=NULL){
        prev=NULL;
        if(key==root->data){
            printf("Cant add %d already in BST : ",key);
            return ;
        }
        else if(key<root->data){
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    struct node* n=(struct node*)malloc(sizeof(struct node));
    n->data=key;
    n->left=NULL;
    n->right=NULL;
    if(key<prev->data){
        prev->left=n;
    }
    else{
        prev->right=n;
    }

}

struct node *createnode(){
    int data;
    printf("Enter the data(-1 for NULL) : ");
    scanf("%d",&data);
    if(data==-1){
        return NULL;
    }
    struct node *n=(struct node*)malloc(sizeof(struct node));
    if(n==NULL){
        printf("Node not cretated");
    }
    else{
        n->data=data;
        n->left=NULL;
        n->right=NULL;
        printf("Enter the left child of %d\n",data);
        n->left=createnode();
        printf("Enter the right child of %d\n",data);
        n->right=createnode();
        return n;
    }


}

int main (){
    struct node *root = createnode();
    printf("Elements in inorder : \n");
    inorder(root);
    insert(root,7);
    printf("%d",root->right->right->data);
}