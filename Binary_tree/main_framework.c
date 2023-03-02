#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

int treeHeight(treetype t) {
  if(t == NULL) return 0;
  else {
    int left_height = treeHeight(t->left);
    int right_height = treeHeight(t->right);
    if(left_height >= right_height) return left_height +1;
    else return right_height +1;
  }
}
int treeNbrLeaf(treetype t) {
  if(t == NULL) return 0;
  if(t->left == NULL && t->right == NULL) return 1;
  else{
    return treeNbrLeaf(t->left) + treeNbrLeaf(t->right);
  }
}
int treeInternalNode(treetype t) { 
  return nb_nodes(t)-treeNbrLeaf(t);
}
int treeNbrRightChildren(treetype t) {
  
}

int main() {
  treetype tr;
  makeNullTree(&tr);
  if (isEmptyTree(tr)) printf("Empty Tree\n");

  elmType giaithua = {"!",0};
  elmType chia = {"/",0};
  elmType tru = {"-",0};
  elmType cong = {"+",0};
  elmType a = {" ",10};
  elmType b = {" ",3};
  elmType c = {" ",4};
  elmType d = {" ",2};

  tr = create_node(cong);
  tr = Add_Left(tr,giaithua);
  tr = Add_Left(tr->left,a);

  tr = Add_Right(tr,chia);
  tr = Add_Left(tr->right,chia);
  tr = Add_Right(tr->right,d);
  
  tr = Add_Left(tr->right->left,b);
  tr = Add_Right(tr->right->left,c);
  // tr = createfrom2(1000, tr, tr);

  printf("Tree Height: %d\n", treeHeight(tr));
  printf("So la: %d\n", treeNbrLeaf(tr));
  printf("# internal node: %d\n", treeInternalNode(tr));
  printf("# right children: %d\n", treeNbrRightChildren(tr));
  return 0;
}