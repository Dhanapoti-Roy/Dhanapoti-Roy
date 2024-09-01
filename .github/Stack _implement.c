#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
} ;

struct node *head=NULL;

void push(int item){
    if(head==NULL){
        head=(struct node*)malloc(sizeof(struct node));
        head->data=item;
        head->next =NULL;
        printf("insert done\n");
    }
    else{
        struct node *newNode=malloc(sizeof(struct node));
        newNode->data=item;
        newNode->next=head;
        head=newNode;
        printf("insert done\n");
    }
}
void pop(){
    if(head==NULL){
        printf("stack is empty!\n");
    }
    else{
        struct node *temp=head;
        head=head->next;
        printf("\n%d is poped from the stack\n",temp->data);
        free(temp) ;   
    }

}
void print(){
    struct node *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main(){
    /*push(10);
    push(20);
    push(30);*/

    FILE *file =fopen("data2.txt","r");
    if(file==NULL){
        printf("error opening!\n");
    }
    else{
        while(!feof(file)){
            int value;
            if(fscanf(file,"%d",&value)==1){
                push(value);
            }
        }
        fclose(file);
    }
    print();
    pop();
    print();
    return 0;
}
