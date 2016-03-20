// Implements a heap-based priority queue in the form of a character
// array. The character array can hold a maximum of 255 items.

#include "priorityqueue.h"
#include <iostream>
#include <cmath>

PriorityQueue::PriorityQueue()
{
    size_ = 0;
}

int PriorityQueue::size()
{
    return size_;
}

// Sets the size of the array to 0. Since all operations depend
// on this size, this essentially eleminates all array elements.
void PriorityQueue::clear()
{
    size_ = 0;
}

void PriorityQueue::append(char a)
{
    if(size_ == 255)  // Makes sure the array is not full before appending
    {
        std::cout << "Insert of '" << a << "' failed: The array is full\n";
    }
    else
    {
        heap[size_] = a;
        size_++;
    }
}

bool PriorityQueue::check()
{
    // Checks the heap order property for each array item
    for (int i = 0; i < size_; i++)
    {
        if (hasLeftChild(i))
        {
            if (heap[i] > heap[2*i + 1])
                return false;
        }
        if (hasRightChild(i))
        {
            if (heap[i] > heap[2*i + 2])
                return false;
        }
    }
    return true;  // Heap order property was not violated
}

void PriorityQueue::insert(char a)
{
    // Adds the new item to the end of the array
    append(a);
    
    // Sets the current index to the added item and finds its parent
    int currentIndex = size_ - 1;
    int parentIndex = floor((currentIndex - 1)/2);
    
    // While the child is smaller than the parent, swap it with the parent
    while (heap[currentIndex] < heap[parentIndex] && currentIndex != 0)
    {
        std::swap(heap[currentIndex], heap[parentIndex]);
        currentIndex = parentIndex;
        parentIndex = floor((currentIndex - 1)/2);
    }
}

char PriorityQueue::remove()
{
    // First item will be removed
    char itemRemoved = heap[0];
    
    // Sends the item to be removed to the back then deletes it
    std::swap(heap[0], heap[size_ - 1]);
    size_--;
    
    // Sets the current index and the index of its left and right children
    int currentIndex = 0;
    int leftIndex = 2*currentIndex + 1;
    int rightIndex = 2*currentIndex + 2;
    
    // Re-heapify the array
    while (hasLeftChild(currentIndex))
    {
        if (hasRightChild(currentIndex))
        {
            // If the current item is greater than its left or right child,
            // find the smaller of the two and swap with it
            if (heap[currentIndex] > heap[leftIndex] || heap[currentIndex] > heap[rightIndex])
            {
                if (heap[leftIndex] < heap[rightIndex])
                {
                    std::swap(heap[currentIndex], heap[leftIndex]);
                    currentIndex = leftIndex;
                }
                else
                {
                    std::swap(heap[currentIndex], heap[rightIndex]);
                    currentIndex = rightIndex;
                }
                
                // Calculates the left and right child for the new position
                leftIndex = 2*currentIndex + 1;
                rightIndex = 2*currentIndex + 2;
            }
            else
            {
                break;  // If it gets to this case it is in the correct position
            }
        }
        else if (heap[currentIndex] > heap[leftIndex])  // Current index only has left child
        {
            std::swap(heap[currentIndex], heap[leftIndex]);
        }
        else
        {
            break;  // If it gets to this case it is in the correct position
        }
    }
    return itemRemoved;  // Return the top item we removed
}

bool PriorityQueue::hasLeftChild(int index)
{
    if (2*index + 1 < size_)
        return true;  // Left child index is within current bounds
    else
        return false;
}

bool PriorityQueue::hasRightChild(int index)
{
    if (2*index + 2 < size_)
        return true;  // Right child index is within current bounds
    else
        return false;
}
