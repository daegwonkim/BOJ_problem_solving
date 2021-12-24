/*
* 1. 아이디어
* - 먼저 벽 3개를 세운 뒤 BFS를 수행하여 바이러스를 퍼뜨림
* - BFS 수행을 마치면 반복문을 돌며 안전 영역의 크기를 확인
* - 위의 과정을 맵에 벽 3개를 세우는 모든 경우의 수에 대해 수행하며 안전 영역의 최댓값을 갱신시킴
* 
* 2. 시간 복잡도
* - V = N * M(3 ~ 8)
* - E = 4V
* - O(V + E) = O(V + 4V) = O(5V) = O(320) < 2억
* 
* 3. 사용 변수
* - int : 지도의 세로 크기, 가로 크기
* - int[] : 좌표 상에서 상, 하, 좌, 우로 이동하기 위한 1차원 배열
* - int[][] : 지도의 형태를 저장하기 위한 2차원 배열, BFS를 수행하기 위한 복사본 배열
* - queue : BFS를 수행하기 위함
* - vector : 바이러스의 초기 위치를 저장하기 위함
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl '\n'
#define MAX 8

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int n, m, ans = 0;
int map[MAX][MAX], copy_map[MAX][MAX];
queue<pair<int, int>> que;
vector<pair<int, int>> vec;

void input()
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> map[i][j];

			if (map[i][j] == 2)
				vec.push_back({ i, j });
		}
	}
}

int counting()
{
	int cnt = 0;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (copy_map[i][j] == 0)
				++cnt;
		}
	}

	return cnt;
}

void BFS()
{
	for (int i = 0; i < vec.size(); ++i)
		que.push({ vec[i].first, vec[i].second });

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

			if (copy_map[ny][nx] == 0)
			{
				copy_map[ny][nx] = 2;
				que.push({ ny, nx });
			}
		}
	}
}

void make_wall(int cnt)
{
	if (cnt == 3)
	{
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				copy_map[i][j] = map[i][j];

		BFS();
		ans = max(ans, counting());

		return;
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (map[i][j] == 0)
			{
				map[i][j] = 1;
				make_wall(cnt + 1);
				map[i][j] = 0;
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
	make_wall(0);

	cout << ans << endl;

	return 0;
}