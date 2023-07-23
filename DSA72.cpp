#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <set>
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
        adj[u].push_back(make_pair(v, weight));
        adj[v].push_back(make_pair(u, weight));
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

    void prims()
    {
        vector<int> key(adj.size() + 1);
        vector<int> parent(adj.size() + 1);
        vector<bool> mst(adj.size() + 1);
        for (int i = 0; i <= adj.size(); i++)
        {
            key[i] = INT_MAX;
            parent[i] = -1;
            mst[i] = false;
        }
        key[1] = 0;
        parent[1] = -1;

        for (int i = 1; i < key.size(); i++)
        {
            int min = INT_MAX;
            int u;
            for (int v = 1; v <= adj.size(); v++)
            {
                if (mst[v] == false && key[v] < min)
                {
                    u = v;
                    min = key[v];
                }
            }

            mst[u] = true;
            for (auto it : adj[u])
            {
                auto v = it.first;
                auto w = it.second;
                if (mst[v] == false && w < key[v])
                {
                    parent[v] = u;
                    key[v] = w;
                }
            }
        }
        vector<pair<pair<int, int>, int>> res;
        for (int i = 2; i < parent.size(); i++)
        {
            res.push_back({{parent[i], i}, key[i]});
        }
        for (const auto &elem : res)
        {
            int first_int1 = elem.first.first;
            int first_int2 = elem.first.second;
            int second_int = elem.second;

            cout << "First pair: (" << first_int1 << ", " << first_int2 << ") - Second integer: " << second_int << endl;
        }
    }
};
int main(int argc, char **argv)
{
    graph<int> g;
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 4, 3);
    g.addEdge(2, 5, 5);
    g.addEdge(2, 3, 8);
    g.addEdge(4, 5, 7);
    g.prims();
    return 0;
}