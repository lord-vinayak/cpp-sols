class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(z>x+y)
            return false;
        if(x>y)
            swap(x,y);
        
        map<vector<int>,int> vis;
        queue<vector<int>> q;
        q.push({0,0});
        vis[{0,0}]++;
        
        while(!q.empty())
        {
            auto tmp=q.front();
            q.pop();
            
            if(tmp[0]+tmp[1]==z or tmp[0]==z or tmp[1]==z)
                return true;
            
            vector<int> k;
            
            //fill jug x
            k=tmp;
            k[0]=x;
            if(!vis[k])
            {
                vis[k]++;
                q.push(k);
            }
            
            //fill jug y
            k=tmp;
            k[1]=y;
            if(!vis[k])
            {
                vis[k]++;
                q.push(k);
            }
            
            //empty jug x
            k=tmp;
            k[0]=0;
            if(!vis[k])
            {
                vis[k]++;
                q.push(k);
            }
            
            //empty jug y
            k=tmp;
            k[1]=0;
            if(!vis[k])
            {
                vis[k]++;
                q.push(k);
            }
            
            k=tmp;
            k[0]=min(x , tmp[0]+tmp[1]);
            if(tmp[1]<x-tmp[0])
                k[1]=0;
            else
                k[1]=tmp[1]-(x-tmp[0]);
            
            if(!vis[k])
            {
                vis[k]++;
                q.push(k);
            }
            
            k=tmp;
            k[1]=min(y , tmp[0]+tmp[1]);
            if(tmp[0]+tmp[1]<y)
                k[0]=0;
            else
                k[0]=tmp[0]-(y-tmp[1]);
            
            if(!vis[k])
            {
                vis[k]++;
                q.push(k);
            }
        }
        
        return false;
    }
};