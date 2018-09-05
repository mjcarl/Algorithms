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

void CreateTree(BiTree &T)   //建立二叉树，先序遍历输入，孩子为空输入'p'，如 abcpppdpp
{
	char data;
	cin >> data;
	if (data == 'p')      //输入p为空结点
	{
		T = NULL;
	}
	else
	{
		T = (BiNode *)malloc(sizeof(BiNode));
		T->data = data;
		vec.push_back(T);  //把节点保存到vector里
		CreateTree(T->lchild);  //先序
		CreateTree(T->rchild);
	}
}

BiTree lowestAncestor(BiTree T, BiTree b, BiTree a)  //查找最小公共父节点
{
	if (T == nullptr || T == b || T == a)
	{
		return T;
	}
	BiTree left = lowestAncestor(T->lchild, b, a);  //后序遍历
	BiTree right = lowestAncestor(T->rchild, b, a);
	if (left != nullptr && right != nullptr)  //左右孩子都分别找到了o1和o2，则此时的head为最小父节点
	{
		return T;
	}
	return left != nullptr ? left : right;
}

void Cal_Dis(BiTree T, BiTree b)  //计算节点b到父节点T的最短距离
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

void CalculateMaxdis(BiTree T, BiTree b)  //求节点b的最长广播距离，算与其他每个节点的距离，求最大值
{
	int maxlen = 0; BiTree father;
	auto it = vec.begin();
	while (it != vec.end())
	{
		if (*it != b)
		{
			cout << "** 计算：" << b->data << " 和 " << (*it)->data << endl;
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
	cout << "=======节点：" << b->data << " MaxDis =  " << maxlen << endl;
}

void FindAllDis(BiTree T, BiTree b)  //遍历查找每个节点的最远广播距离
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

// 高级算法  层序输入，例如111110000010000   类似动态规划，利用父节点的信息
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
            if(j==2*i+1 || j==2*i+2)  //i和j是父子节点关系，此时距离为1
            {
                dis[i][j]=1;
                dis[j][i]=1;
            }
            else if(i==j)
            {
                dis[i][j]=0;
            }
            else  //不是亲父子关系，则看其向上的父节点的距离关系
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
        if(network[i]=='1')  //为1才是有效节点
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
