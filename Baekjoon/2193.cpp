// Date		: 2017.10.25
// Author	: Minhyeok Park
// URL		: https://www.acmicpc.net/problem/2193
#include <iostream>
using namespace std;

int main()
{
	// 구할 자릿 수
	int num;

	// 이친수 자릿 수 마다 계산하기 위한 배열
	long long* binary;
	
	// 자릿 수 입력 받음
	cin >> num;

	// 자릿 수 +1 만큼의 배열 생성
	binary = new long long[num + 1];

	// 한자리나 두자리는 1개
	if (num == 1 || num == 2) {
		cout << 1;
		return 0;
	}

	// 한자리나 두자리는 1개
	binary[1] = 1;
	binary[2] = 1;

	// DP로 계산
	for (int i = 3; i <= num; i++)
	{
		// i-1, i-2 인덱스의 값을 더한 것이 i 인덱스의 값
		binary[i] = binary[i - 2] + binary[i - 1];
	}

	// 결과 계산
	cout << binary[num];
	cin >> num;
	return 0;
}