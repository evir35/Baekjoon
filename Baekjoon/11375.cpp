// Date		: 2017.10.16
// Author	: Minhyeok Park
// URL		: https://www.acmicpc.net/problem/11375

#include <iostream>

using namespace std;

bool match(int N, int M, int** matrix, bool* visited, int* matching, int start)
{
	if (visited[start])
		return false;

	visited[start] = true;

	// ��� ���� Ž��
	for (int i = 1; i < M + 1; i++)
	{
		// ������ ������ ���
		if (matrix[start][i] == 1)
		{
			// ���� ���� ���� ���
			if (matching[i] == 0)
			{
				matching[i] = start;
				return true;
			}
			// �̹� ������ ���� ���
			else
			{
				// �̹� ������ ����� �ٸ� �Ϸ� �ű� �� �ִ� ���
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
	// ������ ��
	int N;
	// ���� ����
	int M;
	// �׷����� ���� ���
	int **matrix;
	// ��Ī �迭
	int *matching;
	// �湮�ߴ��� ���� Ȯ��
	bool *visited;
	// ���� �� ����
	int edge;
	// ���� �� ���� ����
	int end;
	// ��� ����
	int result = 0;

	// �� �Է� ����
	cin >> N >> M;

	// ���� ��� ����
	matrix = new int*[N + 1];
	matching = new int[M + 1];
	visited = new bool[N + 1];
	for (int i = 0; i < N + 1; i++)
	{
		matrix[i] = new int[M + 1];
		matching[i] = 0;

		// ������� �ʱ�ȭ
		for (int j = 0; j < M + 1; j++)
		{
			matrix[i][j] = 0;
		}
	}

	// ������� �Է� ����
	for (int i = 1; i < N + 1; i++)
	{
		// ���� �� �Է� ����
		cin >> edge;

		// ���� ��� ����
		for (int j = 0; j < edge; j++)
		{
			cin >> end;
			matrix[i][end] = 1;
		}
	}

	// �̺и�Ī ����
	for (int i = 1; i < N + 1; i++)
	{
		// �湮 �迭 �ʱ�ȭ
		for (int j = 0; j < N + 1; j++)
		{
			visited[j] = false;
		}

		// ��Ī�� ������ ��� ����
		if (match(N, M, matrix, visited, matching, i))
		{
			result++;
		}
	}

	// ��� ���
	cout << result;

	return 0;
}