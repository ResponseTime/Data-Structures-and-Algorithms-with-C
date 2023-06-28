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
    stack<int> stack;
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
        stack.push(i);
    }
    void dfs_print()
    {
        for (int i = 1; i < adj.size(); i++)
        {
            if (visited[i] == 0)
            {
                dfs(i);
            }
        }
    }
    void topological_sort()
    {
        while (!stack.empty())
        {
            cout << stack.top() << ", ";
            stack.pop();
        }
    }
};

int main(int argc, char **argv)
{
    graph<int> g;
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(4, 5, 1);
    g.addEdge(5, 6, 1);
    g.addEdge(6, 7, 1);
    g.addEdge(4, 8, 1);
    // g.addEdge(5, 6, 1);
    g.printGraph();
    // g.dfs(1);
    g.dfs_print();
    cout << " " << endl;
    g.topological_sort();
    return 0;
}