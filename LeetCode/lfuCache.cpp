struct Node{
public:
    int key;
    int value;
    int freq;
};

class LFUCache {
private:
    unordered_map<int, list<Node>::iterator> keyToNode;
    unordered_map<int, list<Node>> freqToList;
    int minFreq;
    int capacity;

public:
    LFUCache(int capacity) {
        minFreq = 0;
        this->capacity = capacity;    
    }
    
    int get(int key) {
        if(!keyToNode.count(key)){return -1;}

        auto node = keyToNode[key];
        int value = node->value;

        IncreaseFrequency(node); 
        //node becomes null
     
        return value;
    }
    
    void put(int key, int value) {

        if(!keyToNode.count(key) && keyToNode.size() == capacity){
            keyToNode.erase(freqToList[minFreq].begin()->key);
            freqToList[minFreq].pop_front();
        }

        if(!keyToNode.count(key)){
            Node newNode = {key, value, 0};
            freqToList[0].push_back(newNode);
            keyToNode[key] = freqToList[0].begin();
        }
        else{//simply update
            keyToNode[key]->value = value;
        }

        IncreaseFrequency(keyToNode[key]);
    }

    void IncreaseFrequency(list<Node>::iterator node){
        Node nodeObj = *node;
        freqToList[node->freq].erase(node);
        if(minFreq >= nodeObj.freq && freqToList[nodeObj.freq].empty()){minFreq = nodeObj.freq+1;}
        nodeObj.freq++;
        freqToList[nodeObj.freq].push_back(nodeObj);
        keyToNode[nodeObj.key] = --freqToList[nodeObj.freq].end();
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */