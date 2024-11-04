#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 2010;
constexpr ll MOD = 998244353;
bool c[MAX];
map <string, bool> cnt;

template <typename T = ll>
class _trie { // 0-based index
public:
    T n, m, seq = 2;
    vector <vector<T>> adj;
    vector <bool> chk;

    _trie(T k, T n, ll m = 26) { // 문자열 개수, 문자열 길이, 문자 개수
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
            if(adj[cur].empty()) adj[cur].resize(m + 1);
            if(!adj[cur][st - 'a']) return;
            cur = adj[cur][st - 'a'];
        }
        chk[cur] = 0;
    }

    void find(string& s){
        ll cur = 1;
        for(int i = 0;i < s.size();i++){
            char st = s[i];
            if(adj[cur].empty()) adj[cur].resize(m + 1);
            if(!adj[cur][st - 'a']) return;
            cur = adj[cur][st - 'a'];
            if(chk[cur]) c[i + 1] = 1; 
        }
    }
};

int main() {
    fastio;

    cin >> n >> m; _trie<int> a(4010101, 1);
    for(int i = 1;i <= n;i++) cin >> s, a.insert(s);
    for(int i = 1;i <= m;i++) {
        cin >> s; reverse(all(s));
        cnt[s] = 1;
    }

    cin >> m; 
    while(m--){
        cin >> s;

        ll flag = 0; a.find(s);
        reverse(all(s)); string now = s;
        for(int i = 1;i < s.size();i++){
            now.pop_back();
            if(!c[i] || !cnt.count(now)) continue;
            flag = 1; break;
        }  

        memset(c, 0, sizeof(c));
        if(flag) cout << "Yes\n";
        else cout << "No\n";
    }



    return 0;
}

