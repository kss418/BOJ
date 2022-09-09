#include <iostream>
#include <vector>
#include <deque>
using namespace std;
int n, m, tmp;
int arr[100002];
int back[100002];
deque <int> result;

int main() {
    cin >> n >> m;
    fill(arr, arr + 100001, -1);
    arr[n] = 0;
    deque <int> q;
    q.push_back(n);
    while (arr[m] == -1) {
        tmp = q.front();
        q.pop_front();
        for (int cur : {tmp - 1, tmp + 1, 2 * tmp}) {
            if (cur < 0 || cur > 100000) {
                continue;
            }
            if (arr[cur] != -1) {
                continue;
            }
            back[cur] = tmp;
            arr[cur] = arr[tmp] + 1;
            q.push_back(cur);
        }

    }

    cout << arr[m] << "\n";
    result.push_front(m);
    while (m != n) {
        result.push_front(back[m]);
        m = back[m];
    }
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}