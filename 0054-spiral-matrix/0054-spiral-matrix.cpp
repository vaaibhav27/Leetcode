class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int srow = 0, erow = n-1;
        int scol = 0, ecol = m-1;
        vector<int> arr;
        while(srow<=erow && scol <= ecol){
            for(int j = scol; j<=ecol; j++){
                arr.push_back(matrix[srow][j]);
            }
            for(int i = srow + 1; i<=erow; i++){
                arr.push_back(matrix[i][ecol]);
            }
            for(int j = ecol - 1; j>=scol; j--){
                if(srow == erow) break;
                arr.push_back(matrix[erow][j]);
            }
            for(int i = erow-1; i>=srow+1; i--){
                if(scol == ecol) break;
                arr.push_back(matrix[i][scol]);
            }
            srow++; erow--; scol++; ecol--;
        }
        return arr;
    }
};