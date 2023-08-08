class FenwickTree{
    private:
    int N;
    int* fen;

    public:
    FenwickTree(int sz){
        N=sz+1;
        fen=new int[N];
    }

    void update(int i, int add){
        while(i<N){
            fen[i]+=add;
            i+=(i & (-i));
        }
    }

    int sum(int i){
        int s=0;
        while(i>0){
            s+=fen[i];
            i-=(i & (-i));
        }
        return s;
    }
};
