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


void removedup(){
  if(head == NULL || head->next == NULL){
    return ;
  }

  struct node* ptr1 = head;
  struct node* ptr2 = head;
  while(ptr1){
    ptr2 = ptr1;

    while(ptr2->next != NULL){
      if(ptr1->data == ptr2->next->data){
        ptr2->next = ptr2->next->next;
      }
      else{
        ptr2=ptr2->next;
      }
    }
    ptr1=ptr1->next;

  }

}

int main(){

  int n;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    int data;
    scanf("%d",&data);
    insert(data);
  }
  removedup();

  print();

}
