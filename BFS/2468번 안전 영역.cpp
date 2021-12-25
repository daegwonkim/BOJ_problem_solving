/*
* 1. 아이디어
* - 2중 반복문을 통해 BFS를 수행
* - 최소 높이부터 최대 높이까지의 경우의 수를 탐색하며 출력 값을 최댓값으로 갱신시킴
* 
* 2. 시간 복잡도
* - V = N * N(2 ~ 100)
* - E = 4V
* - O(V + E) = O(V + 4V) = O(5V) = O(50,000) * 2 < 2억
* 
* 3. 사용 변수
* - int : 배열의 행과 열의 개수, 최대 높이
* - int[][] : 배열의 형태를 저장하기 위한 2차원 배열, 복사본 배열
* - int[] : 좌표상에서 상, 하, 좌, 우로 이동하기 위한 1차원 배열
* - queue : BFS를 수행하기 위함
*/

#include <iostream>
#include <queue>

using namespace std;

#define endl '\n'
#define MAX 100

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int n;
int ans = 0, max_height = 0;
int arr[MAX][MAX];
int copy_arr[MAX][MAX];
queue<pair<int, int>> que;

void input()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> arr[i][j];
			if (max_height < arr[i][j])
				max_height = arr[i][j];
		}
	}
}

void BFS(int y, int x)
{
	que.push({ y, x });
	copy_arr[y][x] = 0;

	while (!que.empty())
	{
		int yy = que.front().first;
		int xx = que.front().second;
		que.pop();

		for (int i = 0; i < 4; ++i)
		{
			int ny = yy + dy[i];
			int nx = xx + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;

			if (copy_arr[ny][nx] == 1)
			{
				copy_arr[ny][nx] = 0;
				que.push({ ny, nx });
			}
		}
	}
}

void solve(int height)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (arr[i][j] > height)
				copy_arr[i][j] = 1;
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (copy_arr[i][j] == 1)
			{
				BFS(i, j);
				++cnt;
			}
		}
	}

	ans = max(ans, cnt);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();

	for (int i = 0; i < max_height; ++i)
		solve(i);

	cout << ans << endl;

	return 0;
}