// Date		: 2017.09.15
// Author	: Minhyeok Park
// URL		: https://www.acmicpc.net/problem/1149
#include <iostream>

#define RED 0
#define GREEN 1
#define BLUE 2

using namespace std;

int main()
{
	// 집 개수
	int houseNumber;

	// 집 색칠 비용
	int colorValue[1000][3];

	// dynamic programming 배열;
	int valueDP[1000][3];

	// 집 개수 입력 받음
	cin >> houseNumber;

	// 초기화
	for (int houseIndex = 0; houseIndex < houseNumber; houseIndex++)
	{
		valueDP[houseIndex][RED] = 0;
		valueDP[houseIndex][GREEN] = 0;
		valueDP[houseIndex][BLUE] = 0;

		cin >> colorValue[houseIndex][RED]
			>> colorValue[houseIndex][GREEN]
			>> colorValue[houseIndex][BLUE];
	}

	// dp 배열 초기값
	valueDP[0][RED] = colorValue[0][RED];
	valueDP[0][GREEN] = colorValue[0][GREEN];
	valueDP[0][BLUE] = colorValue[0][BLUE];

	// dp 계산
	for (int houseIndex = 1; houseIndex < houseNumber; houseIndex++)
	{
		valueDP[houseIndex][RED] = colorValue[houseIndex][RED];
		valueDP[houseIndex][RED] += (valueDP[houseIndex - 1][GREEN] > valueDP[houseIndex - 1][BLUE]) ? valueDP[houseIndex - 1][BLUE] : valueDP[houseIndex - 1][GREEN];

		valueDP[houseIndex][GREEN] = colorValue[houseIndex][GREEN];
		valueDP[houseIndex][GREEN] += (valueDP[houseIndex - 1][RED] > valueDP[houseIndex - 1][BLUE]) ? valueDP[houseIndex - 1][BLUE] : valueDP[houseIndex - 1][RED];

		valueDP[houseIndex][BLUE] = colorValue[houseIndex][BLUE];
		valueDP[houseIndex][BLUE] += (valueDP[houseIndex - 1][GREEN] > valueDP[houseIndex - 1][RED]) ? valueDP[houseIndex - 1][RED] : valueDP[houseIndex - 1][GREEN];
	}
	
	// 최소값 찾음
	int min = valueDP[houseNumber - 1][0];

	if (min > valueDP[houseNumber - 1][1])
		min = valueDP[houseNumber - 1][1];
	if (min > valueDP[houseNumber - 1][2])
		min = valueDP[houseNumber - 1][2];

	// 결과 출력
	cout << min;

	return 0;
}