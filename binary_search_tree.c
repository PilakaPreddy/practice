//BINARY SEARCH TREE
#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *leftchild,*rightchild;
};
struct node *root=NULL;
void insert(int value)
{
  //create a node ,insert data
  struct node *newnode,*temp,*temp1;
  newnode=(struct node *)malloc(sizeof(struct node));
  newnode->data=value;
  newnode->leftchild=NULL;
  newnode->rightchild=NULL;
  if(root==NULL)
  root=newnode;
  else //tree is not empty
  {
    temp1=temp=root;
    while(temp!=NULL)
    {
      temp1=temp;
      if(value<temp->data)
      temp=temp->leftchild;
      else if(value>temp->data)
      temp=temp->rightchild;
    }
    if(value<temp1->data)
    temp1->leftchild=newnode;
    else
    temp1->rightchild=newnode;
  }
}
void inorder(struct node *temp)
{
  if(temp==NULL)
  return;
  else
  {
    inorder(temp->leftchild);
    printf("%d ",temp->data);
    inorder(temp->rightchild);
  }
}
int main()
{
  insert(40);
  insert(10);
  insert(15);
  insert(28);
  insert(60);
  insert(70);
  insert(55);
  insert(12);
  insert(5);
  insert(80);
  inorder(root);
}
