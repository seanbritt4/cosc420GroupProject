#ifndef TREE_H
#define TREE_H

// #define true 1
// #define false 0
// _Bool DBUG = false;

struct Node{
  struct Node *l, *r;
  _Bool winningMove;
  int id;
};

struct Node* newNode(int id){
  struct Node* node = (struct Node*) malloc(sizeof(struct Node));
  node->id = id;
  node->l = NULL;
  node->r = NULL;
  return(node);
}

//recursively generates subtrees
//parent:
//k: level of tree
//NOTE:
//  was getting an off-by-one, changed if and else if statements:
//    if(k==0){...}else if(k == 1){...
//  to
//    if(k==1){...}else if(k == 2){...
//  not sure what is happening or why it works, but it seems to
//  do what i want it to do
struct Node* genTree(struct Node* parent, int k){

  if(k == 1){
    printf("null\n");
    return NULL;
  }else if(k == 2){
    printf("gT k:%d id:%d\n", k, parent->id);

    parent->l = newNode(parent->id * 2 + 1);
    genTree(parent->l, k-1);
  }else { // k > 1
    printf("gT k:%d id:%d\n", k, parent->id);

    parent->l = newNode(parent->id * 2 + 1);
    genTree(parent->l, k-1);

    if(k-2 > 0){
    parent->r = newNode(parent->id * 2 + 2);
      genTree(parent->r, k-2);
    }
  }
}

void pre(struct Node* n){
  if(n != NULL){
    printf("%d\n", n->id);
    pre(n->l);
    pre(n->r);
  }
}

#endif
