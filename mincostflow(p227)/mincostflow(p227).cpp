#include <iostream>
#include <vector>

#define MAX_V 10

struct edge{
    int to, cost, capacity, rev;
};

int num_v;
vector<edge> G[MAX_V];
int dist[MAX_V];
int prevv[MAX_V], preve[MAX_V];

void add_edge(int from, int to, int cost, int capacity){
    G[from].push_back(edge(to,cost,capacity,G[to].size()));
    G[to].push_back(edge(from,-cost,0,G[from].size()-1));
}

int min_cost_flow(int s, int t, int f){
    
    while(f>0){
        bool update = true;
        while(update){
            update = false;
            for(int v=0; v<num_v; v++){
                if(dist[v] == INF) continue;
                for(int i=0; i<G[v].size(); i++){
                    edge &e = G[v][i];
                    if( e.cap > 0 && d[e.to] > d[v] + e.cost){
                        dist[e.to] = dist[v] + e.cost;
                        prevv[e.to] = v;
                        preve[e.to] = i;
                        update = true;
                    }
                }
            }
        }
        
        if(dist[t] == INF){
            return -1;
        }
        
        int d = f;
        for(int v=t; v != s; v=prevv[v]){
            d = min(d, G[prevv[v]][preve[v]].capacity);
        }
        
        f -= d;
        result += d*dist[t];
        
        for(int v=t; v!=s; v=prevv[v]){
            edge &e = G[prevv[v]][preve[v]];
            e.capacity -= d;
            G[e.to][e.rev].capacity +=d;
        }
    }
    
}



void init(){
    
    
}



