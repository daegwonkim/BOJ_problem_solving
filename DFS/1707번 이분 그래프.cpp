/*
* 1. 아이디어
* - DFS를 수행하여 그래프 탐색
* - 번호를 통해 구별하여 서로 인접한 노드의 번호가 일치할 경우 이분 그래프가 아님을 판별
* 
* 2. 시간 복잡도
* - V = V(1 ~ 20,000)
* - E = E(1 ~ 200,000)
* - K = K(2 ~ 5)
* - O(K * (V + E)) = O(5 * 220,000) = O(1,100,000)
* 
* 3. 사용 변수
* - int : 테스트 케이스의 개수, 정점의 개수, 간선의 개수
* - vector : 그래프의 형태를 저장하기 위한 벡터
* - int[] : 이분 그래프 판별을 위한 1차원 배열
*/

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

#define endl '\n'
#define MAX 20001

int k, v, e;
vector<int> vec[MAX];
int check[MAX];

void input()
{
	cin >> v >> e;
	for (int i = 0; i < e; ++i)
	{
		int u, v;
		cin >> u >> v;

		vec[u].push_back(v);
		vec[v].push_back(u);
	}
}

void DFS(int node, int num)
{	
	check[node] = num;

	for (int i = 0; i < vec[node].size(); ++i)
	{
		int nextNode = vec[node][i];

		if (!check[nextNode])
		{
			if (num == 1)
				DFS(nextNode, 2);
			else
				DFS(nextNode, 1);
		}
	}
}

bool isBigraph()
{
	for (int i = 1; i <= v; ++i)
	{
		for (int j = 0; j < vec[i].size(); ++j)
		{
			int nextNode = vec[i][j];

			if (check[i] == check[nextNode])
				return false;
		}
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> k;
	while (k--)
	{
		input();
		
		for (int i = 1; i <= v; ++i)
		{
			if (!check[i])
				DFS(i, 1);
		}

		if (isBigraph())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

		memset(check, 0, sizeof(check));
		for (int i = 1; i <= v; ++i)
			vec[i].clear();
	}

	return 0;
}