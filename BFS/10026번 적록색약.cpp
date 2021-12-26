/*
* 1. 아이디어
* - BFS를 수행하여 그림을 탐색
* - 적록색약이 아닌 경우와 적록색약인 경우, 총 2번의 BFS를 수행하여 결과를 출력
* - 먼저 적록색약이 아닌 경우에 대한 BFS를 수행한 뒤 배열의 형태를 수정(G -> R)하여 다시 BFS를 수행
* 
* 2. 시간 복잡도
* - V = N * N(1 ~ 100)
* - E = 4V
* - O(V + E) = O(V + 4V) = O(5V) = O(50,000) * 2 < 2억
* 
* 3. 사용 변수
* - int : 그림의 가로, 세로 크기
* - char[][] : 그림의 형태를 저장하기 위한 2차원 배열
* - int[] : 좌표상에서 상, 하, 좌, 우로 이동하기 위한 1차원 배열
* - bool[][] : 방문 여부를 확인하기 위한 2차원 배열
* - queue : BFS를 수행하기 위함
*/

#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

#define endl '\n'
#define MAX 100

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int n;
int count_RGB = 0, count_RG = 0;
char paint[MAX][MAX];
bool visited[MAX][MAX];
queue<pair<int, int>> que;

void input()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;

		for (int j = 0; j < n; ++j)
			paint[i][j] = str[j];
	}
}

void BFS(int y, int x)
{
	visited[y][x] = true;
	que.push({ y, x });

	while (!que.empty())
	{
		int yy = que.front().first;
		int xx = que.front().second;
		que.pop();

		for (int i = 0; i < 4; ++i)
		{
			int ny = yy + dy[i];
			int nx = xx + dx[i];

			if (ny < 0 || nx < 0 || ny >= 100 || nx >= 100) continue;

			if ((paint[ny][nx] == paint[yy][xx]) && !visited[ny][nx])
			{
				visited[ny][nx] = true;
				que.push({ ny, nx });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (!visited[i][j])
			{
				BFS(i, j);
				++count_RGB;
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (paint[i][j] == 'G')
				paint[i][j] = 'R';
		}
	}

	memset(visited, false, sizeof(visited));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (!visited[i][j])
			{
				BFS(i, j);
				++count_RG;
			}
		}
	}

	cout << count_RGB << ' ' << count_RG << endl;

	return 0;
}