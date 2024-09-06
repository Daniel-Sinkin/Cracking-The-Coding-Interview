#ifndef GRAPH_H
#define GRAPH_H

#include "Constants.h"

class GraphNode {
private:
    int m_Val;
    vector<GraphNode *> m_Children;

public:
    GraphNode(int value) : m_Val(value) {}

    const vector<GraphNode *> &getChildren() const {
        return m_Children;
    }

    bool addEdge(GraphNode *child) {
        // Returns true if the edge was added, false else (which is the case when the edge already exists)
        for (GraphNode *registered_child : m_Children) {
            if (registered_child == child) {
                return false;
            }
        }
        m_Children.push_back(child);
        return true;
    }

    int getValue() const {
        return m_Val;
    }
};

class Graph {
private:
    vector<GraphNode *> m_Nodes;

public:
    Graph() : m_Nodes() {}

    const vector<GraphNode *> &getNodes() const {
        return m_Nodes;
    }

    const GraphNode *getNode(size_t idx) const {
        return m_Nodes[idx];
    }

    int getValue(size_t node_idx) {
        return m_Nodes[node_idx]->getValue();
    }

    bool addEdge(size_t idx1, size_t idx2) {
        return m_Nodes[idx1]->addEdge(m_Nodes[idx2]);
    }

    GraphNode *createNewNode(int value) {
        GraphNode *newNode = new GraphNode(value);
        m_Nodes.push_back(newNode);
        return newNode;
    }

    bool findBFS(size_t starting_idx, int value_to_find) const;
    bool findDFS(size_t starting_idx, int value_to_find) const;
};

#endif // GRAPH_H