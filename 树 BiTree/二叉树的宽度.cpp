#include<bits/stdc++.h>
using namespace std;

int WidthOfBinaryTree(BinaryTreeNode*pNode){
	if (pNode == NULL)
	{
		return 0;
	}
	std::deque<BinaryTreeNode*> dequeTreeNode;//˫�˶���
	int maxWidth = 1;//���Ŀ��,���ڵ�ֻ��һ���ڵ�ʱ�򷵻�1
	dequeTreeNode.push_back(pNode);//ͷ������
	while (true)
	{

		int length = dequeTreeNode.size();//��ǰ��ڵ�ĸ���
		if (length == 0)//��ǰ��û�нڵ㣬����ѭ��
		{
			break;
		}
		while (length > 0)//�����ǰ�㻹�нڵ�
		{
			BinaryTreeNode* pTemp = dequeTreeNode.front();
			dequeTreeNode.pop_front();//����
			length--;//���ȼ�һ
			if (pTemp->m_pLeft)
			{
				dequeTreeNode.push_back(pTemp->m_pLeft);//��һ��ڵ����
			}
			if (pTemp->m_pRight)
			{
				dequeTreeNode.push_back(pTemp->m_pRight);//��һ��ڵ����
			}
		}
		maxWidth = maxWidth > dequeTreeNode.size() ? maxWidth : dequeTreeNode.size();//�õ������
	}
	return maxWidth;
}
