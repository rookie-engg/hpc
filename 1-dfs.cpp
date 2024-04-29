#include <bits/stdc++.h>
#include <omp.h>

using namespace std;

class Graph
{
public:
    map<int, bool> visited;
    map<int, list<int>> adj;
    // functiontoaddanedgetograph
    void addEdge(int v, int w);
    // DFStraversaloftheverticesreachablefromv
    void DFS(int v);
};
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Addwtov’slist.
}
void Graph::DFS(int v)
{
#pragma omp parallel
    // Markthecurrentnodeasvisitedandprintit
    visited[v] = true;
    cout << v << "";
    list<int>::iterator i; // Recurforalltheverticesadjacenttothisvertex
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        if (!visited[*i])
            DFS(*i);
    }
}
int main()
{
    omp_set_num_threads(4);
    int z;
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(2, 6);
    cout << "Enter the vertex to start the DFS traversal with:" << endl;
    cin >> z;
    cout << "\nDepth First Traversal:\n";
    g.DFS(z);
    cout << endl;
    return 0;
}