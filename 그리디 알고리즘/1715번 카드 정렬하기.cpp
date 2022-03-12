
#include<iostream>
#include<queue>

using namespace std;

int n, ans = 0;
priority_queue<int, vector<int>, greater<int>> pq;	// 우선순위 큐

void input()
{
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;

		pq.push(num);
	}
}

void solve()
{
	while (pq.size() > 1)
	{
		int a = pq.top();
		pq.pop();

		int b = pq.top();
		pq.pop();

		ans += a + b;
		pq.push(a + b);
	}

	cout << ans << '\n';
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

	return 0;
}﻿​
