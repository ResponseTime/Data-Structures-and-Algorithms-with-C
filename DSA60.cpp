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
    void bfs(int i)
    {
        cout << i << ",";
        visited[i] = 1;
        q.push(i);
        while (!q.empty())
        {
            int n = q.front();
            q.pop();
            for (auto j : adj[n])
            {
                if (visited[j] == 0)
                {
                    cout << j << ",";
                    visited[j] = 1;
                    q.push(j);
                }
            }
        }
    }
    void bfs_print()
    {
        for (int i = 0; i < adj.size(); i++)
        {
            if (visited[i] != 1)
            {
                bfs(i);
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
    g.addEdge(4, 4, 0);
    g.printGraph();
    g.bfs_print();
    return 0;
}