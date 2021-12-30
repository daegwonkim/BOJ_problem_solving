/*
* 1. 아이디어
* - 1행 1열부터 시작하여 현재까지 방문하지 않은 알파벳에 대한 DFS를 수행
* - DFS를 수행하면서 Count 값을 증가시켜가며 최댓값을 찾아 갱신시킴
* 
* 2. 시간 복잡도
* - V = R * C(1 ~ 20)
* - E = 4V
* - O(V + E) = O(V + 4V) = O(5V) = O(20,000) < 2억
* 
* 3. 사용 변수
* - int : 보드의 세로 칸, 가로 칸의 크기
* - char[][] : 보드의 형태를 저장하기 위한 2차원 배열
* - int[] : 좌표상에서 상, 하, 좌, 우로 이동하기 위한 1차원 배열
* - bool[] : 방문 여부를 확인하기 위한 1차원 배열
*/

#include <iostream>
#include <string.h>

using namespace std;

#define endl '\n'
#define MAX 20

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int r, c;
int ans = 0;
char board[MAX][MAX];
bool visited[MAX];

void input()
{
	cin >> r >> c;
	for (int i = 0; i < r; ++i)
	{
		string str;
		cin >> str;

		for (int j = 0; j < c; ++j)
			board[i][j] = str[j];
	}
}

void DFS(int y, int x, int cnt)
{
	visited[board[y][x] - 'A'] = true;
	
	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;

		if (!visited[board[ny][nx] - 'A'])
		{
			DFS(ny, nx, cnt + 1);
			visited[board[ny][nx] - 'A'] = false;
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
	DFS(0, 0, 1);

	cout << ans << endl;

	return 0;
}