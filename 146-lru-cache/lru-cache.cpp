struct Node{
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int key,int val){
        this->key=key;
        this->val=val;
        this->prev=NULL;
        this->next=NULL;
    }
};
class LRUCache {
public:
    int cap;
    Node* head;
    Node* tail;
    map<int,Node*>mp;
    LRUCache(int capacity) {
        cap=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    void del(Node* node){
        Node* temp1=node->next;
        Node* temp2=node->prev;
        temp2->next=temp1;
        temp1->prev=temp2;
        node->next=NULL;
        node->prev=NULL;
    }
    void add(Node* node){
        Node* temp=head->next;
        head->next=node;
        temp->prev=node;
        node->next=temp;
        node->prev=head;
    }
    int get(int key) {
        if(mp.count(key)==0) return -1;
        Node* temp=mp[key];
        int val=temp->val;
        del(temp);
        add(temp);
        return val;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            Node* temp=mp[key];
            temp->val=value;
            del(temp);
            add(temp);
        }
        else{
            if(mp.size()==cap){
                Node* node=tail->prev;
                int k=node->key;
                mp.erase(k);
                del(node);
                delete(node);
                Node* temp=new Node(key,value);
                add(temp);
                mp[key]=temp;
            }
            else{
                Node* node=new Node(key,value);
                add(node);
                mp[key]=node;
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