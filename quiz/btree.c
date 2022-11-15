#include <stdio.h>
#include <stdlib.h>

typedef struct BinaryNode {
  int data;
  struct BinaryNode* left;
  struct BinaryNode* right;
} BinaryNode;

typedef struct BinaryTree {
  BinaryNode* root;
} BinaryTree;

int fun(BinaryNode* curr, int* c) {
  if (curr != NULL) {
    int cl = 0;
    int cr = 0;
    int fl = fun(curr->left, &cl);
    int fr = fun(curr->right, &cr);
    *c = 1 + cl + cr;
    return cl == cr;
  }
  else {
    *c = 0;
    return 1;
  }
}

int main(void)
{
  struct BinaryNode leaf1 = {3, NULL, NULL};
  struct BinaryNode leaf2 = {5, NULL, NULL};
//   struct BinaryNode root = {10, &leaf1, &leaf2}; // 1 for 2 nodes
//   struct BinaryNode root = {10, NULL, &leaf2}; // 0 for 1 node;
    // struct BinaryNode root = {10, &leaf1, NULL}; // 0 for 1 node;

  struct BinaryNode root = {10, NULL, NULL}; // 1 for 0 nodes
  struct BinaryTree tree = {&root};

  int c = -1;
  printf("fun = %d\n", fun(&root, &c));
  
  return 0;
}