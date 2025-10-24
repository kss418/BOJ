#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector <vector <int>> adj, rev, result;
vector <int> pre, nxt, org, num, tmp;
int cnt, dfsn;

void cal(int cur){
    pre[cur] = ++dfsn;

    for(auto& nxt : rev[cur]){
        if(!pre[nxt]) cal(nxt);
    }

    nxt[cur] = ++dfsn;
    org[dfsn] = cur;
}

void dfs(int cur){
    num[cur] = cnt;
    tmp.push_back(cur);
    for(auto& nxt : adj[cur]){
        if(!num[nxt]) dfs(nxt);
    }
}

int main(){
    cin >> n >> m; 
    num.resize(n + 1); org.resize(2 * n + 1);
    adj.resize(n + 1); rev.resize(n + 1);
    pre.resize(n + 1); nxt.resize(n + 1);

    while(m--){
        int s, e; cin >> s >> e;
        adj[e].push_back(s);
        rev[s].push_back(e);
    }

    for(auto& i : adj) sort(i.begin(), i.end());
    for(auto& i : rev) sort(i.begin(), i.end());

    for(int i = 1;i <= n;i++){
        if(!pre[i]) cal(i);
    }

    for(int i = 2 * n;i >= 1;i--){
        if(!org[i] || num[org[i]]) continue;
        ++cnt; dfs(org[i]);

        sort(tmp.begin(), tmp.end());
        result.push_back(tmp);
        tmp.clear();
    }

    sort(result.begin(), result.end());
    
    cout << result.size() << "\n";
    for(auto& i : result){
        for(auto& j : i) cout << j << " ";
        cout << "-1\n";
    }
   
    return 0;
}