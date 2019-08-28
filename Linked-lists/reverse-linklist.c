#include<stdio.h>
struct node{
  int data;
  struct node * next;
};
struct node* head = NULL;

void reverse (){
  struct node * curr = head , *next = NULL , *prev = NULL;

  while(curr!=NULL){
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }

  head = prev;

}

void Insert(int data,int n){
  struct node* temp = (struct node *) malloc (sizeof(struct node));
  temp->data=data;
  temp->next=NULL;
  if(n==1){
    temp->next=head;
    head=temp;
    return;
  }

    struct node * temp2 = head;
    for(int i=0;i<n-2;i++){
      temp2=temp2->next;
    }
    temp->next=temp2->next;
    temp2->next=temp;

}

void print(){
  struct node * temp1=head;

  while(temp1!=NULL){
    printf("%d ",temp1->data );
    temp1=temp1->next;
  }

}


int main(){

  int n;
  scanf("\n%d",&n);
  int data,pos;
  for(int i=0;i<n;i++){
    printf("Enter The element");
    scanf("\n%d",&data);
    printf("Enter The position");
    scanf("\n%d",&pos);
    Insert(data,pos);
  }

  print();

  reverse();
  print();

}
