#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
ll arr[MAX];

bool num(ll n){
    if(n) return 1;
    return 0;
}

class _trie { // 0-based index
public:
    ll n, m, seq = 2;
    vector <vector<ll>> adj;
    vector <ll> chk;

    _trie(ll k, ll n, ll m = 26) { // 문자열 개수, 문자열 길이, 문자 개수
       this->m = m; this->n = n; 
       chk.resize(n * k + 1); adj.resize(n * k + 1);
    }

    void insert(ll s){
        ll cur = 1;
        for(int i = 31; i >= 0; i--){
            ll st = num(s & (1ll << i));
            if(adj[cur].empty()) adj[cur].resize(m + 1);
            if(!adj[cur][st]) adj[cur][st] = seq++;
            cur = adj[cur][st];
            chk[cur]++;
        }
    }

    void erase(ll s){
        ll cur = 1;
        for(int i = 31; i >= 0; i--){
            ll st = num(s & (1ll << i));
            if(adj[cur].empty()) adj[cur].resize(m + 1);
            cur = adj[cur][st];
            chk[cur]--;
        }
    }

    ll find(ll s){
        ll cur = 1, ret = 0, now = 0;
        for(int i = 31; i >= 0; i--){
            ll st = num(s & (1ll << i)); st ^= 1;
            now |= (1ll << i);
            if(adj[cur].empty()) adj[cur].resize(m + 1);
            if(!chk[adj[cur][st]]) st ^= 1, now &= ~(1ll << i);

            cur = adj[cur][st];
        }
        return now;
    }
};

int main() {
    fastio;

    cin >> t;
    _trie trie(MAX, 32, 2);

    trie.insert(0);
    while(t--){
        ll com, x;
        cin >> com >> x;
        
        if(com == 1) trie.insert(x);
        else if(com == 2) trie.erase(x);
        else cout << trie.find(x) << "\n";
    }

  
    return 0;
}