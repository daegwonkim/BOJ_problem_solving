/*
* 1. 아이디어
* - 백트래킹 사용(재귀)
* - 중복 없이 골라야하므로 방문 여부 체크
* - 고른 수열이 오름 차순이어야 하므로 Start 인자값을 추가하여 반복문의 시작점을 조절
* - 원하는 길이가 되었을 때 결과값을 출력
* 
* 2. 시간 복잡도
* - 중복 불가이므로 N!
* - N =  1 ~ 8
* 
* 3. 사용 변수
* - int : 자연수 N과 M
* - int[] : 결과값을 저장하기 위한 1차원 배열
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
		if (!visited[i])
		{
			visited[i] = true;
			result[cnt] = i;
			BT(i + 1, cnt + 1);
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
	BT(1, 0);

	return 0;
}