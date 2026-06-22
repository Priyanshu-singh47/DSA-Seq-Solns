class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int row=0;int Col=m-1;
        while(row<n && Col>=0){
            if(matrix[row][Col]==target) return true;
            else if(matrix[row][Col]<target) row++;
            else Col--;
        }
        return false;
        
    }
};