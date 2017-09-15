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
	// �� ����
	int houseNumber;

	// �� ��ĥ ���
	int colorValue[1000][3];

	// dynamic programming �迭;
	int valueDP[1000][3];

	// �� ���� �Է� ����
	cin >> houseNumber;

	// �ʱ�ȭ
	for (int houseIndex = 0; houseIndex < houseNumber; houseIndex++)
	{
		valueDP[houseIndex][RED] = 0;
		valueDP[houseIndex][GREEN] = 0;
		valueDP[houseIndex][BLUE] = 0;

		cin >> colorValue[houseIndex][RED]
			>> colorValue[houseIndex][GREEN]
			>> colorValue[houseIndex][BLUE];
	}

	// dp �迭 �ʱⰪ
	valueDP[0][RED] = colorValue[0][RED];
	valueDP[0][GREEN] = colorValue[0][GREEN];
	valueDP[0][BLUE] = colorValue[0][BLUE];

	// dp ���
	for (int houseIndex = 1; houseIndex < houseNumber; houseIndex++)
	{
		valueDP[houseIndex][RED] = colorValue[houseIndex][RED];
		valueDP[houseIndex][RED] += (valueDP[houseIndex - 1][GREEN] > valueDP[houseIndex - 1][BLUE]) ? valueDP[houseIndex - 1][BLUE] : valueDP[houseIndex - 1][GREEN];

		valueDP[houseIndex][GREEN] = colorValue[houseIndex][GREEN];
		valueDP[houseIndex][GREEN] += (valueDP[houseIndex - 1][RED] > valueDP[houseIndex - 1][BLUE]) ? valueDP[houseIndex - 1][BLUE] : valueDP[houseIndex - 1][RED];

		valueDP[houseIndex][BLUE] = colorValue[houseIndex][BLUE];
		valueDP[houseIndex][BLUE] += (valueDP[houseIndex - 1][GREEN] > valueDP[houseIndex - 1][RED]) ? valueDP[houseIndex - 1][RED] : valueDP[houseIndex - 1][GREEN];
	}
	
	// �ּҰ� ã��
	int min = valueDP[houseNumber - 1][0];

	if (min > valueDP[houseNumber - 1][1])
		min = valueDP[houseNumber - 1][1];
	if (min > valueDP[houseNumber - 1][2])
		min = valueDP[houseNumber - 1][2];

	// ��� ���
	cout << min;

	return 0;
}