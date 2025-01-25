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
string st[MAX], result;
ll pre[26], nxt[26];

void down(ll cur, ll idx, ll org){
    if(st[cur][0] == '?'){ pre[org] = idx; return; }
    if(idx && st[cur][idx - 1] == '-') down(cur + 1, idx - 1, org);
    else if(idx < m - 1 && st[cur][idx] == '-') down(cur + 1, idx + 1, org);
    else down(cur + 1, idx, org);
}

void up(ll cur, ll idx, ll org){
    if(st[cur][0] == '?'){ nxt[org] = idx; return; }
    if(idx && st[cur][idx - 1] == '-') up(cur - 1, idx - 1, org);
    else if(idx < m - 1 && st[cur][idx] == '-') up(cur - 1, idx + 1, org);
    else up(cur - 1, idx, org);
}

void run(){
    cin >> m >> n >> s;
    for(int i = 0;i < n;i++) cin >> st[i];
    for(int i = 0;i < m;i++) down(0, i, i), up(n - 1, i, s[i] - 'A');

    ll flag = 1; result.resize(m - 1);
    for(int i = 0;i < m;i++){
        if(pre[i] == nxt[i]) result[pre[i]] = '*';
        else if(pre[i] + 1 == nxt[i]) result[pre[i]] = '-';
        else if(pre[i] == nxt[i] + 1) result[pre[i] - 1] = '-';
        else flag = 0;
    }
    for(int i = 0;i < m - 1;i++) if(result[i] != '-') result[i] = '*';

    if(!flag) for(int i = 0;i < m - 1;i++) result[i] = 'x';
    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

