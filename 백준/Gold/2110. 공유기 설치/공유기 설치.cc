#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;
int n, m;
vector <int> arr;


bool dm(int cur) {
    int cnt = 1;
    int pre = 0;
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] - arr[pre] >= cur) {
            cnt++;
            pre = i;
        }

        if (cnt == m) {
            return 1;
        }
    }

    return 0;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    sort(arr.begin(), arr.end());
    int st = 1, en = arr.back() - arr[0];
    int mid = (st + en + 1) / 2;
    while (en > st) {
        mid = (st + en + 1) / 2;
        if (dm(mid)) {
            st = mid;
        }
        else {
            en = mid - 1;
        }
    }

    cout << en;


    return 0;
}