#include<iostream>
#include<queue>
#include<vector>

#define MAX 10001
#define P pair<int, int>

using namespace std;

int v, e, ans = 0;
bool visited[MAX];
vector<P> edge[MAX];
priority_queue<P, vector<P>, greater<P>> pq;

void input()
{
	cin >> v >> e;

	for (int i = 0; i < e; ++i) {
		int a, b, c;
		cin >> a >> b >> c;

		edge[a].push_back({ c, b });
		edge[b].push_back({ c, a });
	}
}

void prim()
{
	pq.push({ 0, 1 });

	while (!pq.empty()) {
		int cost = pq.top().first;
		int node = pq.top().second;
		pq.pop();

		if (!visited[node]) {
			visited[node] = true;
			ans += cost;

			for (int i = 0; i < edge[node].size(); ++i)
				if (!visited[edge[node][i].second])
					pq.push(edge[node][i]);
		}
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
	prim();

	return 0;
}