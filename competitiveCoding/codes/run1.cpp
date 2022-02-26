class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int x=0,y=0;
        int invalid =-10000;
        while(matrix[x][y]!=invalid){
            
//             move right
            for(;y<cols && matrix[x][y] != invalid;y++ ){
                ans.push_back(matrix[x][y]);
                matrix[x][y] = invalid;
            }
            y--;
            
            x++; // new line
//             move down
            for(;x<rows && matrix[x][y] != invalid;x++ ){
                ans.push_back(matrix[x][y]);
                matrix[x][y] = invalid;
            }
            x--;
            y--;
//              move left
            for(;y>=0 && matrix[x][y] != invalid;y-- ){
                ans.push_back(matrix[x][y]);
                matrix[x][y] = invalid;
            }
            y++;
            x--; // new line
            for(;x>=0 && matrix[x][y] != invalid;x-- ){
                ans.push_back(matrix[x][y]);
                matrix[x][y] = invalid;
            }
            x++;
            y++;
            
        }
    return ans;
    }
};