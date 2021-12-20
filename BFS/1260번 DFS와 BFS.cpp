/*
* 1. 아이디어
* - DFS와 BFS 함수를 각각 구현한 뒤 수행한 다음 결과 출력
* 
* 2. 시간복잡도
* - V = N(1 ~ 1,000)
* - E = M(1 ~ 10,000)
* - O(V + E) = O(1,000 + 10,000) = O(11,000) < 2억
* 
* 3. 사용 변수
* - int : 정점의 개수, 간선의 개수, 탐색을 시작할 정점의 번호 저장.
* - queue : BFS를 수행하기 위함.
* - int[][] : 연결 여부를 확인하기 위한 2차원 배열.
* - bool[] : 방문 여부를 확인하기 위한 1차원 배열.
*/

#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

#define endl '\n'
#define MAX 1001

int n, m, v;
int graph[MAX][MAX];
bool check[MAX] = { 0, };
queue<int> que;

void input()
{
	cin >> n >> m >> v;
	for (int i = 1; i <= m; ++i)
	{
		int a, b;
		cin >> a >> b;

		graph[a][b] = 1;
		graph[b][a] = 1;
	}
}

void DFS(int node)
{
	cout << node << ' ';
	check[node] = true;

	for (int i = 1; i <= n; ++i)
	{
		if (graph[node][i] && !check[i])
		{
			DFS(i);
		}
	}
}

void BFS()
{
	que.push(v);
	check[v] = true;

	while (!que.empty())
	{
		int node = que.front();
		cout << node << ' ';
		que.pop();

		for (int i = 1; i <= n; ++i)
		{
			if (graph[node][i] && !check[i])
			{
				check[i] = true;
				que.push(i);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();

	DFS(v);

	cout << endl;
	memset(check, 0, n + 1);

	BFS();

	return 0;
}