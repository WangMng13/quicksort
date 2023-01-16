#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
int n, a[1000], k;
void swap(int*  array, int left, int right)
{
	int tmp = array[left];
	array[left] = array[right];
	array[right] = tmp;
}
int partion(int* array, int begin, int end)//待排序数组的首指针，待排序的首尾元素下标
{
	int key = array[begin];//选取第一个元素为基准值
	int prev = begin;//前指针
	int cur = prev + 1;//后指针
	while(cur <= end)
	{
		if (array[cur] < key && ++prev != cur)//如果cur的值小于key判断++prev的值是否等于cur
			//若不等于，则交换prev和cur的值
			swap(array, prev, cur);
		cur++;//cur向后移动
	}
	//当跳出循环时，说明prev及之前的值都是小于基准值的数，则交换prev指向的值和基准值
	swap(array, prev, begin);
	return prev;//返回此时基准值的下标，便于下次递归调用时分组
}
void quicksort(int* array, int begin, int end)
{
	if (begin >= end)
		return;
	k++;
	int keypos = partion(array, begin, end);
	cout << "第" << k << "次排序：";
	for (int i = 1; i <= n; i++)
		cout << array[i] << " ";
	cout << endl;
	quicksort(array, begin, keypos - 1);
	quicksort(array, keypos + 1, end);
}
int main()
{
	cout << "数组元素的个数:";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cout << "第" << i << "个元素：";
		cin >> a[i];
	}
	quicksort(a, 1, n);  //调用函数
	return 0;
}
