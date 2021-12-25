/*
* 1. 아이디어
* - 2중 반복문을 통해 BFS를 수행하여 맵을 탐색
* - BFS 함수가 호출될 때 마다 Count를 증가시켜 섬의 개수 출력
* - BFS를 수행함과 동시에 방문한 곳을 0으로 초기화 시켜줌으로써 따로 초기화 작업을 수행할 필요 없음
*
* 2. 시간 복잡도
* - V = w * h(1 ~ 50)
* - E = 8V
* - O(V + E) = O(V + 8V) = O(9V) = O(22,500) < 2억
*
* 3. 사용 변수
* - int : 지도의 너비와 높이, 섬의 개수
* - int[][] : 지도의 형태를 저장하기 위한 2차원 배열
* - int[] : 좌표상에서 상, 하, 좌, 우, 대각선으로 이동하기 위한 1차원 배열
* - queue : BFS를 수행하기 위함
*/

#include <iostream>
#include <queue>

using namespace std;

#define endl '\n'
#define MAX 50

int dx[] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dy[] = { 1, -1, 0, 0, -1, 1, -1, 1 };

int w, h;
int map[MAX][MAX];
queue<pair<int, int>> que;

void input()
{
	cin >> w >> h;
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j)
			cin >> map[i][j];
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

		for (int i = 0; i < 8; ++i)
		{
			int ny = yy + dy[i];
			int nx = xx + dx[i];

			if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;

			if (map[ny][nx] == 1)
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

	while (1)
	{
		int cnt = 0;

		input();
		if (w == 0 && h == 0) break;

		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				if (map[i][j] == 1)
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