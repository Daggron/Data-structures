#include<stdio.h>

struct node{
  int data;
  struct node* next;
};
struct node* head = NULL;

void insert (int data , int pos){

  if(pos == 1){
    struct node* temp = (struct node *) malloc(sizeof(struct node));
    temp->data  = data;
    temp->next = head;
    head = temp;
    return;
  }
    struct node * curr = head;
  for(int i=0;i<pos-2;i++){
    curr=curr->next;
  }
  struct node * new_node = (struct node *) malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = curr->next;
  curr->next = new_node;


}

void removef(){
  struct node * curr = head;
  while(curr->next != NULL){
    if(curr->data == (curr->next)->data){
      curr->next = curr->next->next;
    }
    else{
      curr = curr->next;
    }
  }
}

void print(){
  struct node * temp = head;
  printf("here\n");
  while(temp != NULL){
      printf("%d",temp->data);
      temp = temp->next;
  }

}
int main(){
  int n;
  scanf("%d",&n );

  for(int i=0;i<n;i++){
    int data,pos;
    scanf("\n%d",&data);
    scanf("\n%d",&pos);
    insert(data,pos);
  }

  print();
  removef();
  printf("\n");
  print();

}
