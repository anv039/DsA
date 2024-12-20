// #include<stdio.h>
// #include<stdlib.h>


// struct node{
//     int data;
//     struct node *next;
// };

// struct node*f=NULL;
// struct node*r=NULL;

// void linkedlisttraversal(){
//     struct node *ptr=f;
//     printf("Printing the elements of this Queue : \n");
//     while(ptr!=NULL){
//         printf("%d\n",ptr->data);
//         ptr=ptr->next;
//     }
// }

// void enquque(int val){
//     struct node *n=(struct node*)malloc(sizeof(struct node));
//     if(n==NULL){  // Ya to yaha pe ham naya isFull function bana ke v check kar skte hai 
//         printf("Queue is FUll\n");
//     }
//     else{
//         n->data=val;
//         n->next=NULL;
//         if(f==NULL){
//             f=r=n;
//         }
//         else{
//             r->next=n;
//             r=n;
//         }
//     }
// }

// int dequeue(){
//     int val=-1;
//     struct node *p=f;
//     if(f==NULL){
//         printf("Nothing to dequeue");
//     }
//     else{
//         int val=f->data;
//         f=f->next;
//         free(p);
//     }
//     return val;
// }
// int main (){

//     // ye dono ko gobal variable ke jaise treat  karenge to ise pass krne ki vi jarurat nahi padegi
//     //sur naahi functions me likhne ki vi
//     // struct node*f=NULL;
//     // struct node*r=NULL;

//     enquque(7);
//     enquque(18);
//     enquque(71);
//     enquque(199);
//     dequeue();
//     dequeue();
//     linkedlisttraversal();
//     return 0;
// }


#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *f=NULL;
struct node *r=NULL;

void linkedlisttraversal(){
    struct node *ptr=f;
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}

void enqueue(int val){
    struct node *n=(struct node*)malloc(sizeof(struct node));
    if(n==NULL){
        printf("The Queue is Full");
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
    struct node *p=f;
    if(f==NULL){
        printf("THe queue is empty nothing to dequeue\n");
    }
    else{
        val=f->data;
        f=f->next;
        free(p);
    }
}

int main (){
    enqueue(78);
    enqueue(74);
    enqueue(56);
    enqueue(78);
    enqueue(12);
    enqueue(53);
    dequeue();
    linkedlisttraversal();
    return 0;
}