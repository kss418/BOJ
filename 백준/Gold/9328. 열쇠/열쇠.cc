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
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101;
constexpr ll MOD = 998244353;
string st[MAX];
ll result;
ll dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
bool v[MAX][MAX], key[31];
deque <pll> q, nq[31];

void init(){
    result = 0; memset(v, 0, sizeof(v)); q.clear();
    for(int i = 0;i < 30;i++) nq[i].clear(), key[i] = 0;
    if(s[0] != '0') for(auto& i : s) key[i - 'a'] = 1;
}

void bfs(){
    while(1){
        if(q.empty()){
            for(int i = 0;i < 30;i++){
                if(!key[i]) continue;
                if(!nq[i].empty()){
                    auto fr = nq[i].front();
                    q.push_back(fr);
                    v[fr.x][fr.y] = 0;
                    nq[i].pop_front();
                    break;
                }
            }
        }

        if(q.empty()) break;

        auto[cy, cx] = q.front(); q.pop_front();
        if(v[cy][cx]) continue; v[cy][cx] = 1;

        char c = st[cy][cx];
        if(c == '*') continue;
        else if(c >= 'a' && c <= 'z') key[c - 'a'] = 1;
        else if(c == '$') result++;
        else if(c >= 'A' && c <= 'Z' && !key[c - 'A']) {
            nq[c - 'A'].push_back({cy, cx}); continue;
        }

        for(int i = 0;i < 4;i++){
            ll ny = cy + dy[i], nx = cx + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            q.push_back({ny, nx});
        }
    }
}

int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 0;i < n;i++) cin >> st[i];
        cin >> s; init();
 
        for(int i = 0;i < m;i++) {
            if(st[0][i] != '*') q.push_back({0, i});
            if(st[n - 1][i] != '*') q.push_back({n - 1, i});
        }

        for(int i = 1;i < n - 1;i++) {
            if(st[i][0] != '*') q.push_back({i, 0});
            if(st[i][m - 1] != '*') q.push_back({i, m - 1});
        }
        bfs();

        cout << result << "\n";
    }
    
    
    return 0;
}