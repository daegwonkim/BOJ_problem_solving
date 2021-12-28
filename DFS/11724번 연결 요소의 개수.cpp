/*
* 1. 아이디어
* - 2차원 배열에 대한 DFS를 수행하여 그래프 탐색
* - 연결되어 있는 정점은 1로 그렇지 않은 정점은 0으로 판별
* - 방문하지 않은 정점에 대해 탐색을 해가며 새로운 연결 요소를 탐색할 때마다 Count 값을 증가시킴
* 
* 2. 시간 복잡도
* - V = N(1 ~ 1,000)
* - E = M(0 ~ 499,500)
* - O(V + E) = O(1,000 + 499,500) = O(500,500) < 2억
* 
* 3. 사용 변수
* - int : 정점의 개수, 간선의 개수, 간선의 양 끝점
* - int[][] : 그래프의 형태를 저장하기 위한 2차원 배열
* - bool[] : 방문 여부를 확인하기 위한 1차원 배열
*/

#include <iostream>

using namespace std;

#define endl '\n'
#define MAX 1001

int n, m;
int cnt = 0;
int graph[MAX][MAX];
bool visited[MAX];

void input()
{
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;

		graph[u][v] = 1;
		graph[v][u] = 1;
	}
}

void DFS(int node)
{
	visited[node] = true;

	for (int i = 1; i <= n; ++i)
	{
		if (graph[node][i] == 1 && !visited[i])
			DFS(i);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();
	
	for (int i = 1; i <= n; ++i)
	{
		if (!visited[i])
		{
			DFS(i);
			++cnt;
		}
	}

	cout << cnt << endl;

	return 0;
}