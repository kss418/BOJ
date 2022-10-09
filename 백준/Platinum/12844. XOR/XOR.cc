#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
const int len = 500001;
long long arr[len], seg[4 * len], lazy[4 * len];


void prop(int st, int en, int node) {
    if (lazy[node] != 0) {
        if ((en - st + 1) % 2 == 1) {
            seg[node] ^= lazy[node];
        }

        if (st < en) {
            lazy[node * 2] ^= lazy[node];
            lazy[node * 2 + 1] ^= lazy[node];
        }
        lazy[node] = 0;
    }
}

void update(int st, int en, long long k, int l, int r, int node) {
    prop(st, en, node);

    if (en < l || st > r) {
        return;
    }

    if (st >= l && en <= r) {
        if ((en - st + 1) % 2 == 1) {
            seg[node] ^= k;
        }

        if (st != en) {
            lazy[node * 2] ^= k;
            lazy[node * 2 + 1] ^= k;
        }

        return;
    }

    int mid = (st + en) / 2;
    update(st, mid, k, l, r, node * 2);
    update(mid + 1, en, k, l, r, node * 2 + 1);
    seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
}

long long query(int st, int en, int l, int r, int node) {
    prop(st, en, node);

    if (en < l || st > r) {
        return 0;
    }

    if (st >= l && en <= r) {
        return seg[node];
    }

    int mid = (st + en) / 2;
    return query(st, mid, l, r, node * 2) ^ query(mid + 1, en, l, r, node * 2 + 1);
}

long long mk_seg(int st, int en, int node) {
    if (st == en) {
        seg[node] = arr[st];
        return seg[node];
    }

    int mid = (st + en) / 2;
    seg[node] = mk_seg(st, mid, node * 2) ^ mk_seg(mid + 1, en, node * 2 + 1);
    return seg[node];
}


int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);


    int m;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    mk_seg(1, n, 1);

    cin >> m;
    int com, st, en;
    long long value;
    for (int i = 0; i < m; i++) {
        cin >> com;
        if (com == 1) {
            cin >> st >> en >> value;
            update(1, n, value, st + 1, en + 1, 1);
        }
        else if (com == 2) {
            cin >> st >> en;
            cout << query(1, n, st + 1, en + 1, 1) << "\n";
        }
    }

    return 0;
}

