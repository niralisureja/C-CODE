class Solution {
private:
    int getDiameter(int curr, vector<vector<int>>& paths, int &d, vector<bool> &visited){
        visited[curr] = true;
        int max1=0, max2=0;
        for(int &p:paths[curr]){
            if(!visited[p]){
                int depth = getDiameter(p, paths, d, visited);
                if(depth>=max1){
                    max2=max1;
                    max1=depth;
                }
                else if(depth>max2) max2=depth;
            }
        }
        // diameter of curr node is max1+max2
        d = max(d, max1+max2);
        return max(max1,max2)+1;
    }
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int d1=0, d2=0, n=edges1.size()+1, m=edges2.size()+1;
        vector<vector<int>> paths(n);
        for(auto &e:edges1) {
            paths[e[0]].push_back(e[1]);
            paths[e[1]].push_back(e[0]);
        }
        vector<bool> visited(n, false);
        getDiameter(0, paths, d1, visited);

        paths = vector<vector<int>> (m);
        for(auto &e:edges2) {
            paths[e[0]].push_back(e[1]);
            paths[e[1]].push_back(e[0]);
        }
        visited = vector<bool> (m, false);
        getDiameter(0, paths, d2, visited);

        int d3 = (ceil((float) d1/2) + ceil((float) d2/2) +1);

        return max(d3, max(d1,d2));
    }
};