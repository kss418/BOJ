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
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll result = INF;

void solve(ll cur, ll num, ll diff){
    if(cur >= s.size()) return;
    if(cur > (ll)s.size() - 10){
        string sn = s.substr(cur, s.size() - cur);
        ll now = stoll(sn);
        if(now % (num - diff) == 0 && sn[0] != '0'){
            ll div = now / (num - diff);
            if(div >= 2) result = min(result, div);
        }
    }

    ll sz = to_string(num).size();
    string sn = s.substr(cur, sz);
    if(stoll(sn) != num|| sn[0] == '0') return;
    solve(cur + sz, num + diff, diff);
}

void run(){
    cin >> s;
    for(int i = 0;i < min<ll>(s.size(), 10);i++){
        string sn = s.substr(0, i + 1);
        ll now = stoll(sn);
        for(int j = i + 1;j < min<ll>(s.size(), i + 10);j++){
            string nn = s.substr(i + 1, j - i);
            ll nxt = stoll(nn);
            if(nxt - now <= 0 || nn[0] == '0') continue;
            solve(j + 1, 2 * nxt - now, nxt - now);
        }
    }
    
    cout << (result >= INF ? 0 : result);
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}