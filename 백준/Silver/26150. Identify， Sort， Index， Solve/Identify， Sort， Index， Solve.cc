#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101;
constexpr ll MOD = 1e9 + 7;
class node {
public:
    ll i, d;
    string s;

    bool operator <(node& ot) {
        return i < ot.i;
    }
};
node arr[MAX];

char conv(char c) {
    if (c >= 'a' && c <= 'z') return c - 'a' + 'A';
    return c;
}

int main() {
    fastio;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].s;
        cin >> arr[i].i >> arr[i].d;
    }
    sort(arr + 1, arr + n + 1);

    for (int i = 1; i <= n; i++) cout << conv(arr[i].s[arr[i].d - 1]);

    


    return 0;
}