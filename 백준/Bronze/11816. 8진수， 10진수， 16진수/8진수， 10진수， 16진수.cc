#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;

int main() {
    fastio;

    cin >> s;
    if(s[0] == '0' && s[1] == 'x' && s.size() >= 2) cout << stoll(s, nullptr, 16);
    else if(s[0] != '0') cout << stoll(s);
    else cout << stoll(s, nullptr, 8);
    

    return 0;
}