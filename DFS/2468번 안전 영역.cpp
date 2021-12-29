/*
* 1. 아이디어
* - 0 부터 최대 높이까지 반복문을 통해 각 높이에 대한 DFS를 수행하여 안전 영역을 구한 뒤, 개수를 판별
* - DFS를 수행할 때마다 최댓값을 갱신시킴
* 
* 2. 시간 복잡도
* - V = N * N(2 ~ 100)
* - E = 4V
* - O(V + E) = O(V + 4V) = O(5V) = O(50,000) < 2억
* 
* 3. 사용 변수
* - int : 배열의 행과 열의 개수
* - int[][] : 배열의 형태를 저장하기 위한 2차원 배열
* - int[] : 좌표상에서 상, 하, 좌, 우로 이동하기 위한 1차원 배열
* - bool[][] : 방문 여부를 확인하기 위한 2차원 배열
*/

#include <iostream>
#include <string.h>

using namespace std;

#define endl '\n'
#define MAX 100

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int n, curHeight;
int maxHeight = 0, ans = 0;
int arr[MAX][MAX];
bool visited[MAX][MAX];

void input()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> arr[i][j];

			if (arr[i][j] > maxHeight)
				maxHeight = arr[i][j];
		}
	}
}

void DFS(int y, int x)
{
	visited[y][x] = true;

	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;

		if (arr[ny][nx] > curHeight && !visited[ny][nx])
		{
			visited[ny][nx] = true;
			DFS(ny, nx);
		}
	}
}

void solve(int height)
{
	int cnt = 0;

	curHeight = height;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (arr[i][j] > curHeight && !visited[i][j])
			{
				DFS(i, j);
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

	for (int i = 0; i < maxHeight; ++i)
	{
		solve(i);
		memset(visited, false, sizeof(visited));
	}

	cout << ans << endl;

	return 0;
}