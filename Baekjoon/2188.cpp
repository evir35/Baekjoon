// Date		: 2017.10.16
// Author	: Minhyeok Park
// URL		: https://www.acmicpc.net/problem/2188

#include <iostream>

using namespace std;

bool match(int N, int M, int** matrix, bool* visited, int* matching, int start)
{
	if (visited[start])
		return false;

	visited[start] = true;

	// 모든 간선 탐색
	for (int i = 1; i < M + 1; i++)
	{
		// 간선이 존재할 경우
		if (matrix[start][i] == 1)
		{
			// 빈 축사일 경우
			if (matching[i] == 0)
			{
				matching[i] = start;
				return true;
			}
			// 이미 차지한 축사가 있을 경우
			else
			{
				// 이전 소들을 다른 축사로 옮길 수 있을 경우
				if (matching[i] != start && match(N, M, matrix, visited, matching, matching[i]))
				{
					matching[i] = start;
					return true;
				}
			}
		}
	}

	return false;
}

int main()
{
	// 소의 마릿수
	int N;
	// 축사의 개수
	int M;
	// 그래프의 인접 행렬
	int **matrix;
	// 매칭 배열
	int *matching;
	// 방문했는지 여부 확인
	bool *visited;
	// 간선 수 저장
	int edge;
	// 간선 끝 지점 저장
	int end;
	// 결과 저장
	int result = 0;

	// 수 입력 받음
	cin >> N >> M;

	// 인접 행렬 생성
	matrix = new int*[N + 1];
	matching = new int[N + 1];
	visited = new bool[N + 1];
	for (int i = 0; i < N + 1; i++)
	{
		matrix[i] = new int[M+1];
		matching[i] = 0;

		// 인접행렬 초기화
		for (int j = 0; j < M + 1; j++)
		{
			matrix[i][j] = 0;
		}
	}

	// 인접행렬 입력 받음
	for (int i = 1; i < N + 1; i++)
	{
		// 간선 수 입력 받음
		cin >> edge;

		// 인접 행렬 생성
		for (int j = 0; j < edge; j++)
		{
			cin >> end;
			matrix[i][end] = 1;
		}
	}

	// 이분매칭 실행
	for (int i = 1; i < N + 1; i++)
	{
		// 방문 배열 초기화
		for (int j = 0; j < N + 1; j++)
		{
			visited[j] = false;
		}

		// 매칭에 성공할 경우 증가
		if (match(N, M, matrix, visited, matching, i))
		{
			result++;
		}
	}

	// 결과 출력
	cout << result;

	return 0;
}