#include <iostream>
#include <vector>
#include <set>

using namespace std;

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

vector<vector<int>> threeSum(vector<int>& nums) {
    set<vector<int>> v;
    sort(nums.begin(), nums.end());

    for(int currIdx = 0; currIdx < nums.size(); currIdx++){
        int leftIdx = currIdx + 1;
        int rightIdx = nums.size() - 1;

        while(leftIdx <  rightIdx){
            int sum = nums[currIdx] + nums[leftIdx] + nums[rightIdx];
            if (sum == 0){
                vector<int> tuple = {nums[currIdx], nums[leftIdx], nums[rightIdx]};
                v.insert(tuple);
                leftIdx++;
                rightIdx--;
            }
            else if(sum < 0){
                leftIdx++;
            }else{
                rightIdx--;
            }
        }
    }
    vector<vector<int>> output;
    for(vector<int> tuple :v){
        output.push_back(tuple);
    }
    return output;    
}

int main(){
    vector<int> list1 = {-1,0,1,2,-1,-4};
    vector<vector<int>> listNested = threeSum(list1);

    printNestedVector(listNested);
    return 0;
}