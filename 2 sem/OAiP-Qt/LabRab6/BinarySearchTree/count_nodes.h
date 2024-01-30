#ifndef COUNT_NODES_H
#define COUNT_NODES_H
#include <BinarySearchTree.h>

class variant9 : public BinarySearchTree
{

public:

    variant9() : BinarySearchTree(){}

    variant9(std::vector<std::pair<int, std::string>> temp_vec) : BinarySearchTree(temp_vec) {}

    ~variant9() {}

    int countNodesWithOneChild() {
        return help_countNodesWithOneChild(m_root);
    }

private:

    int help_countNodesWithOneChild(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        int count = 0;
        if ((node->left == nullptr && node->right != nullptr) || (node->left != nullptr && node->right == nullptr)) {
            count = 1;
        }
        return count + help_countNodesWithOneChild(node->left) + help_countNodesWithOneChild(node->right);
    }
};

#endif // COUNT_NODES_H
