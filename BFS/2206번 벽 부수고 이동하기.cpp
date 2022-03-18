#include<iostream>
#include<queue>

#define MAX 1001

using namespace std;

int dy[] = { 1, -1, 0, 0 };
int dx[] = { 0, 0, 1, -1 };

int n, m;
int map[MAX][MAX];
int visited[MAX][MAX][2];
queue<pair<pair<int, int>, int>> que;

void input()
{
	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		string str;
		cin >> str;

		for (int j = 1; j <= m; ++j)
			map[i][j] = str[j - 1] - '0';
	}
}

int BFS()
{
	que.push({ {1, 1}, 1 });
	visited[1][1][1] = 1;

	while (!que.empty()) {
		int y = que.front().first.first;
		int x = que.front().first.second;
		int block = que.front().second;
		que.pop();

		if (y == n && x == m)
			return visited[y][x][block];

		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 1 || ny > n || nx < 1 || nx > m) continue;

			if (map[ny][nx] == 1 && block) {
				visited[ny][nx][block - 1] = visited[y][x][block] + 1;
				que.push({ {ny, nx}, block - 1 });
			}

			if (map[ny][nx] == 0 && visited[ny][nx][block] == 0) {
				visited[ny][nx][block] = visited[y][x][block] + 1;
				que.push({ {ny, nx}, block});
			}
		}
	}

	return -1;
}

void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main()
{
	init();
	input();
	
	cout << BFS();

	return 0;
}