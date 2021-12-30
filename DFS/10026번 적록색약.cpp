/*
* 1. 아이디어
* - 2중 반복문을 통해 각 셀에 대한 DFS를 수행하여 구역의 수를 구함
* - 적록색약이 아닌 사람이 보는 경우에 대한 DFS를 먼저 수행한 뒤 값을 구함
* - 배열의 형태를 변경(G -> R)하여 적록색약인 사림이 보는 경우에 대한 DFS를 수행하여 값을 구함
* 
* 2. 시간 복잡도
* - V = N * N(1 ~ 100)
* - E = 4V
* - O(V + E) = O(V + 4V) = O(5V) = O(50,000) < 2억
* 
* 3. 사용 변수
* - int : 그림의 가로, 세로 크기
* - char[][] : 그림의 형태를 저장하기 위한 2차원 배열
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

int n;
char paint[MAX][MAX];
bool visited[MAX][MAX];

void input()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;

		for (int j = 0; j < n; ++j)
			paint[i][j] = str[j];
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

		if (paint[ny][nx] == paint[y][x] && !visited[ny][nx])
		{
			DFS(ny, nx);
		}
	}
}

void solve()
{
	int cnt = 0;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (!visited[i][j])
			{
				DFS(i, j);
				++cnt;
			}
		}
	}

	cout << cnt << ' ';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (paint[i][j] == 'G')
				paint[i][j] = 'R';

	memset(visited, false, sizeof(visited));

	solve();

	return 0;
}