#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct TreeNode{
  int value;
  TreeNode* pLeft;
  TreeNode* pRight;
};

bool IsBalanced(TreeNode* pRoot, int* pDepth)
{
  if(pRoot == NULL)
  {
    *pDepth = 0;
    return true;
  }
  int left,right;
  if(IsBalanced(pRoot->pLeft, &left) && IsBalanced(pRoot->pRight, &right))
  {
    int diff = left - right;
    if(diff <= 1 && diff >= -1)
    {
      *pDepth = 1 + ((left > right)? left : right);
      return true;
    }
}
  return false;
}

bool IsBalanced(TreeNode* pRoot)   //首次进入，重载
{
  int depth = 0;
  return IsBalanced(pRoot,&depth);
}
