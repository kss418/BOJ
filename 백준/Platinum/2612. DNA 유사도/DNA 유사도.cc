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
constexpr ll MAX = 1010; // SET MAX SIZE
constexpr ll MOD = 998244353;
string a, b;
ll dp[MAX][MAX], result;
vector <char> ra, rb;

ll solve(ll as, ll bs){
    ll& ret = dp[as][bs];
    if(as == n || bs == m) return ret = 0;
    if(ret != -1) return ret; ret = 0;

    ret = max(ret, solve(as + 1, bs) - 2);
    ret = max(ret, solve(as, bs + 1) - 2);
    if(a[as] == b[bs]) ret = max(ret, solve(as + 1, bs + 1) + 3);
    else ret = max(ret, solve(as + 1, bs + 1) - 2);

    return ret;
}

void run(){
    cin >> n >> a >> m >> b;
    memset(dp, -1, sizeof(dp));
    
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++) result = max(result, solve(i, j));
    }
    cout << result << "\n";
    
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(solve(i, j) != result) continue;

            while(1){
                ll cur = solve(i, j);
                ll nx = solve(i, j + 1);
                ll ny = solve(i + 1, j);
                ll nxy = solve(i + 1, j + 1);
                if(!cur) break;
                if(cur == nxy + 3 && a[i] == b[j]) {
                    ra.push_back(a[i]); rb.push_back(b[j]);
                    i++; j++;
                }
                else if(cur == nxy - 2 && a[i] != b[j]){
                    ra.push_back(a[i]); rb.push_back(b[j]);
                    i++; j++;
                }
                else if(cur == nx - 2) rb.push_back(b[j]), j++;
                else if(cur == ny - 2) ra.push_back(a[i]), i++;
            }

            for(auto& i : ra) cout << i; cout << "\n";
            for(auto& i : rb) cout << i;
            return;
        }
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

