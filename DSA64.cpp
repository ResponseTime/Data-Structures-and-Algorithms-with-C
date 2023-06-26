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
    int cycleCount = 0;
    T visited[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    unordered_map<T, bool> dfs_visited;
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
    bool dfs(int i)
    {
        visited[i] = 1;
        dfs_visited[i] = true;
        for (auto j : adj[i])
        {
            if (visited[j] == 0)
            {
                bool ch = dfs(j);
                if (ch == true)
                {
                    return true;
                }
            }
            else if (visited[j] == 1 && dfs_visited[j] == true)
            {
                return true;
            }
        }
        dfs_visited[i] = false;
        return false;
    }
    void isCyclic()
    {
        for (int i = 0; i < adj.size(); i++)
        {
            if (visited[i] == 0)
            {
                bool ch = dfs(i);
                if (ch == true)
                {
                    cycleCount++;
                    cout << "Cyclic" << endl;
                }
            }
        }
    }
};

int main(int argc, char **argv)
{
    graph<int> g;
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(2, 4, 1);
    g.addEdge(4, 5, 1);
    g.addEdge(5, 6, 1);
    g.addEdge(6, 4, 1);
    g.addEdge(3, 9, 1);
    g.addEdge(9, 8, 1);
    g.addEdge(8, 3, 1);

    g.printGraph();
    g.isCyclic();
    cout << g.cycleCount << endl;
    return 0;
}