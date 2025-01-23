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
constexpr ll MAX = 81; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], f;
vector <ll> vec;
bool uy[9][10], ux[9][10], ur[9][10];

void bt(){
    if(f) return; ll sz = vec.size();
    if(sz == 81){
        for(int i = 0;i < 9;i++){
            for(int j = 0;j < 9;j++) cout << vec[i * 9 + j] << " ";
            cout << "\n";
        }
        f = 1; return;
    }

    ll cy = sz / 9, cx = sz % 9;
    ll cur = 3 * (cy / 3) + cx / 3;
    if(a[sz]) { 
        vec.push_back(a[sz]);
        bt(); 
        vec.pop_back(); return; 
    }

    for(int i = 1;i <= 9;i++){
        if(ur[cur][i] || uy[cy][i] || ux[cx][i]) continue;
        ur[cur][i] = uy[cy][i] = ux[cx][i] = 1;
        vec.push_back(i);
        bt();
        vec.pop_back();
        ur[cur][i] = uy[cy][i] = ux[cx][i] = 0;
    }
}

void run(){
    for(int i = 0;i < 81;i++) {
        cin >> a[i]; ll sz = i;
        ll cy = sz / 9, cx = sz % 9;
        ll cur = 3 * (cy / 3) + cx / 3;
        ur[cur][a[i]] = uy[cy][a[i]] = ux[cx][a[i]] = 1;
    }

    bt();
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

