#include<iostream>
#include<string.h>
#include<queue>
#include<limits.h>
bool bfs(int g[6][6],int s,int t,int parent[]){
	bool visited[6];
	for(int i=0;i<6;i++){
		visited[i]=0;
	}
	std::queue<int> q;
	q.push(s);
	visited[s]=true;
	parent[s]=-1;
	
	while(!q.empty()){
		int x=q.front();
		q.pop();
		
		for(int j=0; j<6;j++){
			if(visited[j]==false && g[x][j]>0){
				q.push(j);
				parent[j]=x;
				visited[j]=true;
			}
		}
	}
	return (visited[t]==true);
}
int fordFulkerson(int** g,int s,int t){
	int u,v;
	
	int residG[6][6];
	
	for(u=0;u<6;u++){
		for(v=0;v<6;v++){
			residG[u][v]=g[u][v];
		}
	}
	
	int parent[6];
	
	int max_flow=0;
	
	while(bfs(residG,s,t,parent)){
		int path_flow=INT_MAX;
		for(v=t; v!=s;v=parent[v]){
			u=parent[v];
			path_flow=std::min(path_flow,residG[u][v]);
		}
		for(v=t;v!=s;v=parent[v]){
			u=parent[v];
			residG[u][v] -= path_flow;
			residG[u][v] += path_flow;
		}
		max_flow+=path_flow;
	}
	return max_flow;
}

int main(){
	int graph1[][6]{{0,16,13,0,0,0},
			 {0,0,10,12,0,0},
			 {0,4,0,0,14,0},
			 {0,0,9,0,0,20},
			 {0,0,0,7,0,4},
			 {0,0,0,0,0,0}	
			};
	std::cout<<"The maximum possible flow for graph 1 is ~> "<< fordFulkerson(graph1,0,5);

	

	return 0;
}
