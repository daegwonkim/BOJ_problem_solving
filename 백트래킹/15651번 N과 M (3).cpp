/*
* 1. 아이디어
* - 백트래킹 사용(재귀)
* 
* 2. 시간 복잡도
* - 중복이 허용되기 때문에 N^2
* 
* 3. 사용 변수
* - int : 자연수 N과 M
*/

#include <iostream>

using namespace std;

#define endl '\n'
#define MAX 7

int n, m;
int result[MAX];

void input()
{
	cin >> n >> m;
}

void BT(int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; ++i)
			cout << result[i] << ' ';
		cout << endl;

		return;
	}

	for (int i = 1; i <= n; ++i)
	{
		result[cnt] = i;
		BT(cnt + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();
	BT(0);

	return 0;
}