/*
* 1. 아이디어
* - 배열의 1행 1열부터 DFS를 수행
* - DFS는 다음 칸의 높이가 현재 칸의 높이보다 작을 경우에만 수행
* - 위와 같은 과정을 수행했을 때 배열의 (마지막 행, 마지막 열) 좌표에 도달하는 경우의 수를 세어 출력
* - 단순 DFS 방식을 사용하면 시간 초과가 발생하기 때문에 DP 방식을 함께 활용
* 
* 2. 시간 복잡도
* - V = M * N(1 ~ 500)
* - E = 4V
* - O(V + E) = O(V + 4V) = O(5V) = O(1,250,000) = X
* 
* 3. 사용 변수
* - int : 지도의 세로 크기, 가로 크기
* - int[][] : 지도의 형태를 저장하기 위한 2차원 배열, 이전 좌표의 값을 저장하기 위한 2차원 배열
* - int[] : 좌표상에서 상, 하, 좌, 우로 이동하기 위한 1차원 배열
* - bool[][] : 방문 여부를 확인하기 위한 2차원 배열
*/

#include <iostream>

using namespace std;

#define endl '\n'
#define MAX 500

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int m, n;
int map[MAX][MAX];
int DP[MAX][MAX];
bool visited[MAX][MAX];

void input()
{
	cin >> m >> n;
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			cin >> map[i][j];
}

int DFS(int y, int x)
{
	if ((y == (m - 1)) && (x == (n - 1))) return 1;
	if (visited[y][x]) return DP[y][x];

	visited[y][x] = true;

	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= m || nx >= n) continue;

		if (map[ny][nx] < map[y][x])
			DP[y][x] += DFS(ny, nx);
	}

	return DP[y][x];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();

	cout << DFS(0, 0) << endl;

	return 0;
}