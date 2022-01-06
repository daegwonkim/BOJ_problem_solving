/*
* 1. 아이디어
* - 백트래킹 사용(재귀)
* - 중복 없이 골라야하므로 방문 여부 체크 필요
* - 인자로 Count 값을 받아 증가시키면서, 원하는 길이(M)가 되었을 때 출력
* 
* 2. 시간 복잡도
* - 중복 불가능이므로 N!
* - N = 1 ~ 8
* 
* 3. 사용 변수
* - int : 자연수 N과 M
* - int[] : 결과 값을 저장하고 출력하기 위한 1차원 배열
* - bool[] : 방문 여부를 확인하기 위한 1차원 배열
*/

#include <iostream>

using namespace std;

#define endl '\n'
#define MAX 9

int n, m;
int result[MAX];
bool visited[MAX];

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