#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
using namespace std;
template <typename T>
class graph
{

public:
    unordered_map<T, list<T>> adj;
    T visited[10] = {0, 0, 0, 0, 0, 0};

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
    void find(int i, int data)
    {
        if (i == data)
        {
            cout << "Path Exists" << endl;
            return;
        }
        visited[i] = 1;
        for (auto j : adj[i])
        {
            if (visited[j] == 0)
            {
                find(j, data);
            }
        }
    }
};

int main(int argc, char **argv)
{
    graph<int> g;
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 1, 1);
    g.addEdge(3, 4, 1);
    g.find(3, 1);

    return 0;
}