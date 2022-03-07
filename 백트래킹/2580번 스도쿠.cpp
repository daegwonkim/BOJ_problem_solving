#include <iostream>
#include <vector>

using namespace std;

int cnt = 0;
int board[9][9];
vector<pair<int, int>> vec;
bool found = false;

void input()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 0)
            {
                cnt++;
                vec.push_back({ i, j });
            }
        }
    }
}

bool check(pair<int, int> p)
{
    int square_x = p.first / 3;
    int square_y = p.second / 3;

    for (int i = 0; i < 9; i++)
    {
        if (board[p.first][i] == board[p.first][p.second] && i != p.second)
            return false;
        if (board[i][p.second] == board[p.first][p.second] && i != p.first)
            return false;
    }

    for (int i = 3 * square_x; i < 3 * square_x + 3; i++)
    {
        for (int j = 3 * square_y; j < 3 * square_y + 3; j++)
        {
            if (board[i][j] == board[p.first][p.second])
            {
                if (i != p.first && j != p.second)
                    return false;
            }
        }
    }

    return true;
}

void sudoku(int n) {
    if (n == cnt)
    {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++)
                cout << board[i][j] << ' ';
            cout << '\n';
        }

        found = true;
        return;
    }

    for (int j = 1; j <= 9; j++)
    {
        board[vec[n].first][vec[n].second] = j;
        if (check(vec[n]))
            sudoku(n + 1);
        if (found)
            return;
    }

    board[vec[n].first][vec[n].second] = 0;
    return;
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
    sudoku(0);

    return 0;
}