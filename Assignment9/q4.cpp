#include <iostream>
using namespace std;

int main() {
    int n, e;
    cin >> n >> e;

    int arr[100][100] = {0};
    for(int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        arr[u][v] = w;
        arr[v][u] = w;
    }

    int start;
    cin >> start;

    int dist[100];
    bool visited[100];

    for(int i = 0; i < n; i++) {
        dist[i] = 1000000; 
        visited[i] = false;
    }

    dist[start] = 0;
    for(int k = 0; k < n; k++) {
        int u = -1;
        for(int i = 0; i < n; i++) {
            if(!visited[i] && (u == -1 || dist[i] < dist[u])) {
                u = i;
            }
        }

        visited[u] = true;
        for(int v = 0; v < n; v++) {
            if(arr[u][v] != 0 && visited[v] == false) {

                int newDist = dist[u] + arr[u][v];

                if(newDist < dist[v]) {
                    dist[v] = newDist;
                }
            }
        }
    }

    cout << "Shortest distances:"<<endl;
    for(int i = 0; i < n; i++) {
        cout << "Node " << i << " : " << dist[i] << endl;
    }

    return 0;
}

