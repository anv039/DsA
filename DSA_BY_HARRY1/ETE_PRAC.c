// #include<stdio.h>
// #include<stdlib.h>
// struct node{
//     int data;
//     struct node* left;
//     struct node*right;
// };

// struct node* inoerderpredecessor(struct node *root){
//     root=root->left;
//     while(root->right!=NULL){
//         root=root->right;
//     }
//     return root;
// }
// struct node *deletenode(struct node* root,int value){
//     struct node*ipre;
//     // Base condition
//     if(root==NULL){
//         return NULL;
//     }
//     if(root->left==NULL && root->right==NULL){
//         free(root);
//         return NULL;
//     }
//     // Ab mujhe kaatna chatna hai 
//     if(value<root->data){
//         root->left=deletenode(root->left,value);
//     }
//     else if(value>root->data){
//         root->right=deletenode(root->right,value);
//     }
//     // Ab itnwa recursive call jkek bad hogya iska matlab ab mai uss root pe agya jispe operation karna hai 
//     else{
//         ipre=inoerderpredecessor(root);
//         root->data=ipre->data;
//         root->left=deletenode(root->left,ipre->data);

//     }
//     return root;
// }

// #include<stdio.h>
// #include<stdlib.h>
// struct node{
//     int data;
//     struct node  *next;
// };
// void llt(struct node *ptr){
//     while(ptr!=NULL){
//         printf("%d",ptr->data);
//         ptr=ptr->next;
//     }
// }
// struct node *insatbeg(struct node* head,int val){
//     struct node*ptr=(struct node*)malloc(sizeof(struct node));
//     ptr->data=val;
//     ptr->next=head;
//     head=ptr;
//     return ptr;
// }
// struct node *insertatindex(struct node*head,int val,int idx){
//     struct node *p=head;
//     struct node*ptr=(struct node*)malloc(sizeof(struct node));
//     ptr->data=val;
//     int i=0;
//     while(i!=idx-1){
//         p=p->next;
//     }
//     ptr->next=p->next;
//     p->next=ptr;
//     return head;
// }
// struct node *insatend(struct node *head,int val){
//     struct node*ptr=(struct node*)malloc(sizeof(struct node));
//     struct node *p=head;
//     while(p->next!=NULL){
//         p=p->next;
//     }
//     ptr->data=val;
//     p->next=ptr;
//     ptr->next=NULL;
//     return head;
// }

// struct node *head,*temp,*newnode;
// int main (){
//     int choice ;
//     head=NULL;
//     while(choice){
//         newnode=(struct node*)malloc(sizeof(struct node));
//         printf("Enter the data : ");
//         scanf("%d",&newnode->data);
//         newnode->next=NULL;
//         if(head==NULL){
//             head=temp=newnode;
//         }
//         else{
//             temp->next=newnode;
//             temp=newnode;
//         }
//         printf("ENter your choice (0 to stop,1 to continue):");
//         scanf("%d",&choice);
//     }
//     return 0;
// }

// #include<stdio.h>
// #include<stdlib.h>
// struct node{
//     int data;
//     struct node *next;
// };
// struct node *traver(struct node *head){
//     struct node*p=head;
//     do{
//         printf("%d",p->data);
//         p=p->next;
//     }while(p!=head);
// }
// struct  node *insertfirst(struct node *head,int value){
//     struct node*ptr=(struct node*)malloc(sizeof(struct node));
//     ptr->data=value;
//     struct node*p=head->next;
//     while(p->next!=head){
//         p=p->next;
//     }
//     p->next=ptr;
//     ptr->next=head;
//     head=ptr;
//     return head;
// }

// struct node *delatfirst(struct node *head){
//     struct node*p=head;
//     struct node*q=head->next;
//     do{
//         p=p->next;
//     }while(p!=head);
//     p->next=q;
//     free(head);
//     head=q;
// }

// #include<stdio.h>
// #include<stdlib.h>
// struct node{
//     int data;
//     struct node *next;
// };
// void traversal(struct node *ptr){
//     while(ptr!=NULL){
//         printf("%d",ptr->data);
//         ptr=ptr->next;
//     }
// }
// struct node *top=NULL;
// int isFull(struct node*top){
//     struct node *n=(struct node*)malloc(sizeof(struct node));
//     if (n==NULL){
//         return 1;
//     }
//     else 
//         return 0;
// }

// int isEmp(struct node *top){
//     if (top==NULL){
//         return 1;
//     }
//     else
//         return 0;
// }

// struct node* push(struct node*top,int val){
//     if(isFull(top)){
//         printf("CAnt push its full");
//     }
//     else{
//         struct node *ptr=(struct node*)malloc(sizeof(struct node));
//         ptr->data=val;
//         ptr->next=top;
//         top=ptr;
//         return top;
//     }
        
// }

// int pop(struct node*tp){
//     if(isEmp(tp)){
//         printf("Its already empty");
//     }
//     else{
//         struct node*p=tp;
//         top=(tp)->next;
//         int x=p->data;
//         free(p);
//         return x;
//     }
// }
#include<stdio.h>
#include<stdlib.h>
struct stack{
    int size;
    int top;
    char *arr;
};
char *infixtopostfix(char * infix){
    struct stack *sp=(struct stack *)malloc(sizeof(struct stack));
    sp->size=10;
    sp->top=-1;
    sp->arr=(char*)malloc(sp->size*sizeof(char));
    char *postfix=(char*)malloc(sizeof(char)*strlen(infix)+1);
    int i,j=0;
    while(infix[i]!='\0'){
        if(!isOPerator(sp)){
            postfix[j]=infix[i];
            j++;
            i++;
        }
        else{
            if(precedence(infix[i])>precedence(sp->arr[sp->top])){
                push(sp,infix[i]);
                i++;
            }
            else{
                postfix[j]=pop(sp);
                j++;
            }

        }

    }
    while(!isEmpty(sp)){
        postfix[j]=pop(sp);
        j++;
    }
    
}