map<int,int> a;
map<int,int> b;
deque<int> c;
int cap;
LRUCache::LRUCache(int capacity) {
    cap=capacity;
    a.clear();
    b.clear();
    c.clear();
}

int LRUCache::get(int key) {
    int ans;
    if(a.find(key)!=a.end())
      {
          ans=a.find(key)->second;
          b[key]++;
          c.push_back(key);
        
      }
    else
        ans=-1;
    
    return ans;    
    
        
        
    
}

void LRUCache::set(int key, int value) {
    if(a.size()==cap&&a.find(key)==a.end())
        {
        
             int curr=c.at(0);
            while(b[curr]>1)
                {
                    b[curr]--;
                    c.pop_front();
                    curr=c.at(0);
                }
            a.erase(a.find(curr));    
            b.erase(b.find(curr));
            c.pop_front();
        }
        a[key]=value;
        b[key]++;
        c.push_back(key);
        
   

}
