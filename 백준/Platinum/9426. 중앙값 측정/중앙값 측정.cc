#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, a, b, c, k,num, si = 0;
int seg[300000];
vector <int> arr;

void update(int st, int en, int num, int value, int node) {
    if (st > num || num > en) {
        return;
    }

    seg[node] += value;
    if (st == en) {
        return;
    }
    int mid = (st + en) / 2;
    update(st, mid, num, value, node * 2);
    update(mid + 1, en, num, value, node * 2 + 1);
}

int query(int st, int en, int node, int kth) {
    if (st == en) {
        return st;
    }

    int mid = (st + en) / 2;
    if (kth > seg[node * 2]) {
        return query(mid + 1, en, node * 2 + 1,kth - seg[node * 2]);
    }
    else {
        return query(st, mid, node * 2, kth);
    }
}


int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);


    long long result = 0;
    cin >> n >> k;
    for (int i = 0; i < n;i++) {
        cin >> num;
        arr.push_back(num);
    }

    for (int i = 0; i < n; i++) {
        update(1, 66000, arr[i] + 1, 1, 1);
        si++;
        if (si == k) {
            result += query(1, 66000, 1, (k + 1) / 2) - 1;
            update(1, 66000, arr[i - k + 1] + 1, -1, 1);
            si--;
        }
    }

    cout << result;
    return 0;
}

