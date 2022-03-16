#include<iostream>

#define MAX 501
#define INF 987654321

using namespace std;

int n, m, ans = 0;
int graph[MAX][MAX];

void input()
{
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			graph[i][j] = INF;

	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;

		graph[a][b] = 1;
	}
}

void solve()
{
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			for (int k = 1; k <= n; ++k)
				graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);

	for (int i = 1; i <= n; ++i) {
		int cnt = 0;

		for (int j = 1; j <= n; ++j)
			if (graph[i][j] != INF || graph[j][i] != INF)
				++cnt;

		if (cnt == n - 1) ++ans;
	}

	cout << ans;
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
	solve();

	return 0;
}