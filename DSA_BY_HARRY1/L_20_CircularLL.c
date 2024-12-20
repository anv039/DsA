#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};

// Traversal Code
void linkedlisttraversal(struct node* head){
    struct node* ptr=head;
    do {                            // Aur CLL traversal me bas ek bar push dene ke lie ek bar print karke aur
        printf("Element is : %d\n",ptr->data); //ptr ko next me daldia baki kaam khud se hogya
        ptr=ptr->next;
    }while(ptr!=head);
}

// Insert At first 
struct node* insertatfirst(struct node* head,int data){
    struct node * ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    struct node* p=head->next;
    while(p->next!=head){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=head;
    head=ptr;
    return head;
}

// Insert at any position in CLL
struct node* insertatindex(struct node* head,int data ,int index){
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    struct node*p=head;
    for(int i=0;i<index-1;i++){
        p=p->next;
    }
    ptr->next=p->next;
    p->next=ptr;
    return head;
}

// Deletion of the first node
// struct node* deleteFirst(struct node* head){
//     struct node*p=head->next; 
//     struct node *q=head;
//     while(q->next!=head){
//         q=q->next;
//     }
//     q->next=p;
//     free(head);
//     head=p;
//     return head;
// }

struct node* deleteFirst(struct node* head){
     
    struct node *p=head;
    struct node*q=head->next;
    do{
        p=p->next;
    }while(p!=head);
    p->next=q;
    free(head);
    head=q;
    return head;
}

// Yha se main code start
struct node *head,*newnode,*temp;
int main(){
    int choice ;
    head=NULL;
    while(choice){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter the data : ");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head==NULL){
            head=temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
            temp->next=head;  // Yha pe bas change karna pada hai Singly Linked List banane me aur Circular linked list karne me
        }
        printf("Enter your choice(0 to stop,1 to continue) : ");
        scanf("%d",&choice);
    }
    printf("Circular linked list before insertion : \n");
    linkedlisttraversal(head);

    // head=insertatfirst(head,54);
    // printf("Circular linked list after insertion : \n");
    // linkedlisttraversal(head);

    // insertatindex(head,56,2);
    // printf("After Insertion at specified position : \n");
    // linkedlisttraversal(head);

    head=deleteFirst(head);
    printf("After deletion first node : \n");
    linkedlisttraversal(head);
    return 0;
}