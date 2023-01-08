#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;
ll n, m, k, t; string s;

const int MAX = 101010;
int mseg[4 * MAX], Mseg[4 * MAX], sseg[4 * MAX], arr[MAX];
int min_u(int st, int en, int node, int index, int num) {
    if (index < st || index > en) {
        return mseg[node];
    }

    if (st == en) {
        mseg[node] = num;
        return mseg[node];
    }

    int mid = (st + en) / 2;
    mseg[node] = min(min_u(st, mid, node * 2, index, num), min_u(mid + 1, en, node * 2 + 1, index, num));
    return mseg[node];
}

int max_u(int st, int en, int node, int index, int num) {
    if (index < st || index > en) {
        return Mseg[node];
    }

    if (st == en) {
        Mseg[node] = num;
        return Mseg[node];
    }

    int mid = (st + en) / 2;
    Mseg[node] = max(max_u(st, mid, node * 2, index, num), max_u(mid + 1, en, node * 2 + 1, index, num));
    return Mseg[node];
}

int sum_u(int st, int en, int node, int index, int num) {
    if (index < st || index > en) {
        return sseg[node];
    }

    if (st == en) {
        sseg[node] = num;
        return sseg[node];
    }

    int mid = (st + en) / 2;
    sseg[node] = sum_u(st, mid, node * 2, index, num) + sum_u(mid + 1, en, node * 2 + 1, index, num);
    return sseg[node];
}

int min_q(int st, int en, int node, int l, int r) {
    if (l > en || r < st) {
        return 1e9;
    }

    if (l <= st && r >= en) {
        return mseg[node];
    }

    int mid = (st + en) / 2;
    return min(min_q(st, mid, node * 2, l, r), min_q(mid + 1, en, node * 2 + 1, l, r));
}

int max_q(int st, int en, int node, int l, int r) {
    if (l > en || r < st) {
        return 0;
    }

    if (l <= st && r >= en) {
        return Mseg[node];
    }

    int mid = (st + en) / 2;
    return max(max_q(st, mid, node * 2, l, r), max_q(mid + 1, en, node * 2 + 1, l, r));
}

int sum_q(int st, int en, int node, int l, int r) {
    if (l > en || r < st) {
        return 0;
    }

    if (l <= st && r >= en) {
        return sseg[node];
    }

    int mid = (st + en) / 2;
    return sum_q(st, mid, node * 2, l, r) + sum_q(mid + 1, en, node * 2 + 1, l, r);
}


int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);


    cin >> t;
    int sum[MAX];
    sum[0] = 0;
    for (int i = 1; i < MAX - 1; i++) {
        sum[i] = sum[i - 1] + i;
    }

    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            min_u(1, n, 1, i, i);
            max_u(1, n, 1, i, i);
            sum_u(1, n, 1, i, i);
            arr[i] = i;
        }

        for (int i = 0; i < m; i++) {
            int q, a, b;
            cin >> q >> a >> b;
            a++; b++;
            if (!q) {
                int temp = arr[a];
                arr[a] = arr[b];
                arr[b] = temp;

                for (auto j : { a,b }) {
                    min_u(1, n, 1, j, arr[j]);
                    max_u(1, n, 1, j, arr[j]);
                    sum_u(1, n, 1, j, arr[j]);
                }
            }
            else {
                int flag = 1;
                if (min_q(1, n, 1, a, b) != min(a,b)) {
                    flag = 0;               
                }
                if (max_q(1, n, 1, a, b) != max(a, b)) {
                    flag = 0;
                }
                if (sum_q(1, n, 1, a, b) != sum[max(a, b)] - sum[min(a, b) - 1]) {
                    flag = 0;
                }

                if (flag) {
                    cout << "YES" << "\n";
                }
                else {
                    cout << "NO" << "\n";
                }
            }
        }
    }

	

    return 0;
}