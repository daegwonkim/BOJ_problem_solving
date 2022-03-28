#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string.h>

#define MAX 20

using namespace std;

int dy[] = { 1, -1, 0, 0 };
int dx[] = { 0, 0, 1, -1 };

int n, ans = 0;
int pos_y, pos_x;
int current_size = 2, eat_cnt = 0;
int map[MAX][MAX];
int cnt[MAX][MAX];
vector<pair<int, pair<int, int>>> eat_fish;
queue<pair<int, int>> que;

void input()
{
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> map[i][j];

			if (map[i][j] == 9) {	// 처음 시작 위치 저장
				// 처음 시작 위치에 9가 저장되어 있으면 BFS를 수행할 때 물고기의 크기로 인식하고
				// 길을 지나지 못하는 경우가 발생하기 때문에 0으로 초기화 시켜줌
				map[i][j] = 0;
				pos_y = i;
				pos_x = j;
			}
		}
	}
}

void BFS(int y, int x)
{
	que.push({ y, x });

	while (!que.empty()) {
		int y = que.front().first;
		int x = que.front().second;
		que.pop();
		
		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;

			// 한 번도 지나치지 않았으며 아기 상어가 지나갈 수 있는 길일 경우
			if (cnt[ny][nx] == 0 && current_size >= map[ny][nx]) {
				cnt[ny][nx] = cnt[y][x] + 1;

				// 해당 좌표에 물고기가 있으며 그 크기가 아기 상어보다 작을 경우
				if (map[ny][nx] != 0 && current_size > map[ny][nx])
						eat_fish.push_back({ cnt[ny][nx], {ny, nx} });

				que.push({ ny, nx });
			}
		}
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
	
	while (1) {
		BFS(pos_y, pos_x);

		// 먹은 물고기가 없을 경우
		if (eat_fish.empty()) break;
		
		// 거리, y좌표, x좌표 순의 우선순위로 먹은 물고기를 정렬
		sort(eat_fish.begin(), eat_fish.end());

		ans += eat_fish[0].first;	// 가장 가까운 물고기의 거리 저장

		// 아기 상어의 위치를 먹은 물고기의 좌표로 변경
		pos_y = eat_fish[0].second.first;
		pos_x = eat_fish[0].second.second;

		map[pos_y][pos_x] = 0;	// 먹은 물고기 좌표를 0으로 초기화

		// 현재까지 먹은 물고기의 개수에 따라 아기 상어 크기 조절
		if (current_size == ++eat_cnt) {
			++current_size;
			eat_cnt = 0;
		}

		// 다음 사이클 돌기 전에 벡터, 배열 초기화
		eat_fish.clear();
		memset(cnt, 0, sizeof(cnt));
	}

	cout << ans;

	return 0;
}