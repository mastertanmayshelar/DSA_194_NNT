#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
struct node *head = NULL;
void push(int val){
    struct node*newnode = malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = head;
    head = newnode;
}
void pop(){
    struct node*temp;
    if(head==NULL){
        printf("stack is empty \n");
    }
    else{
        printf("poped element = %d\n",head->data);
        temp = head;
        head = head->next;
        free(temp);
    }
}
void printlist(){
    struct node*temp = head;
    while(temp!=NULL){
        printf("%d->" , temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main(){
    push(10);
    push(20);
    push(30);
    printf("Linked list \n");
    printlist();
    pop();
    printf("after the pop the new linked list :\n");
    printlist();
    pop();
    printf("after the pop, new linked list :\n");
    printlist();
    return 0;
}
