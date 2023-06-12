#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;
template <typename T>
class graph
{

public:
    unordered_map<T, list<T>> adj;
    T visited[10] = {0, 0, 0, 0, 0, 0};
    queue<int> q;
    void addEdge(T u, T v, bool direction)
    {
        adj[u].push_back(v);
        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    void printGraph()
    {
        for (auto i : adj)
        {
            cout << i.first << "-> ";
            for (auto j : i.second)
            {
                cout << j << ",";
            }
            cout << endl;
        }
    }
    void dfs(int i)
    {
        visited[i] = 1;
        cout << i << ",";
        for (auto j : adj[i])
        {
            if (visited[j] == 0)
            {
                dfs(j);
            }
        }
    }
    void dfs_print(int i)
    {
        for (int i = 0; i < adj.size(); i++)
        {
            if (visited[i] == 0)
            {
                dfs(i);
            }
        }
    }
};

int main(int argc, char **argv)
{
    graph<int> g;
    g.addEdge(0, 3, 0);
    g.addEdge(3, 1, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(4, 5, 0);
    g.addEdge(4, 6, 0);
    g.addEdge(6, 5, 0);
    g.printGraph();
    g.dfs_print(0);
    return 0;
}