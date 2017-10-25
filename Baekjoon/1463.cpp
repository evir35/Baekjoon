// Date		: 2017.10.17
// Author	: Minhyeok Park
// URL		: https://www.acmicpc.net/problem/1920

#include <iostream>

using namespace std;

// 다이나믹 함수
int dp(int num)
{
	// 다이나믹 배열
	int *arr;

	// 다이나믹 배열 할당
	arr = new int[num + 1];

	// 배열 초기화
	for (int i = 1; i <= num; i++)
	{
		arr[i] = 1000000;
	}

	// 첫 번째는 0이다
	arr[1] = 0;

	// 각 자리의 +1, *2, *3의 경우를 계산
	for (int i = 1; i < num; i++)
	{
		if (i + 1 <= num && arr[i + 1] > arr[i] + 1) arr[i + 1] = arr[i] + 1;
		if (i * 2 <= num && arr[i * 2] > arr[i] + 1) arr[i * 2] = arr[i] + 1;
		if (i * 3 <= num && arr[i * 3] > arr[i] + 1) arr[i * 3] = arr[i] + 1;
	}

	// 결과 리턴
	return arr[num];
}

int main()
{
	// 계산할 수
	int num;

	// 수 입력받음
	cin >> num;

	// 결과 출력
	cout << dp(num);

	return 0;
}