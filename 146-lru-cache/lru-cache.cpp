struct Node{
    int key;
    int val;
    Node* next;
    Node* prev;
    Node(){
        this->key=-1;
        this->val=-1;
        this->next=NULL;
        this->prev=NULL;
    }

    Node(int key,int val){
        this->key=key;
        this->val=val;
        this->next=NULL;
        this->prev=NULL;
    }
    
};
class LRUCache {
public:
    int cap;
    map<int,Node*>mp;
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);

    void del(Node* node){
        Node* temp=node->prev;
        Node* k=node->next;
        temp->next=k;
        k->prev=temp;
    }
    void add(Node* node){
        Node* temp=head->next;
        head->next=node;
        node->next=temp;
        node->prev=head;
        temp->prev=node;
    }
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(mp.count(key)==0) return -1;
        Node* temp=mp[key];
        del(temp);
        add(temp);
        return temp->val;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            Node* temp=mp[key];
            del(temp);
            Node* newNode=new Node(key,value);
            add(newNode);
            mp[key]=newNode;
        }
        else{
            if(int(mp.size())==cap){
               Node* lru=tail->prev;
               del(lru);
               mp.erase(lru->key);
               delete lru;
                Node* newNode=new Node(key,value);
                add(newNode);
                mp[key]=newNode;
            }
            else{
                Node* newNode=new Node(key,value);
                add(newNode);
                mp[key]=newNode;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */