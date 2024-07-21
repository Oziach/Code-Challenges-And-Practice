struct Meeting{
    int id;
    int startTime;
    int endTime;
};

class Solution{
public:
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        
        vector<int> ans;
        Meeting* meetings = new Meeting[N];
        
        for(int i = 0; i < N; i++){
            meetings[i] = {i+1, S[i], F[i]};    
        }
        
        sort(meetings, meetings+N, [](const Meeting& a, const Meeting& b){
            return a.endTime < b.endTime;
        });
        
        int endTime = 0;
        for(int i = 0; i < N; i++){
            if(meetings[i].startTime > endTime){
                ans.push_back(meetings[i].id);
                endTime = meetings[i].endTime;
            }    
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};