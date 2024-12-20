// #include<stdio.h>
// #include<stdlib.h>
// struct node{
//     int data;
//     struct node* next;
// };

// struct node* top=NULL;

// void linkedlisttaversal(struct node* ptr){
//     while(ptr!=NULL){
//         printf("Element is : %d\n",ptr->data);
//         ptr=ptr->next;
//     }
// }

// int isFull(struct node* top){ // Full wale case me maine ek ptr banaya arr nahi ban paya
//     struct node * p=(struct node*)malloc(sizeof(struct node));
//     if(p==NULL){
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }

// int isEmpty(struct node* top){ // yha pe to mujhe node v bnani nhi pdegi direct top ptr ko dekho ki null ko point karra hai to its mty
//     if (top==NULL){
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }

// // Iske lie mujhe ek node banani padegi jo mai insert karunga bnaung tabhi to insert karunga mai
// struct node * push(struct node * top,int x){
//     if (isFull(top)){
//         printf("Stack Overflow");
//     }   //ab push karra hu to sabse pahle check karunga full wali conditiom
//     else{
//         struct node* n=(struct node*)malloc(sizeof(struct node));
//         n->data=x;
//         n->next=top;
//         top=n;
//         return top;
//     }
// }

// int pop(struct node * tp){
//     if(isEmpty(top)){
//         printf("Stack Underflow");
//     }
//     else{
//         struct node* n=tp;
//         int x=n->data;
//         top=tp->next; // Global var arr local wale ka dikkt hora tha to nai kia wese 
//         free(n);
//         return x;
//     }
// }
// int peek(struct node* top,int pos){
//     struct node* p=top;
//     for(int i=0;(i<pos-1 && p!=NULL);i++){
//         p=p->next;
//     }
//     if(p!=NULL){
//         return p->data;
//     }
//     else return -1;
// }

// int main(){
//     int choice ,element,pos;
//     do{
//         printf("chosse an operation\n");
//         printf("1. push an element\n");
//         printf("2. pop an element\n");
//         printf("3. Display stack \n");
//         printf("4. Peek element\n");
//         printf("5. Exit\n");
//         printf("Enter your choice : ");
//         scanf("%d",&choice);

//         switch (choice){
//             case 1:
//                 printf("Enter the element you want to oush : ");
//                 scanf("%d",&element);
//                 top=push(top,element);
//                 break;
//             case 2:
//                 element=pop(top);
//                 printf("The popped element is : %d",element);
//                 break;
//             case 3:
//                 linkedlisttaversal(top);
//                 break;
//             case 4:
//                 printf("Enter the position of element you want : ");
//                 scanf("%d",&pos);
//                 int x=peek(top,pos);
//                 printf("The element at %d pos is : %d\n",pos,x);
//                 break;
//             case 5:
//                 printf("Exiting");
//                 break;
//             default:
//                 printf("Invalid choice ");
//         }
//     }while(choice !=5);
//     return 0;
// }


// INFIX TO POSTFIX

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    char *arr;
};

int stacktop(struct stack *ptr){
    return ptr->arr[ptr->top];
}

int isEmpty(struct stack *ptr){
    if(ptr->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct stack *ptr){
    if(ptr->top==ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack *ptr,char val){
    if(isFull(ptr)){
        printf("Cant push");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}

int pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Cant pop coz it is empty");
    }
    else{
        char val=ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int isOperator(char ch){
    if(ch=='+' || ch=='-' || ch=='/' || ch=='*'){
        return 1;
    }
    else{
        return 0;
    }
}

int precedence(char ch){
    if (ch=='*' || ch=='/'){
        return 3;
    }
    else if(ch=='+' || ch=='-'){
        return 2;
    }
    else{
        return 0;
    }
}

char *infixtopostfix(char* infix){
    struct stack *sp=(struct stack*)malloc(sizeof(struct stack)); // sabse pahle ek stack bna lena 
    sp->size=100;
    sp->top=-1;
    sp->arr=(char*)malloc(sp->size*sizeof(char));
    char *postfix=(char*)malloc(strlen(infix+1)*sizeof(char)); //
    int i=0,j=0;
    while(infix[i]!='\0'){
        if(!isOperator(infix[i])){
            postfix[j]=infix[i];
            i++;
            j++;
        }
        else{
            if(precedence(infix[i])>precedence(stacktop(sp))){  // Yha se ab stack ki baat hori hai 
                push(sp,infix[i]);
            }
            else{
                postfix[j]=pop(sp);
                j++;
            }
        }
        while(isEmpty(sp)){
            postfix[j]=pop(sp);
            j++;
        }
        postfix[j]='\0';
    }
}
int main(){
    char * infix="x-y+z*ghjo-/";
    printf("Postfix is : %s",infixtopostfix(infix));
    return 0;
}