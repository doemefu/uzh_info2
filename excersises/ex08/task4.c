//
// Created by Dominic Furchert on 28.04.2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


//
// Created by Dominic Furchert on 15.04.2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode{
  int val;
  struct TreeNode* left;
  struct TreeNode* right;
};

int max(int a, int b){
  if (a > b){
    return a;
  }
  return b;
}

struct TreeNode* insert(struct TreeNode** root, int val){
  struct TreeNode* newNode = malloc(sizeof(struct TreeNode));
  newNode->val = val;
  newNode->left = NULL;
  newNode->right = NULL;

  struct TreeNode **curr = root;

  while(*curr!=NULL){
    if((*curr)->val > val){
      curr = &((*curr)->left);
    } else {
      curr = &((*curr)->right);
    }
  }
  *curr=newNode;
  printf("%i ",(*curr)->val);
  return NULL;
}

//parent vor children
void preTraverse(struct TreeNode* root){
  if (root == NULL) {
    return;
  }
  printf("%i ",root->val);
  preTraverse(root->left);
  preTraverse(root->right);
}

// parent zwischen children
void inTraverse(struct TreeNode* root){
  if (root == NULL) {
    return;
  }
  inTraverse(root->left);
  printf("%i  ",root->val);
  inTraverse(root->right);
}

//parent nach children
void postTraverse(struct TreeNode* root){
  if (root == NULL) {
    return;
  }
  postTraverse(root->left);
  postTraverse(root->right);
  printf("%i  ",root->val);
}

void traverseTree(struct TreeNode* root){
  printf("\nPreOrder: ");
  preTraverse(root);
  printf("\nInOrder: ");
  inTraverse(root);
  printf("\nPostOrder: ");
  postTraverse(root);
}

void stack_traverseTree(struct TreeNode* root){

}

struct TreeNode* delete(struct TreeNode** root, int val){

  return NULL;
}

int getMaxDepth(struct TreeNode* root) {

  if (root == NULL) {
    return 0;
  }

  int left = 0;
  int right = 0;
  if (root->left != NULL) {
    left+=1;
    left += getMaxDepth(root->left);
  }
  if (root->right != NULL) {
    right += 1;
    right += getMaxDepth(root->right);
  }
  printf("\ngetMaxDepth for node with value %i is left: %i; right: %i",root->val,left,right);

  if (left<right) {
    return right;
  }
  return left;
}

int getDiameter(struct TreeNode* root) {
  if (root==NULL) {
    return 0;
  }
  int left = getMaxDepth(root->left)+1; //+1 für childRoot
  int right = getMaxDepth(root->right)+1;
  int parent = left + right+1; //+1 für parentroot

  printf("\ngetDiameter for node with value %i is %i",root->val,parent);

  return parent;
}

int getMaxDiameter(struct TreeNode* root) {
  int parent = getDiameter(root);
  int childLeft = getDiameter(root->left);
  int childright = getDiameter(root->right);

  if (parent > childLeft && parent > childright) {
    return parent;
  }
  if (childLeft > childright) {
    return childLeft;
  }
  return childright;

}

int diameterV2(struct TreeNode* root) {
  if (root==NULL) {
    return 0;
  }
  int left = getMaxDepth(root->left)+1; //+1 für childRoot
  int right = getMaxDepth(root->right)+1;

  int childLeft = getDiameter(root->left);
  int childright = getDiameter(root->right);

  return max(left+right+1,max(childLeft,childright));
}

int main(){
  struct TreeNode** myTree = malloc(sizeof *myTree);
  *myTree = NULL;

  insert(myTree, 9);
  insert(myTree, 5);
  insert(myTree, 4);
  insert(myTree, 3);
  insert(myTree, 2);
  insert(myTree, 10);
  insert(myTree, 6);
  insert(myTree, 12);
  insert(myTree, 1);
  insert(myTree, 7);
  insert(myTree, 8);

  traverseTree(*myTree);

  printf("\n This is a Tree with diameter: %i", getMaxDiameter(*myTree));
  printf("\n This is a Tree with diameter V2: %i", diameterV2(*myTree));

  return 0;
}

/*
 *                            9
 *                       5        10
 *                   4      6        12
 *                3           7
 *             2               8
 *           1
 */