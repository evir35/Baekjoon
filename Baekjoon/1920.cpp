// Date		: 2017.10.17
// Author	: Minhyeok Park
// URL		: https://www.acmicpc.net/problem/1920

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 이분 탐색으로 숫자를 찾음
bool binarySearch(vector<int>* arr, int findNum)
{
	int left = 0;
	int right = arr->size() - 1;
	int mid;

	// 구간이 1이 될때까지 탐색
	while (left <= right)
	{
		// 구간의 중간 부분 탐색
		mid = (left + right) / 2;

		// 중간이 찾는 수보다 클 경우 오른쪽 구간을 줄여줌
		if ((*arr)[mid] > findNum)
		{
			right = mid - 1;
		}
		// 중간이 찾는 수보다 작을 경우 왼쪽 구간을 줄여줌
		else if ((*arr)[mid] < findNum)
		{
			left = mid + 1;
		}
		// 중간과 값이 같다면 찾았으므로 true를 리턴
		else
		{
			return true;
		}
	}
	// 찾지 못하고 끝났으므로 false를 리턴
	return false;
}

int main()
{
	// 찾으려는 숫자 벡터
	vector<int> findArr;
	// 이미 존재하는 숫자 벡터
	vector<int> numArr;
	// 각 벡터의 사이즈
	int findSize, numSize;
	// 입력 받을 변수
	int num;

	// 이미 존재하는 숫자 받음
	cin >> numSize;
	for (int i = 0; i < numSize; i++)
	{
		cin >> num;
		numArr.push_back(num);
	}
	
	// 찾으려눈 숫자 받음
	cin >> findSize;
	for (int i = 0; i < findSize; i++)
	{
		cin >> num;
		findArr.push_back(num);
	}

	// 배열 정렬
	sort(numArr.begin(), numArr.end());
	
	// 각 숫자가 있는지 이분 탐색
	for (int i = 0; i < findSize; i++)
	{
		cout << binarySearch(&numArr, findArr[i]) << "\n";
	}

	return 0;
}