#include<iostream>
#include<queue>
#include<deque>

#define MAX 101

using namespace std;

int dy[] = { 0, -1, 0, 1 };
int dx[] = { 1, 0, -1, 0 };

int n, k, l;
int board[MAX][MAX];
queue<pair<int, char>> que;
deque<pair<int, int>> deq;

void input()
{
    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        int row, col;
        cin >> row >> col;

        board[row][col] = 2;    // 사과 위치 저장(= 2)
    }

    cin >> l;
    for (int i = 0; i < l; ++i) {
        int sec; char dir;
        cin >> sec >> dir;

        que.push({ sec, dir });
    }
}

void solve()
{
    int y = 1, x = 1;

    // 시작 위치 저장
    board[y][x] = 1;
    deq.push_back({ y, x });

    int time = 0, dir = 0;
    while (1) {
        ++time;

        // 방향에 따른 다음 위치 지정
        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if (ny < 1 || ny > n || nx < 1 || nx > n || board[ny][nx] == 1) break;

        if (board[ny][nx] == 0) {
            board[ny][nx] = 1;
            board[deq.back().first][deq.back().second] = 0;

            deq.push_front({ ny, nx }); // 머리 이동
            deq.pop_back();             // 꼬리 자르기
        }
        else if (board[ny][nx] == 2) {
            board[ny][nx] = 1;
            deq.push_front({ ny, nx }); // 머리만 이동
        }

        if (!que.empty()) {
            if (time == que.front().first) {
                if (que.front().second == 'L')  // 방향 전환
                    dir = (dir + 1) % 4;
                else
                    dir = (dir + 3) % 4;

                que.pop();
            }
        }
        
        // 행, 열 갱신
        y = ny; x = nx;
    }

    cout << time;
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