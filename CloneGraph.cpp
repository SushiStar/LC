/*
 * Given a reference of a node in a connected undirected graph.
 * Return a deep copy (clone) of the graph.
 * Each node in the graph contains a val(int) and a list(List[Node])
 * of its neighbors.
 *
 * Date: 04/02/2020
 * Author: Wei Du
 */

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node *> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node *>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node *>();
    }

    Node(int _val, vector<Node *> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node *cloneGraph(Node *node) {
        if (!node) return nullptr;
        std::unordered_map<Node *, Node *> ori2new;
        std::deque<Node *> bfs{node};
        Node *curr{node};
        Node *currCopy = new Node(node->val);
        ori2new[curr] = currCopy;
        while (!bfs.empty()) {
            curr = bfs.front();
            bfs.pop_front();
            currCopy = ori2new[curr];

            // get successors
            for (auto nb : curr->neighbors) {
                if (ori2new.find(nb) == ori2new.end()) {
                    bfs.push_back(nb);
                    auto nbCopy = new Node(nb->val);
                    ori2new[nb] = nbCopy;
                }
                currCopy->neighbors.push_back(ori2new[nb]);
            }
        }
        return ori2new[node];
    }
};
