#include <iostream>
#include <algorithm> 
#include <queue>     
#include <limits>    
#include <ios>       




class avl_tree {
private:
    
    class node {
    public:
        int key; 
        node* left;  
        node* right; 
        int height;
        node(int key) {
            this->key = key;
            this->left = nullptr;
            this->right = nullptr;
            this->height = 1; 
        }

        ~node() {
            
        }
    };

public:
    node* root; 

    avl_tree() : root(nullptr) {}

    avl_tree(int key) {
        this->root = new node(key);
    }

    
    int getHeight(node* n) {
        if (n == nullptr) {
            return 0;
        }
        return n->height;
    }

    void updateHeight(node* n) {
        if (n != nullptr) {
             n->height = 1 + std::max(getHeight(n->left), getHeight(n->right));
        }
    }

    int getBalanceFactor(node* n) {
        if (n == nullptr) {
            return 0;
        }
        return getHeight(n->left) - getHeight(n->right);
    }
  
    node* leftRotate(node* y) {
        node* x = y->right; 
        node* T2 = x->left; 
        x->left = y;
        y->right = T2;
        updateHeight(y);
        updateHeight(x);
        return x;
    }

    node* rightRotate(node* x) {
        node* y = x->left;  
        node* T2 = y->right;
        y->right = x;
        x->left = T2;
        updateHeight(x);
        updateHeight(y);
        return y;
    }

    node* lrRotate(node* z) {
        z->left = leftRotate(z->left);        
        return rightRotate(z);
    }

    node* rlRotate(node* z) {
        z->right = rightRotate(z->right);
        return leftRotate(z);
    }

    
    
    node* insert_recursive(node* node, int key) {
        
        if (node == nullptr) {
            return new node(key);
        }

        if (key < node->key) {
            node->left = insert_recursive(node->left, key);
        } else if (key > node->key) {
            node->right = insert_recursive(node->right, key);
        } else {
            
            std::cout << "Warning: Duplicate key " << key << " not inserted." << std::endl;
            return node;
        }

        
        updateHeight(node);

        
        int balance = getBalanceFactor(node);

        

        
        if (balance > 1 && key < node->left->key) {
            return rightRotate(node);
        }

        
        if (balance < -1 && key > node->right->key) {
            return leftRotate(node);
        }

        
        if (balance > 1 && key > node->left->key) {
            
            node->left = leftRotate(node->left); 
            return rightRotate(node);            
        }

        
        if (balance < -1 && key < node->right->key) {
            
            node->right = rightRotate(node->right); 
            return leftRotate(node);                
        }

        
        return node;
    }

    
    void insert(int key) {
        root = insert_recursive(root, key);
    }

    
    void inorder_display(node* node) {
        if (node != nullptr) {
            inorder_display(node->left);
            std::cout << node->key << " ";
            inorder_display(node->right);
        }
    }

    
    void display_level_order() {
        if (root == nullptr) {
            std::cout << "Tree is empty." << std::endl;
            return;
        }

        std::queue<node*> q;
        q.push(root);

        std::cout << "AVL tree (level by level):" << std::endl;

        while (!q.empty()) {
            int levelSize = q.size(); 

            
            for (int i = 0; i < levelSize; ++i) {
                node* currentNode = q.front();
                q.pop();

                std::cout << currentNode->key << " ";

                
                if (currentNode->left != nullptr) {
                    q.push(currentNode->left);
                }

                
                if (currentNode->right != nullptr) {
                    q.push(currentNode->right);
                }
            }
            std::cout << std::endl; 
        }
    }


    
    void delete_recursive(node* node) {
        if (node == nullptr) {
            return;
        }
        delete_recursive(node->left);
        delete_recursive(node->right);
        
        delete node;
    }

    
    ~avl_tree() {
        delete_recursive(root);
        root = nullptr; 
    }
};


int main() {
    avl_tree tree;
    int choice;
    int key;

    do {
        std::cout << "\nAVL Tree Menu:\n";
        std::cout << "1. Insert Element\n";
        std::cout << "2. Display Tree (Level by Level)\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";

        
        std::cin >> choice;

        
        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear(); 
            
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue; 
        }

        switch (choice) {
            case 1:
                std::cout << "Enter element to insert: ";
                std::cin >> key;
                if (std::cin.fail()) {
                    std::cout << "Invalid input. Please enter an integer.\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                } else {
                    tree.insert(key);
                    std::cout << key << " inserted.\n";
                }
                break;
            case 2:
                tree.display_level_order();
                break;
            case 3:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
