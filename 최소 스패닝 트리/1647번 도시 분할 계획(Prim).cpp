#include<iostream>
#include<vector>
#include<queue>

#define MAX 100001
#define P pair<int, int>

using namespace std;

int n, m, ans = 0;
vector<P> edges[MAX];
priority_queue<P, vector<P>, greater<P>> pque;
bool visited[MAX];

void input()
{
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;

		edges[a].push_back({ c, b });
		edges[b].push_back({ c, a });
	}
}

void solve()
{
	int max_cost = 0;

	pque.push({ 0, 1 });

	while (!pque.empty()) {
		int cost = pque.top().first;
		int house = pque.top().second;
		pque.pop();

		if (!visited[house]) {
			visited[house] = true;
			ans += cost;
			max_cost = max(max_cost, cost);

			for (int i = 0; i < edges[house].size(); ++i) {
				int max_cost = edges[house][i].first;
				int next_house = edges[house][i].second;

				if (!visited[next_house])
					pque.push({ max_cost, next_house });
			}
		}
	}

	cout << ans - max_cost;
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