#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> v;
    sort(v.begin(), v.end());
    return v;    
}

void printVector(vector<int> v){
    cout << "[";
  
    for(int n : v){
        cout << n << " ";
    }
    cout << "]\n";
}

void printNestedVector(vector<vector<int>> vn){
    for(vector<int> v : vn){
        printVector(v);
    }
}

int main(){
    vector<int> list1 = {-1,0,1,2,-1,-4};
    vector<vector<int>> listNested = {list1, list1};

    return 0;
}