#include<iostream>

#define MAX 1000

using namespace std;

int n, ans = 0;
int arr[MAX];
int dp[MAX], dp_left[MAX], dp_right[MAX];

void input()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
}

void solve()
{
	for (int i = 0; i < n; ++i) {
		dp_left[i] = 1;

		for (int j = 0; j < i; ++j)
			if (arr[i] > arr[j])
				dp_left[i] = max(dp_left[i], dp_left[j] + 1);
	}

	for (int i = n - 1; i > -1; --i) {
		dp_right[i] = 1;

		for (int j = n - 1; j > i; --j)
			if (arr[i] > arr[j])
				dp_right[i] = max(dp_right[i], dp_right[j] + 1);
	}

	for (int i = 0; i < n; ++i) {
		dp[i] = dp_left[i] + dp_right[i];

		ans = max(ans, dp[i]);
	}
		
	cout << ans - 1;
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