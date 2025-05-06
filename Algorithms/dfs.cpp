#include <iostream>

class graph{

    int** array;
    int size = 10;

    int* visited;
    int* queue;

    graph(int size){
        if(size > 0){
            this->size = size;
            this->array = new int*[this->size];
            for(int i=0; i<size; i++){
                this->array[i] = new int[size]; 
            }
        }
        this->visited = new int[this->size];
        this->queue = new int[this->size];
    }
    
    void print_mat(){
        for(int i=0; i<this->size; i++){
            for(int j=0; j<this->size; j++){
                std::cout << this->array[i][j] << "\t";
            }
            std::cout << std::endl;
        }
    }

    void take_input(){
        std::cout << "Enter the Adjacency Matrix: " << std::endl;
        for(int i=0; i<this->size; i++){
            for(int j=0; j<this->size; j++){
                std::cin >> this->array[i][j];
                std::cout << "\t";
            }
            std::cout << std::endl;
        }
        this->print_mat();
    }

};
