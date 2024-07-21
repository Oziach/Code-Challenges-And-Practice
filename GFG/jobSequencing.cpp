class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr, arr+n, [](Job& a, Job& b){
           return a.profit > b.profit;
        });
        
        int totalProfit = 0;
        int numberOfJobs = 0;
        vector<int> scheduled(n+1, -1);
        
        for(int i = 0; i < n; i++){
            
            int deadline = arr[i].dead;
            int jobId = arr[i].id;
            int profit = arr[i].profit;
            
            for(int j = deadline; j >= 1; j--){
                if(scheduled[j] != -1){continue;}
                scheduled[j] = jobId;
                totalProfit += profit;
                numberOfJobs++;
                break;
            }
        }
        
        return {numberOfJobs, totalProfit};
    } 
};