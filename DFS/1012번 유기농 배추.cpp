/*
* 1. 아이디어
* - 2중 반복문을 통해 DFS를 수행하며 새로운 구역을 탐색할 때마다 Count 값을 증가시킴
* 
* 2. 시간 복잡도
* - V = N * N, M * M(1 ~ 50)
* - E = 4V
* - O(V + E) = O(5V) = O(12,500) < 2억
* 
* 3. 사용 변수
* - int : 배추밭의 가로 길이, 세로 길이, 배추가 심어져 있는 위치의 개수
* - int[][] : 배추밭의 형태를 저장하기 위한 2차원 배열
* - int[] : 좌표상에서 상, 하, 좌, 우로 이동하기 위한 1차원 배열
*/

#include <iostream>

using namespace std;

#define endl '\n'
#define MAX 50

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int n, m, k;
int map[MAX][MAX];

void input()
{
	cin >> m >> n >> k;
	for (int i = 0; i < k; ++i)
	{
		int x, y;
		cin >> x >> y;

		map[y][x] = 1;
	}
}

void DFS(int y, int x)
{
	map[y][x] = 0;

	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

		if (map[ny][nx] == 1)
			DFS(ny, nx);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t--)
	{
		int cnt = 0;

		input();

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (map[i][j] == 1)
				{
					DFS(i, j);
					++cnt;
				}
			}
		}

		cout << cnt << endl;
	}

	return 0;
}