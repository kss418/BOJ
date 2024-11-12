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
constexpr ll MAX = 101010; // PLZ CHK!
constexpr ll MOD = 998244353;
ll a[MAX], fib[36], num[3010101];
ll cnt[36];

int main() {
    fastio;

    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];

    fib[1] = 1;
    for(int i = 2;i <= 35;i++) fib[i] = fib[i - 1] + fib[i - 2];

    for(int i = 1;i < 3010101;i++){
        memset(cnt, 0, sizeof(cnt));
        for(int j = 1;j <= 35;j++){
            if(i < fib[j]) break;
            cnt[num[i - fib[j]]]++;
        }

        ll cur = 0;
        for(int j = 0;j <= 35;j++){
            if(cnt[j] && j == cur) cur++;
            if(j > cur) break;
        }

        num[i] = cur;
    }

    ll all = 0;
    for(int i = 1;i <= n;i++) all ^= num[a[i]];

    if(all) cout << "koosaga";
    else cout << "cubelover";

    
    return 0;
}