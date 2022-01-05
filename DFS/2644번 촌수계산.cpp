/*
* 1. 아이디어
* - DFS를 수행하여 그래프 탐색
* - 자식 노드에 대한 DFS를 수행하며 촌수를 늘려가며 계산
* 
* 2. 시간 복잡도
* - V = n(1 ~ 100)
* - E = n - 1
* - O(V + E) = O(2n - 1) = O(9,999) < 2억
* 
* 3. 사용 변수
* - int : 전체 사람의 수, 촌수를 계산해야 하는 서로 다른 두 사람의 번호, 부모 자식 간의 관계의 수
* - vector : 부모 자식 간의 관계를 저장하기 위함
* - bool[] : 방문 여부를 확인하기 위한 1차원 배열
*/

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

#define endl '\n'
#define MAX 101

int n, m, a, b, ans;
vector<int> vec[MAX];
bool visited[MAX];

void input()
{
	cin >> n >> a >> b >> m;
	for (int i = 0; i < m; ++i)
	{
		int x, y;
		cin >> x >> y;

		vec[x].push_back(y);
		vec[y].push_back(x);
	}
}

void DFS(int node, int cnt)
{
	if (node == b)
	{
		ans = cnt;
		return;
	}

	visited[node] = true;

	for (int i = 0; i < vec[node].size(); ++i)
	{
		if (!visited[vec[node][i]])
			DFS(vec[node][i], cnt + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();
	DFS(a, 0);

	if (ans != 0)
		cout << ans << endl;
	else
		cout << -1 << endl;

	return 0;
}