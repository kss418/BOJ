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
ll result[10];

void cal(ll cur, ll cnt){
    while(cur) result[cur % 10] += cnt, cur /= 10;
}

void solve(ll st, ll en, ll cnt){
    while(st % 10 && st <= en) cal(st++, cnt);
    if(st > en) return;
    while(en % 10 != 9 && st <= en) cal(en--, cnt); 
    
    
    for(int i = 0;i < 10;i++) result[i] += ((en / 10 - st / 10 + 1)) * cnt;
    solve(st / 10, en / 10, 10 * cnt);
}

void run(){
    cin >> n; solve(1, n, 1);
    for(int i = 0;i < 10;i++) cout << result[i] << " ";
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

