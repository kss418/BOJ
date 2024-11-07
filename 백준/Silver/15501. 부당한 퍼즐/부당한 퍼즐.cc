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
ll a[MAX], b[MAX], rb[MAX];
ll mb[MAX], mrb[MAX];

bool match(ll* arr){
    ll idx = 0;
    for(int i = 1;i <= n;i++){
        ll cur = arr[i];
        if(cur != a[1]) continue;
        idx = i - 1; break;
    }

    for(int i = 0;i < n;i++){
        if(arr[(idx + i) % n + 1] == a[i + 1]) continue;
        return 0;
    }

    return 1;
}

int main() {
    fastio;

    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) cin >> b[i];
    for(int i = 1;i <= n;i++) rb[i] = b[i];
    reverse(rb + 1, rb + n + 1);

    bool result = match(b) | match(rb);
    if(result) cout << "good ";
    else cout << "bad ";
    cout << "puzzle";

    
    return 0;
}