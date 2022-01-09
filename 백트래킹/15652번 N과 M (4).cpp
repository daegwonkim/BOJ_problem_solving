/*
* 1. 아이디어
* - 백트래킹 사용
*
* 2. 시간 복잡도
* - 중복 허용이므로 N^2
* 
* 3. 사용 변수
* - int : 자연수 N과 M
* - int[] : 결과값을 저장하기 위한 1차원 배열
*/

#include <iostream>

using namespace std;

#define endl '\n'
#define MAX 8

int n, m;
int result[MAX];

void input()
{
	cin >> n >> m;
}

void BT(int start, int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; ++i)
			cout << result[i] << ' ';
		cout << endl;

		return;
	}

	for (int i = start; i <= n; ++i)
	{
		result[cnt] = i;
		BT(i, cnt + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();
	BT(1, 0);

	return 0;
}