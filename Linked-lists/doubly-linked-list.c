#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node * next;
  struct node * prev;
};

struct node* head = NULL;

void insertAtHead(int data){
  struct node* new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = head;
  new_node->prev = NULL;

  if(head !=NULL){
    head->prev = new_node;
  }
  head = new_node;
}

void insertAtN(int data, int pos){
  struct node * temp = head;

  if(pos == 0){
    insertAtHead(data);
  }

  for(int i=0;i<pos-1;i++){
        temp = temp->next;
  }

  struct node* new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = data;

  new_node->next = temp->next;

  new_node->prev = temp;

  if(temp->next !=NULL){
    temp->next->prev = new_node;
  }

  temp->next = new_node;


}

void print(){
  struct node * temp = head;

  if(temp == NULL){
    return ;
  }

  while(temp!=NULL){
    printf("%d\n", temp->data);
    temp = temp->next;
  }
}

void printRevrse(){
  printf("Printing in reverse\n");
  struct node * temp = head;
  while(temp->next!=NULL){
    temp = temp->next;
  }


  while(temp !=NULL){
    printf("%d\n",temp->data);
    temp = temp->prev;
  }

}

int main(){
  
  insertAtHead(1);

  insertAtN(2,1);
  insertAtN(3,2);
  print();
  printRevrse();

}
