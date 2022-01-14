/*
* 1. 아이디어
* - 백트래킹(재귀)을 수행하면서 배열의 순서를 바꿔가며 최댓값을 구함
* 
* 2. 시간 복잡도
* - 중복 불가능이므로 N!
* 
* 3. 사용 변수
* - int : 배열의 크기
* - int[] : 배열에 들어있는 정수를 저장하기 위한 1차원 배열, 순서가 바뀐 배열을 저장하기 위한 1차원 배열
* - bool[] : 방문 여부를 확인하기 위한 1차원 배열
*/

#include <iostream>
#include <math.h>

using namespace std;

#define endl '\n'
#define MAX 8

int n, ans = 0;
int arr[MAX], result[MAX];
bool visited[MAX];

void input()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
}

void BT(int cnt)
{
	if (cnt == n)
	{
		int sum = 0;

		for (int i = 0; i < n - 1; ++i)
			sum += abs(result[i] - result[i + 1]);

		ans = max(ans, sum);
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		if (!visited[i])
		{
			visited[i] = true;
			result[cnt] = arr[i];
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

	cout << ans << endl;

	return 0;
}