#include<iostream>
#include<queue>

#define MAX 20

using namespace std;

int dy[] = { 0, 0, -1, 1 };
int dx[] = { 1, -1, 0, 0 };

int n, m, x, y, k;
int map[MAX][MAX];
int dice[6];
queue<int> order;

void input()
{
    cin >> n >> m >> y >> x >> k;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> map[i][j];

    for (int i = 0; i < k; ++i) {
        int dir;
        cin >> dir;

        order.push(dir);
    }
}

void roll(int dir)
{
    int temp = dice[0];

    // 동쪽 이동
    if (dir == 0) {
        dice[0] = dice[3];
        dice[3] = dice[5];
        dice[5] = dice[2];
        dice[2] = temp;
    }
    // 서쪽 이동
    else if (dir == 1) {
        dice[0] = dice[2];
        dice[2] = dice[5];
        dice[5] = dice[3];
        dice[3] = temp;
    }
    // 북쪽 이동
    else if (dir == 2) {
        dice[0] = dice[4];
        dice[4] = dice[5];
        dice[5] = dice[1];
        dice[1] = temp;
    }
    // 남쪽 이동
    else {
        dice[0] = dice[1];
        dice[1] = dice[5];
        dice[5] = dice[4];
        dice[4] = temp;
    }
}

void solve()
{
    while (!order.empty()) {
        int dir = order.front() - 1;
        order.pop();

        // 방향에 따라 다음 이동 좌표 설정
        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

        roll(dir);  // 방향에 따라 주사위 굴리기

        if (map[ny][nx] == 0)
            map[ny][nx] = dice[5];
        else {
            dice[5] = map[ny][nx];
            map[ny][nx] = 0;
        }

        cout << dice[0] << '\n';

        y = ny; x = nx;
    }
}

void init()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main(void)
{
    init();
    input();
    solve();

    return 0;
}