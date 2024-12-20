#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};

// Progrm for sll traversal
void linkedlisttraversal(struct node *ptr){
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}
// sabse pahle is full and is empty ko implement karleta hu top mera ek pointer hoga struct node type ka 
// iEMpty mere tack ka top lega aur isi ko dekh ke btaega ki mera full hogya hia ki  nahi
int isEmpty(struct node * top){
    if (top==NULL){
        return 1;
    }else{
        return 0;
    }
}

//IsFull bhi top hi lega 
int isFull(struct node* top){
    struct node *p=(struct node*)malloc(sizeof(struct node));
    if(p==NULL){
        return 1;
    } // iska matlab mai dynamically memory allocate nai kar para hu 
    else{
        return 0;
    }
}

//push me hamne sabse paghkle lement ko insert kia tha index 0 pe
// Ab jab mai push karra hu elements ko to mai is fulll check karunga 
struct node* push(struct node* top,int x){
    if(isFull(top)){
        printf("Stack Overflow");
    }
    else{
        struct node* n=(struct node*)malloc(sizeof(struct node));
        n->data=x;
        n->next=top;
        top=n;
        return top;
    }
} 
// Pop ka code yaha hai ye ek integer type return karega
int pop(struct node** top){
    if (isEmpty(*top)){
        printf("Stack Underflow \n");
    }
    else{
        struct node * n=*top;
        *top=(*top)->next;
        int x=n->data;
        free(n);
        return x;
    }
}

// Yha se main ka code start 
struct node *top,*newnode,*temp;
int main(){
    top = NULL; //top null ko point karra hai iska matlb ,eri linked list khali hai
    top = push (top,78);
    top = push (top,7);
    top = push (top,8);
    linkedlisttraversal(top);
    int element = pop(&top); // tack jo hai meri uska topmost pointer mai dera hu arr bolra hu ki ek elelment pop krke do arr btao o element kya hi
    printf("Popped element is : %d\n ",element );
    linkedlisttraversal(top); // output aisa icilie aara hai kiuki ham elements jo push karre hai wo ll ke starting me kare hai
    return 0;
}