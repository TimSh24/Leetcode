class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size()-1, m = matrix[0].size()-1;
        int k = 0, i = 0, j = 0;
        int upperBound = 0, lowerBound = n, leftBound = 0, rightBound = m;
        vector<int> answer((m+1)*(n+1));
        while (k < (m+1)*(n+1)) {
            if (i == upperBound+1 && j == leftBound) {
                if (upperBound < lowerBound-1) upperBound++;
                if (rightBound > leftBound+1) rightBound--;
                if (lowerBound > upperBound+1 && m!=0) lowerBound--;
                if (leftBound < rightBound-1) leftBound++;
            }
            answer[k] = matrix[i][j];
            if (i == upperBound && j < rightBound) j++;
            else if (i == lowerBound && j > leftBound) j--;
            else if (j == leftBound && i > upperBound) i--;
            else if (j == rightBound && i < lowerBound) i++;
            k++;
        }
        return answer;
    }
};
