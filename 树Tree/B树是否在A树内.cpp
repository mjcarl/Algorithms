#include<iostream>
using namespace std;

struct Treenode{
	int m_value;
	Treenode* m_left;
	Treenode* m_right;
};

//递归思路
bool HasSubtree(Treenode* Root1,Treenode* Root2)  //1.查找相同的根节点
{
	bool result = false;
	if(Root1!=NULL && Root2!=NULL)
	{
		if(Root1->m_value == Root2->m_value)
			result = DoesTree1haveTree2(Root1,Root2);
		if(result == false)
			result = HasSubtree(Root1->m_left,Root2);
		if(result == false)
			result = HasSubtree(Root1,Root2->m_left);
	}
	return result;
}

bool DoesTree1haveTree2(Treenode* Root1,Treenode* Root2)   //2.判断后面的是否相同
{
	if(Root2==NULL)  //子树检查完毕
		return true;
	if(Root1==NULL)   //子树还有剩余
		return false;
	if(Root1->m_value != Root2->m_value)
		return false;

	return (DoesTree1haveTree2(Root1->m_left,Root2->m_left) && DoesTree1haveTree2(Root1->m_right,Root2->m_right));  //同左同右
}

