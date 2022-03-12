#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;

int n, ans = 0;
int alp[26];

bool compare(int a, int b)
{
	if (a > b) return true;

	return false;
}

void input()
{
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		string word;
		cin >> word;

		for (int j = 0; j < word.length(); ++j)
			// 자릿수에 따라 10의 거듭제곱 적용
			alp[word[j] - 'A'] += pow(10, word.length() - j - 1);
	}

	sort(alp, alp + 26, compare);	// 내림차순 정렬
}

void solve()
{
	int num = 9;

	for (int i = 0; i < 26; ++i)
	{
		if (alp[i] != 0)
		{
			ans += alp[i] * num;
			--num;
		}
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
}