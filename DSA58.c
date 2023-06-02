#include <stdio.h>

int main(int argc, char **argv)
{

    return 0;
}

// prims algorithm
// start with any node
// mantain a set of non mst nodes and mst nodes
// find the minimum edge from starting node to next node
// add that node to mst set and remove from non mst set
// do this until all nodes are in mst set