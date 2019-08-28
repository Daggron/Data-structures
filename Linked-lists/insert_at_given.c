#include<stdio.h>
struct node{
  int data;
  struct node* next;
};
struct node* head = NULL;
void insert(int data,int pos){
  struct node * A=head;
  struct node* temp = (struct node *) malloc(sizeof(struct node));
  if(pos==1){
    temp->data = data;
    temp->next = head;
    head = temp;
    return;
  }
  else{
    struct node* temp = head;
    for(int i=0;i<pos-2;i++){
      temp=temp->next;
    }
    struct node * temp2 = (struct node *) malloc(sizeof(struct node));
    temp2->data = data;
    temp2->next = temp->next;
    temp->next = temp2;
  }
}

void print(){
    struct node * temp2 = head;
    while(temp2!=NULL){
      printf("%d\n",temp2->data );
      temp2 = temp2->next;
    }
}
int main(){

  int n;
  scanf("\n%d",&n);
  for(int i=0;i<n;i++){
    int data,pos;
    printf("\nEnter The data you want to enter");
    scanf("\n%d",&data);
    printf("\nEnter The positio you want to insert");
    scanf("\n%d",&pos );
    insert(data,pos);
  }
  print();
}
