/*
* 1. 아이디어
* - 루트 노드부터 DFS를 수행하여 부모 노드를 구함
* 
* 2. 시간 복잡도
* - V = N(2 ~ 100,000)
* - E = N - 1
* - O(V + E) = O(2N - 1) = O(200,000 - 1) = O(199,999) < 2억
* 
* 3. 사용 변수
* - int : 노드의 개수
* - vector : 트리의 형태를 저장하기 위한 벡터
* - bool[] : 방문 여부를 확인하기 위한 1차원 배열
* - int[] : 부모 노드를 저장하기 위한 1차원 배열
*/

#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'
#define MAX 100001

int n;
vector<int> tree[MAX];
int result[MAX];
bool visited[MAX];

void input()
{
	cin >> n;
	for (int i = 0; i < n - 1; ++i)
	{
		int a, b;
		cin >> a >> b;

		tree[a].push_back(b);
		tree[b].push_back(a);
	}
}

void DFS(int parent)
{
	visited[parent] = true;

	for (int i = 0; i < tree[parent].size(); ++i)
	{
		int child = tree[parent][i];

		if (!visited[child])
		{
			result[child] = parent;
			DFS(child);
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

	for (int i = 2; i <= n; ++i)
		cout << result[i] << endl;

	return 0;
}