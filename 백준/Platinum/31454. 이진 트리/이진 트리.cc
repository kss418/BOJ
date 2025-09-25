#include <bits/stdc++.h>
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
ll l[MAX], r[MAX], c[MAX], root;
ll sz[MAX], result, cc, out[MAX];
vector <ll> rev[MAX];
bool v[MAX];
deque <ll> q;

void init(){
    for(int i = 1;i <= n;i++){
        v[i] = c[i] = out[i] = 0;
        rev[i].clear();
    }
    root = result = cc = 0; q.clear();
}

ll dfs(ll cur){
    ll lsz = (l[cur] ? dfs(l[cur]) : 0) + 1;
    ll rsz = (r[cur] ? dfs(r[cur]) : 0) + 1;
    result += lsz * rsz;

    return sz[cur] = lsz + rsz;
}

void fc(ll cur){
    if(v[cur]){
        cc++;
        return;
    }

    v[cur] = 1;
    if(l[cur] && c[l[cur]]) fc(l[cur]);
    if(r[cur] && c[r[cur]]) fc(r[cur]);
    c[cur] = 0;
}

void run(){
    cin >> n; init(); ll cnt = 0;
    for(int i = 1;i <= n;i++){
        cin >> l[i]; c[l[i]]++;
        if(l[i]){
            cnt++; out[i]++;
            rev[l[i]].push_back(i);
        }
    }

    for(int i = 1;i <= n;i++){
        cin >> r[i]; c[r[i]]++;
        if(r[i]){
            cnt++; out[i]++;
            rev[r[i]].push_back(i);
        }
    }

    bool flag = 1;
    for(int i = 1;i <= n;i++){
        if(c[i]) continue;
        if(!root) root = i;
        else flag = 0;
    }

    if(cnt != n - 1 || !flag){ cout << 0 << "\n"; return; }

    for(int i = 1;i <= n;i++) if(!c[i]) q.push_back(i);
    while(!q.empty()){
        auto cur = q.front(); q.pop_front();
        if(l[cur] && !--c[l[cur]]) q.push_back(l[cur]);
        if(r[cur] && !--c[r[cur]]) q.push_back(r[cur]);
    }

    for(int i = 1;i <= n;i++) if(!out[i]) q.push_back(i);
    while(!q.empty()){
        auto cur = q.front(); q.pop_front();
        for(auto& nxt : rev[cur]){
            if(!--out[nxt]) q.push_back(nxt);
        }
    }

    bool cy = 0; ll a = 0, b = 0;
    for(int i = 1;i <= n;i++){
        if(out[i] == 1 && c[i] == 1) a++;
        else if(!c[i]) b += 2;
    }

    for(int i = 1;i <= n;i++){
        if(!c[i]) continue;
        cy = 1; fc(i);
    }

    if(cy){
        if(cc != 1){ cout << 0 << "\n"; return; }
        cout << a * b << "\n";
    }
    else{
        dfs(root);
        cout << result << "\n";
    }
}

int main() {
    fastio; cin >> t;
    while(t--) run();
    
    return 0;
}