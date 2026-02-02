#include <iostream>
#include <vector>

using namespace std;

void MakeSet(int i, int *p, int *r) {
    p[i] = i;
    r[i] = 0;
}
int Find(int i, int* p) {
    if (i != p[i]) {
        p[i] = Find(p[i], p);
    }
    return p[i];
}
void Union(int i, int j, int *p, int *r) {
    int i_id = Find(i, p);
    int j_id = Find(j, p);
    if (i_id == j_id) {
        return;
    }
    if (r[i_id] > r[j_id]) {
        p[j_id] = i_id;
    }
    else {
        p[i_id] = j_id;
        if (r[i_id] == r[j_id]) {
            r[j_id] += 1;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    int input[n+1];
    int parent[n+1];
    int max = 0;
    for (int i = 1; i <= n; ++i) {
        int r;
        cin >> r;
        input[i] = r;
        if (r > max) max = r;
        parent[i] = i;
    }

    for (int k = 1; k <= m; ++k) {
            int i, j;
            cin >> i >> j;
            auto q = Find(i, parent);
            auto l = Find(j, parent);
            if (q != l) {
                input[q] += input[l];
                parent[l] = q;
                if (input[q] > max) {
                    max = input[q];
                }
            }
            cout << max << endl;
        }
    return 0;
}
