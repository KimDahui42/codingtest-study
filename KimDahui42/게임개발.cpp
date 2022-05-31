#include <iostream>
#include <vector>

using namespace std;

int facing;

void isLand(next_r, next_c);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, cr, cc, cnt = 0;
    int go_dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int back_dir[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

    cin >> n >> m;
    cin >> cr >> cc >> facing;
    vector<vector<int>> game_map(n, vector<int>(m, 1));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> game_map[i][j];

    while (true)
    {
        int next_face = (facing + 1) % 4;
        int next_r = cr + go_dir[next_face][0];
        int next_c = cc + go_dir[next_face][1];
        if (game_map[next_r][next_c] == 0)
        {
            isLand(next_r, next_c);
            continue;
        }
        while (next_face != facing)
        {
            next_face = (next_face + 1) % 4;
            next_r = cr + go_dir[next_face][0];
            next_c = cc + go_dir[next_face][1];
            if (game_map[next_r][next_c] == 0)
            {
                isLand(next_r, next_c, next_face);
                break;
            }
        }
        if (next_face == facing)
        {
            next_r = cr + back_dir[next_face][0];
            next_c = cc + back_dir[next_face][1];
            next_face = (next_face + 1) % 4;
            while (next_face != facing)
            {
                next_face = (next_face + 1) % 4;
                next_r = cr + go_dir[next_face][0];
                next_c = cc + go_dir[next_face][1];
                if (game_map[next_r][next_c] == 0)
                {
                    isLand(next_r, next_c, next_face);
                    break;
                }
            }
            next_face == facing;
            break;
        }
    }
    cout << cnt;
}
void isLand(next_r, next_c, next_face)
{
    cr = next_r;
    cc = next_c;
    facing = next_face;
    game_map[next_r][next_c] = 1;
    cnt++;
    continue;
}