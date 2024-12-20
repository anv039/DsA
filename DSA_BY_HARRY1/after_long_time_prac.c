#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};

// LIst traversal and printing
void listtraversal(struct node* ptr){
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}

// CASE 1 : Deletion from the beginning
// Yani jo struct node type ka pointer hai wahi return karega
struct node* deleteFirst(struct node *head){
    struct node *ptr=head;
    head=head->next;
    free(ptr);
    return head;
}

// CASE 2:Delete the element at the given index
// Mai waha tak dusre pointer ko chalata jaunga jab tk delete hone wale pointer pe q na phuch jae
struct node* deleteatindex(struct node* head,int index){
    struct node* p = head;
    struct node* q = head->next;
    for(int i=0;i<index-1;i++){
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    return head;
}

//CASE 3: Delete from the end
struct node* deleteend(struct node*head){
    struct node* p=head;
    struct node* q=head->next;
    while(q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;
}

// CASE 4: Delete a node with a given value 
struct node* deleteatindex(struct node* head,int value){
    struct node * p=head;
    struct node * q=head->next;
    while(q->data!=value && q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    if (q->data=value){
        p->next=q->next;
        free(q);
    }
    return head;
}

struct node *head,*newnode,*temp;
int main(){
    int choice;
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
        }
        printf("Enter your choice(0 to stop,1 to continue) : ");
        scanf("%d",&choice);
    }
    printf("\n Linked list traversal before deletion : ");
    listtraversal(head);

    // head=deleteFirst(head); //ye ek aisi linked list return karega jiska first node remove ho chuka hai
    // printf("\n Linked list traversal after deletion : ");
    // listtraversal(head);
    // return 0;

    // Delete at a particular index
    // head=deleteatindex(head,2);
    // printf("Linked list after deletion : ");
    // listtraversal(head);

    // Delete from the end
    // head=deleteend(head);
    // printf("Linked list after deletion at end : ");
    // listtraversal(head);

    // CASE 4: Delete a node with a given value
    head=deleteatindex(head,3);
    printf("Linked list after deletion at end : ");
    listtraversal(head);
}


