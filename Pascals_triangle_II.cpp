class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> previous={1,1};
        vector<int> current;
        for (int i=0; i<=rowIndex; i++) {
                current.resize(i+1);
                current[0] = current[i] = 1;
                for (int j = 1; j<=i/2; j++) {
                    current[j] = current[i-j] = previous[j-1] + previous[j];
                }
            previous = current;
            }
        return current;
    }
};
