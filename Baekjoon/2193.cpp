// Date		: 2017.10.25
// Author	: Minhyeok Park
// URL		: https://www.acmicpc.net/problem/2193
#include <iostream>
using namespace std;

int main()
{
	// ���� �ڸ� ��
	int num;

	// ��ģ�� �ڸ� �� ���� ����ϱ� ���� �迭
	long long* binary;
	
	// �ڸ� �� �Է� ����
	cin >> num;

	// �ڸ� �� +1 ��ŭ�� �迭 ����
	binary = new long long[num + 1];

	// ���ڸ��� ���ڸ��� 1��
	if (num == 1 || num == 2) {
		cout << 1;
		return 0;
	}

	// ���ڸ��� ���ڸ��� 1��
	binary[1] = 1;
	binary[2] = 1;

	// DP�� ���
	for (int i = 3; i <= num; i++)
	{
		// i-1, i-2 �ε����� ���� ���� ���� i �ε����� ��
		binary[i] = binary[i - 2] + binary[i - 1];
	}

	// ��� ���
	cout << binary[num];
	cin >> num;
	return 0;
}