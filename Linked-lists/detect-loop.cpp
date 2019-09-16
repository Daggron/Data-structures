// C++ program to detect and remove loop
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int key;
	struct Node* next;
};

Node* newNode(int key)
{
	Node* temp = new Node;
	temp->key = key;
	temp->next = NULL;
	return temp;
}

void printList(Node* head)
{
	while (head != NULL) {
		cout << head->key << " ";
		head = head->next;
	}
	cout << endl;
}

void detectLoop(Node* head)
{

  if (head == NULL || head->next == NULL){
    return ;
  }

  struct Node * sp = head->next;
  struct Node * fp = head->next->next;

  while(fp && fp->next !=NULL){
    if(sp == fp){
      printf("Loop Detected");
      return ;
    }
    sp = sp->next;
    fp = fp->next->next;
  }

}


int main()
{
	Node* head = newNode(50);
	head->next = head;
	head->next = newNode(20);
	head->next->next = newNode(15);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(10);

	/* Create a loop for testing */
	head->next->next->next->next->next = head->next->next;

	detectLoop(head);



	return 0;
}
