// Programming Project 0

#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
    std::ifstream input(argv[1]);
    int i;
    int size = 0;
    int numbers[100];
    
    while (input >> i)
    {
        numbers[size] = i;
        size++;
    }
    
    // Bubble Sort
    bool swapped = true;
    int j = 0;
    int temp;
    while (swapped)
    {
        swapped = false;
        j++;
        for (int i = 0; i < size - j; i++)
        {
            if (numbers[i] > numbers[i + 1])
            {
                temp = numbers[i + 1];
                numbers[i + 1] = numbers[i];
                numbers[i] = temp;
                swapped = true;
            }
        }
    }
    
    
    // Print numbers array
    for (int y = 0; y < size; y++)
    {
        std::cout << numbers[y] << " ";
    }
    
    return 0;
}
