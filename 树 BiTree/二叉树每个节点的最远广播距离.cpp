#include<bits/stdc++.h>
using namespace std;

typedef struct BiNode
{
	char data;
	struct BiNode *lchild;
	struct BiNode *rchild;
}BiNode, *BiTree;

vector<BiTree>vec;
int dis = 0, adis = 0, td = 0;

void CreateTree(BiTree &T)   //����������������������룬����Ϊ������'p'���� abcpppdpp
{
	char data;
	cin >> data;
	if (data == 'p')      //����pΪ�ս��
	{
		T = NULL;
	}
	else
	{
		T = (BiNode *)malloc(sizeof(BiNode));
		T->data = data;
		vec.push_back(T);  //�ѽڵ㱣�浽vector��
		CreateTree(T->lchild);  //����
		CreateTree(T->rchild);
	}
}

BiTree lowestAncestor(BiTree T, BiTree b, BiTree a)  //������С�������ڵ�
{
	if (T == nullptr || T == b || T == a)
	{
		return T;
	}
	BiTree left = lowestAncestor(T->lchild, b, a);  //�������
	BiTree right = lowestAncestor(T->rchild, b, a);
	if (left != nullptr && right != nullptr)  //���Һ��Ӷ��ֱ��ҵ���o1��o2�����ʱ��headΪ��С���ڵ�
	{
		return T;
	}
	return left != nullptr ? left : right;
}

void Cal_Dis(BiTree T, BiTree b)  //����ڵ�b�����ڵ�T����̾���
{
	if (T == nullptr)
	{
		return;
	}
	if (T == b)
	{
		dis = td;
		return;
	}
	if (T != b)
	{
		td++;
		Cal_Dis(T->lchild, b);
		Cal_Dis(T->rchild, b);
		td--;
	}
}

void CalculateMaxdis(BiTree T, BiTree b)  //��ڵ�b����㲥���룬��������ÿ���ڵ�ľ��룬�����ֵ
{
	int maxlen = 0; BiTree father;
	auto it = vec.begin();
	while (it != vec.end())
	{
		if (*it != b)
		{
			cout << "** ���㣺" << b->data << " �� " << (*it)->data << endl;
			dis = 0; adis = 0; td = 0;
			father = lowestAncestor(T, b, *it);
			Cal_Dis(father, b);   adis += dis;
			dis = 0;  td = 0;
			Cal_Dis(father, *it);   adis += dis;
			cout << "adis = " << adis << endl;
			maxlen = maxlen > adis ? maxlen : adis;
		}
		it++;
	}
	cout << "=======�ڵ㣺" << b->data << " MaxDis =  " << maxlen << endl;
}

void FindAllDis(BiTree T, BiTree b)  //��������ÿ���ڵ����Զ�㲥����
{
	if (b == nullptr)
	{
		return;
	}
	CalculateMaxdis(T, b);
	FindAllDis(T, b->lchild);
	FindAllDis(T, b->rchild);
}

int main()
{
	BiTree T;
	CreateTree(T);
	FindAllDis(T, T);
	return 0;
}

// �߼��㷨  �������룬����111110000010000   ���ƶ�̬�滮�����ø��ڵ����Ϣ
vector<int> min(string network)
{
    int len=network.size();
    int i,j;
    vector<vector<int>>dis(len);
    for(i=0;i<len;i++)
        dis[i].resize(len);
    for(i=0;i<len;i++)
    {
        for(j=0;j<len;j++)
        {
            if(j==2*i+1 || j==2*i+2)  //i��j�Ǹ��ӽڵ��ϵ����ʱ����Ϊ1
            {
                dis[i][j]=1;
                dis[j][i]=1;
            }
            else if(i==j)
            {
                dis[i][j]=0;
            }
            else  //�����׸��ӹ�ϵ���������ϵĸ��ڵ�ľ����ϵ
            {
                dis[i][j]=dis[i][(j-1)/2]+1;
                dis[j][i]=dis[i][j];
            }
        }
    }
    vector<int>res;
    int tmp;
    for(i=0;i<len;i++)
    {
        if(network[i]=='1')  //Ϊ1������Ч�ڵ�
        {
            tmp=0;
            for(j=0;j<len;j++)
            {
                if(dis[i][j]>tmp)
                {
                    tmp=dis[i][j];
                }
            }
            res.push_back(tmp);
        }
    }
    return res;
}
