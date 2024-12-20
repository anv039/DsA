#include<stdio.h>
#include<stdlib.h>
struct stack{
    int size;
    int top;
    int *arr;//ye wo pointer hai jiski shayata se mai dynamically memory alloate karunga apne is array ke lie jo ki stack ko hold karega
};

int isEmpty(struct stack* ptr){
    if(ptr->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct stack* ptr){
    if(ptr->top==ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

void Push(struct stack * ptr,int val){
    if(isFull(ptr)){
        printf("Stack Overflow\n");
        return ;
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}

int pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow !!\n");
    }
    else{
        int val=ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

// L-27 time 11:00
int peek(struct stack *ptr,int i){
    if(ptr->top-i+1<0){
        printf("Invalid position ");
    }
    else{
        return ptr->top-i+1;
    }
}

// struct stack *sp=(struct stack*)malloc(sizeof(struct stack)) -->> ye mujhe dedega ye dynamically mujhe de dega hmaara struct stack ka ek instance aur ye instance aagye hmare pass 
// to mai uss instance ka size top aur arr hai arrow operator ke help se use kar skta hu
int main (){
    // struct stack s;
    // s.size=80;
    // s.top=-1;
    // s.arr=(int *)malloc(s.size*sizeof(int)); // mai array me integer tore karr ahu cilie maine ize of int likha hu ahai yha pe
    // Pahle s ek stack thi ab stack ek struct stack * likha to ye structure ka ek pointer ban gya
    struct stack *sp=(struct stack*)malloc(sizeof(struct stack)); // mai if stack pointer bana lu to mai is stack pointer ko functions ko pass kar skta hu call by reference AARAM SE ho jaega->
    sp->size=80;      //struct stack *sp iska matlab ek structur pointer ek aisa pointer jo ki adderess store krta hai ek structure ka-
    sp->top=-1;       //-Ab ye sirf ek pointer hai ye ek stack pointer hai jo ki stack structure ke instance ko point karta hai-
    sp->arr=(int *)malloc(sp->size*sizeof(int)); //- mujhe yaha pe actual structure ka ek instance v banana padega jo ki ma idynamically bnaunga

    // Pushing an element into stack 
    sp->arr[0]=4;
    sp->top++;


    // Check if stack is empty
    if(isEmpty(sp)){
        printf("Stack is empty ");
    }
    else{
        printf("Stack is not empty");
    }
    return 0;
}