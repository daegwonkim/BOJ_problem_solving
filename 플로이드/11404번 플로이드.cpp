#include<iostream>

#define MAX 101
#define INF 987654321

using namespace std;

int n, m;
int dist[MAX][MAX];

void input()
{
	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == j) dist[i][j] = 0;
			else dist[i][j] = INF;
		}
	}
		
			

	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;

		dist[a][b] = min(dist[a][b], c);
	}
}

void solve()
{
	for (int i = 1; i <= n; ++i)			// 거치는 노드
		for (int j = 1; j <= n; ++j)		// 시작 노드
			for (int k = 1; k <= n; ++k)	// 도착 노드
				dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (dist[i][j] == INF) cout << 0 << ' ';
			else cout << dist[i][j] << ' ';
		}
		cout << '\n';
	}		
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