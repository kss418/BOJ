#include <bits/stdc++.h>
#define rep(i, a, n) for(auto i = a; i < n; i++)
#define REP(i, a, n) for(auto i = a; i <= n; i++)
#define pb push_back
#define endl "\n"
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0), cout.tie(0)
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define X first
#define Y second
#define all(v) (v).begin(), (v).end()
#define PIV (1 << 20)

using namespace std;

int main() {
    FAST_IO;

    int n;
    vector<int> v;
    cin >> n;

    v.resize(100 + 5, 0);

    int cnt = 0;

    rep(i, 0, n) {
        int num; cin >> num;
        if (v[num]) cnt++;
        else v[num] = 1;
    }

    cout << cnt;
}