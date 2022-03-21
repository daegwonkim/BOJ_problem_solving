#include<iostream>
#include<algorithm>

#define MAX 100000
#define ll long long

using namespace std;

int n;
ll arr[MAX];
pair<int, int> ans;

void input()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	sort(arr, arr + n);
}

void solve()
{
	ll close = 2000000000;
	int left = 0, right = n - 1;

	while (left != right) {
		ll sum = arr[left] + arr[right];
		if (close > abs(sum)) {
			close = abs(sum);
			ans.first = arr[left];
			ans.second = arr[right];
		}

		if (sum >= 0) --right;
		else ++left;
	}

	cout << ans.first << ' ' << ans.second;
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