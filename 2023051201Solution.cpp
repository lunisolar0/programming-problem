// 经典dfs问题，很简单，很经典，适合练手，体会一下深度优先搜索的过程。
// 画出树形结构以辅助理解
#include <bits/stdc++.h>

using namespace std;

vector<vector<bool>> a; // 二维动态数组存储棋盘
int counter = 0;        // 计数全局变量
void dfs(int x, int y, int n, int m) // 深度优先遍历
{
    if (x > n || y > m || !a[x][y])  // 合法性检测(筛除死路)
        return; 
    if (x == n && y == m)            // 计数检测(记录成功路径)
    {
        counter++;
        return;
    }
    dfs(x + 1, y, n, m); // 先深度
    dfs(x, y + 1, n, m); // 后广度
}

int main()
{
    int n, m, hx, hy;
    cin >> n >> m >> hx >> hy;
    for (int i = 0; i <= n; i++) //初始化棋盘
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
    // 上面这一坨是跳马的八个点以及马所在点的处理
    dfs(0, 0, n, m);
    cout << counter << endl;
    return 0;
}
