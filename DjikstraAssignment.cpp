#include <limits.h>
#include <iostream>
#include <vector>
#include <queue>
#define NUM 9

using namespace std;

struct Graph
{
    vector<vector<int>> adjacent_matrix;
};

void display(const vector<int> &dist)
{
    cout << "Vertices Distances" << endl;
    for (int i = 0; i < NUM; i++)
    {
        cout << "  " << i << " \t   " << dist[i] << endl;
    }
}

void dijkstra(const Graph &graph, int src)
{
    vector<int> dist(NUM, INT_MAX);
    dist[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for (int k = 0; k < NUM; k++)
        {
            if (graph.adjacent_matrix[u][k] && dist[u] + graph.adjacent_matrix[u][k] < dist[k])
            {
                dist[k] = dist[u] + graph.adjacent_matrix[u][k];
                pq.push({dist[k], k});
            }
        }
    }
    display(dist);
}

int main(int argc, char* argv[])
{
    Graph graph;
    graph.adjacent_matrix = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                        {4, 0, 8, 0, 0, 0, 0, 11, 0},
                        {0, 8, 0, 7, 0, 4, 0, 0, 2},
                        {0, 0, 7, 0, 9, 14, 0, 0, 0},
                        {0, 0, 0, 9, 0, 10, 0, 0, 0},
                        {0, 0, 4, 14, 10, 0, 2, 0, 0},
                        {0, 0, 0, 0, 0, 2, 0, 1, 6},
                        {8, 11, 0, 0, 0, 0, 1, 0, 7},
                        {0, 0, 2, 0, 0, 0, 6, 7, 0}};

    dijkstra(graph, 0);
    return 0;
}
