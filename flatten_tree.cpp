//
//  flatten_tree.cpp
//  learningC++
//
//  Created by Zhisheng Huang on 7/6/14.
//
//

#include "flatten_tree.h"

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



TreeNode *flattenTree(TreeNode *root)
{
  if (root == NULL) {
    return NULL;
  }
  
  TreeNode *rightmostOfLeft = flattenTree(root->left);
  TreeNode *rightmostOfRight = flattenTree(root->right);
  TreeNode *rightTree = root->right;
  
  if (root->left != NULL) {
    root->right = root->left;
    root->left = NULL;
    rightmostOfLeft->right = rightTree;
  }
  
  if (rightmostOfRight != NULL) {
    return rightmostOfRight;
  } else if (rightmostOfLeft != NULL) {
    return rightmostOfLeft;
  } else {
    return root; // itself is the right most
  }
}


void flatten(TreeNode *root)
{
  flattenTree(root);
}

int main() {
  
  TreeNode a = TreeNode(1);
  TreeNode b = TreeNode(2);
  //TreeNode c = TreeNode(3);
  //TreeNode d = TreeNode(4);
  
  
  a.right = &b;
  // b.right = &c;
  // a.right = &d;
  
  flatten(&a);
  
  
  TreeNode *currentNode = &a;
  while (currentNode != NULL) {
    printf("%d\n", currentNode->val);
    currentNode = currentNode->right;
  }
  
  return 0;
}
