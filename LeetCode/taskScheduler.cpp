#include<bits/stdc++.h>

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        priority_queue<pair<int,char>> maxHeap;
        int count = 0;

        int freqs[26];
        for(int i = 0; i < 26; i++){
            freqs[i] = 0;
        }

        for(int i = 0; i < tasks.size(); i++){
            char ch = tasks[i];
            freqs[ch - 'A']++;
        }

        for(int i = 0; i < 26; i++){
            char ch = 'A' + i;
            if(freqs[i] > 0){
                maxHeap.push({freqs[i], ch});
            }
        }

        int time = 0;
        vector<pair<int,char>> coldStorage;

        while(!maxHeap.empty()){

            pair<int,char> task = maxHeap.top();
            maxHeap.pop();

            //task performed
            time++;

            //stove away in the cold storage
            task.first--;
            if(task.first != 0) coldStorage.push_back(task);

            if(!coldStorage.empty() && time % (n+1) == 0){
                for(int i = 0; i < coldStorage.size(); i++){
                    maxHeap.push(coldStorage[i]);
                }
                coldStorage.clear();
                vector<pair<int,char>> v;
                coldStorage = v;
            }

            if(!coldStorage.empty() && maxHeap.empty()){//ran out of tasks, but cold storage still has stuff
                time = ((time + n + 1)/(n+1))*(n+1);
                for(int i = 0; i < coldStorage.size(); i++){
                    maxHeap.push(coldStorage[i]);
                }
                coldStorage.clear();
            }
        }

        return time;

    }
};