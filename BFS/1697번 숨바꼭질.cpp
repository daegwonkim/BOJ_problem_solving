/*
* 1. 아이디어
* - 가장 빠른 시간을 구해야 하므로 BFS를 수행
* - BFS를 수행하면서 동생의 위치에 도달했을 때 Count 값을 출력하고 프로그램 종료
* 
* 2. 시간 복잡도
* - V = N(0 ~ 100,000)
* - E = 3V
* - O(V + E) = O(V + 3V) = O(4V) = O(400,000) < 2억
* 
* 3. 사용 변수
* - int : 수빈이와 동생의 위치
* - int[] : 현재 위치에서 { +1, -1, *2 }의 위치로 이동하기 위한 1차원 배열
* - bool[] : 방문 여부를 확인하기 위한 1차원 배열
* - queue : BFS를 수행하기 위함
*/

#include <iostream>
#include <queue>

using namespace std;

#define endl '\n'
#define MAX 100000

int dp[] = { 1, -1, 2 };

int n, k;
bool check[MAX + 1];
queue<pair<int, int>> que;

void input()
{
	cin >> n >> k;
}

void BFS()
{
	que.push({n, 0});

	while (!que.empty())
	{
		int point = que.front().first;
		int count = que.front().second;
		que.pop();

		if (point == k)
		{
			cout << count << endl;
			return;
		}

		for (int i = 0; i < 3; ++i)
		{
			int nPoint;

			if (i == 2)
				nPoint = point * dp[i];
			else
				nPoint = point + dp[i];

			if (nPoint < 0 || nPoint > MAX) continue;
			if (!check[nPoint])
			{
				check[nPoint] = true;
				que.push({ nPoint, count + 1 });
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
	BFS();

	return 0;
}