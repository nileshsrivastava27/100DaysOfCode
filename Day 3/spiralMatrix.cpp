#include<iostream>
#include<vector>
 using namespace std;

 
 
 class Solution {
    public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
 
    vector<int> v;
    
    int row=matrix.size();
    int col=matrix[0].size();
    
    int startingRow=0;
    int startingCol=0;
    int endingRow=row-1;
    int endingCol=col-1;
    int total=row*col;
    while(total>0){
        
        for(int i=startingCol; total>0 && i<=endingCol; i++){
            v.push_back(matrix[startingRow][i]);
            total--;
        }
        startingRow++;
        
        for(int i=startingRow; total>0 && i<=endingRow; i++){
            v.push_back(matrix[i][endingCol]);
            total--;
        }
        endingCol--;
        
        for(int i=endingCol; total>0 && i>=startingCol; i--){
            v.push_back(matrix[endingRow][i]);
            total--;
        }
        endingRow--;
        
        for(int i=endingRow; total>0 && i>=startingRow; i--){
            v.push_back(matrix[i][startingCol]);
            total--;
        }
        startingCol++;
        
    }
            return v;
}
};

int main(){
    return 0;

}