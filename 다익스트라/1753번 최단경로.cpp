#include<iostream>
#include<vector>
#include<queue>

#define MAX 20001
#define INF 987654321
#define P pair<int, int>

using namespace std;

int v, e, k;
int dist[MAX];	// 총 간선의 비용을 저장하기 위한 인접 리스트
vector<P> vec[MAX];
priority_queue<P, vector<P>, greater<P>> pq;

void input()
{
	cin >> v >> e >> k;

	for (int i = 0; i < e; ++i) {
		int a, b, c;
		cin >> a >> b >> c;

		vec[a].push_back({ c, b });
	}
}

void solve()
{
	for (int i = 1; i <= v; ++i)
		dist[i] = INF;	// 인접 리스트 초기화

	dist[k] = 0;	// 시작 노드의 비용 = 0
	pq.push({ 0, k });

	while (!pq.empty()) {
		int cost = pq.top().first;
		int node = pq.top().second;
		pq.pop();

		for (int i = 0; i < vec[node].size(); ++i) {
			int next_cost = vec[node][i].first;
			int next_node = vec[node][i].second;

			if (dist[next_node] > (cost + next_cost)) {
				dist[next_node] = cost + next_cost;
				pq.push({ dist[next_node], next_node });
			}
		}
	}

	for (int i = 1; i <= v; ++i) {
		if (dist[i] == INF) cout << "INF" << '\n';
		else cout << dist[i] << '\n';
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