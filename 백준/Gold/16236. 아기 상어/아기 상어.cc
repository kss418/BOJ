#include <iostream>
#include <algorithm>
#include <deque>
#include <queue>
#include <tuple>
using namespace std;
int n, num, curx, cury;
int arr[20][20] = {};
pair <int, int> cur;
deque <pair<int, int>> q;
int x[4] = { 0,-1,1,0 };
int y[4] = { -1,0,0,1 };
int eat = 0;
int big = 2;
int t = 0;
int resulty, resultx;
priority_queue <tuple <int,int, int>, vector<tuple <int,int, int>>, greater<tuple<int,int, int>>> pq;

void bfs() {
    int visited[20][20] = {};
    int d[20][20] = {};
    q.push_back(cur);
    curx = cur.first;
    cury = cur.second;
    visited[cury][curx] = 1;
    while (!q.empty()) {
        cur = q.front();
        q.pop_front();
        if (arr[cur.second][cur.first] != 0 && d[cur.second][cur.first] != 0 && arr[cur.second][cur.first] < big) {
            pq.push({ d[cur.second][cur.first],cur.second,cur.first });
        }
        for (int i = 0; i < 4; i++) {
            curx = cur.first + x[i];
            cury = cur.second + y[i];
            if (curx >= n || curx < 0 || cury >= n || cury < 0 || arr[cury][curx] > big) {
                continue;
            }
            if (visited[cury][curx] == 1) {
                continue;
            }
            visited[cury][curx] = 1;
            d[cury][curx] = d[cur.second][cur.first] + 1;
            q.push_back({ curx,cury });
        } 
    }
    if (pq.size() == 0) {
        return;
    }
    int len, a, b;
    tie(len, a, b) = pq.top();
    arr[a][b] = 0;
    cur = { b,a };
    t += len;
    eat += 1;
    if (eat == big) {
        big += 1;
        eat = 0;
    }
    while (!pq.empty()) {
        pq.pop();
    }

    bfs();
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> num;
            arr[y][x] = num;
            if (num == 9) {
                cur = { x,y };
                arr[y][x] = 0;
            }
        }
    }


    bfs();

    cout << t;
    return 0;
}