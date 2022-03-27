#include<iostream>

#define INF 987654321
#define MAX 401

using namespace std;

int v, e, ans = INF;
int dist[MAX][MAX];

void input()
{
	cin >> v >> e;

	for (int i = 1; i <= v; ++i)
		for (int j = 1; j <= v; ++j)
			dist[i][j] = INF;

	for (int i = 0; i < e; ++i) {
		int a, b, c;
		cin >> a >> b >> c;

		dist[a][b] = c;
	}
}
void solve()
{
	for (int i = 1; i <= v; ++i)
		for (int j = 1; j <= v; ++j)
			for (int k = 1; k <= v; ++k)
				if (dist[j][k] > dist[j][i] + dist[i][k])
					dist[j][k] = dist[j][i] + dist[i][k];

	for (int i = 1; i <= v; ++i)
		ans = min(ans, dist[i][i]);

	if (ans == INF) cout << -1;
	else cout << ans;
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