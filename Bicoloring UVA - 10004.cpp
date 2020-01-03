#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define maxn 205

int m[maxn][maxn];
int visited[maxn],color[maxn];
int node,edge,res;
int QUEUE[100005],f=0,r=-1;
bool bfs(int src){

    QUEUE[++r]=src;
    visited[src]=1;
    color[src]=1;
    res=1;
    while(f<=r){
        int u=QUEUE[f];
        f++;
        for(int i=0 ; i<node ; i++){
            if(m[u][i]){
                int v=i;
                if(!visited[v]){
                    visited[v]=1;
                    QUEUE[++r]=v;
                    color[v] = 1-color[u];
                }
                if(color[v]==color[u]) return false;
            }
        }
    }
    return true;

}

int main(){

    while(cin >> node ){

        if(node==0) break;
        cin >> edge;

        memset(m, 0 , sizeof(m));
        memset(visited, 0 , sizeof(visited));
        memset(color, 0 , sizeof(color));
        f=0,r=-1;
        for(int i=1; i<=edge ; i++){
            int u,v;
            cin >> u >> v;
            m[u][v]=1;
            m[v][u]=1;
        }

        if(bfs(0)){
            cout << "BICOLORABLE." << endl;
        }else {
            cout << "NOT BICOLORABLE." << endl;
        }

    }

    return 0;
}
