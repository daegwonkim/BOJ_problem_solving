/*
* 1. 아이디어
* - DFS를 수행하여 그래프 탐색
* - 1번 컴퓨터부터 탐색을 시작하여 새로운 구역을 탐색할 때마다 Count 값을 증가시킴
* 
* 2. 시간 복잡도
* - V <= 100
* - E <= 99 * 100
* - O(V + E) = O(100 + 9,900) = O(10,000) < 2억
* 
* 3. 사용 변수
* - int : 컴퓨터의 수, 컴퓨터 쌍의 수
* - int[][] : 그래프의 형태를 저장하기 위한 2차원 배열
* - bool[] : 방문 여부를 확인하기 위한 1차원 배열
*/

#include <iostream>

using namespace std;

#define endl '\n'
#define MAX 101

int v, e;
int cnt = 0;
int graph[MAX][MAX];
bool visited[MAX];

void input()
{
	cin >> v >> e;
	for (int i = 0; i < e; ++i)
	{
		int a, b;
		cin >> a >> b;

		graph[a][b] = 1;
		graph[b][a] = 1;
	}
}

void DFS(int node)
{
	visited[node] = true;

	for (int i = 1; i <= v; ++i)
	{
		if (graph[node][i] == 1 && !visited[i])
		{
			++cnt;
			DFS(i);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();
	DFS(1);

	cout << cnt << endl;

	return 0;
}