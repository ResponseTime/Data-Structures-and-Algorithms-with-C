#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
template <typename T>
class graph
{

public:
    unordered_map<T, list<T>> adj;
    T visited[10] = {0, 0, 0, 0, 0, 0};
    queue<T> queue;
    unordered_map<int, int> parent;
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
        // for (auto i : adj)
        // {
        //     cout << i.first << "-> ";
        //     for (auto j : i.second)
        //     {
        //         cout << j << ",";
        //     }
        //     cout << endl;
        // }
        for (auto i : parent)
        {
            cout << i.first << "-> " << i.second << endl;
        }
    }
    void shortestPath(int strt, int end)
    {
        visited[strt] = 1;
        parent[strt] = -1;
        queue.push(strt);
        while (!queue.empty())
        {
            int fr = queue.front();
            queue.pop();
            for (auto j : adj[fr])
            {
                if (visited[j] == 0)
                {
                    visited[j] = 1;
                    parent[j] = fr;
                    queue.push(j);
                }
            }
        }
        vector<int> ans;
        int cur = end;
        ans.push_back(cur);
        while (cur != strt)
        {
            cur = parent[cur];
            ans.push_back(cur);
        }
        reverse(ans.begin(), ans.end());
        for (auto &j : ans)
        {
            cout << j << ",";
        }
    }
};

int main(int argc, char **argv)
{
    graph<int> g;
    g.addEdge(1, 2, 0);
    g.addEdge(2, 3, 0);
    g.addEdge(3, 5, 0);
    g.addEdge(5, 1, 0);
    g.shortestPath(3, 1);
    g.printGraph();
    return 0;
}