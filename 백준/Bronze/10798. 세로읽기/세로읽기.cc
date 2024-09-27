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
string st[5];

int main() {
    fastio;

    for(int i = 0;i < 5;i++){
        cin >> st[i];
    }

    for(int i = 0;i < 15;i++){
        for(int j = 0;j < 5;j++){
            if(st[j].size() <= i) continue;
            cout << st[j][i];
        }
    }

    return 0;
}