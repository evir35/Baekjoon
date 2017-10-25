// Date		: 2017.10.17
// Author	: Minhyeok Park
// URL		: https://www.acmicpc.net/problem/1920

#include <iostream>

using namespace std;

// ���̳��� �Լ�
int dp(int num)
{
	// ���̳��� �迭
	int *arr;

	// ���̳��� �迭 �Ҵ�
	arr = new int[num + 1];

	// �迭 �ʱ�ȭ
	for (int i = 1; i <= num; i++)
	{
		arr[i] = 1000000;
	}

	// ù ��°�� 0�̴�
	arr[1] = 0;

	// �� �ڸ��� +1, *2, *3�� ��츦 ���
	for (int i = 1; i < num; i++)
	{
		if (i + 1 <= num && arr[i + 1] > arr[i] + 1) arr[i + 1] = arr[i] + 1;
		if (i * 2 <= num && arr[i * 2] > arr[i] + 1) arr[i * 2] = arr[i] + 1;
		if (i * 3 <= num && arr[i * 3] > arr[i] + 1) arr[i * 3] = arr[i] + 1;
	}

	// ��� ����
	return arr[num];
}

int main()
{
	// ����� ��
	int num;

	// �� �Է¹���
	cin >> num;

	// ��� ���
	cout << dp(num);

	return 0;
}