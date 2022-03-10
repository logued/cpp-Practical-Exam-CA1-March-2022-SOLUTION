#include <iostream>
using namespace std;

// Student Name:  >>>>>>>>>    ENTER YOUR NAME HERE   <<<<<<<<<<<

// Do NOT modify any code that is given to you.
// Test each task as you complete it to ensure that it is correct.

void question1() {  // Topic: Accessing array using Pointer Notation

    double array[] = {1.1,2.2,3.3,4.4,5.5};

    // a. Declare a pointer named 'ptr' and assign it
    //    to point at the array 'array'

    double* ptr = array;

    // b. Write a for(){} loop that will output all elements in
    //    the array using POINTER NOTATION (NOT Array notation)
    //    by de-referencing the pointer.

    for(int i=0; i<5; i++) {    // hardcode OK here as sizeof() required below
        cout << *ptr << endl;
        ptr++;
    }

    // c. Output the size in bytes of the pointer 'ptr'

    cout << "sizeof(ptr) = " << sizeof(ptr) << endl;

    // d. Write code to calculate the number of elements in the
    //    array 'array' (i.e. Output the number of elements
    //    in the array 'array' without hard-coding the size)

    cout << "Number of elements in array[] = "
            << "sizeof(array)/sizeof(double) = "
            << sizeof(array)/sizeof(double) << endl;

    // e. Set the pointer 'ptr' to point at the LAST array element
    //    and output the last element using the pointer.

    int size = sizeof(array)/sizeof(double);
    ptr = array + size-1;
            // ptr must be set to point at last element using the above
            // or some similar pointer manipulation.
    cout << "Last element = " << *ptr << endl;

    // f. Using a for(){} loop, iterate in reverse (right-to-left)
    //    through the elements, outputting each element using
    //    the pointer 'ptr' and pointer notation. (NOT array notation)

    cout << "Array in reverse:\n";
    for( int i=0; i<size; i++) {
        cout << *ptr << "," << endl;
        ptr--;  // decrement the pointer
    }

    // g. Draw a memory diagram (on paper) that will show all variables
    //    and values in memory at this point in the execution of the program.
    //    i.e. diagram includes the pointer and the array variables.

        // Manual drawing activity ! Hand up drawing with name on it.

    // h. Given an C-style string (i.e. array of char) that stores one word,
    //    declare a pointer pChar and set it to point at the first character
    //    in the string.
    //    Write a "while(){}" loop that will use the pointer and pointer notation
    //    to iterate through the characters of the string and maintain a count
    //    of the number of "lowercase s" characters in the word.
    //    Output the count of the characters.

    char word[] = "Mississippi";        // given

    char* pChar = word;
    int count = 0;
    while( *pChar != '\0') {
        if(*pChar == 's'){
            count++;
        }
        pChar++;
    }
    cout << "Count of 's' characters = " << count << endl;
}

void question2() {  // dynamic memory allocation

    // a. Dynamically allocate a block of memory to store an
    //    array of 100 integer values. Declare a pointer
    //    called "array" that will store the address of the
    //    array block.
    //
    //    Using array notation, iterate over the array
    //    and output all elements in the array. Count an output
    //    all values greater than one million.
    //
    //    You must implement good dynamic memory management practices.
    //
    //    Type a comment in after your code explaining where
    //    the values displayed came from. ALso, comment on the
    //    repeatability of the (i.e. will your program always
    //    give the output that is currently displayed. Explain.


    int size=100;                   // given

    int* array = new int[size];
    int count = 0;
    for(int i=0; i<size; i++) {
        cout << array[i] << ", " ;
        if( array[i] > 1000000 ) {
            count++;
        }
    }
    cout << "2.a. Count of numbers between +- 1 million = " << count << endl;

    // ANSWER: Students should explain that the dynamic array will
    // initially contain garbage values and those values will be
    // valid integers. There will be a 'random' number of them falling
    // in the range s.
    //

    delete [] array;    // free up the memory block
    array = nullptr;    // prevent dangling pointer


cout << "test" << endl;

}



int main() {
    std::cout << "OOP Practical Examination - CA1 - March 2022" << std::endl;
    //question1();
    question2();
    return 0;
}

