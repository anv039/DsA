#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct node *f=NULL;
struct node *r=NULL;

void linkedlisttraversal(struct node *ptr){
    printf("Printing the elements of this linked list  : \n");
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}

void enqueue(int val){
    struct node *n=(struct node *)malloc(sizeof(struct node));
        if(n==NULL){
            printf("Quueue is full");
        }
        else{
            n->data=val;
            n->next=NULL;
            if(f==NULL){
                f=r=n;
            }
            else{
                r->next=n;
                r=n;
            }
        }
    
}

int dequeue(){
    int val=-1;
    struct node*ptr=f;
    if(f==NULL){
        printf("Queue is empty\n");
    }
    else{
        f=f->next;
        val=ptr->data;
        free(ptr);
    }
    return val;
}


int main (){
    
    linkedlisttraversal(f);
    printf("Dequeueing element is :%d\n",dequeue());
    enqueue(34);
    enqueue(4);
    enqueue(7);
    enqueue(71);
    printf("Dequeueing element is :%d\n",dequeue());
    linkedlisttraversal(f);
    return 0;
}