/*
* 1. 아이디어
* - 백트래킹 수행
* - 백트래킹을 수행하면서 정수 S와 비교하여 크기가 같다면 Count(결과값)를 증가시킴
* 
* 2. 시간 복잡도
* - 중복 불가능하므로 N!
* 
* 3. 사용 변수
* - int : 정수의 개수 N, 기준 값 S
* - int[] : 수열을 저장하기 위한 1차원 배열
*/

#include <iostream>

using namespace std;

#define endl '\n'
#define MAX 20

int n, s;
int ans = 0;
int arr[MAX];

void input()
{
	cin >> n >> s;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
}

void BT(int start, int sum)
{
	if (sum == s && start != 0)
		++ans;

	for (int i = start; i < n; ++i)
		BT(i + 1, sum + arr[i]);
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