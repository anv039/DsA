#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};

void listtraversal(struct node*ptr){
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}
//Deleting the first element from the SLL
struct node* deletefrombeg(struct node*head){
    if (head==NULL){
        printf("Deletion is not possible");
        return NULL;
    }
    else{
        struct node* p=head;
        head=head->next;
        free(p);
        return head;
    }
}
// Deleting an element at an given index from The SLL
struct node* deleteatindex(struct node*head){
    int pos,i=1;
    printf("Enter the position which you want to delete :");
    scanf("%d",&pos);
    if (pos==1){
        return deletefrombeg(head);
    }
    //
    struct node*p=head;
    // Delete hone wale pointer tak q ko pahuchana hai matlab ye hi delete hone wala node hai
    struct node* q=head->next;
    //ele = 10 20 30
    //pos =  1  2  3
    while(i<pos-1){
        p=p->next;
        q=q->next;
        i++;
    }
    p->next=q->next;
    free(q);
    return head;
} 

// Delete from end
struct node* deletefromend(struct node*head){
    struct node*p=head;
    struct node*q=head->next;
    if(head==NULL){
        printf("No node is present to be deleted");
    }
    else{
        while(q->next!=NULL){
            p=p->next;
            q=q->next;
        }
    }
    p->next=NULL;
    free(q);
    return head;
}
// delete an element with a given value
struct node* deletewithvalue(struct node* head){
    struct node* p=head;
    struct node* q=head->next;
    int value=1;
    printf("Enter the value contained in a node which u want to delete :");
    scanf("%d",&value);
    // wahi delete karna hai jispe q baitha hua hoa
    while(q->data!=value);

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
        printf("Enter your choice (0 to stop , 1 to continue) : ");
        scanf("%d",&choice);
    }
    printf("\nList before deletion ");
    listtraversal(head);
    //head=deletefrombeg(head);
    // printf("\nList after deletion ");
    // listtraversal(head);
    //head=deleteatindex(head);
    //printf("\nList after deletion ");
    //listtraversal(head);
    head=deletefromend(head);
    printf("\nList after deleting the node at end : \n");
    listtraversal(head);
    return 0;
}