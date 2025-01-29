#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using std::cin, std::cout, std::vector, std::string, std::find;

int main(){
    vector<int> nums;
    cout << "Enter the elements:(q to stop):\n";
    string usrin;
    for(int i=0; i<5;i++){
        cin >> usrin;
        nums.push_back(stoi(usrin));
    }
    vector<int> top3;
    for(int j=0; j<3; j++){
        int highest = nums[0];
        for(int i=0; i<nums.size(); i++){
            if(highest < nums[i]){
                highest = nums[i];
            }
        }
        top3.push_back(highest);
        nums.erase(find(nums.begin(), nums.end(), highest));
    }
    for(int i=0; i<3; i++){
        cout << top3[i] << " ";
    }
}