// 经典dfs问题，很简单，很经典，适合练手，体会一下深度优先搜索的过程。
// 画出树形结构以辅助理解
#include <bits/stdc++.h>

using namespace std;

vector<vector<bool>> a;
int counter = 0;
void dfs(int x, int y, int n, int m)
{
    if (x > n || y > m || !a[x][y])
        return;
    if (x == n && y == m)
    {
        counter++;
        return;
    }
    dfs(x + 1, y, n, m);
    dfs(x, y + 1, n, m);
}

int main()
{
    int n, m, hx, hy;
    cin >> n >> m >> hx >> hy;
    for (int i = 0; i <= n; i++)
    {
        vector<bool> temp(m + 1, true);
        a.push_back(temp);
    }
    a[hx][hy] = false;
    if (hx - 1 >= 0 && hy - 2 >= 0)
        a[hx - 1][hy - 2] = false;
    if (hx - 2 >= 0 && hy - 1 >= 0)
        a[hx - 2][hy - 1] = false;
    if (hx - 2 >= 0 && hy + 1 <= m)
        a[hx - 2][hy + 1] = false;
    if (hx - 1 >= 0 && hy + 2 <= m)
        a[hx - 1][hy + 2] = false;
    if (hx + 1 <= n && hy - 2 >= 0)
        a[hx + 1][hy - 2] = false;
    if (hx + 2 <= n && hy - 1 >= 0)
        a[hx + 2][hy - 1] = false;
    if (hx + 2 <= n && hy + 1 <= m)
        a[hx + 2][hy + 1] = false;
    if (hx + 1 <= n && hy + 2 <= m)
        a[hx + 1][hy + 2] = false;
    dfs(0, 0, n, m);
    cout << counter << endl;
    return 0;
}