#include <iostream>
#include "graph.hpp"

int main(){
    std::cout << "Enter the number of nodes: " << std::endl;
    int n = 0;
    std::cin >> n;
    if(n<1){
        std::cout << "Invalid Size" << std::endl;
        return 1;
    }
    graph my_graph(n);
    my_graph.get_mat();
    my_graph.print_mat();
    return 0;
}
