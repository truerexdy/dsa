#include <iostream>
#include <vector>
#include <chrono>
#include <random>

bool merge(std::vector<int>* array, int l, int m, int h){
    if(!array){
        return false;
    }
    std::vector<int> left;
    std::vector<int> right;

    for(int i=l; i<m; i++){
        left.push_back((*array)[i]);
    }
    for(int i=m; i<h+1; i++){
        right.push_back((*array)[i]);
    }
    
    int i=0;
    int j=0;
    int k=0;

    while(l+i < m && m+j < h+1){
        if(left[i]<=right[j]){
            (*array)[l+k] = left[i];
            i++;
            k++;
        }
        else{
            (*array)[l+k] = right[j];
            j++;
            k++;
        }
    }
    
    while(l+i < m ) {
        (*array)[l+k] = left[i];
        i++;
        k++;
    }
    while(m+j < h+1){
        (*array)[l+k] = right[j];
        j++;
        k++;
    }

    return true;
}

bool merge_sort(std::vector<int>* array, int l, int h){
    if(!array){
        return false;
    }
    int m = l + ((h-l)/2);
    if(l<h){
        merge_sort(array, l, m);
        merge_sort(array, m+1, h);
    }
    merge(array, l, m, h);
    return true;
}

int main() {
    int n;

    std::cout << "Enter the size of the vector (n): ";
    std::cin >> n;

    if (n < 0) {
        std::cerr << "Error: Vector size cannot be negative. Exiting." << std::endl;
        return 1;
    }

    std::vector<int> myVector(n);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, n);

    for (int i = 0; i < n; ++i) {
        myVector[i] = distrib(gen);
    }

    auto startTime = std::chrono::high_resolution_clock::now();

    merge_sort(&myVector, 0, myVector.size());

    auto endTime = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);

    std::cout << "\nResultant vector (first 10 elements or fewer if n is small):" << std::endl;
    int sampleSize = 10;
    for (int i = 0; i < std::min(n, sampleSize); ++i) {
        std::cout << myVector[i] << (i == std::min(n, sampleSize) - 1 ? "" : ", ");
    }
    if (n > sampleSize) {
        std::cout << " ... (and " << (n - sampleSize) << " more elements)";
    }
    std::cout << std::endl;

    std::cout << "\nExecution time: " << duration.count() << " microseconds" << std::endl;

    return 0;
}
