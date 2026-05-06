class Solution {
public:

    int par[101], size_[101];

    void make_set(int a) {
        par[a] = a;
        size_[a] = 1;
    }

    int find_set(int a) {
        if ( par[a] == a )
            return a;
        return par[a] = find_set(par[a]);
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);

        if (a!=b) {
            if ( size_[a] < size_[b] )
                swap(a,b);
            par[b] = a;
            size_[a] += size_[b];
        }

    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ret;
        for ( int i = 1; i <= edges.size(); i++ )
            make_set(i);
        for ( auto x : edges ) {
            if ( find_set(x[0]) == find_set(x[1]) )
                ret = x;
            else
                union_sets(x[0],x[1]);
        }
        return ret;
    }
};
