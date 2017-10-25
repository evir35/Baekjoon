// Date		: 2017.10.17
// Author	: Minhyeok Park
// URL		: https://www.acmicpc.net/problem/2579

#include <iostream>
#include <vector>

using namespace std;

// 다이나믹 함수
int dp(vector<int>& stair, int size)
{
	// 다이나믹 배열 생성
	int** dp;

	// 다이나믹 배열 생성
	dp = new int*[size + 1];
	for (int i = 0; i <= size; i++)
	{
		dp[i] = new int[2];
	}

	// 초기값 세팅
	dp[0][0] = 0;
	dp[0][1] = 0;
	dp[1][0] = stair[0];
	dp[1][1] = 0;

	// 다이나믹 계산
	for (int i = 2; i <= size; i++)
	{
		if (dp[i - 2][0] > dp[i - 2][1]) dp[i][0] = stair[i - 1] + dp[i - 2][0];
		else							 dp[i][0] = stair[i - 1] + dp[i - 2][1];

		dp[i][1] = stair[i - 1] + dp[i - 1][0];
	}

	// 결과 반환
	return (dp[size][0] > dp[size][1] ? dp[size][0] : dp[size][1]);
}

int main()
{
	// 계단 점수 저장
	vector<int> stair;
	// 계단 사이즈
	int size;
	// 계단 점수 임시 저장
	int score;

	// 계단 사이즈 입력
	cin >> size;

	// 계단 점수 입력 받음
	for (int i = 0; i < size; i++)
	{
		cin >> score;
		stair.push_back(score);
	}

	// 결과 출력
	cout << dp(stair, size);

	return 0;
}