#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

struct Position
{
    int x, y;
};

int function3(vector<vector<int> > meCung)
{
    int n = meCung.size();
    Position start = {0, 0},
             end = {n - 1, n - 1};
    vector<vector<int> > trace(n, vector<int>(n, 0));

    queue<Position> q;
    q.push(start);
    if (!meCung[start.x][start.y])
        return -1;
    trace[start.x][start.y] = 1;
    int ans = 0;
    while (!q.empty())
    {
        Position u = q.front();
        q.pop();
        if (u.x == end.x && u.y == end.y)
            break;
        for (int i = 0; i < 4; i++)
        {
            Position v;
            v.x = u.x + dx[i];
            v.y = u.y + dy[i];
            if (v.x >= 0 && v.x < n && v.y >= 0 && v.y < n && meCung[v.x][v.y])
            {
                if (trace[v.x][v.y] == 0)
                {
                    q.push(v);
                    trace[v.x][v.y] = trace[u.x][u.y] + 1;
                }
            }
        }
    }

    if (trace[end.x][end.y] == 0)
        return -1;
    return trace[end.x][end.y] - 1;
}

int main()
{
    // Bo cmt cac dong duoi day neu ban muon giao tiep chuong trinh thong qua file

    // if (fopen("./input1.txt", "r")) {
    //     freopen("./input1.txt", "r", stdin);
    //      freopen("./output1.txt", "w", stdout);
    // }
    int n;
    cin >> n;
    vector<vector<int> > meCung(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> meCung[i][j];

    vector<vector<int> > distance(n, vector<int>(n, -1));
    cout << function3(meCung);

    // Luu y rang ban se phai cmt dong duoi day lai khi nop bai, neu khong se bi sai output.
    // cerr << "Execution time: " << ((double) (end - start)) / CLOCKS_PER_SEC << "s";
    return 0;
}