#include<unordered_map>
using namespace std;
struct DLinkedNode
{
    int key;
    int value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode()
    {
        key=0;
        value=0;
        prev=nullptr;
        next=nullptr;
    }
    DLinkedNode(int _key,int _value)
    {
        key=_key;
        value=_value;
        prev=nullptr;
        next=nullptr;
    }
    
};

class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity=capacity;
        size=0;
        head=new DLinkedNode();
        tail=new DLinkedNode();
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) 
    {
        if(!cache.count(key))
        {
            return -1;
        }
        else
        {
            DLinkedNode* node=cache[key];
            moveToHead(node);
            return node->value;
        }
    }
    void addToHead(DLinkedNode* node)
    {
        node->next=head->next;
        node->prev=head;
        head->next->prev=node;
        head->next=node;
    }
    void removeNode(DLinkedNode* node)
    {
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }
    void moveToHead(DLinkedNode* node)
    {
        removeNode(node);
        addToHead(node);
    }
    void put(int key, int value) {
        if(cache.count(key))
        {
            DLinkedNode* node=cache[key];
            node->value=value;
            moveToHead(node);
        }
        else
        {
            DLinkedNode* node=new DLinkedNode(key,value);
            cache[key]=node;
            addToHead(node);
            size++;
            if(size>capacity)
            {
                DLinkedNode* removeNode=removeTail();
                cache.erase(removeNode->key);
                delete removeNode;
                size--;
            }
        }
    }
    DLinkedNode* removeTail()
    {
        DLinkedNode* res=tail->prev;
        tail->prev->prev->next=tail;
        tail->prev=tail->prev->prev;
        return res;
    }
private:
    int capacity;
    int size;
    DLinkedNode* head;
    DLinkedNode* tail;
    unordered_map<int,DLinkedNode*> cache;
};