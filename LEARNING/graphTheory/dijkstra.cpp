#include<climits>
#include<iostream>
#include<stdio.h>

#define V 9
// this is O(V^2) implementation
int minDistance(int dist[], bool sptSet[]){
    int min = INT_MAX, minIndex;

    for(int i = 0; i< V; i++){
        if(sptSet[i] == false && dist[i] <= min){
            min = dist[i], minIndex= i;
        }
       
    }
     return minIndex;
}

// A utility function to print the constructed distance array 
void printSolution(int dist[]) 
{ 
    printf("Vertex \t\t Distance from Source\n"); 
    for (int i = 0; i < V; i++) 
        printf("%d \t\t %d\n", i, dist[i]);
} 
  


void dijkstra(int graph[V][V], int src){
    bool sptSet[V]; // hold what vertices are not explored yet

    int dist[V]; // will hold the shortest distance from source to i 

    //initialising initial values
    for(int i = 0; i< V; i++){
        dist[i]= INT_MAX, sptSet[i]= false;
    }
    dist[src]=0;
    for(int count = 0; count<V-1; count++){

        int u = minDistance(dist, sptSet);
        sptSet[u]=true;
        for(int v = 0; v<V; v++){
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
                && dist[u] + graph[u][v] < dist[v]){ 
                dist[v] = dist[u] + graph[u][v]; 
            }
        }
    }

    printSolution(dist); 
}

int main(){
   int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
    
    dijkstra(graph, 0);
    return 0;
}