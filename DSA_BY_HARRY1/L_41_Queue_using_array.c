#include<stdio.h>
#include<stdlib.h>
struct queue{
    int size;
    int f;
    int r;
    int *arr;
};
 
int isFull(struct queue* q){
    if(q->r==q->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(struct queue *q){
    if(q->f==q->r){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(struct queue*q,int val){
    if(isFull(q)){
        printf("This queue is Full\n");
    }
    else{
        q->r++;
        q->arr[q->r]=val;
    }
}

int dequeue(struct queue* q){
    int a=-1;
    if(isEmpty(q)){
        printf("The queue is Empty cant dequeue\n ");
    }
    else{
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

void display(struct queue *q){
    for (int i=0;i<=q->r;i++){
        printf("Element is : %d\n",q->arr[i]);
    }
}

int main (){
    struct queue *q=(struct queue*)malloc(sizeof(struct queue));
    q->size=100;
    q->r=q->f=-1;
    q->arr=(int*)malloc(q->size*sizeof(int));

    int choice,val;
    printf("Enter the operation you want to perform : \n");
    printf("1.Enqueue\n2.Dequeue\n3.Display");

    do{
        printf("\nEnter your choice : ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("\nEnter the value to enqueue  : ");
                scanf("%d",&val);
                enqueue(q,val);
                break;
            case 2:
                printf("Dequeued Element is : %d",dequeue(q));
                break;
            case 3:
                display(q);
                break;
            default:
                printf("Invalid choice");
                break;
        }
    }while(choice!=4);
    return 0;
}



// #include<stdio.h>
// #include<stdlib.h>
// struct node {
//     int data;
//     struct node *next;
// };
// struct queue{
//     struct queue *front;
//     struct queue *rear;
// };
// void enqueue(int val){
    
// }