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
    void dijkstra(int src)
    {
        vector<int> dist(adj.size() + 1);
        for (int i = 0; i < adj.size() + 1; i++)
        {
            dist[i] = INT_MAX;
        }
        set<pair<int, int>> st;
        dist[src] = 0;
        st.insert(make_pair(0, src));
        while (!st.empty())
        {
            auto top = *(st.begin());
            int topD = top.first;
            int topN = top.second;
            st.erase(st.begin());
            for (auto i : adj[topN])
            {
                if (dist[topN] != INT_MAX)
                {

                    if (topD + i.second < dist[i.first])
                    {
                        auto record = st.find(make_pair(dist[i.first], i.first));
                        if (record != st.end())
                        {
                            st.erase(record);
                        }
                        dist[i.first] = topD + i.second;
                        st.insert(make_pair(dist[i.first], i.first));
                    }
                }
            }
        }
        for (auto &i : dist)
        {
            cout << i << " ";
        }
    }
};

int main(int argc, char **argv)
{
    graph<int> g;
    g.addEdge(2, 1, 3);
    g.addEdge(2, 0, 1);
    g.addEdge(1, 4, 1);
    g.addEdge(1, 3, 5);
    g.addEdge(4, 3, 7);
    g.addEdge(0, 3, 2);
    g.addEdge(0, 1, 7);
    // g.addEdge(0, 1, 5);
    // g.addEdge(0, 2, 3);
    // g.addEdge(1, 2, 2);
    // g.addEdge(1, 3, 6);
    // g.addEdge(2, 3, 7);
    // g.addEdge(2, 4, 4);
    // g.addEdge(2, 5, 2);
    // g.addEdge(3, 4, -1);
    // g.addEdge(4, 5, -2);
    g.dijkstra(0);
    return 0;
}