#include <bits/stdc++.h>
using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int visited[26];
char a[24][24];

int r, c;
int mx = 1;

void dfs(int y, int x, int cnt) {
    mx = max(mx, cnt);

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= r || nx < 0 || nx >= c) {
            continue;
        }

        int alp = a[ny][nx] - 'A';

        if (visited[alp]) {
            continue;
        }

        visited[alp] = 1;
        dfs(ny, nx, cnt + 1);
        visited[alp] = 0;  
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        cin >> a[i];
    }

    visited[a[0][0] - 'A'] = 1;
    dfs(0, 0, 1);

    cout << mx;
}