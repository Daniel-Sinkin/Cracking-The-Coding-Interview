#include "graph.h"

bool Graph::findBFS(size_t starting_idx, int value_to_find) const {
    unordered_set<const GraphNode *> seen_nodes;
    queue<const GraphNode *> nodes_to_visit;

    const GraphNode *first_node = this->getNode(starting_idx);
    nodes_to_visit.push(first_node);
    seen_nodes.insert(first_node);

    while (!nodes_to_visit.empty()) {
        const GraphNode *current_node = nodes_to_visit.front();
        nodes_to_visit.pop();

        if (current_node->getValue() == value_to_find) {
            return true;
        }

        for (GraphNode *const &child : current_node->getChildren()) {
            bool child_was_seen = seen_nodes.find(child) != seen_nodes.end();
            if (!child_was_seen) {
                seen_nodes.insert(child);

                nodes_to_visit.push(child);
            }
        }
    }
    return false;
}

bool Graph::findDFS(size_t starting_idx, int value_to_find) const {
    unordered_set<const GraphNode *> seen_nodes;

    stack<const GraphNode *> nodes_to_visit;

    const GraphNode *starting_node = getNode(starting_idx);
    nodes_to_visit.push(starting_node);
    seen_nodes.insert(starting_node);

    while (!nodes_to_visit.empty()) {
        const GraphNode *current_node = nodes_to_visit.top();
        nodes_to_visit.pop();

        if (current_node->getValue() == value_to_find) {
            return true;
        }

        for (GraphNode *const &child : current_node->getChildren()) {
            bool child_not_seen = seen_nodes.find(child) == seen_nodes.end();
            if (child_not_seen) {
                seen_nodes.insert(child);
                nodes_to_visit.push(child);
            }
        }
    }
    return false;
}
