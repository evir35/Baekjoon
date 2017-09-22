// Date		: 2017.09.15
// Author	: Minhyeok Park
// URL		: https://www.acmicpc.net/problem/1697
#include <iostream>
#include <queue>

using namespace std;

int main()
{
	// 현재 위치
	int srcPos;

	// 도착 위치
	int	destPos;

	// 임시 저장 변수
	int temp;

	// 방문 여부 배열
	int visited[100001];

	// 거리 저장 큐
	queue<int> dis;

	// 방문 여부 배열 초기화
	for (int visitedIndex = 0; visitedIndex < 100001; visitedIndex++)
	{
		visited[visitedIndex] = -1;
	}

	// 시작 위치 도착 위치 받음
	cin >> srcPos >> destPos;

	// 시작 지점 저장
	dis.push(srcPos);
	visited[srcPos] = 0;

	// 큐가 빌 때 까지 수행
	while (!dis.empty())
	{
		// 하나의 정점 
		temp = dis.front();
		dis.pop();

		if (temp == destPos)
		{
			cout << visited[temp];
			break;
		}

		// 뒤로 이동
		if (temp - 1 >= 0 && visited[temp - 1] == -1) 
		{
			visited[temp - 1] = visited[temp] + 1;
			dis.push(temp - 1);
		}
		
		// 앞으로 이동
		if (temp + 1 <= 100000 && visited[temp + 1] == -1)
		{
			visited[temp + 1] = visited[temp] + 1;
			dis.push(temp + 1);
		}
		
		// 순간이동
		if (temp * 2 <= 100000 && visited[temp * 2] == -1)
		{
			visited[temp * 2] = visited[temp] + 1;
			dis.push(temp * 2);
		}
	}

	cin >> srcPos;

	return 0;
}