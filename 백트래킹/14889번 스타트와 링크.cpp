/*
* 1. 아이디어
* - 백트래킹 사용
* - 방문 여부를 확인하는 1차원 배열을 사용하여 스타트 팀과 링크 팀을 구분
* - 이후 팀원의 수가 충족되었을 때 방문 여부에 따라 능력치의 합을 계산하여 필요시 출력값을 갱신
* 
* 2. 시간 복잡도
* - 중복 불가능하므로 N!
* - 인자 값으로 Start 값을 주지 않고 반복문을 수행시키면 시간 초과가 발생하였음
* 
* 3. 사용 변수
* - int : 배열의 크기 N
* - int[][] : 선수들의 능력치를 저장하기 위한 2차원 배열
* - bool[] : 방문 여부를 확인하기 위한 1차원 배열
*/

#include <iostream>
#include <math.h>

using namespace std;

#define endl '\n'
#define MAX 20

int n;
int ans = 987654321;
int stats[MAX][MAX];
bool visited[MAX];

void input()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> stats[i][j];
}

void BT(int start, int cnt)
{
	if (cnt == n / 2)
	{
		int start = 0, link = 0;

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (visited[i] && visited[j])
					start += stats[i][j];
				else if(!visited[i] && !visited[j])
					link += stats[i][j];
			}
		}

		ans = min(ans, abs(start - link));

		return;
	}

	for (int i = start; i < n; ++i)
	{
		visited[i] = true;
		BT(i + 1, cnt + 1);
		visited[i] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();
	BT(0, 0);

	cout << ans << endl;

	return 0;
}