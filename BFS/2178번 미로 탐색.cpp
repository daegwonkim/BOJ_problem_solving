/*
* 1. 아이디어
* - BFS를 이용하여 미로를 탐색.
* - 현재까지 지나온 칸의 수를 저장하기 위한 배열을 따로 지정하여 Count를 센다.
* 
* 2. 시간복잡도
* - V, E = N, M(2 ~ 100)
* - O(V + E) = O(100 + 100) = O(200) < 2억
* 
* 3. 사용 변수
* - int : 배열의 가로, 세로 크기.
* - string : 맵의 형태를 입력받기 위함(공백없이 입력 되기 때문).
* - queue : BFS를 구현하기 위함.
* - int[] : 상, 하, 좌, 우로 이동하기 위한 1차원 배열.
* - bool[][] : 방문 여부를 확인하기 위한 2차원 배열.
* - int[][] : 맵의 형태를 저장하기 위한 2차원 배열.
*/

#include <iostream>
#include <queue>
#include <string>

using namespace std;

#define endl '\n'
#define MAX 101

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int n, m;
int map[MAX][MAX];
int cnt[MAX][MAX] = { 0, };
bool check[MAX][MAX] = { 0, };
queue<pair<int, int>> que;

void input()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		string input;
		cin >> input;

		for (int j = 1; j <= m; ++j)
			map[i][j] = input[j - 1] - '0';
	}
}

void BFS()
{
	check[1][1] = true;
	cnt[1][1] = 1;
	que.push({ 1, 1 });

	while (!que.empty())
	{
		int y = que.front().first;
		int x = que.front().second;
		que.pop();

		for (int i = 0; i < 4; ++i)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny <= 0 || nx <= 0 || ny > n || nx > m) continue;

			if (map[ny][nx] && !check[ny][nx])
			{
				check[ny][nx] = true;
				cnt[ny][nx] = cnt[y][x] + 1;
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

	cout << cnt[n][m] << endl;

	return 0;
}