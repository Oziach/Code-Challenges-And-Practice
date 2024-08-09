class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
       
        map<int,int> freq;
        int count = 0;

        for(int i = 0; i < hand.size(); i++){
            freq[hand[i]]++;
            count++;
        }

        //if not enough elements to make proper groups
        if(count % groupSize != 0){return false;}

        while(freq.size() > 0){

            map<int,int>::iterator it = freq.begin();
            int firstCount = it->second;
            int prev = it->first - 1;

            for(int i = 0; i < groupSize; i++){
                
                if(it->first - 1 != prev){return false;} //if not consectuive

                it->second -= firstCount;
                prev = it->first;

                if(it->second == 0){freq.erase(it->first);}
                else if(it->second < 0){return false;}

                it++;    

            }
        }

        return true;
    }
};