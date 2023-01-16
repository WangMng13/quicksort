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
int partion(int* array, int begin, int end)//�������������ָ�룬���������βԪ���±�
{
	int key = array[begin];//ѡȡ��һ��Ԫ��Ϊ��׼ֵ
	int prev = begin;//ǰָ��
	int cur = prev + 1;//��ָ��
	while(cur <= end)
	{
		if (array[cur] < key && ++prev != cur)//���cur��ֵС��key�ж�++prev��ֵ�Ƿ����cur
			//�������ڣ��򽻻�prev��cur��ֵ
			swap(array, prev, cur);
		cur++;//cur����ƶ�
	}
	//������ѭ��ʱ��˵��prev��֮ǰ��ֵ����С�ڻ�׼ֵ�������򽻻�prevָ���ֵ�ͻ�׼ֵ
	swap(array, prev, begin);
	return prev;//���ش�ʱ��׼ֵ���±꣬�����´εݹ����ʱ����
}
void quicksort(int* array, int begin, int end)
{
	if (begin >= end)
		return;
	k++;
	int keypos = partion(array, begin, end);
	cout << "��" << k << "������";
	for (int i = 1; i <= n; i++)
		cout << array[i] << " ";
	cout << endl;
	quicksort(array, begin, keypos - 1);
	quicksort(array, keypos + 1, end);
}
int main()
{
	cout << "����Ԫ�صĸ���:";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cout << "��" << i << "��Ԫ�أ�";
		cin >> a[i];
	}
	quicksort(a, 1, n);  //���ú���
	return 0;
}
