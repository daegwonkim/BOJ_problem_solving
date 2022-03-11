#include <iostream>

using namespace std;

#define endl '\n'
#define MAX 50

int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

int n, m, cnt = 0;
int y, x, d;
int map[MAX][MAX];

void input()
{
	cin >> n >> m;
	cin >> y >> x >> d;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> map[i][j];
}

void cleaning()
{
	while (1)
	{
		bool check = false;

		if (map[y][x] == 0)
		{
			map[y][x] = 2;
			++cnt;
		}

		for (int i = 0; i < 4; ++i)
		{
			d = (d + 3) % 4;
			int ny = y + dy[d];
			int nx = x + dx[d];

			if (map[ny][nx] == 0)
			{
				y = ny; x = nx;
				check = true;
				break;
			}
		}

		if (!check)
		{
			int dir = (d + 2) % 4;
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (map[ny][nx] == 1)
				break;
			else
				y = ny; x = nx;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();
	cleaning();

	cout << cnt << endl;

	return 0;
}