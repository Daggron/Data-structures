#include<stdio.h>
struct node {
  int data;
  struct node * next;
};
struct node* head = NULL;
void delete(int pos){
    struct node * temp = head;
    if(pos==0){
      head->next= head->next->next;
      return;
    }
    for(int i=0;i<pos-1;i++){
      temp=temp->next;
    }
    temp->next = temp->next->next;
    return;
}

void insert(int data,int pos){
  struct node* temp = head;
  struct node * new_node = (struct node *) malloc(sizeof(struct node));
  if(pos==0){
    new_node->data = data;
    new_node->next = head;
    head = new_node;
    return;
  }
  else{
    for(int i=0;i<pos-1;i++){
      temp = temp->next;
    }
    new_node->data = data;
    new_node->next = temp->next;
    temp->next = new_node;
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
  delete(2);
  printf("\n");
  print();

}
