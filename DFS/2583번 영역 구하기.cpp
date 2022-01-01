/*
* 1. 아이디어
* - 모눈종이의 형태와 직사각형의 영역을 입력받은 뒤, DFS를 수행하여 분리된 각 영역의 넓이를 구함
* - 구한 넓이를 오름차순으로 정렬하여 출력
* 
* 2. 시간 복잡도
* - V = M * N(1 ~ 100)
* - E = 4V
* - O(V + E) = O(V + 4V) = O(5V) = O(50,000) < 2억
* 
* 3. 사용 변수
* - int : 모눈종이의 가로, 세로 크기, 직사각형의 개수
* - int[][] : 모눈종이의 형태를 저장하기 위한 2차원 배열
* - int[] : 좌표상에서 상, 하, 좌, 우로 이동하기 위한 1차원 배열
* - bool[][] : 방문 여부를 확인하기 위한 2차원 배열
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define endl '\n'
#define MAX 100

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int m, n, k, cnt;
int paper[MAX][MAX];
bool visited[MAX][MAX];

vector<int> vec;

void input()
{
	cin >> m >> n >> k;
	for (int i = 0; i < k; ++i)
	{
		int startX, startY, endX, endY;
		cin >> startX >> startY >> endX >> endY;

		for (int y = startY; y < endY; ++y)
			for (int x = startX; x < endX; ++x)
				paper[y][x] = 1;
	}
}

void DFS(int y, int x)
{
	visited[y][x] = true;
	++cnt;

	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= m || nx >= n) continue;

		if (paper[ny][nx] == 0 && !visited[ny][nx])
			DFS(ny, nx);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cnt = 0;

			if (paper[i][j] == 0 && !visited[i][j])
			{
				DFS(i, j);
				vec.push_back(cnt);
			}
		}
	}

	sort(vec.begin(), vec.end());

	cout << vec.size() << endl;
	for (int i = 0; i < vec.size(); ++i)
		cout << vec[i] << ' ';

	return 0;
}