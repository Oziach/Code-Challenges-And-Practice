class Solution{
public:
    int pageFaults(int N, int C, int pages[]){
        list<int> q;
        map<int, list<int>::iterator> m;
        int faults = 0;
        
        for(int i = 0; i < N; i++){
            int page = pages[i];
            
            if(!m.count(page)){
                faults++;
                if(m.size() == C){
                    //delete lru
                    auto toDelete = q.front();
                    m.erase(toDelete);
                    q.pop_front();
                }
                
                q.push_back(page);
                m[page] = --q.end();
            }
            else{
                int toPush = *m[page];
                q.erase(m[page]);
                q.push_back(toPush);
            }
        }
        
        return faults;
    }
};