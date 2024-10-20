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
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 1010;
constexpr ll MOD = 998244353;
ll a[MAX], hack[MAX];
vector <tll> q;


int main() {
    fastio;

    cin >> n >> m >> k;
    for(int i = 1;i <= k;i++) cin >> t, a[t] = 1;

    while(m--){
        ll t, a, b; cin >> t >> a >> b;
        q.push_back({t, a, b});
    }
    sort(all(q));

    for(int i = 1;i <= n;i++){
        memset(hack, 0, sizeof(hack));
        hack[i] = 1; 

        for(auto& j : q){
            auto& [t, s, e] = j;
            if(hack[s]) hack[e] = 1;
        }

        ll flag = 1;
        for(int i = 1;i <= n;i++){
            if(a[i] != hack[i]) flag = 0;
        }

        if(flag) cout << i;
    }


    return 0;
}