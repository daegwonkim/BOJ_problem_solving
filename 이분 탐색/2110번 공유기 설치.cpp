/*
* 단순 반복문을 통해 풀이할 경우 시간 초과가 발생
* 시간 복잡도를 줄이기 위해 이분 탐색을 수행
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, c;
int ans = 0;
vector<int> houses;

void input()
{
	cin >> n >> c;

	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;

		houses.push_back(temp);
	}

	sort(houses.begin(), houses.end());		// 이분 탐색을 위해 정렬 수행
}

void solve()
{
	int left = 1; 							// 최소 간격
	int right = houses[n - 1] - houses[0];  // 최대 간격

	// 이분 탐색
	while (left <= right)
	{
		int dist = (left + right) / 2;	// 공유기 사이의 간격
		int cnt = 1;					// 설치한 공유기 개수

		int prev = houses[0];
		for (int i = 1; i < n; ++i)
		{
			// 이전 집에 공유기를 설치할 경우 조건을 충족하는지 체크
			if (houses[i] - prev >= dist)
			{
				++cnt;				// 해당 집에 공유기 설치
				prev = houses[i];	// 이전 집 갱신
			}
		}

		// 설치한 공유기의 수가 조건보다 많거나 같을 경우
		// 간격을 더 크게 설치할 수 있는 경우가 있을 수 있으므로
		if (cnt >= c)
		{
			ans = max(ans, dist);	// 출력값 갱신

			// left 값을 증가시키므로써 공유기 사이 간격을 증가시킨 후 다시 이분 탐색
			left = dist + 1;
		}
		// 설치한 공유기의 수가 조건보다 적을 경우
		else
			// right 값을 감소시키므로써 공유기 사이 간격을 감소시킨 후 다시 이분 탐색
			right = dist - 1;
	}
}

void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main()
{
	init();
	input();
	solve();

	cout << ans << '\n';

	return 0;
}