#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

void BracketChecker(const string &a){
    stack<pair<char, int>> c;
    for (int i = 0; i <a.size(); ++i) {
        if (a[i] == '[' || a[i] == '(' || a[i] == '{') {
            c.push({a[i],i+1});
        }
        else if (!c.empty() && ((a[i] == ']' && c.top().first == '[') ||
                                    (a[i] == ')' && c.top().first == '(') ||
                                            (a[i] == '}' && c.top().first == '{'))) {
            c.pop();
        }
        else if ((a[i] == ']' && (c.empty() || c.top().first != '[')) ||
                (a[i] == ')' && (c.empty() || c.top().first != '(')) ||
                (a[i] == '}' && (c.empty() || c.top().first != '{'))) {
            cout << i + 1 << endl;
            return;
        }
    }
    if (c.empty()) {
        cout << "Success" << endl;
    }
    else {
        cout << c.top().second << endl;
    }
};

int main(){
    string a;
    getline(cin,a);
    BracketChecker(a);
    return 0;
}
