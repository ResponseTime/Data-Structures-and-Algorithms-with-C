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
    unordered_map<T, T> parent;
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
    bool isCyclicDfs(int i, int par = -1)
    {
        visited[i] = 1;
        parent[i] = par;
        cout << i << ",";
        for (auto j : adj[i])
        {
            if (visited[j] == 0)
            {
                isCyclicDfs(j, i);
            }
            else if (visited[j] == 1 && j != parent[i])
            {
                return true;
            }
        }
        return false;
    }
    void isCyclic()
    {
        for (int i = 0; i < adj.size(); i++)
        {
            if (visited[i] != 1)
            {
                if (isCyclicDfs(i))
                {
                    cout << "Yes" << endl;
                }
                else
                {
                    cout << "No" << endl;
                }
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
    g.isCyclic();
    return 0;
}