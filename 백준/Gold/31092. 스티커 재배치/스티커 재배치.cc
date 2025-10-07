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
constexpr ll MAX = 505; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll buy[26], co[MAX], a[MAX], h[26];
char c[MAX];
priority_queue <ll, vector<ll>, greater<ll>> pq[26];

void init(){
    memset(h, 0, sizeof(h));
    for(int i = 0;i < 26;i++){
        while(!pq[i].empty()) pq[i].pop();
    }
}

void run(){
    cin >> n >> m >> k;
    memset(buy, 0x3f, sizeof(buy));
    for(int i = 1;i <= m;i++){
        ll b; cin >> c[i] >> co[i] >> b;
        buy[c[i] - 'a'] = min(buy[c[i] - 'a'], b);
    }

    for(int i = 1;i <= n;i++) cin >> a[i];
    cin >> s;

    ll result = INF;
    for(int i = 1;i <= n - k + 1;i++){
        ll now = 0; init();

        for(int j = 1;j < i;j++){
            pq[c[a[j]] - 'a'].push(co[a[j]]);
        }

        for(int j = i + k;j <= n;j++){
            pq[c[a[j]] - 'a'].push(co[a[j]]);
        }

        for(int j = i;j < i + k;j++){
            char org = c[a[j]], ch = s[j - i];
            if(ch == org) continue;
            h[org - 'a']++; now += co[a[j]];
            now = min(now, INF);
        }   

        for(int j = i;j < i + k;j++){
            char ch = s[j - i], org = c[a[j]];
            if(ch == org) continue;
            if(h[ch - 'a']) h[ch - 'a']--;
            else if(!pq[ch - 'a'].empty()){
                now += min(pq[ch - 'a'].top(), buy[ch - 'a']);
                pq[ch - 'a'].pop();
            }
            else now += buy[ch - 'a']; 
            now = min(now, INF);
        }

        result = min(result, now);
    }

    cout << (result >= INF ? -1 : result);
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}