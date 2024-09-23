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
constexpr ll MAX = 501010;
constexpr ll MOD = 998244353;
deque <ll> num[10];
vector <ll> result;

int main() {
    fastio;

    cin >> n >> m >> s;
    m = n - m;
    for (int i = 0; i <= n - m; i++) num[s[i] - '0'].push_back(i);
    
    ll la = -1;
    while (m) {
        for (int i = 9; i >= 0; i--) {
            while (!num[i].empty() && num[i].front() <= la) num[i].pop_front();
            if (num[i].empty()) continue;

            m--; result.push_back(i); la = num[i].front();
            if (m) num[s[n - m] - '0'].push_back(n - m);
            break;
        }
    }

    for (auto& i : result) cout << i;


    return 0;
}