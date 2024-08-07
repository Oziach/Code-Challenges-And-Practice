class Node{
public:

    Node* prev;
    Node* next;
    pair<int,int> keyValue;

    Node(pair<int,int> data){
        keyValue = data;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache {
private:
Node* dummyHead;
Node* dummyTail;

unordered_map<int, Node*> m;
    int capacity;

public:
    LRUCache(int capacity) {
        dummyHead = new Node({-1,-1});
        dummyTail = new Node({-1,-1});
        dummyHead->next = dummyTail;
        dummyTail->prev = dummyHead;

        this->capacity = capacity;
    }
    
    int get(int key) {
        if(!m.count(key)){return -1;}

        //key present
        AddToQueueBack(m[key]);
        return m[key]->keyValue.second;
    }
    
    void put(int key, int value) {
        
        if(!m.count(key) && m.size() == capacity){
            //remove end of q
            Node* toRemove = dummyTail->prev;
            m.erase(toRemove->keyValue.first);
            PluckNode(toRemove);
            delete toRemove;
        }
    
        if(!m.count(key)){
            Node* newNode = new Node({key, value});
            m[key] = newNode;
            AddToQueueBack(newNode);
        }
        else{ //just update existing
            m[key]->keyValue.second = value;
            AddToQueueBack(m[key]);
        }
        
    }

    void PluckNode(Node* node){

        if(node->prev){node->prev->next = node->next;}
        if(node->next){node->next->prev = node->prev;}
        node->next = NULL;
        node->prev = NULL;
    }

    void AddToQueueBack(Node* node){
        PluckNode(node);
        dummyHead->next->prev = node;
        node->next = dummyHead->next;
        dummyHead->next = node;
        node->prev = dummyHead;
    }

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */