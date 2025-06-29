#include <exception>
#include <iostream>
#include <sys/types.h>

template <typename T>
class bst{
    private:
        class node{
           private:
               T data;
               node* leftchild;
               node* rightchild;
           public:
               node(){
                   try{
                       this->data = 0;
                   } catch (const std::exception& e){
                       std::cerr << e.what() << std::endl;
                       return;
                   }
                   this->leftchild = nullptr;
                   this->rightchild = nullptr;
               }
               node(T value){
                   this->data = value;
                   this->leftchild = nullptr;
                   this->rightchild = nullptr;
               }
               void update_data(T value){
                   this->data = value;
               }
               T get_data(){
                   return this->data;
               }
               node* get_leftchild(){
                   return this->leftchild;
               }
               node* get_rightchild(){
                   return this->rightchild;
               }
               void set_leftchild(node* p){
                   this->leftchild = p;
               }
               void set_rightchild(node* p){
                   this->rightchild = p;
               }
        };
        node* root = nullptr; 
    public:
        bst(node* root){
            this->root = root;
        }
        bst(T value){
            this->root = new node(value);
        }
        node* insert(node* current, node* new_node){
            if(!current){
                current = new_node;
                return current;
            }
            else{
                if(new_node->get_data() == current->get_data()){
                    std::cerr << "Duplicate Entry" << std::endl;
                    return current;
                }
                else if(new_node->get_data() < current->get_data()){
                    current->set_leftchild(insert(current->get_leftchild(), new_node));
                }
                else{
                    current->set_rightchild(insert(current->get_rightchild(), new_node));
                }
            }
            return current;
        }

        bool insert(T value){
            if(!this->root){
                std::cerr << "Error root does not exist." << std::endl;
            }
            node* new_node = new node(value);
            node* current = this->root;
            try{
                current = insert(current, new_node);
            }
            catch(std::exception e){
                std::cerr << e.what() << std::endl;
                return false;
            }
            return true;
        }
        void pre_order(node* current){
            if(!current){
                return;
            }
            std::cout << current->get_data() << " ";
            pre_order(current->get_leftchild());
            pre_order(current->get_rightchild());
        }
        void pre_order(){
            node* current = this->root;
            if(!current){
                return;
            }
            pre_order(current);
            std::cout << std::endl;
        }
};

int main(){
    bst<int>* t = new bst(6);
    t->insert(2);
    t->insert(8);
    t->insert(0);
    t->insert(9);
    t->insert(1);
    t->insert(7);
    t->insert(3);
    t->insert(13);
    t->insert(4);
    t->insert(6);
    t->insert(8);
    t->pre_order();
}
