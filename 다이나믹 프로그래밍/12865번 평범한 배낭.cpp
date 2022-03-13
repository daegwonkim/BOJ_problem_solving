#include<iostream>

using namespace std;

int n, k;
int DP[101][100001];
int weight[101], value[101];

void input()
{
	cin >> n >> k;

	for (int i = 1; i <= n; ++i)
		cin >> weight[i] >> value[i];
}

void solve()
{
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= k; ++j) {
			if (j - weight[i] >= 0)
				DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - weight[i]] + value[i]);
			else DP[i][j] = DP[i - 1][j];
		}
	}

	cout << DP[n][k] << '\n';
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