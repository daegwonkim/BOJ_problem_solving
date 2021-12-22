/*
* 1. 아이디어
* - 최소 일수를 구해야하기 때문에 BFS를 수행
* - 시작점이 여러 개일 수 있으므로 입력을 받는 순간에 시작점을 Queue에 바로 삽입하여 각 시작점마다 병렬처리를 수행
* - 방문 여부를 따로 확인할 필요 없이 구역을 확인할 때마다 1로 초기화 시켜줌
* 
* 2. 시간 복잡도
* - V = N * M(2 ~ 1000)
* - E = 4V
* - O(V + E) = O(V + 4V) = O(5V) = O(5,000,000) < 2억
* 
* 3. 사용 변수
* - int : 상자의 크기(가로, 세로)
* - int[][] : 상자에 저장된 토마토들의 정보를 저장하기 위한 2차원 배열
* - int[] : 상, 하, 좌, 우로 이동하기 위한 1차원 배열
* - queue : BFS를 수행하기 위함
*/

#include <iostream>
#include <queue>

using namespace std;

#define endl '\n'
#define MAX 1000

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int m, n, ans = 0;
int box[MAX][MAX];
queue<pair<int, int>> que;

void input()
{
	cin >> m >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> box[i][j];
			if (box[i][j] == 1)
				que.push({ i, j });
		}
	}
}

void BFS()
{
	while (!que.empty())
	{
		int y = que.front().first;
		int x = que.front().second;
		que.pop();

		for (int i = 0; i < 4; ++i)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

			if (box[ny][nx] == 0)
			{
				box[ny][nx] = box[y][x] + 1;
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
	BFS();

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (box[i][j] == 0)
			{
				cout << -1 << endl;
				return 0;
			}
			else
				ans = max(ans, box[i][j]);
		}
	}

	cout << ans - 1 << endl;

	return 0;
}