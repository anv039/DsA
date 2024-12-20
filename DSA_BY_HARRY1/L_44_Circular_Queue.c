#include<stdio.h>
#include<stdlib.h>
struct circularqueue{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct circularqueue *q){
    if((q->r+1)%q->size==q->f){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(struct circularqueue*q){
    if(q->f==q->r){
        return 1;
    }
    else {
        return 0;
    }
}

void enqueue(struct circularqueue *q,int val){
    if(isFull){
        printf("the circular queue is Full \n");
    }
    else{
        q->r=(q->r+1)%q->size;
        q->arr[q->r]=val;
    }
}

int dequeue(struct circularqueue*q){
    int a=-1;
    if(isEmpty){
        printf("The queue is empty cant dequeue \n");
    }
    else{
        q->f=(q->f+1)%q->size;
        a=q->arr[q->f];
    }
    return a;
}

int main (){
    struct circularqueue *q=(struct circularqueue*)malloc(sizeof(struct circularqueue));
    q->size=4;
    q->r=q->f=0;
    q->arr=(int*)malloc(q->size*sizeof(int));

    enqueue(q,12);
    enqueue(q,15);
    enqueue(q,1);
    // enqueue(q,2);
    printf("Dequeuing Element is %d\n",dequeue(q));
    printf("Dequeuing Element is %d\n",dequeue(q));
    printf("Dequeuing Element is %d\n",dequeue(q));
    printf("Dequeuing Element is %d\n",dequeue(q));
    if(isEmpty(q)){
        printf("Queue is empty\n");
    }
    if(isFull(q)){
        printf("Queue is full\n");
    }
    return 0;
}