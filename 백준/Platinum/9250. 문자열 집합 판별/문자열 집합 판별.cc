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

class _ac{
public:
    ll n, m, seq = 2;
        vector <vector<ll>> adj;
        vector <ll> chk, f;

    _ac(ll k, ll n, ll m = 26) { // 문자열 개수, 문자열 길이, 문자 개수
        this->m = m; this->n = n; 
        chk.resize(n * k + 1); adj.resize(n * k + 1);
        f.resize(n * k + 1);
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
    
    void init(){
        deque <ll> q;
        q.push_back(1);
        f[1] = 1;
        
        while(!q.empty()){
            ll cur = q.front(); q.pop_front();
            if(adj[cur].empty()) adj[cur].resize(m + 1);

            for(int i = 0;i < m;i++){
                ll nxt = adj[cur][i];
                if(!nxt) continue;

                if(cur == 1) f[nxt] = 1;
                else{
                    ll dest = f[cur];

                    if(adj[dest].empty()) adj[dest].resize(m + 1);
                    while(dest != 1 && !adj[dest][i]) {
                        dest = f[dest];               
                        if(adj[dest].empty()) adj[dest].resize(m + 1);
                    }
                    if(adj[dest][i]) dest = adj[dest][i];
                    f[nxt] = dest;
                }

                if(chk[f[nxt]]) chk[nxt] = 1;
                q.push_back(nxt);
            }
        }
    }

    bool find(string& s){
        ll cur = 1;
        for(auto& st : s){
            if(adj[cur].empty()) adj[cur].resize(m + 1);
            while(cur != 1 && !adj[cur][st - 'a']) {
                cur = f[cur];
                if(adj[cur].empty()) adj[cur].resize(m + 1);
            }

            ll nxt = adj[cur][st - 'a'];
            if(nxt) cur = nxt;
            if(chk[cur]) return 1;
        }

        return 0;
    }
};

int main() {
    fastio;

    cin >> n;
    _ac ac(1010, 101);
    for(int i = 1;i <= n;i++){
        cin >> s;
        ac.insert(s);
    }
    ac.init();

    cin >> m;
    for(int i = 1;i <= m;i++){
        cin >> s;
        if(ac.find(s)) cout << "YES\n";
        else cout << "NO\n";
    }


    return 0;
}