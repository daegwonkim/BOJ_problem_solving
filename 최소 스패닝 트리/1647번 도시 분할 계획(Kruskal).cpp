#include<iostream>
#include<vector>
#include<algorithm>

#define MAX 100001

using namespace std;

int n, m, ans = 0;
int parent[MAX];
vector<pair<int, pair<int, int>>> edges;

void input()
{
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;

		edges.push_back({ c, {a, b} });
	}

	sort(edges.begin(), edges.end());
}

int getParent(int node)
{
	if (node == parent[node])
		return node;

	return parent[node] = getParent(parent[node]);
}

void unionParent(int a, int b)
{
	a = getParent(a);
	b = getParent(b);

	if (a != b)
		parent[a] = b;
}

bool findParent(int a, int b)
{
	a = getParent(a);
	b = getParent(b);

	if (a == b) return true;
	return false;
}

void solve()
{
	int max_cost = 0;

	for (int i = 1; i <= n; ++i)
		parent[i] = i;

	for (int i = 0; i < edges.size(); ++i) {
		int a = edges[i].second.first;
		int b = edges[i].second.second;
		int cost = edges[i].first;

		if (!findParent(a, b)) {
			ans += cost;
			max_cost = max(max_cost, cost);
			unionParent(a, b);
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