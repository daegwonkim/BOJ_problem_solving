#include<iostream>
#include<vector>
#include<algorithm>

#define MAX 10001

using namespace std;

int v, e, ans = 0;
int parent[MAX];
vector<pair<int, pair<int, int>>> vec;

void input()
{
	cin >> v >> e;

	for (int i = 1; i <= v; ++i)
		parent[i] = i;	// 부모를 확인하기 위한 배열 초기화

	for (int i = 0; i < e; ++i) {
		int a, b, c;
		cin >> a >> b >> c;

		vec.push_back({ c, { a, b } });
	}

	// Kruskal 알고리즘을 사용하기 위해 간선의 비용에 따라 오름차순 정렬
	sort(vec.begin(), vec.end());
}

// 노드의 부모를 찾기 위한 함수
int find_parent(int x)
{
	if (parent[x] == x) return x;
	return parent[x] = find_parent(parent[x]);
}

void union_parent(int x, int y)
{
	int parent_x = find_parent(x);
	int parent_y = find_parent(y);

	if (parent_x != parent_y)
		parent[parent_y] = parent_x;
}

// 두 노드의 부모를 확인하기 위한 함수
bool check_parent(int x, int y)
{
	int parent_x = find_parent(x);
	int parent_y = find_parent(y);

	if (parent_x == parent_y) return true;
	return false;
}

void kruskal()
{
	for (int i = 0; i < e; ++i) {
		int node_A = vec[i].second.first;
		int node_B = vec[i].second.second;

		if (!check_parent(node_A, node_B)) {
			union_parent(node_A, node_B);
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