#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;
template <typename T>
class graph
{

public:
    T visited[15] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    stack<int> stack;
    unordered_map<int, list<pair<int, int>>> adj;
    void addEdge(T u, T v, int weight)
    {
        pair<int, int> p = make_pair(v, weight);
        adj[u].push_back(p);
    }

    void printGraph()
    {
        for (auto i : adj)
        {
            cout << i.first << "-> ";
            for (auto j : i.second)
            {
                cout << "(" << j.first << "," << j.second << "), ";
            }
            cout << endl;
        }
    }
    void dfs(int i)
    {
        visited[i] = 1;
        for (auto j : adj[i])
        {
            if (visited[j.first] == 0)
            {
                dfs(j.first);
            }
        }
        stack.push(i);
    }
    void topo_sort()
    {
        for (int i = 0; i < adj.size(); i++)
        {
            if (visited[i] == 0)
            {
                dfs(i);
            }
        }
    }
    void shortestPath(int strt)
    {
        topo_sort();
        vector<int> dist(adj.size());
        for (int i = 0; i < adj.size(); i++)
        {
            dist[i] = INT_MAX;
        }
        dist[strt] = 0;
        while (!stack.empty())
        {
            int top = stack.top();
            stack.pop();
            if (dist[top] != INT_MAX)
            {

                for (auto j : adj[top])
                {
                    if (dist[top] + j.second < dist[j.first])
                    {
                        dist[j.first] = dist[top] + j.second;
                    }
                }
            }
        }
        for (int i = 0; i < dist.size(); i++)
        {
            cout << dist[i] << " ";
        }
    }
};

int main(int argc, char **argv)
{
    graph<int> g;
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);
    // g.printGraph();
    g.shortestPath(0);
    return 0;
}