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
constexpr ll MAX = 1010101;
constexpr ll MOD = 998244353;
ll a[MAX];


int main() {
    fastio;

    cin >> n; 
    for(int i = 0;i < n;i++) cin >> a[i];

    ll mn = INF, result = 0;
    for(int i = 0;i < n - 1;i++){
        ll cur = a[i] + a[i + 1]; cur *= 3;
        if(cur > mn) continue;

        if(cur == mn) result = min<ll>(result, i);
        else mn = cur, result = i; 
    }

    for(int i = 0;i < n - 2;i++){
        ll cur = a[i] + a[i + 1] + a[i + 2]; cur *= 2;
        if(cur > mn) continue;
        
        if(cur == mn) result = min<ll>(result, i);
        else mn = cur, result = i; 
    }

    cout << result;
    
    
    return 0;
}