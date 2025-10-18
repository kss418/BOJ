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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], b[MAX], result, cnt[1010101];
bool v[MAX], use[1010101];
vector <ll> idx[1010101];
set <pll> ms;

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) cin >> b[i];

    for(int i = 1;i <= n;i++){
        idx[a[i]].push_back(i);
        idx[b[i]].push_back(i);
    }

    for(int i = 0;i < 1010101;i++){
        if(idx[i].empty()) continue;
        ms.insert({idx[i].size(), i});
        cnt[i] = idx[i].size();
    }

    while(!ms.empty()){
        auto [cc, now] = *ms.begin(); 
        ms.erase(ms.begin());

        result++; cnt[now] = 0;
        ll mx = 0, num = -1;
        for(auto& i : idx[now]){
            if(v[i]) continue;
            if(use[a[i]] || use[b[i]]) mx = INF, num = i;
            else{
                ll nxt = (a[i] == now ? cnt[b[i]] : cnt[a[i]]);
                if(nxt > mx) mx = nxt, num = i;
            } 
        }

        use[now] = 1; 
        if(num == -1) continue;
        v[num] = 1;

        ll nxt = (a[num] == now ? b[num] : a[num]); cnt[nxt]--; 
        auto lb = ms.find({cnt[nxt] + 1, nxt});
        if(lb != ms.end()) ms.erase(lb);
        if(cnt[nxt] > 0) ms.insert({cnt[nxt], nxt});
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}