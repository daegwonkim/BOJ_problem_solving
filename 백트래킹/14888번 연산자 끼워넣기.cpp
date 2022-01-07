/*
* 1. 아이디어
* - 백트래킹 사용(재귀)
* - 연산자의 개수를 배열에 저장한 뒤, 이를 사용하여 백트래킹 수행
* - 연산자의 종류에 따라 인자값을 전달
* - 수열의 개수가 충족된 경우 결과값을 현재의 최댓값, 최솟값과 비교하여 필요시 갱신시킴
* 
* 2. 시간 복잡도
* - 중복 불가능하므로 N!
* 
* 3. 사용 변수
* - int : 수의 개수, 수열의 수, 연산자의 개수
* - int[] : 수열의 저장하기 위한 1차원 배열, 연산자의 개수를 저장하기 위한 1차원 배열
*/

#include <iostream>

using namespace std;

#define endl '\n'
#define MAX 11

int n;
int ansMax = -987654321, ansMin = 987654321;
int arr[MAX];
int opt[4];

void input()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	
	for (int i = 0; i < 4; ++i)
		cin >> opt[i];
}

void BT(int result, int cnt)
{
	if (cnt == n)
	{
		ansMax = max(result, ansMax);
		ansMin = min(result, ansMin);

		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		if (opt[i] != 0)
		{
			--opt[i];

			switch (i)
			{
			case 0: BT(result + arr[cnt], cnt + 1);
				break;
			case 1: BT(result - arr[cnt], cnt + 1);
				break;
			case 2: BT(result * arr[cnt], cnt + 1);
				break;
			case 3: BT(result / arr[cnt], cnt + 1);
				break;
			}

			++opt[i];
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();
	BT(arr[0], 1);

	cout << ansMax << endl;
	cout << ansMin << endl;

	return 0;
}