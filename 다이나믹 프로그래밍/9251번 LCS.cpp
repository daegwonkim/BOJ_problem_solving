#include<iostream>
#include<cstring>

#define MAX 1001

using namespace std;

char str_a[MAX], str_b[MAX];
int DP[MAX][MAX];

void input()
{
	cin >> str_a >> str_b;
}

void solve()
{
	int size_a = strlen(str_a);
	int size_b = strlen(str_b);

	for (int i = 1; i <= size_a; ++i) {
		for (int j = 1; j <= size_b; ++j) {
			if (str_a[i - 1] == str_b[j - 1])
				DP[i][j] = DP[i - 1][j - 1] + 1;
			else
				DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
		}
	}

	cout << DP[size_a][size_b] << '\n';
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