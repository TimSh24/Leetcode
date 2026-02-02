#include <iostream>
#include <queue>

using namespace std;

struct package {
    int arrival;
    int duration;
    int begin_proc;
    int number;
};

int main() {
    queue<package> input, buffer;
    int size, n;
    cin >> size >> n;
    vector<int> z(n+1);
    for (int i = 1; i <= n; ++i) {
        package a;
        cin >> a.arrival >> a.duration;
        a.begin_proc = a.arrival;
        a.number = i;
        input.push(a);
    }
    for (int j = 0; j < min(n,size); j++) {
        auto m = input.front();
        buffer.push(m);
        input.pop();
    }
    while (buffer.size() > 0) {
        auto k = buffer.front();
        int proc_end = k.begin_proc + k.duration;
        z[k.number] = k.begin_proc;
        buffer.pop();
        buffer.front().begin_proc = max(proc_end, buffer.front().begin_proc);
        while(input.front().arrival < proc_end && !input.empty()) {
            auto k = input.front();
            z[k.number] = -1;
            input.pop();
        }
        if (!input.empty()) {
            auto k = input.front();
            buffer.push(k);
            input.pop();
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << z[i] << '\n';
    }
    return 0;
}
