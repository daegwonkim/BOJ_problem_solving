#include<iostream>
#include<vector>

using namespace std;

int n, ans = 0;
vector<int> prime;
vector<bool> check;

void input()
{
	cin >> n;
	check.resize(n + 1, true);
}

void get_prime()
{
	for (int i = 2; i * i <= n; ++i) {
		if (!check[i]) continue;

		for (int j = i * i; j <= n; j += i)
			check[j] = false;
	}

	for (int i = 2; i <= n; ++i)
		if (check[i])
			prime.push_back(i);
}

void solve()
{
	int sum = 0;
	int left = 0, right = 0;

	while (1) {
		if (sum > n) sum -= prime[left++];
		else {
			if (sum == n) ++ans;
			if (right >= prime.size()) break;
			sum += prime[right++];
		}
	}

	cout << ans;
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
	get_prime();
	solve();

	return 0;
}