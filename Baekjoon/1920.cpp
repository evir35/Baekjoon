// Date		: 2017.10.17
// Author	: Minhyeok Park
// URL		: https://www.acmicpc.net/problem/1920

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// �̺� Ž������ ���ڸ� ã��
bool binarySearch(vector<int>* arr, int findNum)
{
	int left = 0;
	int right = arr->size() - 1;
	int mid;

	// ������ 1�� �ɶ����� Ž��
	while (left <= right)
	{
		// ������ �߰� �κ� Ž��
		mid = (left + right) / 2;

		// �߰��� ã�� ������ Ŭ ��� ������ ������ �ٿ���
		if ((*arr)[mid] > findNum)
		{
			right = mid - 1;
		}
		// �߰��� ã�� ������ ���� ��� ���� ������ �ٿ���
		else if ((*arr)[mid] < findNum)
		{
			left = mid + 1;
		}
		// �߰��� ���� ���ٸ� ã�����Ƿ� true�� ����
		else
		{
			return true;
		}
	}
	// ã�� ���ϰ� �������Ƿ� false�� ����
	return false;
}

int main()
{
	// ã������ ���� ����
	vector<int> findArr;
	// �̹� �����ϴ� ���� ����
	vector<int> numArr;
	// �� ������ ������
	int findSize, numSize;
	// �Է� ���� ����
	int num;

	// �̹� �����ϴ� ���� ����
	cin >> numSize;
	for (int i = 0; i < numSize; i++)
	{
		cin >> num;
		numArr.push_back(num);
	}
	
	// ã������ ���� ����
	cin >> findSize;
	for (int i = 0; i < findSize; i++)
	{
		cin >> num;
		findArr.push_back(num);
	}

	// �迭 ����
	sort(numArr.begin(), numArr.end());
	
	// �� ���ڰ� �ִ��� �̺� Ž��
	for (int i = 0; i < findSize; i++)
	{
		cout << binarySearch(&numArr, findArr[i]) << "\n";
	}

	return 0;
}