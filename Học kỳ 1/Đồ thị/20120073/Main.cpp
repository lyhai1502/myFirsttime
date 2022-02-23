#include "Source.cpp"
int main()
{
    Graph g = createGraptFromFile("Graph.txt");
    DisplayGraph(g);
    cout << (IsUndirectedGraph(g) ? "Do thi vo huong" : "Khong phai do thi vo huong");
    cout << "\nSo luong canh trong do thi: " << CountEdge(g, IsConnectedGraph(g));
    cout << "\nThong tin bac dau vao, dau ra cua do thi\n";
    listDegreeOfVertices(g);
    cout << "\nDuyet do thi theo chieu sau: ";
    DFS(g, 1);
    cout << "\nDuyet do thi theo chieu rong: ";
    BFS(g, 1);
    cout << (isCyclicGraph(g) ? "\nDo thi co chu trinh" : "\nDo thi khong co chu trinh");
    cout << (IsConnectedGraph(g) ? "\nDo thi lien thong" : "\nDo thi khong lien thong");
    cout << "\nSo thanh phan lien thong cua do thi: " << CountConnectedComponents(g);
    // cout << "\nDuong di ngan nhat: ";
    // FindShortestPathFloyd(g);
    // FindShortestPathDijkstra(g, 1);
    // prim(g,1)
    return 0;
}