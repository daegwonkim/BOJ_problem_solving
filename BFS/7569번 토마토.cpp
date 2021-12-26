/*
* 1. 아이디어
* - BFS를 수행하여 토마토 상자를 탐색
* - x, y축 뿐만 아니라 z축 방향으로도 탐색해야 하기 때문에 z축 배열을 추가하여 탐색 수행
* - 탐색을 수행할 때마다 Count 값을 증가시킨 뒤 최종적으로 배열을 조사하면서 알맞은 결과를 출력
* 
* 2. 시간 복잡도
* - V = N * N, M * M(2 ~ 100)
* - E = 6N, 6M
* - O(V + E) = O(V + 6V) = O(7V) = O(70,000) < 2억
* 
* 3. 사용 변수
* - int : 상자의 가로, 세로, 높이
* - int[][][] : 저장된 토마토의 정보를 저장하기 위한 3차원 배열
* - int[] : 좌표상에서 상, 하, 좌, 우, 위, 아래로 이동하기 위한 1차원 배열
* - queue : BFS를 수행하기 위함
*/

#include <iostream>
#include <queue>

using namespace std;

#define endl '\n'
#define MAX 100

int dx[] = { 0, 0, 1, -1, 0, 0 };
int dy[] = { 1, -1, 0, 0, 0, 0 };
int dz[] = { 0, 0, 0, 0, 1, -1 };

int n, m, h;
int ans = 0;
int box[MAX][MAX][MAX];
queue<pair<int, pair<int, int>>> que;

void input()
{
	cin >> m >> n >> h;
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < m; ++k)
			{
				cin >> box[i][j][k];

				if (box[i][j][k] == 1)
					que.push({ i, {j, k} });
			}
		}
	}
}

void BFS()
{
	while (!que.empty())
	{
		int y = que.front().second.first;
		int x = que.front().second.second;
		int z = que.front().first;
		que.pop();

		for (int i = 0; i < 6; ++i)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			int nz = z + dz[i];

			if (ny < 0 || nx < 0 || nz < 0 || ny >= n || nx >= m || nz >= h) continue;

			if (box[nz][ny][nx] == 0)
			{
				box[nz][ny][nx] = box[z][y][x] + 1;
				que.push({ nz, {ny, nx} });
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

	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < m; ++k)
			{
				if (box[i][j][k] == 0)
				{
					cout << -1 << endl;
					return 0;
				}
				else
					ans = max(ans, box[i][j][k]);
			}
		}
	}

	cout << ans - 1 << endl;

	return 0;
}