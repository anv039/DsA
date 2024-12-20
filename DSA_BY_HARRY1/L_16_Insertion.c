#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
void linkedlisttraversal(struct node *ptr){
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}
struct node* insertatfirst(struct node* head,int data){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->next=head;
    ptr->data=data;
    head=ptr;
    return ptr;
}

struct node* insertatindex(struct node *head,int data,int index){
    struct node* ptr=(struct node*)malloc(sizeof(struct node)); // Yha mai phle ek naya node to bana lu
    struct node *p=head ; // as mujhe traverse karna padega to naya pointer jo ki ek pahle tak jaega position ot be inserted ke
    int i=0;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;
}

struct node* insertatend(struct node *head,int data){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    struct node*p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    ptr->data=data;
    p->next=ptr;
    ptr->next=NULL;
    return head;
}

struct node* insertafternode(struct node*head,struct node* prevnode,int data){
    // Mujhe har ek funtion me ek naya to banana hi hai node
    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=prevnode->next;
    prevnode->next=ptr;
    return head;
}

int main(){
    struct node *head,*second,*third;
    head=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));
    head->data=7;
    head->next=second;

    second->data=11;
    second->next=third;

    third->data=66;
    third->next=NULL;

    printf("Linked List Before Insertion : ");
    linkedlisttraversal(head);
    //head=insertatfirst(head,56);
    //insertatindex(head,56,1);
    insertatend(head,89);
    printf("\nLinked List After Insertion : ");
    linkedlisttraversal(head);
    insertafternode(head,second,45);
    printf("\nLinked List After Insertion of a particular node: ");
    linkedlisttraversal(head);
    return 0;
}