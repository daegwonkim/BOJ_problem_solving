/*
* 1. 아이디어
* - BFS를 수행하여 맵을 탐색
* - 새로운 구역을 탐색할 때마다 Count 값을 증가시켜 결과 출력
* - 테스트 케이스가 여러 번이기 때문에 방문 여부를 따로 확인할 필요 없이 방문할 때마다 배열의 값을 0으로 변경함으로써 배열 초기화 과정을 생략함
* 
* 2. 시간 복잡도
* - V = M, N(1 ~ 50)
* - E = 4V
* - O(V + 4V) = O(5V) = O(2500 * 5) = O(12,500)
* 
* 3. 사용 변수
* - int : 테스트 케이스의 개수, 맵의 가로 크기, 세로 크기, 배추가 심어져 있는 위치의 개수
* - int[][] : 배추가 심어져 있는 위치를 저장하기 위한 2차원 배열
* - int[] : 상, 하, 좌, 우로 이동하기 위한 1차원 배열
* - queue : BFS를 수행하기 위함(y, x 좌표를 저장)
*/

#include <iostream>
#include <queue>

using namespace std;

#define endl '\n'
#define MAX 50

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int t, m, n, k;
int map[MAX][MAX];
queue<pair<int, int>> que;

void input()
{
	cin >> m >> n >> k;
	for (int i = 0; i < k; ++i)
	{
		int a, b;
		cin >> a >> b;

		map[b][a] = 1;
	}
}

void BFS(int y, int x)
{
	que.push({ y, x });
	map[y][x] = 0;

	while (!que.empty())
	{
		int yy = que.front().first;
		int xx = que.front().second;
		que.pop();

		for (int i = 0; i < 4; ++i)
		{
			int ny = yy + dy[i];
			int nx = xx + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

			if (map[ny][nx])
			{
				map[ny][nx] = 0;
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

	cin >> t;
	while (t--)
	{
		int cnt = 0;

		input();

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (map[i][j])
				{
					BFS(i, j);
					++cnt;
				}
			}
		}

		cout << cnt << endl;
	}

	return 0;
}