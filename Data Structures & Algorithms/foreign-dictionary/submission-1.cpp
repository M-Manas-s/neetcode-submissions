class Solution {
public:

    bool dfs(int n, vector<set<int>> &adj, map<int,int> &mp,
    vector<int> &vis, vector<int> &dfsvis) {

        vis[n] = 1;
        dfsvis[n] = 1;

        for ( auto x : adj[n]) {
            if ( dfsvis[mp[x] - 1] == 1 )
                return 1;
            int ret = dfs(mp[x] - 1,adj,mp,vis,dfsvis);
            if (ret == 1)
                return ret;
        }

        dfsvis[n] = 0;
        return 0;

    }

    bool cycle(vector<set<int>> &adj, map<int,int> &mp) {

        int n = adj.size();
        vector<int> vis(n), dfsvis(n);

        for ( int i = 0; i < n; i++ ) {
            if (vis[i] == 0) {
                bool res = dfs(i,adj,mp,vis,dfsvis);
                if (res == 1)
                    return 1;
            }
        }

        return 0;
    }

    string foreignDictionary(vector<string>& words) {
        
        map<int,int> mp;
        int cur_idx = 0;
        vector<set<int>> adj;
        map<int,int> ind;

        set<int> st;
        for ( auto x : words ) {
            for ( auto y : x) {
                if (st.count(y) == 0) {
                    st.insert(y);
                    mp[y] = cur_idx + 1;
                    cur_idx++;
                    adj.push_back(set<int>());
                    ind[y] = 0;
                }
            }
        }

        for ( int i = 0; i < words.size() - 1; i++ ) {
            string w1 = words[i];
            string w2 = words[i+1];

            int diff_pos = -1;

            for ( int j = 0; j < min(w1.length(), w2.length()); j++ ) {
                if ( w1[j] != w2[j] ) {
                    diff_pos = j;
                    break;
                }
            }

            if ( diff_pos == -1 && w1.size() > w2.size() )
                return "";
            else if (diff_pos != -1) {
                int w1_idx = mp[w1[diff_pos]] - 1;

                // cout << w1[diff_pos] << ' ' << w2[diff_pos] << endl;

                if (adj[w1_idx].count(w2[diff_pos]) == 0) {
                    adj[w1_idx].insert(w2[diff_pos]);
                    ind[w2[diff_pos]]++;
                }
            }
        }

        if ( cycle(adj,mp) )
            return "";

        // int p = 0;
        // for ( auto x : adj) {
        //     cout << p++ << ": ";
        //     for ( auto y : x )
        //         cout << mp[y] - 1 << ' ';
        //     cout << endl;
        // }
        
        queue<int> qu;
        for ( auto x : ind ) {
            if (x.second == 0) {
                qu.push(x.first);
            }
        }

        string res = "";

        while(!qu.empty()) {
            int top = qu.front();
            qu.pop();
            res += (char)top;
            for ( auto x : adj[mp[top]-1] ) {
                ind[x]--;
                if (ind[x] == 0) 
                    qu.push(x);
            }
        }

        return res;
    }
};
