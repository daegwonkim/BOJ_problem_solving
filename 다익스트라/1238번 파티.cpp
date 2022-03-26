#include<iostream>
#include<vector>
#include<queue>

#define MAX 1001
#define INF 987654321
#define P pair<int, int>

using namespace std;

int n, m, x, ans = 0;
int temp[MAX], result[MAX];
vector<P> vec[MAX];
priority_queue<P, vector<P>, greater<P>> pque;

void input()
{
	cin >> n >> m >> x;

	for (int i = 0; i < m; ++i) {
		int from, to, time;
		cin >> from >> to >> time;

		vec[from].push_back({ to, time });
	}
}

void Dijkstra(int start)
{
	temp[start] = 0;
	pque.push({ 0, start });

	while (!pque.empty()) {
		int time = pque.top().first;
		int node = pque.top().second;
		pque.pop();

		for (int i = 0; i < vec[node].size(); ++i) {
			int next_node = vec[node][i].first;
			int next_time = vec[node][i].second;

			if (temp[next_node] > next_time + time) {
				temp[next_node] = next_time + time;
				pque.push({ temp[next_node], next_node });
			}
		}
	}
}

void solve()
{
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j)
			temp[j] = INF;
		Dijkstra(i);
		result[i] = temp[x];
	}

	for (int i = 1; i <= n; ++i)
		temp[i] = INF;
	Dijkstra(x);

	for (int i = 1; i <= n; ++i) {
		result[i] += temp[i];
		ans = max(ans, result[i]);
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