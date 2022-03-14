#include<iostream>
#include<vector>
#include<queue>

#define MAX 1001
#define P pair<int, int>

using namespace std;

int n, m, ans = 0;
bool visited[MAX];
vector<P> vec[MAX];
priority_queue<P, vector<P>, greater<P>> pq;

void input()
{
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;

		vec[a].push_back({ c, b });
		vec[b].push_back({ c, a });
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

			for (int i = 0; i < vec[node].size(); ++i)
				if (!visited[vec[node][i].second])
					pq.push(vec[node][i]);
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