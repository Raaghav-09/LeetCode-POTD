class Node{
public:
    int key , val ; 
    Node* lptr ; 
    Node* rptr ; 
    Node(int key , int val){
        this->key = key ; 
        this->val = val ; 
        lptr = nullptr ; 
        rptr = nullptr ; 
    }
};
class DoublyLinkedList{
public:
    Node* head , *tail ; 
    DoublyLinkedList(){
        head = nullptr ; 
        tail = nullptr ; 
    }
    void insert(int key , int val){
        Node* newNode = new Node(key,val) ; 
        if(head == nullptr){
            head = newNode ; 
            tail = head ; 
            return ; 
        }

        tail->rptr = newNode ; 
        newNode->lptr = tail ; 
        tail = newNode ; 
    }
    void deleteAtHead(){
        if(head == nullptr) return ; 

        Node* temp = head ; 
        head = head->rptr ; 

        if(head == nullptr){
            tail = nullptr ; 
        }
        else{
            head->lptr = nullptr ; 
        }
    }
    void deleteThisNode(Node* &node){
        Node* prevNode = node->lptr ; 
        Node* nextNode = node->rptr ; 

        if(prevNode == nullptr && nextNode == nullptr){
            head = tail = nullptr ; 
            return ; 
        }
        else if(prevNode == nullptr){
            head = nextNode ; 
            nextNode->lptr = nullptr;
        }
        else if(nextNode == nullptr){
            tail = prevNode ; 
            tail->rptr = nullptr ; 
        }
        else{
            nextNode->lptr = prevNode ; 
            prevNode->rptr = nextNode ; 
        }

        node->lptr = nullptr ; 
        node->rptr = nullptr ; 
    }

};
class LRUCache {
    unordered_map<int,Node*> mp ;
    DoublyLinkedList dll ; 
    int cp ;
public:
    LRUCache(int capacity) {
        cp = capacity ; 
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1 ; 
        int val = mp[key]->val ; 
        dll.deleteThisNode(mp[key]) ; 
        dll.insert(key,val) ; 
        mp[key] = dll.tail ; 
        return val ; 
    }
    
    void put(int key, int value) {
        if(cp == 0) return ;

        if(mp.find(key) != mp.end()){
            dll.deleteThisNode(mp[key]) ; 
            mp.erase(key) ; 
        }

        if(mp.size() == cp){
            int keyToDelete = dll.head->key ; 
            mp.erase(keyToDelete) ; 
            dll.deleteAtHead() ; 
        }
        
        dll.insert(key,value) ; 
        mp[key] = dll.tail ; 
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */