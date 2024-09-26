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

class _trie { // 0-based index
public:
    ll n, m, seq = 2;
    vector <vector<ll>> adj;
    vector <ll> chk;

    _trie(ll k, ll n, ll m = 26) { // 문자열 개수, 문자열 길이, 문자 개수
       this->m = m; this->n = n; 
       chk.resize(n * k + 1); adj.resize(n * k + 1);
    }

    void insert(string& s){
        ll cur = 1;
        for(auto &st : s){
            if(adj[cur].empty()) adj[cur].resize(m + 1);
            if(!adj[cur][st - 'a']) adj[cur][st - 'a'] = seq++;
            cur = adj[cur][st - 'a'];
        }
        chk[cur] = 1;
    }

    void erase(string& s){
        ll cur = 1;
        for(auto &st : s){
            if(!adj[cur][st - 'a']) return;
            cur = adj[cur][st - 'a'];
        }
        chk[cur] = 0;
    }

    bool find(string& s){
        ll cur = 1;
        for(auto &st : s){
            if(!adj[cur][st - 'a']) return 0;
            cur = adj[cur][st - 'a'];
        }
        return 1;
    }
};

int main() {
    fastio;

    cin >> n >> m;
    _trie trie(10101, 501);
    while(n--){
        cin >> s;
        trie.insert(s);
    }

    ll result = 0;
    while(m--){
        cin >> s;
        result += trie.find(s);
    }

    cout << result;


    return 0;
}