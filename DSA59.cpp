#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;
template <typename T>
class graph
{

public:
    unordered_map<T, list<T>> adj;
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
};
int main(int argc, char **argv)
{
    int n, m;
    cin >> n >> m;
    graph<int> g;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 0);
    }
    g.printGraph();
    return 0;
}