/* create my first binary search tree */
#include <stdio.h>
#include <stdlib.h>

struct BST{
  int val;
  struct BST* left;
  struct BST* right;
};

typedef struct BST bst;

int maxInt(int a, int b){
  return (a > b)? a:b;
}

bst* create_node(int val){
  bst* node = (bst*)malloc(sizeof(bst));
  node->val = val;
  node->left = NULL;
  node->right = NULL;
  return node;
}

bst* insert(bst* root, int val){
  bst* node = NULL;
  if(root == NULL)
    root = create_node(val);
  else if(val <= root->val)
    root->left = insert(root->left, val);
  else
    root->right = insert(root->right, val);

  return root;
}

void search(bst* root){
  bst* node = root;
  int val; 
  printf("Enter an integer to search for in the binary search tree and press enter\n");
  scanf("%d", &val);
  while(node != NULL){
    if(val == node->val){
       printf("Found\n");
       return;
    }
    else{
      if(val < node->val)
	node = node->left;
      else node = node->right;
    }
  }
  if(node == NULL){
    printf("Not Found\n");
    return;
  }
}

bst* minVal(bst* root){
  bst* node = root;
  if(node == NULL) return NULL;
  else
    while(node->left != NULL){
      node = node->left;
    }
  return node;
}

bst* maxVal(bst* root){
  bst* node = root;
  if(node == NULL) return NULL;
  else
    while(node->right != NULL){
      node = node->right;
    }
  return node;
}

void printTreeSide(bst* root, char* side){
  bst* node = root;
  int i = 1;
  char* left = "left";
  if(side == left){
    while(node != NULL){
    printf("Level %d \n", i);
    printf("%d \n", node->val);
    printf("%d \t %d \n ", (node->left != NULL)? node->left->val:0, (node->right != NULL)? node->right->val:0);
    node = node->left;
    i++;
    }
  }
  else{
    while(node != NULL){
      printf("\t Level %d \n", i);
      printf("%d \n", node->val);
      printf("%d \t %d \n", (node->left != NULL)? node->left->val:0, (node->right != NULL)? node->right->val:0);
      node = node->right;
      i++;
    }
  }
}

int FindHeight(bst* root){
  if(root == NULL)
    return -1;
  else
    return maxInt(FindHeight(root->left), FindHeight(root->right)) + 1;
  }
struct Queue{
  bst* root;
  struct Queue* next;
};

typedef struct Queue q;

q* Qcreate_node(bst* node){
  q* qnode = (q*)malloc(sizeof(q));
  qnode->root = node;
  qnode->next = NULL;
  return qnode;
}

// Queue for managing the horizontal traversals
void  Enqueue(q** qfront, q** qtail, bst* node){
  q* qnode;
  if(node == NULL) return;
  else if(*qtail == NULL && *qfront == NULL){
    *qfront = Qcreate_node(node);
    *qtail = *qfront;
  }
  else{
    qnode = Qcreate_node(node);
    (*qtail)->next = qnode;
    *qtail = qnode;
  }
}

void Dequeue(q** qfront, q** qtail){
  q* temp;
  if(*qfront != NULL && *qtail != NULL){
    temp = *qfront;
    *qfront = temp->next;
    free(temp);
  }
}

int QIsNotEmpty(q* qfront){
  if(qfront != NULL) return 1;
  else return 0;
}

void QueuePop(q** qfront){
  q* temp;
  if(*qfront != NULL){
    temp = *qfront;
    printf(" %d ", (*qfront)->root->val);
    *qfront = temp->next;
    free(temp);
  }
}

//Level Order traverses the tree level by level
void LevelOrder(bst* root){
  q* qfront = NULL;
  q* qtail = NULL;
  
  if(root == NULL) return;
  else{
    Enqueue(&qfront, &qtail, root);
    while(QIsNotEmpty(qfront) == 1){
      root = qfront->root;
      if(root->left != NULL) Enqueue(&qfront, &qtail, root->left);
      if(root->right != NULL) Enqueue(&qfront, &qtail, root->right);
      QueuePop(&qfront);
    }
  }
  return;
}

// preOrder traverses a tree in this order root -> left subtree -> right subtree
void preOrder(bst* root){
  if(root != NULL){
    printf("%d ",root->val);
    preOrder(root->left);
    preOrder(root->right);
  }
  else
    return;
}

void inOrder(bst* root){
  if(root != NULL){
    inOrder(root->left);
    printf("%d ", root->val);
    inOrder(root->right);
  }
  else return;
}

void postOrder(bst* root){
  if(root != NULL){
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->val);
  }
  else return;
}

int isLesserSubTree(bst* left_node, int root_val){
  if(left_node != NULL){
    if((left_node->val <= root_val) &&
       isLesserSubTree(left_node->left, root_val)
       && isLesserSubTree(left_node->right, root_val)) return 1;
    else return 0;
  }
  else
    return 1;
}

int isGreaterSubTree(bst* right_node, int root_val){
  if(right_node != NULL){
    if((right_node->val > root_val)
       && isGreaterSubTree(right_node->right, root_val)
       && isGreaterSubTree(right_node->left, root_val))
      return 1;
    else return 0;
  }
  else return 1;
}

int isBinarySearchTree(bst* root){
  if(root == NULL) return 1;
  else{
    if((isLesserSubTree(root->left, root->val) && isBinarySearchTree(root->left))
       && (isGreaterSubTree(root->right, root->val) && isBinarySearchTree(root->right)))
      return 1;
    else return 0;
  }
}

bst* deleteNode(bst* root, int val){
  //deleteNode function returns the pointer to the node to be deleted
  bst* temp;
  if(root == NULL) return NULL;
  else if(val < root->val)
    root->left = deleteNode(root->left, val);
  else if(val > root->val)
    root->right = deleteNode(root->right, val);
  else{
    // Case 1: node to be deleted is a leaf node(no child)
    if(root->left == NULL && root->right == NULL){
      free(root);
      root = NULL;
    }
    // parent's right or left pointer will be fixed since we are returning the new
    // pointer to it
    // Case 2: node has one child
    else if(root->left == NULL){
      temp = root;
      root = root->right;
      free(temp);
    }
    else if(root->right == NULL){
      temp = root;
      root = root->left;
      free(temp);
    }
    else{
      //Case 3: 2 children
      /* we can find the minimum of the right subtree at this point [will still be greater than left subtree]
	 and plug it in (return it) and then delete the duplicate from memory. If it is the minimum of
	 the right subtree, it will have no left subtree
      OR we can find the maximum of the left subtree at this point [ it will still be less than anything in the
      right subtree]. Because it is the max of the left subtree, it will have no right subtree
      */
      temp = minVal(root->right);
      root->val = temp->val;
      root->right = deleteNode(root->right, temp->val);
    }
  }
  return root;
}

bst* find(bst* root, int val){
  if(root == NULL) return NULL;
  else if(root->val == val) 
    return root;
  else{
    while(root != NULL){
      if(root->val > val) root = root->left;
      else if(root->val < val) root = root->right;
      else return root;
    }
    return NULL;
  }
}

bst* getInOrderSuccessor(bst* root, int val){
  if(root == NULL) return NULL;
  bst* current = find(root, val);
  if(current == NULL) return NULL;
  bst* temp = NULL;
  if(current->right != NULL){
    // Case 1: if the target node has a right subtree, its successor is the minimum
    // of the right subtree (ie, the leftmost value in the right subtree)
    temp = current->right;
    while(temp->left != NULL){
      temp = temp->left;
    }
    return temp;
  }
  else{
    // Case 2: no right subtree
    bst* successor = NULL;
    bst* ancestor = root;
    while(ancestor != current){
      if(ancestor->val > val ){
	successor = ancestor;
	ancestor = ancestor->left;
      }
      else ancestor = ancestor->right;
    }
    // note that we only change successor whenever we move to the left so that the successor
    // is the deepest left grandparent
    return successor;
  }
}   

bst* getInOrderPredecessor(bst* root, int val){
  if(root == NULL) return NULL;
  bst* target = find(root, val);
  if(target == NULL) return NULL;
  
  //Case 1 if target node has a left subtree
  if(target->left != NULL){
    bst* temp = target->left;
    while(temp->right != NULL){
      temp = temp->right;
    }
    return temp;
  }
  else{
    //Case 2: if target node has no left subtree
    bst* predecessor = NULL;
    bst* ancestor = root;
    while(ancestor != target){
      if(ancestor->val < val){
	predecessor = ancestor;
	ancestor = ancestor->right;
      }
      else ancestor = ancestor->left;
    }
    return predecessor;
  }
}
      
int main(){
  bst* integers = NULL;
  integers = insert(integers, 5);
  bst* i;
  i = insert(integers, 3);
  i = insert(integers,15);
  i = insert(integers, 4);
  i = insert(integers, 2);
  i = insert(integers, 11);
  printf("Inserting %d, %d, %d, %d, %d \n", 3,15,4,2,11);
  printTreeSide(integers, "left");  
  printf("Searching\n");
  search(integers);
  printf("Searching again\n");
  search(integers);
  printf("min = %d \t max = %d\n", (minVal(integers))->val, ((maxVal(integers))->val));
  printf("Height of tree = %d \n", FindHeight(integers));
  printf("Level Order\n");
  LevelOrder(integers);
  printf("\nPreOrder \n");
  preOrder(integers);
  printf("\nInOrder \n");
  inOrder(integers);
  printf("\nPostOrder\n");
  postOrder(integers);
  printf("\nIs Binary Search Tree? : ");
  printf("%d \n", isBinarySearchTree(integers));
  printf("Deleting node 5\n");
  deleteNode(integers, 5);
  LevelOrder(integers);
  printf("\n Get InOrder successor of 11\n");
  printf("%d ", (getInOrderSuccessor(integers, 11))->val);
  printf("\nInOrder \n");
  inOrder(integers);
  printf("Level Order\n");
  LevelOrder(integers);
  printf("\n Get InOrder successor of 4\n");
  printf("%d ", (getInOrderSuccessor(integers, 4))->val);
  printf("\n Get InOrder predecessor of 4\n");
  printf("%d ", (getInOrderPredecessor(integers, 4))->val);
  printf("\n Get InOrder predecessor of 11\n");
  printf("%d ", (getInOrderPredecessor(integers, 11))->val);
  return 0;
}

