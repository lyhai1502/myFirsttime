#include "Header.h"

// Tao do thi tu tap tin
Graph createGraptFromFile(const string &filename)
{
    ifstream ifs;
    ifs.open(filename, ios::in);

    Graph g;
    ifs >> g.num_vertices;
    int i = 0, j = 0;
    while (!ifs.eof())
    {
        if (j + 1 != g.num_vertices)
        {
            ifs >> g.adjacency_list[i][j];
            j++;
        }
        else
        {
            ifs >> g.adjacency_list[i][j];
            i++;
            j = 0;
        }
    }
    ifs.close();
    return g;
}
// Hien thi do thi duoi dang danh sach ke
void DisplayGraph(Graph g)
{
    for (int i = 0; i < g.num_vertices; i++)
    {
        cout << i + 1 << ": ";
        for (int j = 0; j < g.num_vertices; j++)
            if (g.adjacency_list[i][j])
                cout << j + 1 << " ";
        cout << "\n";
    }
}
// Kiem tra do thi co phai la do thi vo huong khong
bool IsUndirectedGraph(Graph g)
{
    for (int i = 0; i < g.num_vertices; i++)
    {
        if (g.adjacency_list[i][i] != 0)
            return 0;
        for (int j = i; j < g.num_vertices; j++)
        {
            if (g.adjacency_list[i][j] != INF && g.adjacency_list[j][i] != INF)
                continue;
            else
                return 0;
        }
    }
    return 1;
}

// Dem so luong canh trong do thi
int CountEdge(Graph g, bool UndirectedGraph)
{
    int sum = 0;
    for (int i = 0; i < g.num_vertices; i++)
        for (int j = 0; j < g.num_vertices; j++)
            sum += g.adjacency_list[i][j];
    if (UndirectedGraph)
        return sum / 2;
    else
        return sum;
}

// Liet ke thong tin bac dau vao, dau ra cua cac dinh trong do thi
void listDegreeOfVertices(Graph g)
{
    int i = 0;
    while (i < g.num_vertices)
    {
        cout << "\tDinh " << i + 1 << ":\tDi ra: ";
        for (int j = 0; j < g.num_vertices; j++)
        {
            if (g.adjacency_list[i][j])
                cout << j + 1 << ' ';
        }
        cout << "\tDi vao: ";
        for (int j = 0; j < g.num_vertices; j++)
        {
            if (g.adjacency_list[j][i])
                cout << j + 1 << ' ';
        }
        cout << '\n';
        i++;
    }
}
// Duyet do thi theo chieu sau, in ra duong di
void DFS(Graph g, int start_vextex)
{
    vector<int> s;
    vector<bool> free;
    free.resize(g.num_vertices);
    s.push_back(start_vextex);
    while (s.size() != 0)
    {
        int temp = s[s.size() - 1];
        s.pop_back();
        if (free[temp - 1] == 1)
            continue;
        free[temp - 1] = 1;
        cout << temp << ' ';
        for (int i = g.num_vertices - 1; i >= 0; i--)
        {
            if (g.adjacency_list[temp - 1][i] == 1)
            {
                s.push_back(i + 1);
            }
        }
    }
}

// Duyet do thi theo chieu rong, in ra duong di
void BFS(Graph g, int start_vextex)
{
    vector<int> free;
    free.resize(g.num_vertices);
    vector<int> q;
    q.push_back(start_vextex - 1);
    free[start_vextex - 1] = 1;
    while (q.size() != 0)
    {
        for (int j = 0; j < g.num_vertices; j++)
        {
            if (g.adjacency_list[q[0]][j] == 1 && free[j] == 0)
            {
                q.push_back(j);
                free[j] = 1;
            }
        }
        cout << q[0] + 1 << ' ';
        q.erase(q.begin(), q.begin() + 1);
    }
}

// Kiem tra do thi co chu trinh hay khong
bool isCyclicGraph(Graph g)
{
    vector<int> s;
    vector<bool> free;
    free.resize(g.num_vertices);
    int start_vextex = 1;
    bool cycle = 0;
    for (int k = start_vextex - 1; k < g.num_vertices; k++)
    {
        s.push_back(k + 1);
        while (s.size() != 0)
        {
            int temp = s[s.size() - 1];
            s.pop_back();
            if (free[temp - 1] == 1)
            {
                if (temp - 1 == k)
                    return 1;
                else
                    continue;
            }
            free[temp - 1] = 1;
            for (int i = g.num_vertices - 1; i >= 0; i--)
            {
                if (g.adjacency_list[temp - 1][i] == 1)
                {
                    s.push_back(i + 1);
                }
            }
        }
        fill(free.begin(), free.end(), 0);
    }
    return 0;
}

// Kiem tra do thi co lien thong khong
bool IsConnectedGraph(Graph g)
{
    vector<bool> free;
    free.resize(g.num_vertices);
    vector<int> s;
    s.push_back(0);
    do
    {
        int k = s[s.size() - 1];
        free[k] = 1;
        s.pop_back();
        for (int i = 0; i < g.num_vertices; i++)
        {
            if (g.adjacency_list[k][i] != 0 && free[i] == 0)
                s.push_back(i);
        }
    } while (s.size() != 0);
    for (int i = 0; i < g.num_vertices; i++)
    {
        if (!free[i])
            return 0;
    }
    return 1;
}

bool DFSForConnect(Graph g, int start_vextex, vector<bool> &free)
{
    vector<int> s;
    s.push_back(start_vextex);
    bool lienthong = 0;
    if (free[start_vextex - 1] == 1)
        return 0;
    while (s.size() != 0)
    {
        int temp = s[s.size() - 1];
        s.pop_back();
        if (free[temp - 1] == 1)
            continue;
        lienthong = 1;
        free[temp - 1] = 1;
        for (int i = g.num_vertices - 1; i >= 0; i--)
        {
            if (g.adjacency_list[temp - 1][i] == 1)
            {
                s.push_back(i + 1);
            }
        }
    }
    return lienthong;
}

// Dem so thanh phan lien thong cua do thi
int CountConnectedComponents(Graph g)
{
    vector<bool> free;
    free.resize(g.num_vertices);
    int cnt = 0;
    for (int i = 1; i <= g.num_vertices; i++)
    {
        if (DFSForConnect(g, i, free))
            cnt++;
    }
    return cnt;
}

// Tim duong di ngan nhat tu mot dinh den cac dinh con lai

// void FindShortestPathDijkstra(trongSoGraph g, int start_vertex)
// {
//     priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
//     vector<pair<int, int> > dist;
//     vector<bool> check;
//     check.resize(g.num_vertices);
//     check[start_vertex - 1] = 1;
//     int tmp = 0, i = 1;
//     for (int i = 0; i < g.num_vertices; i++)
//     {
//         dist.push_back({inf, 0});
//     }
//     cout << "Duong di ngan nhat:\n";
//     do
//     {
//         for (int i = 0; i < g.num_vertices; i++)
//         {
//             if (check[i] == 0)
//             {
//                 if (g.adjacency_list[start_vertex - 1][i] + tmp < dist[i].first)
//                 {
//                     dist[i] = {g.adjacency_list[start_vertex - 1][i] + tmp, start_vertex};
//                     q.push({g.adjacency_list[start_vertex - 1][i] + tmp, i});
//                 }
//             }
//         }
//         for (int i = 0; i < g.num_vertices; i++)
//         {
//             if (dist[i].second == 0)
//                 cout << "(inf,-)\t";
//             else
//                 cout << "(" << dist[i].first << "," << dist[i].second << ")\t";
//         }
//         cout << "\n";
//         tmp = q.top().first;
//         check[q.top().second] = 1;
//         start_vertex = q.top().second + 1;
//         q.pop();
//     } while (!q.empty());
//     cout << "Src\tDes\tWei\n";
//     for (int i = 0; i < g.num_vertices; i++)
//     {
//         if (dist[i].second != 0)
//             cout << i + 1 << '\t' << dist[i].second << '\t' << dist[i].first << '\n';
//     }
// }
// void FindShortestPathDijkstra(Graph g, int start_vertex, vector<int> &ans)
// {
//     priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
//     vector<bool> free(g.num_vertices + 1, true);
//     q.push({0, start_vertex});
//     ans.resize(g.num_vertices + 1, INF);
//     ans[start_vertex] = 0;
//     while (!q.empty())
//     {
//         int u = q.top().second;
//         ans[u] = q.top().first;
//         q.pop();
//         if (!free[u])
//             continue;
//         free[u] = false;
//         for (int i = 0; i < g.adjacency_list[u].size(); i++)
//         {
//             int v = g.adjacency_list[u][i].first,
//                 x = g.adjacency_list[u][i].second;
//             if (!free[v])
//                 continue;
//             if (ans[v] > ans[u] + x)
//             {
//                 ans[v] = ans[u] + x;
//                 q.push({ans[v], v});
//             }
//         }
//     }
// }
// void FindShortestPathBellman(trongSoGraph g, int start_vertex)
// {
//     vector<pair<int, int> > dist;
//     cout << "Duong di ngan nhat:\n";
//     for (int i = 0; i < g.num_vertices; i++)
//     {
//         if (i == start_vertex - 1)
//             dist.push_back({0, 0});
//         else
//             dist.push_back({inf, 0});
//     }
//     int v = 0;
//     while (true)
//     {
//         bool check = 1;
//         if (v == 0)
//         {
//             for (int i = 0; i < g.num_vertices; i++)
//             {
//                 if (g.adjacency_list[start_vertex - 1][i] < inf)
//                     dist[i] = {g.adjacency_list[start_vertex - 1][i], start_vertex};
//             }
//         }
//         for (int i = 0; i < g.num_vertices; i++)
//         {
//             if (i == start_vertex - 1)
//                 continue;
//             pair<int, int> tmp = {inf, 0};
//             for (int j = 0; j < g.num_vertices; j++)
//                 if (dist[j].first + g.adjacency_list[j][i] < tmp.first)
//                     tmp = {dist[j].first + g.adjacency_list[j][i], j + 1};
//             if (dist[i] != tmp)
//                 check = 0;
//             dist[i] = tmp;
//         }
//         for (int i = 0; i < g.num_vertices; i++)
//         {
//             if (dist[i].second == 0)
//                 cout << "(0,-)\t";
//             else if (dist[i].first == inf)
//                 cout << "(inf,-)\t";
//             else
//                 cout << "(" << dist[i].first << "," << dist[i].second << ")\t";
//         }
//         cout << "\n";
//         if (v == 0)
//         {
//             v++;
//             continue;
//         }
//         if (check == 1)
//             break;
//         if (v == g.num_vertices)
//         {
//             if (check == 0)
//                 cout << "Vo nghiem";
//             break;
//         }
//     }
// }
// Tim cay khung nho nhat cua do thi
// Thuat toan Prim
// long long prim(trongSoGraph g, int x)
// {
//     priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
//     long long ans = 0;
//     vector<int> d(g.num_vertices + 1, INF);
//     d[x] = 0;
//     q.push({0, x});
//     while (!q.empty())
//     {
//         int temp = q.top().first,
//             u = q.top().second;
//         q.pop();

//         if (temp != d[u])
//             continue;

//         ans += d[u];
//         d[u] = -INF;

//         for (int i = 0; i < g.adjacency_list[u].size(); i++)
//         {
//             int v = g.adjacency_list[u][i].first,
//                 w = g.adjacency_list[u][i].second;
//             if (d[v] > w)
//             {
//                 d[v] = w;
//                 q.push({d[v], v});
//             }
//         }
//     }
//     return ans;
// }
