#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node* next;

};

struct node* head = NULL;

void insert(int data){
  if(head == NULL){
    struct node * new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
  }
  else{
    struct node * new_node = (struct node*) malloc(sizeof(struct node));
    struct node* top = head;
    while(top->next != NULL){
      top =top->next;
    }
    new_node->data = data;
    top->next = new_node;
    new_node->next = NULL;
  }
}

void print(){
  while(head !=NULL){
    printf("%d\n",head->data );
    head = head->next;
  }
}

void swap(int a,int b){
  struct node * top = head;
  while (head) {
    if(head->data == a){
      head->data = b;
    }
    else if(head->data == b){
      head->data = a;
    }
    head = head->next;
  }

  head = top;
}

int main(){

    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
      int data;
      scanf("%d",&data);
      insert(data);
    }

int a,b;
scanf("%d",&a );
scanf("%d",&b);

  swap(a,b);

  print();



}
