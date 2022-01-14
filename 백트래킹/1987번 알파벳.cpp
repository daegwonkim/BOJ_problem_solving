/*
* 1. 아이디어
* - 백트래킹 수행
* - 방문 여부를 확인하며 재귀를 수행하여 Count 값을 증가시킴
* - 필요시 결과값을 갱신시켜 나가며 최종적으로 출력할 결과값을 구함
* 
* 2. 시간 복잡도
* - 중복 불가능이므로 N!
* 
* 3. 사용 변수
* - int : 보드의 세로와 가로 크기
* - char[][] : 보드의 형태를 저장하기 위한 2차원 배열
* - bool[] : 방문 여부를 확인하기 위한 1차원 배열
* - int[] : 좌표상에서 상, 하, 좌, 우로 이동하기 위한 1차원 배열
*/

#include <iostream>

using namespace std;

#define endl '\n'
#define MAX 20

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int r, c;
int ans = 0;
char board[MAX][MAX];
bool visited[26];

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

void BT(int y, int x, int cnt)
{
	visited[board[y][x] - 'A'] = true;

	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;

		if (!visited[board[ny][nx] - 'A'])
		{
			BT(ny, nx, cnt + 1);
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
	BT(0, 0, 1);

	cout << ans << endl;

	return 0;
}