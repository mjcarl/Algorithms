#include<iostream>
using namespace std;

struct Treenode{
	int m_value;
	Treenode* m_left;
	Treenode* m_right;
};

//�ݹ�˼·
bool HasSubtree(Treenode* Root1,Treenode* Root2)  //1.������ͬ�ĸ��ڵ�
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

bool DoesTree1haveTree2(Treenode* Root1,Treenode* Root2)   //2.�жϺ�����Ƿ���ͬ
{
	if(Root2==NULL)  //����������
		return true;
	if(Root1==NULL)   //��������ʣ��
		return false;
	if(Root1->m_value != Root2->m_value)
		return false;

	return (DoesTree1haveTree2(Root1->m_left,Root2->m_left) && DoesTree1haveTree2(Root1->m_right,Root2->m_right));  //ͬ��ͬ��
}

