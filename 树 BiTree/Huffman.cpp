#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<iostream>

//���ָ��ʸߵ��ַ�ʹ�ý϶̵ı��룬ʹ��������ֵ�ƽ���������
//���裺����ѡ��Ȩֵ��С������Ϊ������������һ���µĶ���������������Ϊ����Ȩֵ֮�͡�Ȼ���ٽ�����������ĸ������ʣ����С��Ȩֵ����µĶ�����......





typedef int Status;
typedef struct
{
	unsigned int weight;
	unsigned int parent,lchild,rchild;   //�������-1��Ϊ����㣬���ӽ�����Ϊ-1����Ҷ�ӽڵ�
}HTNode,*HuffmanTree;
//typedef char **HuffmanCode;



int min(HuffmanTree HT,int k)
{
	int i=0,min_weight=0,min=0;
	while(HT[i].parent!=-1)
		i++;
	min_weight=HT[i].weight;
	min=i;
	for(i=0;i<k;i++)
	{
		if(HT[i].weight<min_weight&&HT[i].parent==-1)
		{
			min_weight=HT[i].weight;
			min=i;
		}
	}
	//HT[min].parent=1;
	return min;
}

HuffmanTree CreateTree(int *wet,int n)
{
	int i;
	int total=2*n-1;
	HuffmanTree HT=(HuffmanTree)malloc(total*sizeof(HTNode));
	
	for(i=0;i<n;i++)   //��ʼ��n��Ҷ�ӽ��
	{
		HT[i].parent=-1;
		HT[i].lchild=-1;
		HT[i].rchild=-1;
		HT[i].weight=*wet;
		wet++;
	}
	for(i;i<total;i++)    //����м乹������½��
	{
		HT[i].parent=-1;
		HT[i].lchild=-1;
		HT[i].rchild=-1;
		HT[i].weight=0;
	}
	int min1,min2;  //ÿ��ѡ������СȨֵ������ֵ����parentΪ0�Ľ��
	for(i=n;i<total;i++)
	{
		min1=min(HT,i);
		HT[min1].parent=i;
		min2=min(HT,i);
		HT[min2].parent=i;

		HT[i].lchild=min1;
		HT[i].rchild=min2;
		HT[i].weight=HT[min1].weight+HT[min2].weight;
		printf("���i=%d,weight=%d,lc=%d,rc=%d,f=%d\n",i,HT[i].weight,HT[min1].weight,HT[min2].weight,HT[i].parent);
	}
	return HT;
}

void HuffmanCoding(HuffmanTree HT,char * p[], int n)   //Huffman���룬��ÿ��Ҷ�ӽ�㿪ʼ���ϱ�������  HC������,������������������ܹ�����ס,������ָ��
{
	char *code=(char *)malloc(n*sizeof(char ));
	code[n-1]='\0';       //������

	int i;
	for(i=0;i<n;i++)
	{
		int current=i;
		int father=HT[i].parent;
		int start=n-1;     //ÿ�α����λ�ã���ʼΪ�����������λ��

		while(father!=-1)      //���Ǹ����
		{
			if(HT[father].lchild==current)    //���ӱ���Ϊ0
				code[--start]='0';
			else
				code[--start]='1';       //�Һ��ӱ���Ϊ1
			current=father;
			father=HT[father].parent;
		}
		p[i]=code+start;
	}
	//free(code);   //����free........

}

int main()
{
	const int amount=0;
	int i=0;
	
	printf("input the munber of letters: ");
	scanf_s("%d",&amount);
	int *wet=(int *)malloc(amount*sizeof(int));
	printf("input the weight:\n");
	for(i=0;i<amount;i++)
		scanf_s("%d",wet+i);
	
	HuffmanTree HT;

	HT=CreateTree(wet,amount);
	char *p[amount];       //?????????/
	HuffmanCoding(HT,p,amount);
	printf("\nHuffman���������£�\n");
	for(i=0;i<amount;i++)
		printf("%d--->%s\n",HT[i].weight,p[i]);

	free(wet);
	return 1;
}

	

//----------------------------------------------------------------------
//----------------------------------------------------------------------

int min(HuffmanTree HT,int k);


void select_minium(HuffmanTree HT,int k,int &min1,int &min2)
{
	min1 = min(HT,k);
	min2 = min(HT,k);
}

HuffmanTree create_HuffmanTree(int *wet,int n)
{
	//һ����n��Ҷ�ӽڵ�ĺշ���������2n-1���ڵ�
	int total = 2*n-1;
	HuffmanTree HT = (HuffmanTree)malloc(total*sizeof(HTNode));
	if(!HT)
	{
		printf("HuffmanTree malloc faild!");
		exit(-1);
	}
	int i;

	//HT[0],HT[1]...HT[n-1]�д����Ҫ�����n��Ҷ�ӽڵ�
	for(i=0;i<n;i++)
	{
		HT[i].parent = 0;
		HT[i].lchild = 0;
		HT[i].rchild = 0;
		HT[i].weight = *wet;
		wet++;
	}

	//HT[n],HT[n+1]...HT[2n-2]�д�ŵ����м乹�����ÿ�ö������ĸ��ڵ�
	for(;i<total;i++)
	{
		HT[i].parent = 0;
		HT[i].lchild = 0;
		HT[i].rchild = 0;
		HT[i].weight = 0;
	}

	int min1,min2; //��������ÿһ��ѡ��������weight��С��parentΪ0�Ľڵ�
	//ÿһ�ֱȽϺ�ѡ���min1��min2����һ�ζ�����,��󹹳�һ�úշ�����
	for(i=n;i<total;i++)
	{
		select_minium(HT,i,min1,min2);
		HT[min1].parent = i;
		HT[min2].parent =i;
		//�������Ӻ��Һ��ӿ��Է����������ɵ�Ҳ��һ�úշ�������ֻ�����õı��벻ͬ
		HT[i].lchild = min1;
		HT[i].rchild = min2;
		HT[i].weight =HT[min1].weight + HT[min2].weight;
	}
	return HT;
}


//��HT�����ǰk��Ԫ����ѡ��weight��С��parentΪ0���������ֱ�����ű�����min1��min2��



//��HT�����ǰk��Ԫ����ѡ��weight��С��parentΪ0��Ԫ�أ�������Ԫ�ص���ŷ���



//��Ҷ�ӽڵ㵽���ڵ�������շ�����HT��n��Ҷ�ӽڵ�ĺշ������룬��������HC��

void HuffmanCoding(HuffmanTree HT,HuffmanCode &HC,int n)
{
	//��������ָ��ÿ���շ������봮��ָ��
	HC = (HuffmanCode)malloc(n*sizeof(char *));
	if(!HC)
	{
		printf("HuffmanCode malloc faild!");
		exit(-1);
	}

	//��ʱ�ռ䣬��������ÿ����õĺշ������봮
	char *code = (char *)malloc(n*sizeof(char));
	if(!code)
	{
		printf("code malloc faild!");
		exit(-1);
	}

	code[n-1] = '\0';  //����������������ַ�����Ľ�����־
	//��ÿ���ַ��ĺշ�������
	int i;
	for(i=0;i<n;i++)
	{
		int current = i;           //���嵱ǰ���ʵĽڵ�
		int father = HT[i].parent; //��ǰ�ڵ�ĸ��ڵ�
		int start = n-1;           //ÿ�α����λ�ã���ʼΪ�����������λ��
		//��Ҷ�ӽڵ�����շ�����ֱ�����ڵ�
		while(father != 0)
		{
			if(HT[father].lchild == current)   //��������ӣ������Ϊ0
				code[--start] = '0';
			else                              //������Һ��ӣ������Ϊ1
				code[--start] = '1';
			current = father;
			father = HT[father].parent;
		}

		//Ϊ��i���ַ��ı��봮����洢�ռ�
		HC[i] = (char *)malloc((n-start)*sizeof(char));
		if(!HC[i])
		{
			printf("HC[i] malloc faild!");
			exit(-1);
		}
		//�����봮��code���Ƶ�HC
		strcpy_s(HC[i],sizeof(code+start),code+start);
	}

	free(code); //�ͷű�����봮����ʱ�ռ�
}

int min(HuffmanTree HT,int k)
{
	int i = 0;
	int min;        //�������weight��С��parentΪ0��Ԫ�ص����
	int min_weight; //�������weight��С��parentΪ0��Ԫ�ص�weightֵ

	//�Ƚ���һ��parentΪ0��Ԫ�ص�weightֵ����min_weight,�����Ժ�Ƚ��á�
	//ע�⣬���ﲻ�ܰ���һ�����������ֱ�ӽ�HT[0].weight����min_weight��
	//��Ϊ���HT[0].weight��ֵ�Ƚ�С����ô�ڵ�һ�ι��������ʱ�ͻᱻѡ�ߣ�
	//��������ÿһ��ѡ����СȨֵ����������ıȽϻ�������HT[0].weight��ֵ�������жϣ�
	//�����ֻ��ٴν���ѡ�ߣ��Ӷ������߼��ϵĴ���
	while(HT[i].parent != 0)
		i++;
	min_weight = HT[i].weight;
	min = i;

	//ѡ��weight��С��parentΪ0��Ԫ�أ���������Ÿ���min
	for(;i<k;i++)
	{
		if((HT[i].weight<min_weight) && HT[i].parent==0)
		{
			min_weight = HT[i].weight;
			min = i;
		}
	}

    //ѡ��weight��С��Ԫ�غ󣬽���parent��0��ʹ����һ�αȽ�ʱ�����ų����⡣
	HT[min].parent = 1;

	return min;
}
int main()
{
	int n;   //��Ҫ������ַ��ĸ���
	printf("��������Ҫ������ַ��ĸ�����>1����");
	scanf_s("%d",&n);
    while(n<=1)
	{
		printf("�ַ������������1�����������룺");
		scanf_s("%d",&n);
	}

	int i;
	int *wet = (int *)malloc(n*sizeof(int));  //���ÿ���ַ���Ȩֵ
	printf("������������%d���ַ���Ȩֵ�����ͣ���",n);
	for(i=0;i<n;i++)
	{
		scanf_s("%d",wet+i);
	}

	HuffmanCode HC;  //����շ�������
	HuffmanTree HT = create_HuffmanTree(wet,n);  //���ɺշ�����
	HuffmanCoding(HT,HC,n);        //��ÿ���ַ��ĺշ�������

	printf("��������˳�򣬸�Ȩֵ��Ӧ�ַ��ĺշ����������£�\n");
	for(i=0;i<n;i++)
	{
		puts(HC[i]);
	}
	free(wet);

	return 0;
}



