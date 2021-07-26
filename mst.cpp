/ Time comnplexity: O(V^2)
// space Complexity: O(V)

// Function to construct and print MST for
// a graph represented using adjacency
// matrix representation, with V vertices.
// graph[i][j] = weight if edge exits else INT_MAX

int calMinIndex(vector<bool>&Inmst,vector<int>&key, int V){
     
     int min_val=INT_MAX;
     int min_index;
     
     for(int i=0;i<V;i++){
          
          if(Inmst[i]==false && key[i]<min_val){
              min_val=key[i];
              min_index=i;
          }
     }
     return min_index;
}
int spanningTree(int V, int E, vector<vector<int>> &graph) {
    
    //InMst vector to chcek if a vertex is included in mst or not
    vector<bool>Inmst(V,false);
    
    // vector to calcultae the minimum distance to reach every vertices
    vector<int>key(V,INT_MAX); // initailaised with INT_MAX as we have to find the minimum distance
    key[0]=0; // because the 0th vertex have minimum distance 0
    
    // run a loop till v-1 because mst will have v-1 edges only
    for(int i=0;i<V-1;i++){
          
          int u=calMinIndex(Inmst,key,V);  // find the index with minimum ditance which is not included inmst
          Inmst[u]=true;
          
          //find the nearest neighbour at min distance which is not visited and update the distance array/key array
          for(int i=0;i<V;i++){
              if(graph[u][i] && Inmst[i]==false && graph[u][i]<key[i])
                key[i]=graph[u][i];
         }
    }
    
    // sum up weights of Mst present in sistance/key array
    int res=0;
    for(int i=0;i<V;i++) res+=key[i];
    
    return res;
}
