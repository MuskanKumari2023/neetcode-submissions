class Node{
        public:
            Node* next;
            Node* prev;
            int key,val;
            Node(int k,int v){
                key=k;
                val=v;
                next=NULL;
                prev=NULL;
            }
    };
class LRUCache {
public:
    int limit;
    Node* head;
    Node* tail;
    map<int,Node*>mp;
    void insert(Node* node){
        Node* next=head->next;
        head->next=node;
        node->prev=head;
        node->next=next;
        next->prev=node;
    }
    void remove(Node* node){
        Node* prev=node->prev;
        Node* next=node->next;
        prev->next=next;
        next->prev=prev;
    }
    LRUCache(int capacity) {
        limit=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())return -1;
        Node* node=mp[key];
        remove(node);
        insert(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* node=mp[key];
            node->val = value;
            remove(node);
            insert(node);
        }
        else{
            Node* node=new Node(key,value);
            insert(node);
            mp[key]=node;
            if(mp.size()>limit){
                Node* delNode=tail->prev;
                mp.erase(delNode->key);
                remove(delNode);
            }
        }
    }
};
