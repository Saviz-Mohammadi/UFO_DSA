#ifndef _AVL_
#define _AVL_

#include <iostream>
#include <iomanip> // for std::setw
#include <queue>

namespace ufo
{
    template <typename T>
    class AVLTree {
    private:
        struct Node {
            T data;
            Node* left;
            Node* right;
            int height;

            Node(const T& value) : data(value), left(nullptr), right(nullptr), height(1) {}
        };

        Node* root;

        int height(Node* node) {
            return node ? node->height : 0;
        }

        int getBalance(Node* node) {
            return node ? height(node->left) - height(node->right) : 0;
        }

        Node* rotateRight(Node* y) {
            Node* x = y->left;
            Node* T2 = x->right;

            x->right = y;
            y->left = T2;

            y->height = std::max(height(y->left), height(y->right)) + 1;
            x->height = std::max(height(x->left), height(x->right)) + 1;

            return x;
        }

        Node* rotateLeft(Node* x) {
            Node* y = x->right;
            Node* T2 = y->left;

            y->left = x;
            x->right = T2;

            x->height = std::max(height(x->left), height(x->right)) + 1;
            y->height = std::max(height(y->left), height(y->right)) + 1;

            return y;
        }

        Node* insert(Node* node, const T& data) {
            if (!node)
            return new Node(data);

            if (data < node->data)
            node->left = insert(node->left, data);
        else if (data > node->data)
            node->right = insert(node->right, data);
        else
            return node;

            node->height = 1 + std::max(height(node->left), height(node->right));
            int balance = getBalance(node);

            // Balance checks
            if (balance > 1 && data < node->left->data)
            return rotateRight(node);

            if (balance < -1 && data > node->right->data)
            return rotateLeft(node);

            if (balance > 1 && data > node->left->data) {
                node->left = rotateLeft(node->left);
                return rotateRight(node);
            }

            if (balance < -1 && data < node->right->data) {
                node->right = rotateRight(node->right);
                return rotateLeft(node);
            }

            return node;
        }

        Node* minValueNode(Node* node) {
            Node* current = node;
            while (current->left)
            current = current->left;
        return current;
        }

        Node* deleteNode(Node* root, const T& data) {
            if (!root)
            return root;

            if (data < root->data)
            root->left = deleteNode(root->left, data);
        else if (data > root->data)
            root->right = deleteNode(root->right, data);
        else {
                if (!root->left || !root->right) {
                    Node* temp = root->left ? root->left : root->right;
                    if (!temp) {
                        temp = root;
                        root = nullptr;
                    } else {
                        *root = *temp;
                    }
                    delete temp;
                } else {
                    Node* temp = minValueNode(root->right);
                    root->data = temp->data;
                    root->right = deleteNode(root->right, temp->data);
                }
            }

            if (!root)
            return root;

            root->height = 1 + std::max(height(root->left), height(root->right));
            int balance = getBalance(root);

            // Balance checks
            if (balance > 1 && getBalance(root->left) >= 0)
            return rotateRight(root);

            if (balance > 1 && getBalance(root->left) < 0) {
                root->left = rotateLeft(root->left);
                return rotateRight(root);
            }

            if (balance < -1 && getBalance(root->right) <= 0)
            return rotateLeft(root);

            if (balance < -1 && getBalance(root->right) > 0) {
                root->right = rotateRight(root->right);
                return rotateLeft(root);
            }

            return root;
        }

        void inOrder(Node* root) const {
            if (root) {
                inOrder(root->left);
                std::cout << root->data << " ";
                inOrder(root->right);
            }
        }

        void preOrder(Node* root) const {
            if (root) {
                std::cout << root->data << " ";
                preOrder(root->left);
                preOrder(root->right);
            }
        }

        void postOrder(Node* root) const {
            if (root) {
                postOrder(root->left);
                postOrder(root->right);
                std::cout << root->data << " ";
            }
        }

        void levelOrder(Node* root) const {
            if (!root) return;
        std::queue<Node*> q;
            q.push(root);
            while (!q.empty()) {
                Node* node = q.front();
                q.pop();
                std::cout << node->data << " ";
                if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        }

        int maxDepth(Node* node) const {
            if (!node) return 0;
        return 1 + std::max(maxDepth(node->left), maxDepth(node->right));
        }

        void destroyTree(Node* node) {
            if (node) {
                destroyTree(node->left);
                destroyTree(node->right);
                delete node;
            }
        }

    public:
        AVLTree() : root(nullptr) {}

        ~AVLTree() {
            destroyTree(root);
        }

        void insert(const T& data) {
            root = insert(root, data);
        }

        void remove(const T& data) {
            root = deleteNode(root, data);
        }

        bool isEmpty() const {
            return root == nullptr;
        }

        int depth() const {
            return maxDepth(root);
        }

        void printInOrder() const {
            inOrder(root);
            std::cout << std::endl;
        }

        void printPreOrder() const {
            preOrder(root);
            std::cout << std::endl;
        }

        void printPostOrder() const {
            postOrder(root);
            std::cout << std::endl;
        }

        void printLevelOrder() const {
            levelOrder(root);
            std::cout << std::endl;
        }

        // Comparison operators (for equality of trees)
        bool operator==(const AVLTree& other) const {
            return compareTrees(root, other.root);
        }

        bool operator!=(const AVLTree& other) const {
            return !(*this == other);
        }

        void printTree() const {
            if (root == nullptr) {
                std::cout << "(empty tree)" << std::endl;
                return;
            }

            std::queue<std::pair<Node*, int>> q;
            int current_level = 0;

            q.push({root, 0});
            while (!q.empty()) {
                auto [node, level] = q.front();
                q.pop();

                if (level != current_level) {
                    std::cout << "\n"; // Start a new line for each new level
                    current_level = level;
                }

                // Print node with some spacing
                if (node) {
                    std::cout << std::setw(4) << node->data;
                    q.push({node->left, level + 1});
                    q.push({node->right, level + 1});
                } else {
                    // Print spacing for null nodes to maintain tree structure
                    std::cout << "    ";
                }
            }
            std::cout << "\n"; // Final newline at end of tree
        };

        // Stream operators for input and output
        friend std::ostream& operator<<(std::ostream& os, const AVLTree& tree) {
            tree.inOrder(tree.root);
            return os;
        }

        friend std::istream& operator>>(std::istream& is, AVLTree& tree) {
            T value;
            while (is >> value) {
                tree.insert(value);
            }
            return is;
        }

    private:
        // Utility function to compare trees
        bool compareTrees(Node* a, Node* b) const {
            if (!a && !b) return true;
        if (a && b && a->data == b->data)
            return compareTrees(a->left, b->left) && compareTrees(a->right, b->right);
        return false;
        }
    };
}


#endif // _AVL_
