#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], h[MAX], l[MAX], r[MAX];
ll root = -1, flag = 1, cnt;
set <ll> num[MAX];
map <ll, ll> org;

void dfs(ll cur, ll lb, ll ub){
    ll mn = *--num[h[cur] + 1].lower_bound(a[cur]);
    if(mn >= lb && mn <= ub){
        num[h[cur] + 1].erase(num[h[cur] + 1].find(mn));
        l[cur] = org[mn];
    }

    if(l[cur] != -1) dfs(l[cur], lb, a[cur] - 1);

    ll mx = *num[h[cur] + 1].upper_bound(a[cur]);
    if(mx >= lb && mx <= ub){
        num[h[cur] + 1].erase(num[h[cur] + 1].find(mx));
        r[cur] = org[mx];
    }

    if(r[cur] != -1) dfs(r[cur], a[cur] + 1, ub);
    cnt++;
}

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i] >> h[i];
        org[a[i]] = i;
        num[h[i]].insert(a[i]);
        if(h[i] == 1){
            if(root == -1) root = i;
            else flag = 0;
        }
    }

    memset(l, -1, sizeof(l));
    memset(r, -1, sizeof(r));
    for(int i = 1;i <= n + 1;i++){
        num[i].insert(INF);
        num[i].insert(MINF);
    }

    if(root != -1) dfs(root, MINF + 1, INF - 1);
    else flag = 0;

    if(!flag || cnt != n) cout << -1;
    else for(int i = 1;i <= n;i++) cout << l[i] << " " << r[i] << "\n";
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

