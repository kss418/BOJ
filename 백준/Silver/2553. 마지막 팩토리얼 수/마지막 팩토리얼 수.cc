#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 4010;
constexpr ll MOD = 1e9 + 7;


int main() {
    fastio;
    cin >> n;
    ll result = 1, two = 0, five = 0;
    
    for (int i = 2; i <= n; i++) {
        ll cur = i;
        while (cur % 2 == 0) {
            two++; cur /= 2;
        }

        while (cur % 5 == 0) {
            five++; cur /= 5;
        }
        result *= (cur % 10);
        result %= 10;
    }

    ll mn = min(two, five);
    two -= mn; five -= mn;

    if (two >= five) {
        for (int i = 1; i <= two; i++) {
            result *= 2;
            result %= 10;
        }
    }
    else {
        for (int i = 1; i <= five; i++) {
            result *= 5;
            result %= 10;
        }
    }

    cout << result % 10;


    return 0;
}