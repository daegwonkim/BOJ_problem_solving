/*
* 1. 아이디어
* - 각 테스트 케이스마다 백트래킹을 수행
* 
* 2. 시간 복잡도
* - 중복 불가능이므로 N!
* 
* 3. 사용 변수
* - int : 집합 S에 포함되는 수의 개수
* - int[] : 집합 S를 저장하기 위한 1차원 배열, 결과값을 저장하기 위한 1차원 배열
*/

#include <iostream>

using namespace std;

#define endl '\n'
#define MAX 12

int k;
int arr[MAX];
int result[6];

void input()
{
	cin >> k;
	for (int i = 0; i < k; ++i)
		cin >> arr[i];
}

void BT(int start, int cnt)
{
	if (cnt == 6)
	{
		for (int i = 0; i < 6; ++i)
			cout << result[i] << ' ';
		cout << endl;

		return;
	}

	for (int i = start; i < k; ++i)
	{
		result[cnt] = arr[i];
		BT(i + 1, cnt + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (1)
	{
		input();

		if (k == 0) break;

		BT(0, 0);
		cout << endl;
	}

	return 0;
}