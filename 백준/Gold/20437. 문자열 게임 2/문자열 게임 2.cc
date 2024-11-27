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
using ld = long double; using pld = pair<ld, ld>;
using ull = unsigned long long; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;


int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> s >> n;
        ll mn = INF, mx = 0;
        vector <ll> num[26];

        for(int i = 0;i < s.size();i++){
            num[s[i] - 'a'].push_back(i);
        }

        for(int c = 0;c < 26;c++){
            for(int cur = 0;cur < num[c].size();cur++){
                ll nxt = cur + n - 1;
                if(nxt >= num[c].size()) break;
                ll diff = num[c][nxt] - num[c][cur] + 1;
                mx = max(mx, diff); mn = min(mn, diff); 
            }
        }

        if(mn == INF) cout << -1 << "\n";
        else cout << mn << " " << mx << "\n";
    }
    
     
    return 0;
}