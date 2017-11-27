#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

//----------------求多项式的和 (Horner算法)------------------------

//----如F(X)=4X^3+8X^2+X+2

//#define N 4    //几项
//#define X 3    //X=3时的结果
//int main()
//{
//	int poly=0,i,A[N];
//	A[0]=4;
//	A[1]=8;
//	A[2]=1;
//	A[3]=2;
//	for(i=0;i<N;i++)
//	{
//		poly=poly*X+A[i];   //A[i]为多项式的系数
//	}
//	printf("poly=% d\n",poly);
//	return poly;
//}

#define MaxDegree 20  //系数
typedef struct PL
{
	int CoeffArray[MaxDegree+1];
	int HighPower;
}*Polynomial;
Polynomial Poly1,Poly2,PolySum,PolyProd;

int Max(int a, int b)
{
	return a>b?a:b;
}

void ZeroPolynomial(Polynomial Poly)   //初始化
{
	int i;
	for(i=0;i<=MaxDegree;i++)
		Poly->CoeffArray[i]=0;
	Poly->HighPower=0;
}

void input( Polynomial Poly1, Polynomial Poly2)
{
	int n1=0,n2=0;
	ZeroPolynomial( Poly1);
	ZeroPolynomial( Poly2);
	ZeroPolynomial( PolySum);
	ZeroPolynomial( PolyProd);

	printf("Input the Poly1's HighPower: ");
	scanf_s("%d",&n1);
	Poly1->HighPower=n1;
	printf("Input the Poly1's CoeffArray: \n");
	while(n1>=0)
	{
		scanf_s("%d",&Poly1->CoeffArray[n1]);
		n1--;
	}
	printf("Input the Poly2's HighPower: ");
	scanf_s("%d",&n2);
	Poly2->HighPower=n2;
	printf("Input the Poly2's CoeffArray: \n");
	while(n2>=0)
	{
		scanf_s("%d",&Poly2->CoeffArray[n2]);
		n2--;
	}
}
void AddPolynomial( Polynomial Poly1, Polynomial Poly2, Polynomial PolySum)   //两个多项式相加
{
	int i,p;
	input(Poly1,Poly2);
	PolySum->HighPower=Max(Poly1->HighPower, Poly2->HighPower);
	printf("answer of add polynomial is : ");
	for(i=PolySum->HighPower;i>=0;i--)
	{
		PolySum->CoeffArray[i] = Poly1->CoeffArray[i] + Poly2->CoeffArray[i];
		p= PolySum->CoeffArray[i];
		printf("%dX^%d ",p,i);
	}

}

void MultPolynomial( Polynomial Poly1, Polynomial Poly2, Polynomial PolyProd)   //两个多项式相乘
{
	int i,j;
	int p;
	input(Poly1,Poly2);
	printf("answer of mult polynomial is : ");
	for(i=Poly1->HighPower;i>=0;i--)
		for(j=Poly2->HighPower;j>=0;j--)
			PolyProd->CoeffArray[i+j] += Poly1->CoeffArray[i] * Poly2->CoeffArray[j];
	for(i=Poly1->HighPower+Poly2->HighPower;i>=0;i--)
	{
		p=PolyProd->CoeffArray[i];
		printf("%dX^%d ",p,i);
	}
}

void CalculatePolynomial(Polynomial Poly)
{
	int i,s=0,x=0;
	int n1=0;
	ZeroPolynomial( Poly);
	printf("Input the Poly's HighPower: ");
	scanf_s("%d",&n1);
	Poly->HighPower=n1;
	printf("Input the Poly's CoeffArray: \n");	
	while(n1>=0)
	{
		scanf_s("%d",&Poly->CoeffArray[n1]);
		n1--;
	}
	printf("Input the x: ");
	scanf_s("%d",&x);
	for(i=Poly->HighPower;i>=0;i--)
		s= s*x + Poly->CoeffArray[i];
	printf("answer of calculate polynomial is : %d",s);
}

int main()
{	
	int flag=1;
	Poly1=(struct PL*)malloc(sizeof(Polynomial));
	Poly2=(struct PL*)malloc(sizeof(Polynomial));
	PolySum=(struct PL*)malloc(sizeof(Polynomial));
	PolyProd=(struct PL*)malloc(sizeof(Polynomial));
		
	while(flag!=0)
	{
		printf("\ninput 1 for Add; 2 for Mult; 3 for calculate; 0 for exit \n");
		scanf_s("%d",&flag);
		switch(flag)
		{
			case 1:
				 AddPolynomial(Poly1,Poly2,PolySum);
				 break;
			case 2:
				MultPolynomial(Poly1,Poly2,PolyProd);
				break;
			case 3:
				
				CalculatePolynomial(Poly1);
				break;
			case 0:
				flag=0;
				break;
			default:
				printf("input error!\n");
		}
	}
}
	





