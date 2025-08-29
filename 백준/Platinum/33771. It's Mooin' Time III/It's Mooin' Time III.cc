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
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll pre[MAX][31], nxt[MAX][31];
vector <ll> idx[31];

void run(){
    cin >> n >> m >> s;
    for(int i = 0;i < n;i++) idx[s[i] - 'a'].push_back(i + 1);
    memset(nxt, 0x3f, sizeof(nxt));

    for(int i = 1;i <= n;i++){
        for(int j = 0;j < 26;j++){
            pre[i][j] = pre[i - 1][j];
            if(s[i - 1] - 'a' == j) pre[i][j] = i;
        }
    }

    for(int i = n;i >= 1;i--){
        for(int j = 0;j < 26;j++){
            nxt[i][j] = nxt[i + 1][j];
            if(s[i - 1] - 'a' == j) nxt[i][j] = i;
        }
    }

    while(m--){
        ll l, r; cin >> l >> r;
        ll now = -1;

        for(int i = 0;i < 26;i++){
            ll st = INF, en = pre[r][i];
            for(int j = 0;j < 26;j++){
                if(i == j) continue;
                st = min(st, nxt[l][j]); 
            }

            if(st == INF || !en) continue;
            ll mid = (st + en) / 2;
            ll ub = upper_bound(all(idx[i]), mid) - idx[i].begin();
            ll lb = ub - 1;
            
            ub = (ub >= idx[i].size() || ub < 0) ? -1 : idx[i][ub];
            lb = (lb >= idx[i].size() || lb < 0) ? -1 : idx[i][lb];

            if(ub > st && ub < en) now = max(now, (en - ub) * (ub - st));
            if(lb > st && lb < en) now = max(now, (en - lb) * (lb - st));
        }

        cout << now << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}