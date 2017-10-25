// Date		: 2017.10.17
// Author	: Minhyeok Park
// URL		: https://www.acmicpc.net/problem/2579

#include <iostream>
#include <vector>

using namespace std;

// ���̳��� �Լ�
int dp(vector<int>& stair, int size)
{
	// ���̳��� �迭 ����
	int** dp;

	// ���̳��� �迭 ����
	dp = new int*[size + 1];
	for (int i = 0; i <= size; i++)
	{
		dp[i] = new int[2];
	}

	// �ʱⰪ ����
	dp[0][0] = 0;
	dp[0][1] = 0;
	dp[1][0] = stair[0];
	dp[1][1] = 0;

	// ���̳��� ���
	for (int i = 2; i <= size; i++)
	{
		if (dp[i - 2][0] > dp[i - 2][1]) dp[i][0] = stair[i - 1] + dp[i - 2][0];
		else							 dp[i][0] = stair[i - 1] + dp[i - 2][1];

		dp[i][1] = stair[i - 1] + dp[i - 1][0];
	}

	// ��� ��ȯ
	return (dp[size][0] > dp[size][1] ? dp[size][0] : dp[size][1]);
}

int main()
{
	// ��� ���� ����
	vector<int> stair;
	// ��� ������
	int size;
	// ��� ���� �ӽ� ����
	int score;

	// ��� ������ �Է�
	cin >> size;

	// ��� ���� �Է� ����
	for (int i = 0; i < size; i++)
	{
		cin >> score;
		stair.push_back(score);
	}

	// ��� ���
	cout << dp(stair, size);

	return 0;
}