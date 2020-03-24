/*
 * There are n servers numbered from 0 to n-1 connected by undirected
 * server-to-server connections forming a network where connections[i] = [a][b]
 * represents a connection between servers a and b. Any server can reach any
 * other server directly or indirectly through the network. A Critical
 * connection is a connection that, if removed, will make some server unable to
 * reach some other server. Return all critical connection in the network in any
 * order.
 *
 * Date: 03/24/2020
 * Author: Wei Du
 */

class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        if (n < 2) return connections;
        std::vector<std::vector<int>> result{};
    
        // initialize
        std::vector<vertex*> vertices(n, nullptr);
        for (int i = 0; i < n; ++i) 
            vertices[i] = new vertex(i);
        int idx = 0;
        for (auto &edge : connections) {
            auto v0 = vertices[edge[0]];
            auto v1 = vertices[edge[1]];
            v0->neighbors.push_back(v1);
            v1->neighbors.push_back(v0);
            v0->edgePtr.push_back(idx);
            v1->edgePtr.push_back(idx);
            ++idx;
        }
        vertices[0]->timeStamp = 0;
        dfs(vertices[0], nullptr, connections);
        
        for (auto &edge : connections) {
            if (edge.size() == 2){ 
                result.push_back(edge);
            }
        }
        
        return result;
    }
private:
    struct vertex {
        vertex(int val_) : val(val_), timeStamp(-1), neighbors(){}
        int val;
        int timeStamp;
        std::vector<vertex*> neighbors;
        std::vector<int> edgePtr;
    };
    
    int dfs(vertex* curr, vertex* parent, vector<vector<int>>& connections) {
        
        int result{curr->timeStamp};
        for (int i = 0; i < curr->neighbors.size(); ++i){
            auto nb = curr->neighbors[i];
            if (nb == parent) continue;
            int circle {INT_MAX};
            if (nb->timeStamp == -1){ 
                nb->timeStamp = curr->timeStamp +1;
                circle = dfs(nb, curr, connections);
            } else {
                circle = nb->timeStamp;
            }
            if (circle <= curr->timeStamp) {
                // remove edge mark [curr, nb] / [nb, curr];
                connections[curr->edgePtr[i]].push_back(-1);
                result = std::min(result, circle);
            } 
        }
        return result;
    }
};
