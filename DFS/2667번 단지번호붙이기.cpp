/*
* 1. 아이디어
* - 2중 반복문을 통해 DFS를 수행하여 지도를 탐색
* - 새로운 구역을 방문할 때마다 Count 값을 증가시켜 결과값에 저장 후 출력
* 
* 2. 시간 복잡도
* - V = N * N(5 ~ 25)
* - E = 4V
* - O(V + E) = O(625 + 2,500) = O(3,125) < 2억
* 
* 3. 사용 변수
* - int : 지도의 크기, 각 단지내 집의 수
* - int[][] : 지도의 형태를 입력받기 위한 2차원 배열
* - int[] : 좌표상에서 상, 하, 좌, 우로 이동하기 위한 1차원 배열
* - bool[][] : 방문 여부를 확인하기 위한 2차원 배열
* - vector : 결과값을 저장하기 위함
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define endl '\n'
#define MAX 25

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int n, cnt;
int map[MAX][MAX];
bool visited[MAX][MAX];
vector<int> vec;

void input()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;

		for (int j = 0; j < n; ++j)
			map[i][j] = str[j] - '0';
	}
}

void DFS(int y, int x)
{
	visited[y][x] = true;

	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;

		if (map[ny][nx] == 1 && !visited[ny][nx])
		{
			++cnt;
			DFS(ny, nx);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();
	
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (map[i][j] == 1 && !visited[i][j])
			{
				cnt = 1;
				DFS(i, j);
				vec.push_back(cnt);
			}
		}
	}

	sort(vec.begin(), vec.end());

	cout << vec.size() << endl;
	for(int i = 0; i < vec.size(); ++i)
		cout << vec[i] << endl;

	return 0;
}