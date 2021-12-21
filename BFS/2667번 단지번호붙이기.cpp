/*
* 1. 아이디어
* - BFS를 수행하여 지도를 탐색.
* - 2중 for문을 사용하여 각각의 위치에서 부터 탐색.
* - BFS 함수를 수행한 뒤 Count 값을 Vector에 저장하여 단지 수와 집의 수 Vector를 사용하여 출력.
* 
* 2. 시간복잡도
* - V = N(5 ~ 25)
* - E = 4V
* - O(25 * 25 + 4 * 25) = O(625 + 100) = O(725) < 2억
* 
* 3. 사용 변수
* - int : 지도의 크기
* - string : 지도의 형태를 입력받기 위함(공백 구분 없이 입력되기 때문)
* - int[][] : 지도의 형태를 저장하기 위한 2차원 배열
* - bool[][] : 방문 여부를 확인하기 위한 2차원 배열
* - int[] : 상, 하, 좌, 우로 이동하기 위한 1차원 배열
* - vector : BFS 수행 결과를 저장하기 위함
* - queue : BFS를 수행하기 위함
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define endl '\n'
#define MAX 25

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int n;
int map[MAX][MAX];
bool check[MAX][MAX] = { 0, };

vector<int> vec;
queue<pair<int, int>> que;

void input()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string input;
		cin >> input;

		for (int j = 0; j < n; ++j)
			map[i][j] = input[j] - '0';
	}
}

void BFS(int y, int x)
{
	int cnt = 1;

	check[y][x] = true;
	que.push({ y, x });

	while (!que.empty())
	{
		int yy = que.front().first;
		int xx = que.front().second;
		que.pop();

		for (int i = 0; i < 4; ++i)
		{
			int ny = yy + dy[i];
			int nx = xx + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;

			if (map[ny][nx] && !check[ny][nx])
			{
				check[ny][nx] = true;
				que.push({ ny, nx });
				++cnt;
			}
		}
	}

	vec.push_back(cnt);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (map[i][j] && !check[i][j])
				BFS(i, j);

	sort(vec.begin(), vec.end());

	cout << vec.size() << endl;
	for (int i = 0; i < vec.size(); ++i)
		cout << vec[i] << endl;

	return 0;
}