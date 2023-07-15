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
    void kahn_algo()
    {
        int indeg[adj.size()] = {0, 0, 0, 0, 0, 0, 0, 0};
        queue<int> q;
        for (auto i : adj)
        {
            for (auto j : i.second)
            {
                indeg[j]++;
            }
        }
        for (int i = 0; i < adj.size(); i++)
        {
            if (indeg[i] == 0)
            {
                q.push(i);
            }
        }
        vector<int> ans;
        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            ans.push_back(front);
            for (auto j : adj[front])
            {
                indeg[j]--;
                if (indeg[j] == 0)
                {
                    q.push(j);
                }
            }
        }
        for (auto &i : ans)
        {
            cout << i << " ";
        }
    }
};

int main(int argc, char **argv)
{
    graph<int> g;
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 5, 1);
    g.addEdge(3, 5, 1);
    g.addEdge(5, 4, 1);
    g.kahn_algo();
    return 0;
}