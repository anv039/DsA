#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* prev;
    struct node* next;
};
// Ab traverse karte hai Doubly Linked List me
void linkedlisttraversal(struct node *head){
    struct node * p=head;
    struct node* q=NULL;
    printf("Element in natural order : \n");
    while(p!=NULL){
        printf("%d ",p->data);
        q=p;
        p=p->next;
    }
    printf("Element in reverse order : \n");
    while(q!=NULL){
        printf("%d ",q->data);
        q=q->prev;
    }
}

// Yha se main code hai
struct node *head,*newnode,*temp;
int main(){
    int choice;
    head=NULL;
    newnode=NULL;
    temp=NULL;
    while(choice){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter the data : ");
        scanf("%d",&newnode->data);
        newnode->prev=NULL;
        newnode->next=NULL; 
        if(head==NULL){
            head=temp=newnode;
        }
        else{
            temp->next=newnode;
            newnode->prev=temp;
            temp=newnode;
        }
        printf("Enter your choice(0 to stop,1 to continue) : ");
        scanf("%d",&choice);
    }
    linkedlisttraversal(head);

    return 0;
}