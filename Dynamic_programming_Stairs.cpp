#include <iostream>
#include <vector>
using namespace std;

int max_sum(vector<int> &input) {

    int n = input.size();
    vector<int> D(n);
    D[0] = input[0];
    D[1] = max(input[0] + input[1], input[1]);
    for (int i = 2; i < n; ++i) {
        D[i] = max(D[i - 2], D[i - 1]) + input[i];
    }
    return D[n-1];
}



int main() {
    int n;
    cin >> n;
    vector<int> input(n);
    for (int i = 0; i < n; ++i) {
        cin >> input[i];
    }
    cout << max_sum(input);
    return 0;
}
