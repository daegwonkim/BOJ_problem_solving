#include<iostream>
#include<vector>
#include<algorithm>

#define MAX 1001

using namespace std;

int n, m, ans = 0;
int parent[MAX];
vector<pair<int, pair<int, int>>> vec;

void input()
{
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		parent[i] = i;

	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;

		vec.push_back({ c, {a, b} });
	}

	sort(vec.begin(), vec.end());
}

int find_parent(int x)
{
	if (parent[x] == x) return x;
	return parent[x] = find_parent(parent[x]);
}

void union_node(int x, int y)
{
	int parent_x = find_parent(x);
	int parent_y = find_parent(y);

	if (parent_x != parent_y)
		parent[parent_y] = parent_x;
}

bool check_parent(int x, int y)
{
	int parent_x = find_parent(x);
	int parent_y = find_parent(y);

	if (parent_x == parent_y) return true;
	return false;
}

void kruskal()
{
	for (int i = 0; i < vec.size(); ++i) {
		int node_A = vec[i].second.first;
		int node_B = vec[i].second.second;

		if (!check_parent(node_A, node_B)) {
			union_node(node_A, node_B);
			ans += vec[i].first;
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
	kruskal();

	return 0;
}