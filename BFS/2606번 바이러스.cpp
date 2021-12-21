/*
* 1. 아이디어
* - BFS를 수행하여 그래프 탐색
* - Queue에 값이 Push 될 때마다 Count를 증가시킴
*
* 2. 시간 복잡도
* - V <= 100
* - E <= 99
* - O(100 + 99) = O(199) < 2억
* 
* 3. 사용 변수
* - int : 컴퓨터의 수, 연결되어 있는 컴퓨터 쌍의 수를 저장하기 위함
* - bool[] : 방문 여부를 확인하기 위한 1차원 배열
* - int[][] : 그래프 형태를 저장하기 위한 2차원 배열
* - queue : BFS를 수행하기 위함
*/

#include <iostream>
#include <queue>

using namespace std;

#define endl '\n'
#define MAX 101

int v, e;
bool check[MAX];
int graph[MAX][MAX];
queue<int> que;

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

void BFS(int node)
{
	int cnt = 0;

	que.push(node);
	check[node] = true;

	while (!que.empty())
	{
		int cpt = que.front();
		que.pop();

		for (int i = 1; i <= v; ++i)
		{
			if (graph[cpt][i] && !check[i])
			{
				check[i] = true;
				que.push(i);
				++cnt;
			}
		}
	}

	cout << cnt << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();
	BFS(1);

	return 0;
}