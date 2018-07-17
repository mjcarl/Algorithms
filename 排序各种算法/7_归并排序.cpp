#include<iostream>
#include<stdio.h>
using namespace std;

void Merge(int sourceArr[], int tempArr[], int startIndex, int midIndex, int endIndex)
{
	int i = startIndex, j = midIndex + 1, k = startIndex;
	while (i != midIndex + 1 && j != endIndex + 1)
	{
		if (sourceArr[i] > sourceArr[j])
			tempArr[k++] = sourceArr[j++];
		else
			tempArr[k++] = sourceArr[i++];
	}
	while (i != midIndex + 1)
		tempArr[k++] = sourceArr[i++];
	while (j != endIndex + 1)
		tempArr[k++] = sourceArr[j++];
	for (i = startIndex; i <= endIndex; i++)
		sourceArr[i] = tempArr[i];
}

//内部使用递归
void MergeSort(int sourceArr[], int tempArr[], int startIndex, int endIndex)
{
	int midIndex;
	if (startIndex < endIndex)
	{
		midIndex = (startIndex + endIndex) / 2;
		MergeSort(sourceArr, tempArr, startIndex, midIndex);
		MergeSort(sourceArr, tempArr, midIndex + 1, endIndex);
		Merge(sourceArr, tempArr, startIndex, midIndex, endIndex);
		cout << "============" << endl << "star t= " << startIndex << " ; end = " << endIndex << endl;
		for (int i = startIndex; i<=endIndex; i++)
			cout << sourceArr[i] << " ";
		cout << endl;
	}
}

int main(int argc, char * argv[])
{
	int a[8] = { 50, 10, 80, 30, 70, 40, 20, 60 };
	int i, b[8];
	cout << "原始数组：" << endl;
	for (i = 0; i < 8; i++)
		cout << a[i] << " " ;
	cout << endl; 
	MergeSort(a, b, 0, 7);
	cout<< "排序后：" << endl;
	for (i = 0; i<8; i++)
		cout << a[i] << " " ;
	cout << endl;
	return 0;
}