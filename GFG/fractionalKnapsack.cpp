class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n) {
        
        sort(arr, arr + n, [](const Item& a, const Item& b){
            return (double(a.value) / a.weight) > (double(b.value) / b.weight);
        });
        
        int i = 0;
        double currentWeight = 0;
        double totalCost = 0;
        
        for(i; i < n && currentWeight < w; i++){
            int availableWeight = w - currentWeight;
            
            if(availableWeight > arr[i].weight){
                totalCost += arr[i].value;
                currentWeight += arr[i].weight;
            }
            else{
                totalCost += (double(availableWeight) / arr[i].weight) * arr[i].value;
                currentWeight += availableWeight;
            }
        }
        
        return totalCost;
    }
};