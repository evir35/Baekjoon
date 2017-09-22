// Date		: 2017.09.15
// Author	: Minhyeok Park
// URL		: https://www.acmicpc.net/problem/1697
#include <iostream>
#include <queue>

using namespace std;

int main()
{
	// ���� ��ġ
	int srcPos;

	// ���� ��ġ
	int	destPos;

	// �ӽ� ���� ����
	int temp;

	// �湮 ���� �迭
	int visited[100001];

	// �Ÿ� ���� ť
	queue<int> dis;

	// �湮 ���� �迭 �ʱ�ȭ
	for (int visitedIndex = 0; visitedIndex < 100001; visitedIndex++)
	{
		visited[visitedIndex] = -1;
	}

	// ���� ��ġ ���� ��ġ ����
	cin >> srcPos >> destPos;

	// ���� ���� ����
	dis.push(srcPos);
	visited[srcPos] = 0;

	// ť�� �� �� ���� ����
	while (!dis.empty())
	{
		// �ϳ��� ���� 
		temp = dis.front();
		dis.pop();

		if (temp == destPos)
		{
			cout << visited[temp];
			break;
		}

		// �ڷ� �̵�
		if (temp - 1 >= 0 && visited[temp - 1] == -1) 
		{
			visited[temp - 1] = visited[temp] + 1;
			dis.push(temp - 1);
		}
		
		// ������ �̵�
		if (temp + 1 <= 100000 && visited[temp + 1] == -1)
		{
			visited[temp + 1] = visited[temp] + 1;
			dis.push(temp + 1);
		}
		
		// �����̵�
		if (temp * 2 <= 100000 && visited[temp * 2] == -1)
		{
			visited[temp * 2] = visited[temp] + 1;
			dis.push(temp * 2);
		}
	}

	cin >> srcPos;

	return 0;
}