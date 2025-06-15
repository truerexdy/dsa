#include <iostream>

class disjoint_sets{
    private:
        int* in_mst;
        int* not_mst;
        int size = 0;

    public:
        disjoint_sets(){
            this->size = 32;
            in_mst = new int[this->size];
            not_mst = new int[this->size];
        }
        disjoint_sets(int n){
            this->size = n;
            in_mst = new int[this->size];
            not_mst = new int[this->size];
        }
        bool add_to_set
};
