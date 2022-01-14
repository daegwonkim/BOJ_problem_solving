/*
* 1. 아이디어
* - 백트래킹 수행
* 
* 2. 시간 복잡도
* - 중복 불가능이므로 N!
* 
* 3. 사용 변수
* - int : 순열의 크기
* - int[] : 결과값을 저장하기 위한 1차원 배열
* - bool[] : 방문 여부를 확인하기 위한 1차원 배열
*/

#include <iostream>

using namespace std;

#define endl '\n'
#define MAX 8

int n;
int result[MAX + 1];
bool visited[MAX + 1];

void input()
{
	cin >> n;
}

void BT(int cnt)
{
	if (cnt == n)
	{
		for (int i = 0; i < n; ++i)
			cout << result[i] << ' ';
		cout << endl;

		return;
	}

	for (int i = 1; i <= n; ++i)
	{
		if (!visited[i])
		{
			visited[i] = true;
			result[cnt] = i;
			BT(cnt + 1);
			visited[i] = false;
		}
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