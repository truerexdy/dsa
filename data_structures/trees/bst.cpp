#include <cmath>
#include <exception>
#include <iostream>
#include <sys/types.h>

template <typename T>
class bst{
    private:
        class node{
           private:
               T data;
               T* leftchild;
               T* rightchild;
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
        };
        node* root = nullptr;
    private:
        bst(node* root){
            this->root = root;
        }
        bst(T value){
            this->root = new node(value);
        }
    public:
        bool insert(){
};
