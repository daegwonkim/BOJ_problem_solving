#include<iostream>

#define MAX 20

using namespace std;

int n, ans;
int board[MAX][MAX];
int copy_board[MAX][MAX];
int dir[5];

void input()
{
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
}

void move_board(int dir)
{
    // 위쪽으로 움직이기
    if (dir == 0) {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n; j++)
            {
                bool check = false;
                if (copy_board[i][j] == 0)
                {
                    int k = i + 1;
                    while (k <= n - 1)
                    {
                        if (copy_board[k][j] != 0)
                        {
                            check = true;
                            break;
                        }
                        k++;
                    }

                    if (check == true)
                    {
                        copy_board[i][j] = copy_board[k][j];
                        copy_board[k][j] = 0;
                    }
                }
            }
        }

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (copy_board[i][j] == copy_board[i + 1][j])
                {
                    copy_board[i][j] = copy_board[i][j] * 2;
                    copy_board[i + 1][j] = 0;
                }
            }
        }

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n; j++)
            {
                bool check = false;
                if (copy_board[i][j] == 0)
                {
                    int k = i + 1;
                    while (k <= n - 1)
                    {
                        if (copy_board[k][j] != 0)
                        {
                            check = true;
                            break;
                        }
                        k++;
                    }

                    if (check == true)
                    {
                        copy_board[i][j] = copy_board[k][j];
                        copy_board[k][j] = 0;
                    }
                }
            }
        }
    }
    // 오른쪽으로 움직이기
    else if (dir == 1) {
        for (int i = 0; i < n; i++)
        {
            for (int j = n - 1; j > 0; j--)
            {
                bool check = false;
                if (copy_board[i][j] == 0)
                {
                    int k = j - 1;
                    while (k >= 0)
                    {
                        if (copy_board[i][k] != 0)
                        {
                            check = true;
                            break;
                        }
                        k--;
                    }
                    if (check == true)
                    {
                        copy_board[i][j] = copy_board[i][k];
                        copy_board[i][k] = 0;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = n - 1; j > 0; j--)
            {
                if (copy_board[i][j] == copy_board[i][j - 1])
                {
                    copy_board[i][j] = copy_board[i][j] * 2;
                    copy_board[i][j - 1] = 0;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = n - 1; j > 0; j--)
            {
                bool check = false;
                if (copy_board[i][j] == 0)
                {
                    int k = j - 1;
                    while (k >= 0)
                    {
                        if (copy_board[i][k] != 0)
                        {
                            check = true;
                            break;
                        }
                        k--;
                    }
                    if (check == true)
                    {
                        copy_board[i][j] = copy_board[i][k];
                        copy_board[i][k] = 0;
                    }
                }
            }
        }
    }
    // 아래쪽으로 움직이기
    else if (dir == 2) {
        for (int i = n - 1; i > 0; i--)
        {
            for (int j = 0; j < n; j++)
            {
                bool check = false;
                if (copy_board[i][j] == 0)
                {
                    int k = i - 1;
                    while (k >= 0)
                    {
                        if (copy_board[k][j] != 0)
                        {
                            check = true;
                            break;
                        }
                        k--;
                    }
                    if (check == true)
                    {
                        copy_board[i][j] = copy_board[k][j];
                        copy_board[k][j] = 0;
                    }
                }
            }
        }

        for (int i = n - 1; i > 0; i--)
        {
            for (int j = 0; j < n; j++)
            {
                if (copy_board[i - 1][j] == copy_board[i][j])
                {
                    copy_board[i][j] = copy_board[i][j] * 2;
                    copy_board[i - 1][j] = 0;
                }
            }
        }
        for (int i = n - 1; i > 0; i--)
        {
            for (int j = 0; j < n; j++)
            {
                bool check = false;
                if (copy_board[i][j] == 0)
                {
                    int k = i - 1;
                    while (k >= 0)
                    {
                        if (copy_board[k][j] != 0)
                        {
                            check = true;
                            break;
                        }
                        k--;
                    }
                    if (check == true)
                    {
                        copy_board[i][j] = copy_board[k][j];
                        copy_board[k][j] = 0;
                    }
                }
            }
        }
    }
    // 왼쪽으로 움직이기
    else {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                bool check = false;
                if (copy_board[i][j] == 0)
                {
                    int k = j + 1;
                    while (k <= n - 1)
                    {
                        if (copy_board[i][k] != 0)
                        {
                            check = true;
                            break;
                        }
                        k++;
                    }
                    if (check == true)
                    {
                        copy_board[i][j] = copy_board[i][k];
                        copy_board[i][k] = 0;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                if (copy_board[i][j] == copy_board[i][j + 1])
                {
                    copy_board[i][j] = copy_board[i][j] * 2;
                    copy_board[i][j + 1] = 0;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                bool check = false;
                if (copy_board[i][j] == 0)
                {
                    int k = j + 1;
                    while (k <= n - 1)
                    {
                        if (copy_board[i][k] != 0)
                        {
                            check = true;
                            break;
                        }
                        k++;
                    }
                    if (check == true)
                    {
                        copy_board[i][j] = copy_board[i][k];
                        copy_board[i][k] = 0;
                    }
                }
            }
        }
    }
}

void select_move_dir(int cnt)
{
    if (cnt == 5)
    {
        // 기존 보드의 형태를 유지하기 위해 복사
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                copy_board[i][j] = board[i][j];

        // 백트래킹을 통해 얻은 중복순열에 따라 보드 움직이기
        for (int i = 0; i < 5; ++i)
            move_board(dir[i]);

        // 최댓값 구하기
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                ans = max(ans, copy_board[i][j]);

        return;
    }

    for (int i = 0; i < 4; i++)
    {
        // 0부터 3까지(위, 오른쪽, 아래, 왼쪽)의 방향으로 이루어진 중복순열 저장
        dir[cnt] = i;
        select_move_dir(cnt + 1);
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
    select_move_dir(0);

    cout << ans;

    return 0;
}