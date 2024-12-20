#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

// struct node* createTree(){
//     int data;
//     printf("Enter data (-1 for NULL): ");
//     scanf("%d", &data);

//     if (data == -1) {
//         return NULL;
//     }

//     struct node *newNode = (struct node*)malloc(sizeof(struct node));
//     if (newNode == NULL) {
//         printf("Memory allocation failed\n");
//         exit(1);
//     }
//     newNode->data = data;
//     newNode->left = NULL;
//     newNode->right = NULL;

//     printf("Enter left child of %d\n", data);
//     newNode->left = createTree();

//     printf("Enter right child of %d\n", data);
//     newNode->right = createTree();

//     return newNode;
// }

struct node *createtree(){
    int data;
    printf("Enter the DATA(-1 for NULL) : ");
    scanf("%d",&data);
    if(data==-1){
        return NULL;
    }
    struct node*n=(struct node*)malloc(sizeof(struct node));
    if(n==NULL){
        printf("Memory Allocation not done\n");
        exit(1);
    }
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    printf("Enter the left child of %d :\n",data);
    n->left=createtree();
    printf("Enter the data of the right child %d\n",data);
    n->right=createtree();

    return n;
}

void preorder(struct node *root){
    if(root!=NULL){
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main (){
    printf("Create the binary tree:\n");
    struct node *root = createtree();

    printf("\nPreorder traversal of the tree:\n");
    preorder(root);

    return 0;
}



