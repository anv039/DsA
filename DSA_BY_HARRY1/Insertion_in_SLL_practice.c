#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next;
};
 
// YHa maine  traversal kara lia 
void linkedlisttraversal(struct node* head){
    struct node *ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}

// insert krne k lie ek nayya bnate hai function 
struct node * insertatindex(struct node*head,int data,int index){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    struct node* p=head;
    ptr->data=data;
    for(int i=0;i<index-1;i++){
        p=p->next;
    }
    ptr->next=p->next;
    p->next=ptr;
    return head;
}

struct node *delatfirst(struct node *head){
    struct node *p=head;
    head=head->next;
    free(p);
    return head;
}
struct node *delatidx(struct node *head,int idx){
    struct node *p=head;
    struct node *q=head->next;
    for (int i =0;i<idx-1;i++){
        p=p->next;
        q=q->next;
    }
    p->next-q->next;
    free(q);
    return head;
}
struct node* delatlasst(struct node*head){
    struct node*p=head;
    struct node*q=head->next;
    while(q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;
}

// Yha se main function started hai
struct node *head,*newnode,*temp;
int main(){
    int choice;
    head=NULL;
    while(choice){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("ENter ythe data : ");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head==NULL){
            head=temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
        printf("Enter your choice(0 to stop,1 to continue) : ");
        scanf("%d",&choice);
    }
    printf("LL before insertion : \n");
    linkedlisttraversal(head);


    head=insertatindex(head,5,2);
    printf("LL after insertion : \n");
    linkedlisttraversal(head);
    return 0;
}