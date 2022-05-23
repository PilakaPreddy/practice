#include <stdio.h> 
#include <stdlib.h> 
 struct node{ 
  struct node* left; 
  int data; 
  struct node *right; 
}; 
 
 struct node * root = NULL; 
 
void create(int val){ 
  struct node* newNode = (struct node*)malloc(sizeof(struct node)); 
  newNode->left = newNode->right = NULL; 
  newNode->data = val; 
  if(root == NULL){ 
    root = newNode; 
  } 
  else{ 
    struct node* temp = root, *temp1; 
    while(temp != NULL){ 
      temp1 = temp; 
      if(newNode->data > temp->data){ 
        temp = temp->right; 
      } 
      else if(newNode->data < temp->data){ 
        temp = temp->left; 
      } 
    } 
   if(newNode->data > temp1->data){ 
      temp1->right = newNode; 
    } 
    else if(newNode->data < temp1->data){ 
      temp1->left = newNode; 
    } 
  } 
} 
   
void search(int val){ 
 int flag; 
 struct node* temp = root, *temp1; 
    if(root == NULL){ 
    printf("BS Tree is empty"); 
  } 
  else{ 
        while(temp != NULL){ 
      if(temp->data==val) 
         { 
          flag=1; 
          break; 
   } 
           else  if(val > temp->data){ 
        temp = temp->right; 
      } 
      else if(val< temp->data){ 
        temp = temp->left; 
      } 
    } 
    if(flag==1) 
        printf("key found"); 
        else 
          printf("not found"); 
  } 
} 
void minimum(struct node * root){ 
  if(root == NULL) 
    return; 
    else 
    { 
     int min=root->data; 
     struct node *temp=root; 
     while(temp->left!=NULL) 
     { 
      temp=temp->left; 
      if(temp->data<min) 
        min=temp->data; 
  } 
  printf("Min=%d\n",min); 
 } 
  } 
void InOrder(struct node * root){ 
  if(root == NULL) 
    return; 
  InOrder(root->left); 
  printf("%d ", root->data); 
  InOrder(root->right); 
} 
 
void PostOrder(struct node * root){ 
  if(root == NULL) 
    return; 
  PostOrder(root->left); 
  PostOrder(root->right); 
  printf("%d ",root->data); 
} 
 
void PreOrder(struct node * root){ 
  if(root == NULL) 
    return; 
  printf("%d ", root->data); 
  PreOrder(root->left); 
  PreOrder(root->right); 
} 
int leaf(struct node *temp) 
{ 
if(temp==NULL) 
   return 0; 
else{ 
  int c1=leaf(temp->left); 
  int c2=leaf(temp->right); 
if(c1==0&&c2==0) return c1+c2+1; 
else return c1+c2;} 
} 
struct node * minValueNode( struct node* n){ 
 struct node* current = n; 
 
while (current && current->left != NULL) 
current = current->left; 
 
return current; 
} 
 
struct node* delete_node( struct node* root, int data){ 
    if (root == NULL) 
    return root; 
 
    if (data < root->data) 
    root->left = delete_node(root->left, data); 
 
    else if (data > root->data) 
    root->right = delete_node(root->right, data); 
 
else{ 
      if (root->left == NULL){ 
      struct node *temp = root->right; 
      free(root); 
      return temp; 
      } 
      else if (root->right == NULL){ 
      struct node *temp = root->left; 
      free(root); 
      return temp; 
      } 
 
     struct node* temp = minValueNode(root->right); 
 
     root->data = temp->data; 
 
     root->right = delete_node(root->right, temp->data); 
   } 
   return root; 
} 
 
int main(){ 
  int val,ch,x; 
  while(1){ 
    printf("1. Insert Node 2.Inorder 3. PostOrder 4. PreOrder 5.mimimum 6:search 7:delete 8:exit\n"); 
    scanf("%d",&ch); 
    switch(ch){ 
      case 1: printf("Enter data\n"); 
          scanf("%d",&val); 
          create(val); 
          break; 
      case 2: printf("Printing InOrder\n"); 
          InOrder(root);break; 
          case 5: 
    minimum(root);break; 
    case 6:printf("enter searching node"); 
           scanf("%d",&x); 
    search(x); break; 
           
      case 3: printf("Printing PostOrder\n"); 
          PostOrder(root);break; 
           
      case 4: printf("Printing PreOrder\n"); 
          PreOrder(root);break; 
        case 7: printf("enter searching node"); 
           scanf("%d",&x); 
      root=delete_node(root,x); break;  
      case 8: exit(0);break; 
       
      default: printf("Invalid\n"); 
    } 
  } 
  return 0; 
}
