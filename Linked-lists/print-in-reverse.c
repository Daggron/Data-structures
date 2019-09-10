#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node* next;
};

struct node* head = NULL;

void insert(int data){
  if(head==NULL){
    struct node * new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = head;
    head=new_node;
  }

  else{
    struct node* top = head;
    while(top->next!=NULL){
      top=top->next;
    }
    struct node * new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    top->next = new_node;
  }
}

void print(struct node* op){
  if(op == NULL){
    return ;
  }
  int tp = op->data;
  op=op->next;
  print(op);
  printf("%d ",tp);
}



int main(){
  printf("Enter The Size of linked list\n");
  int n;
  scanf("%d", &n);

  int data;
  printf("Enter The Elements in the linked list\n" );
  for(int i=0;i<n;i++){
    scanf("%d",&data);
    insert(data);
  }

  printf("\nLinked list in the reverse order\n");
  print(head);

}
