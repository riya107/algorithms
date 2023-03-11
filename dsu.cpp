class DSU{
    int *parent;
    int *rank;
public:
    DSU(int n){
        parent=new int[n];
        rank=new int[n];
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
            rank[i]=0;
        }
    }
    
    // Find function
    int find(int node){
        if(node==parent[node]) return node;
        return parent[node]=find(parent[node]);
    }
    
    // Union function 
     void Union(int u,int v){
        u=find(u);
        v=find(v);
        if(u!=v)
        {
            if(rank[u]<rank[v])
            {
                swap(u,v);
            } 
            parent[v]=u; 
            if(rank[u]==rank[v])
                rank[u]++;
        }
    }
};
