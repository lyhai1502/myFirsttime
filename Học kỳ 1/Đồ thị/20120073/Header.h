#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <string>
using namespace std;

#define MAX 100
#define INF 10e7

struct Graph
{
    int num_vertices;
    int adjacency_list[MAX][MAX];
};

// struct trongSoGraph
// {
//     int num_vertices;
//     vector<vector<pair<int, int> > > adjacency_list;
// };

Graph createGraphFromFile(const string &filename);
void DisplayGraph(Graph g);
bool IsUndirectedGraph(Graph g);
int CountEdge(Graph g);
void listDegreeOfVertices(Graph g);
void BFS(Graph g, int &start_vextex);
void DFS(Graph g, int &start_vextex);
bool isCyclicGraph(Graph g);
bool IsConnectedGraph(Graph g);
int CountConnectedComponents(Graph g);
// void FindShortestPathDijkstra(trongSoGraph g, int start_vertex);
// void FindShortestPathFloyd(trongSoGraph g, int start_vertex);
// void FindShortestPathBellman(trongSoGraph g, int start_vertex);
// long long prim(trongSoGraph g, int x);
// long long kruskal(trongSoGraph g);