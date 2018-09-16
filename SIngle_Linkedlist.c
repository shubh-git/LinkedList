#include<stdio.h>
#include<stdlib.h>

struct Node{
  int data;
  struct Node *next;

};

void InsertAtFirst(struct Node **head,int new_data){
  struct Node *new_node=(struct Node *)malloc(sizeof(struct Node));
  new_node->data=new_data;
  new_node->next=*head;
  *head=new_node;

}

void InsertAtLast(struct Node **head,int new_data){
  struct Node *new_node=(struct Node *)malloc(sizeof(struct Node));
  struct Node *last=*head;
  new_node->data=new_data;
  new_node->next= NULL;

    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
}

void InsertInBetween(struct Node *prev_node,int new_data){

  struct Node *new_node=(struct Node *)malloc(sizeof(struct Node));
  new_node->data=new_data;
  new_node->next=prev_node->next;
  prev_node->next=new_node;

}

void printList(struct Node *node){
  while(node!=NULL){
      printf("%d\n",node->data );
      node=node->next;
  }
}

int main(){
  int n=0,t=0;
  printf("How Many numbers you want to enter?\n");
  scanf("%d\n",&n);
  struct Node *head=NULL;
  for(int i=0;i<n;i++){
    if(i==0){
      scanf("%d",&t);
      head=(struct Node *)malloc(sizeof(struct Node));
      head->data=t;
    }
    else{
      scanf("%d",&t);
      //InsertAtFirst(&head,t);
      InsertAtLast(&head,t);
    }
  }
  InsertInBetween(head->next,8);
  printList(head);
  return 0;
}
