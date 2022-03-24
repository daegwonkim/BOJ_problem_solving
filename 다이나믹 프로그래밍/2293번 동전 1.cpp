#include<iostream>

using namespace std;

int n, k;
int coin[101];
int dp[10001];

void input()
{
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		cin >> coin[i];
}

void solve()
{
	dp[0] = 1;

	for (int i = 1; i <= n; ++i)
		for (int j = coin[i]; j <= k; ++j)
			dp[j] += dp[j - coin[i]];

	cout << dp[k];
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
}