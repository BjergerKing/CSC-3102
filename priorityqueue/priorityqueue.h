// Implements a heap-based priority queue in the form of a character
// array. The character array can hold a maximum of 255 items.

#ifndef priorityqueue_h
#define priorityqueue_h

class PriorityQueue {
public:
    PriorityQueue();
    int size();
    void clear();
    void append(char a);
    bool check();
    void insert(char a);
    char remove();
    bool hasLeftChild(int index);
    bool hasRightChild(int index);
    
private:
    char heap[255];
    int size_;
};

#endif
