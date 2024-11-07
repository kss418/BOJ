#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
ll a[MAX];

int main() {
    fastio;

    cin >> n >> s;
    ll result = 0;

    for(int i = 0;i < s.size() / 2;i++){
        ll cur = i, nxt = s.size() - i - 1;
        if(s[cur] == '?' && s[nxt] == '?') result += 26;
        else if(s[cur] == '?' || s[nxt] == '?') result++;
        else if(s[cur] != s[nxt])result = -INF;
    }

    cout << max(result, 0ll);

    
    return 0;
}