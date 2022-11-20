class Solution {
public:
void rotate(vector<int>& nums, int k) {
    if (k == 0) return;
    int l = 0, m = 0;
    int temp, init;
    while (m < nums.size()) {
        temp = nums[l];
        init = l;
        while (true) {
            l = (l + k) % nums.size();
            swap(temp, nums[l]);
            m++;
            if (l == init) break;
        }
            l++;
        }
    }
};
