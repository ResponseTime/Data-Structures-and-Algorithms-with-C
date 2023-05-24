#include <stdio.h>

int main(int argc, char **argv)
{

    return 0;
}
// bfs traversal

// method 1
// bfs spanning tree
// consider a graph
// take any node
// construct a tree with the nodes
// dash all the sideways edges and duplicate edges
// this constructed tree is called bfs spanning tree
// level order traversal of a bfs spanning tree is a valid bfs traversal graph

// method 2
// vist all the nodes in the graph enqueue them
// keep nodes for exploration