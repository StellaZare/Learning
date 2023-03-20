#include <iostream>
#include <vector>

using namespace std;


vector<vector<int>> generate(int numRows) {
    vector<vector<int>> pascals;

    for(int currRow = 1; currRow <= numRows; currRow++){
        vector<int> rowList;

        for(int currIdx = 0; currIdx < currRow; currIdx++){
            if(currIdx == 0 || currIdx == currRow-1){
                rowList.push_back(1);
                continue;
            }
            vector<int> prevRow = pascals.back();
            rowList.push_back(prevRow[currIdx-1]+prevRow[currIdx]);
        }

        pascals.push_back(rowList);
    }

    return pascals;
}

void printPascals(vector<vector<int>> pascals){
    for(vector<int> row : pascals){
        for(int num : row){
            cout << num << " ";
        }
        cout << "\n";
    }
}

int main(){

    int rows = 15;

    vector<vector<int>> pascals = generate(rows);

    printPascals(pascals);

    return 0;
}