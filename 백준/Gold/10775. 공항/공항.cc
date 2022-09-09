#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
int n, p, num;
set <int> arr;

int main() {
    cin >> n >> p;

    for (int i = 1; i <= n; i++) {
        arr.insert(-i);
    }

    int result = 0;
    while (p--) {
        cin >> num;
        auto it = arr.lower_bound(-num);
        if (it == arr.end()) {
            break;
        }
        result++;
        arr.erase(it);
    }

    cout << result;



    return 0;
}