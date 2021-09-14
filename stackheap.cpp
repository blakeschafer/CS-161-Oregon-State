#include <iostream>
using namespace std;

int main()
{

    int stack_array[10]; //declaring a static array
    int *heap_array = NULL; //declaring a pointer to an array to put on the heap

    //how do i allocate 10 ints for heap_array
    int size = 10; //user input
    heap_array = new int[size]; //new puts array on heap

    //how do i intialize the 1st element in arrays
    stack_array[0] = 0;
    *stack_array = 0;

    heap_array[0] = 0;
    *heap_array = 0;

    //how do i initialize the 3rd element in arrays to 5
    stack_array[2] = 5;
    *(stack_array + 2) = 5;
    
    heap_array[2] = 5;
    *(heap_array + 2) = 5;

    //how do i print the contents of the first element
    cout << stack_array[0] << endl;
    cout << *(stack_array + 2) << endl;

    cout << heap_array[0] << endl;
    cout << *(heap_array + 2) << endl; 

    //how do i print the addr of the pointer to the arrays
    cout << &stack_array << endl;
    cout << &heap_array << endl;

    //what is the content of the pointer, and how do i print it
    cout << stack_array << endl;
    cout << heap_array << endl;

    //how do i print the addr of where the array begins in memory
    cout << &(stack_array[0]) << endl;
    cout << &(heap_array[0]) << endl;

    cout << &(stack_array[1]) << endl;
    cout << &(heap_array[1]) << endl;

    delete [] heap_array;
    heap_array = NULL;

    return 0;
}