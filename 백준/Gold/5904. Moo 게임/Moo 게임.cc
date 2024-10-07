#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
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
vector <ll> arr;
ll len[MAX];

ll solve(ll cur, ll cnt){
    if(cur <= len[cnt]) return solve(cur, cnt - 1);
    else if(cur == len[cnt] + 1) return 1;
    else if(cur <= len[cnt] + cnt + 3) return 0;
    return solve(cur - len[cnt] - cnt - 3, cnt - 1);
}

int main() {
    fastio;

    cin >> n;

    ll cnt = 0, cur = 0; len[0] = 0;
    while(cur <= n){
        cnt++;
        len[cnt] = len[cnt - 1] * 2 + cnt + 2;
        cur = len[cnt];
    }

    ll ret = solve(n, cnt - 1);
    if(ret) cout << "m";
    else cout << "o";

    return 0;
}