#include<stdio.h>
#include<stdlib.h>
struct stack{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack*ptr){
    if(ptr->top==-1){
        return 1;
    }
    else 
        return 0;
}

int isFull(struct stack *ptr){
    if(ptr->top==ptr->size-1){
        return 1;
    }
    else
        return 0;
}

void push(struct stack *ptr,int val){
    if(isFull(ptr)){
        printf("Stack Overflow \n");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}

int pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack Undeflow\n");
    }
    else{
        int val=ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek(struct stack *ptr,int i ){
    if (ptr->top-i+1<0){
        printf("Invalid Position \n");
    }
    else{
        return ptr->top-i+1;
    }
}

void display(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack empty ");
    }
    else{
        for(int i=ptr->top;i>=0;i--){
            printf("%d\n",ptr->arr[i]);
        }
    }
}

int stackTop(struct stack * ptr){
    return ptr->arr[ptr->top];
}

int stackBottom(struct stack *ptr){
    return ptr->arr[0];
}

int main (){
    struct stack *sp=(struct stack*)malloc(sizeof(struct stack));
    sp->size=80;
    sp->top=-1;
    sp->arr=(int*)malloc(sp->size*sizeof(int));

    int choice,value,pos;
    printf("Stack Operation \n");
    printf("1.Push\n2. Pop\n3. Peek\n4. display\n5.exit");

    do{
        printf("Enter your choice : \n");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("ENter the value to Push :");
                scanf("%d",&value);
                push(sp,value);
                break;
            
            case 2:
                printf("Pop an element form the stack :\n");
                pop(sp);
                break;

            case 3:
                printf("Enter the position of eleemnt u want :\n");
                scanf("%d",&pos);
                int u =peek(sp,pos);
                printf("\nPeek value is %d",u);
                break;

            case 4:
                display(sp);
                break;

            case 5:
                printf("The topmost element is : %d\n",stackTop(sp));
                break;

            case 6:
                printf("exiting ");
                break;

            default:
                printf("Invalid choice");
                break;
        }
    }while(choice!=6);
    return 0;
}