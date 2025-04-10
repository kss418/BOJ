#include <iostream>
#include <queue>
using namespace std;
using ll = long long;

const ll MAX = 101010;
ll n, m, d[MAX], cnt[MAX];
queue <ll> q;

void bfs(ll st){
    q.push(st); 
    d[st] = 0; cnt[st] = 1;
    while(!q.empty()){
        ll cur = q.front(); q.pop();
        for(auto& nxt : {cur + 1, cur - 1, 2 * cur}){
            if(nxt < 0 || nxt >= MAX) continue;
            if(d[nxt] == -1){
                q.push(nxt); 
                d[nxt] = d[cur] + 1;
            }

            if(d[nxt] == d[cur] + 1) cnt[nxt] += cnt[cur];
        }
    }
}

int main(){
    ios::sync_with_stdio(0); // fastio
    cin.tie(0), cout.tie(0); // fastio

    cin >> n >> m;
    for(int i = 0;i < MAX;i++) d[i] = -1;
    bfs(n);

    cout << d[m] << "\n" << cnt[m];

    return 0;
}