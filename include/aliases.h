#ifndef ALIASES_H
#define ALIASES_H

#include <memory>
#include <vector>

using std::make_unique;
using std::unique_ptr;
using std::vector;

class Node;
class TreeNode;

using UP_Node = std::unique_ptr<Node>;
using UP_TreeNode = std::unique_ptr<TreeNode>;

#endif // ALIASES_H