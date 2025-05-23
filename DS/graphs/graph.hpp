#include <iostream>

class graph{
    private:
    int* visited;
    int size = 10;

    public:
    int** array;
    graph(int size){
        if(size > 0){
            this->size = size;
            this->array = new int*[this->size];
            for(int i=0; i<size; i++){
                this->array[i] = new int[size]; 
            }
        }
        this->visited = new int[this->size];
    }

    int get_size(){
        return this->size;
    }

    void print_mat(){
        std::cout << "Adjacency Matrix" << std::endl;
        for(int i=0; i<this->size; i++){
            for(int j=0; j<this->size; j++){
                std::cout << this->array[i][j] << "\t";
            }
            std::cout << std::endl;
        }
    }

    void get_mat(){
        std::cout << "Enter the Adjacency Matrix:" << std::endl;
        for(int i=0; i<this->size; i++){
            for(int j=0; j<this->size; j++){
                std::cin >> this->array[i][j];
            }
            std::cout << std::endl;
        }
    }    

    void dfs(int v){
        if(v >= this->size){
            return;
        }
        std::cout << v << std::endl;
        this->visited[v] = 1;
        for(int i=0; i<this->size; i++){
            if(this->array[v][i] == 1 && this->visited[i] != 1){
                this->dfs(i);
            }
        }
    }
};
