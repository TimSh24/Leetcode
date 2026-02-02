#include <iostream>
#include <queue>

using namespace std;

class Priority_queue_int {
public:
    Priority_queue_int() {}
    ~Priority_queue_int() {}

    void Insert(int p) {
        H.push_back(p);
        SiftUp(H.size()-1);
    }
    int ExtractMin() {
        int result = H[0];
        H[0] = H[H.size()-1];
        H.pop_back();
        SiftDown(0);
        return result;
    }
    int Front() {
        return H[0];
    }
    void Remove(int i) {
        H[i] = std::numeric_limits<int>::infinity();
        SiftUp(i);
        ExtractMin();
    }
    void Print() {
        for (auto i : H) {
            cout << i << ' ';
        }
        cout << endl;
    }
    bool Empty() {
        return H.empty();
    }
private:
    int Parent(int i) {
        return (i - 1) / 2;
    }
    int Lch(int i) {
        return 2 * i + 1;
    }
    int Rch(int i) {
        return 2 * i + 2;
    }
    void SiftUp(int i) {
        while (i > 0 && H[Parent(i)] > H[i]) {
            swap(H[Parent(i)], H[i]);
            i = Parent(i);
        }
    }
    void SiftDown(int i) {
        int maxindex = i;
        int l = Lch(i);
        if (l < H.size() && H[l] < H[maxindex]) {
            maxindex = l;
        }
        int r = Rch(i);
        if (r < H.size() && H[r] < H[maxindex]) {
            maxindex = r;
        }
        if (i != maxindex) {
            swap(H[i], H[maxindex]);
            SiftDown(maxindex);
        }

    }
    vector<int> H;
};

struct task {
public:
    task() {
        t_start = 0;
    }
    ~task() {}
    long t_start;
    long duration;
    int processor;
    long t_end;
    int number;
};

class Priority_queue_task {
public:
    Priority_queue_task(){}
    ~Priority_queue_task(){}
    void Insert(task p) {
        H.push_back(p);
        SiftUp(H.size()-1);
    }
    task ExtractMin() {
        auto result = H[0];
        H[0] = H[H.size()-1];
        H.pop_back();
        SiftDown(0);
        return result;
    }
    bool Empty() {
        return H.empty();
    }
    task Front() {
        return H[0];
    }

private:
    int Parent(int i) {
        return (i - 1) / 2;
    }
    int Lch(int i) {
        return 2 * i + 1;
    }
    int Rch(int i) {
        return 2 * i + 2;
    }
    void SiftUp(int i) {
        while (i > 0 &&  compare(H[Parent(i)], H[i])) {
            swap(H[Parent(i)], H[i]);
            i = Parent(i);
        }
    }
    void SiftDown(int i) {
        int maxindex = i;
        int l = Lch(i);
        if (l < H.size() && !compare(H[l], H[maxindex])) {
            maxindex = l;
        }
        int r = Rch(i);
        if (r < H.size() && !compare(H[r], H[maxindex])) {
            maxindex = r;
        }
        if (i != maxindex) {
            swap(H[i], H[maxindex]);
            SiftDown(maxindex);
        }

    }
    bool compare(task &lhs, task &rhs) {
        if (lhs.t_end == rhs.t_end) {
            return lhs.processor > rhs.processor;
        }
        return (lhs.t_end > rhs.t_end);
    }
    vector<task> H;
};

int main() {
    int n, m;
    cin >> n >> m;
    queue<long> durations;
    for (int i = 0; i < m; ++i) {
        int k;
        cin >> k;
        durations.push(k);
    }
    Priority_queue_int processors;
    for (int i = 0; i < n; ++i) {
        processors.Insert(i);
    }
    vector<long> t_answer(m);
    vector<int> proc_answer(m);
    Priority_queue_task processing;
    int l = 0;
    while(!durations.empty()) {
        task item;
        item.duration = durations.front();
        durations.pop();
        if (!processors.Empty()) {
            if (!processing.Empty() && processors.Front() > processing.Front().processor && processing.Front().t_end == 0) {
                auto p = processing.ExtractMin();
                item.t_start  = p.t_end;
                item.t_end = item.duration + item.t_start;
                item.processor = p.processor;
            }
            else {
                item.processor = processors.ExtractMin();
                item.t_end = item.duration + item.t_start;
                item.number = l;
            }
        }
        else if (!processing.Empty()) {
            auto p = processing.ExtractMin();
            item.t_start  = p.t_end;
            item.t_end = item.duration + item.t_start;
            item.processor = p.processor;
        }

        item.number = l;
        t_answer[l] = item.t_start;
        proc_answer[l] = item.processor;
        processing.Insert(item);
        l += 1;
    }
    while (!processing.Empty()) {
        auto p = processing.ExtractMin();
        t_answer[p.number] = p.t_start;
        proc_answer[l] = p.processor;

    }
    for (int i = 0; i < m; ++i) {
        cout <<  proc_answer[i] << ' ' << t_answer[i] << endl;
    }

    return 0;
}
