#include<iostream>

#define MAX 100000

using namespace std;

int n, s;
int num[MAX];
int ans = MAX;

void input()
{
	cin >> n >> s;
	for (int i = 0; i < n; ++i)
		cin >> num[i];
}

void solve()
{
	int sum = 0, left = 0, right = 0;

	while (right <= n)
	{
		if (sum >= s)
		{
			ans = min(ans, right - left);
			sum -= num[left++];
		}
		else
			sum += num[right++];
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

	if (ans == MAX) cout << 0 << '\n';
	else cout << ans << '\n';

	return 0;
}