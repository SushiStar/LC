/*
 * Program to find Dijkstra's shortest path using
 * priority queue in STL.
 *
 * source code from web: 
 * https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-priority_queue-stl/
 *
 * Date: Mar/07/2019
 *
 */

#include <cstdlib>
#include <list>
#include <queue>
#include <functional>

using namespace std;

typedef pair<int,int> ipair; 

// This class represents a directed graph using adjacency list.
// adjacency list representation
class Graph{
    int V;  // No. of vertices

    // In a weighted graph we need to store vertex
    // and weight pair for every edge
    list<ipair>* adj;

public:  
    Graph(int V);

    // function to add an edge to the graph
    void addEdge(int u, int v, int w);

    // prints shortest path from s
    void shortestPath(int s);
};

// allocates memory for adjacency list
Graph::Graph(int V) {
    this->V = V;
    adj = new list<ipair>[V];
}
void Graph::addEdge(int u, int v, int w) {
    adj[u].push_back(make_pair(v,w));
    adj[v].push_back(make_pair(u,w));
}

// print shortest path from src to all vertices
void Graph::shortestPath(int s) {
    priority_queue<ipair, vector<ipair>, greater<ipair>> pq;
    vector<int> dist(V,INT_MAX);
    
    pq.push(make_pair(0,s));
    dist[s] = 0;

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        list<ipair>::iterator i;
        for(i = adj[u].begin(); i!= adj[u].end(); ++i) {
            int v = (*i).first;
            int w = (*i).second;

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    printf("Vertex distance from %d.\n", s);
    for (int i=0; i < V; ++i) 
        printf("%d \t\t %d\n", i, dist[i]);
}

int main() {
    // create the graph given in above fugure
    int V = 9;
    Graph g(V);

    //  making above shown graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    g.shortestPath(0);

    return 0;
}
