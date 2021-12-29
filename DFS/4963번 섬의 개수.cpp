/*
* 1. 아이디어
* - 2중 반복문을 통해 모든 좌표에 대한 DFS를 수행하여 새로운 구역을 탐색할 때마다 Count 값을 증가시킴
* - 대각선으로 연결된 경우도 포함되기 때문에 이동 배열에 대각선 경로를 추가
* 
* 2. 시간 복잡도
* - V = w * h(1 ~ 50)
* - E = 8V
* - O(V + E) = O(V + 8V) = O(9V) = O(22,500) < 2억
* 
* 3. 사용 변수
* - int : 지도의 너비와 높이
* - int[][] : 지도의 형태를 저장하기 위한 2차원 배열
* - int[] : 좌표상에서 상, 하, 좌, 우, 대각선으로 이동하기 위한 1차원 배열
*/

#include <iostream>

using namespace std;

#define endl '\n'
#define MAX 50

int dx[] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dy[] = { 1, -1, 0, 0, -1, 1, -1, 1 };

int w, h;
int map[MAX][MAX];

void input()
{
	cin >> w >> h;
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j)
			cin >> map[i][j];
}

void DFS(int y, int x)
{
	map[y][x] = 0;
	
	for (int i = 0; i < 8; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;

		if (map[ny][nx] == 1) 
			DFS(ny, nx);
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
					DFS(i, j);
					++cnt;
				}
			}
		}

		cout << cnt << endl;
	}

	return 0;
}