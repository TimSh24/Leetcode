class Solution {
public:
   vector<int> sortArray(vector<int>& nums) {
        int q[nums.size()];
        for (int i=0; i<nums.size(); ++i) {
            q[i] = nums[i];
        }
        merge_sort(q, 0, nums.size()-1);
        for (int i=0; i<nums.size(); ++i) {
            nums[i] = q[i];
        }
        return nums;
    }
private:
    void merge(int* v, int left, int right, int mid) {
        int i = left, j = mid+1, t = 0;
        int c[right-left+1];
        while (i <= mid && j <= right) {
            if (v[i] <= v[j]) {
                c[t++] = v[i++];}
            else {
                c[t++] = v[j++];}
        }
        while (i <= mid) {
            c[t++] = v[i++];
        }

        while (j <= right) {
            c[t++] = v[j++];
        }
        while (--t >= 0) {
            v[right--] = c[t];
        }
    }
    void merge_sort(int* v, int left, int right) {
        if (left==right) {
            return;
        }
        int mid = left + (right - left) / 2;
        merge_sort(v, left, mid);
        merge_sort(v, mid + 1, right);
        merge(v, left, right, mid);
    }
};
