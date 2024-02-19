#include <iostream>
//#include <bits/stdc++.h>

using namespace std;

int V;
int result = 0;

void floydWarshall(int graphdata[])
{
    int dist[100][100] = { 0 };
    int i, j, k;

    k = 0;
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if (i == j && graphdata[i * V + j] == 0) {
                return;
            }
            dist[i][j] = graphdata[i * V + j];
        }
    }

    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                dist[i][j] = dist[i][j] | (dist[i][k] & dist[k][j]);
            }
        }
    }

    bool same = true;
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if (dist[i][j] != graphdata[i * V + j]) {
                same = false;
                break;
            }
        }
    }

    if (same == true) {
        result++;
    }
}

void T(int graphdata[], int current) {
    if (current == V * V) {
        floydWarshall(graphdata);
        return;
    }
    graphdata[current] = 0;
    T(graphdata, current + 1);

    graphdata[current] = 1;
    T(graphdata, current + 1);
}

int main()
{
    scanf_s("%d", &V);

    int graphdata[10001];

    result = 0;
    T(graphdata, 0);

    printf("%d\n", result);

    return 0;
}
