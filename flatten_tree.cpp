//
//  flatten_tree.cpp
//  learningC++
//
//  Created by Zhisheng Huang on 7/6/14.
//
//

#include "flatten_tree.h"
#include <stack>

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

void flatten_iteratively(TreeNode *root)
{

  if (root == NULL);

  stack<TreeNode*> s;  
  TreeNode *rightMostNode; 
  
  s.push(root);
  while (!s.empty()) {
    TreeNode *currentNode = s.top(); 
    s.pop();
    if (currentNode->right != NULL) s.push(currentNode->right);
    if (currentNode->left  != NULL) s.push(currentNode->left);
    
    currentNode->left = NULL;
    currentNode->right = NULL;

    if (rightMostNode != NULL) {
      rightMostNode->right = currentNode;
    }

    rightMostNode = currentNode;
  }
}

int main() {
  
  TreeNode a = TreeNode(1);
  TreeNode b = TreeNode(2);
  TreeNode c = TreeNode(3);
  TreeNode d = TreeNode(4);
  a.left = &b;
  a.right = &d;
  b.right = &c;
 

  //flatten(&a); 
   flatten_iteratively(&a);
  
  
  TreeNode *currentNode = &a;
  while (currentNode != NULL) {
    printf("%d\n", currentNode->val);
    currentNode = currentNode->right;
  }
  return 0;
}
