#includeiostream
#includequeue
#includealgorithm

#define MAX 300000

using namespace std;

int n, k;
long long ans = 0;
int bag[MAX];
pairint, int jewel[MAX];
priority_queueint pque;

void input()
{
	cin  n  k;
	for (int i = 0; i  n; ++i)
		cin  jewel[i].first  jewel[i].second;

	for (int i = 0; i  k; ++i)
		cin  bag[i];

	sort(jewel, jewel + n);
	sort(bag, bag + k);
}

void solve()
{
	int index = 0;

	for (int i = 0; i  k; ++i) {
		while (index  n && jewel[index].first = bag[i])
			pque.push(jewel[index++].second);

		if (!pque.empty()) {
			ans += pque.top();
			pque.pop();
		}
	}

	cout  ans;
}

void init()
{
	ios_basesync_with_stdio(false);
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