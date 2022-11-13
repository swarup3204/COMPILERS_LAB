void floydWarshall(int graph[4][4])
{
    int dist[4][4], i, j, k;

    for (i = 0; i < 4; i++){
        for (j = 0; j < 4; j++){
            dist[i][j] = graph[i][j];
        }
    }       
    for (k = 0; k < 4; k++) {
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
 
}

 

int main()
{
    int graph[4][4];
 
    floydWarshall(graph);
    return 0;
}
