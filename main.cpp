#include <iostream> // <<<  ENTER YOUR NAME  HERE  >>>
#include <cstdlib>
#include <ctime>
#include<sstream>
using namespace std;

// student struct definition - given
struct student {
    string name;
    string studentNumber;
    int age;
};



double average_array_notation(int[], int);
double average_pointer_notation(int *, int);

// Do NOT modify any code that is given to you.
// Test each task as you complete it to ensure that it is correct.

void question1() {  // Topic: Accessing array using Pointer Notation

    double array[] = {1.1, 2.2, 3.3, 4.4, 5.5};

    //TODO  1a. Declare a pointer named 'ptr' and assign it
    //      to point at the array 'array'

    double *ptr = array;

    //TODO  1b. Write a for(){} loop that will output all elements in
    //      the array using POINTER NOTATION (NOT Array notation)
    //      by de-referencing the pointer.

    for (int i = 0; i < 5; i++) {    // hardcode OK here as sizeof() required below
        cout << *ptr << endl;
        ptr++;
    }

    //TODO  1c. Output the size in bytes of the pointer 'ptr'

    cout << "sizeof(ptr) = " << sizeof(ptr) << endl;

    //TODO 1d. Write code to calculate the number of elements in the
    //         array 'array' (i.e. Output the number of elements
    //         in the array 'array' without hard-coding the size)

    cout << "Number of elements in array[] = "
         << "sizeof(array)/sizeof(double) = "
         << sizeof(array) / sizeof(double) << endl;

    //TODO 1e. Set the pointer 'ptr' to point at the LAST array element
    //     and output the last element using the pointer.

    int size = sizeof(array) / sizeof(double);
    ptr = array + size - 1;
    // ptr must be set to point at last element using the above
    // or some similar pointer manipulation.
    cout << "Last element = " << *ptr << endl;

    //TODO 1f. Using a for(){} loop, iterate in reverse (right-to-left)
    //         through the elements, outputting each element using
    //         the pointer 'ptr' and pointer notation. (NOT array notation)

    cout << "Array in reverse:\n";
    for (int i = 0; i < size; i++) {
        cout << *ptr << "," << endl;
        ptr--;  // decrement the pointer
    }

    //TODO g. Given an C-style string (i.e. array of char) that stores one word,
    //    declare a pointer pChar and set it to point at the first character
    //    in the string.
    //    Write a "while(){}" loop that will use the pointer and pointer notation
    //    to iterate through the characters of the string and maintain a count
    //    of the number of "lowercase s" characters in the word.
    //    Output the count of the characters.

    char word[] = "Mississippi";        // given

    char *pChar = word;
    int count = 0;
    while (*pChar != '\0') {
        if (*pChar == 's') {
            count++;
        }
        pChar++;
    }
    cout << "Count of 's' characters = " << count << endl;
}

void question2() {  // dynamic memory allocation

    //TODO 2a(i).
    //      Dynamically allocate a block of memory to store an array of 100
    //      integer values. Declare a variable called "array" that will store
    //      the address of the array block.
    //      Using array notation, iterate over the array and assign each
    //      element with a random value in the range 1 to 100.
    //      (Code to generate random number is given below)

    int size = 100;                        // size of array - given

    int *array = new int[size];

    // code to generate random number in a range
    srand((unsigned) time(0));      // use current time to seed rand() - given
    int randomNumber = (rand() % 100) + 1;    // IN RANGE 1 TO 100  - given

    cout << "Q2.a(i) Generate array of 100 random numbers (Range 1-48):" << endl;
    for (int index = 0; index < size; index++) {
        randomNumber = (rand() % 47) + 1;  // IN RANGE 1 TO 47
        array[index] = randomNumber;
        cout << randomNumber << ",";
    }
    cout << endl;

    //TODO  Q.2a(ii)
    //      Write a function average_array_notation() that accepts the array
    //      as a parameter, and iterates over the array to calculate and return
    //      the average of the EVEN values.  Output the returned average value.
    //      Use ARRAY Notation in your function.
    //      (Remember to use a function prototype if necessary)

    double average = average_array_notation(array, size);
    cout << "Q2a(ii) Average of even numbers = " << average << endl;

    //TODO  Q.2a(iii)
    //      Write a function average_pointer_notation() that accepts the array
    //      as a parameter, and iterates over the array to calculate and return
    //      the average of the ODD values.  Output the returned average value.
    //      Use POINTER Notation and pointer arithmetic in your function.
    //      (Remember to use a function prototype if necessary)

    double average2 = average_pointer_notation(array, size);
    cout << "Q2a(iii) Average of ODD numbers = " << average2 << endl;

    delete[] array;    // free up the memory block
    array = nullptr;    // prevent dangling pointer

    cout << "test" << endl;
}

// Q2.a(ii)
double average_array_notation(int array[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] % 2 == 0) {    // only even numbers
            sum = sum + array[i];
        }
    }
    return (double) sum / size;
}

// Q2.a(iii)
double average_pointer_notation(int* ptr_int, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if ( *ptr_int % 2 != 0) {    // only odd numbers
            sum = sum + *ptr_int;
        }
        ptr_int++;
    }
    return (double) sum / size;
}

//TODO Q3  (Recursion)
//      Write a recursive function called bounce() that will accept a starting integer value
//      and output a sequence of numbers, reducing by one on each iteration, down to zero,
//      followed by a sequence of increasing values as follows:
//      bounce(4)  - will print 4,3,2,1,0,1,2,3,4
//      bounce(3) – will print 3,2,1,0,1,2,3  etc.
//      Call your function with the integer argument 3.

//Q.3
void bounce(int n) {
    if (n > 0) {
        cout << n << ", ";
        bounce(n - 1);   // recursive call
    }
    cout << n << ", ";
}

// Q4(a)
void initialize_student(student& stuRef) {
    stuRef.name = "Joe Bloggs";
    stuRef.studentNumber = "D00002357";
    stuRef.age = 18;
}

// Q4(b)
void display(student s) {       // call by value
    cout << "Name: " << s.name << ", ";
    cout << "Number: " << s.studentNumber << ", ";
    cout << "Age: " << s.age << endl;
}

// Q4(c)
void incrementAge(student* pStudent) {  // pointer notation
    pStudent->age++;
}

//Q4(d)
void fillArray(student arr[], int size) {

    for (int i = 0; i < size; i++) {
        cout << "Enter name: ";
        getline(cin, arr[i].name);
        cout << "Enter ID: ";
        getline(cin, arr[i].studentNumber);
        cout << "Enter age: ";
        string temp;
        getline(cin, temp);
        (stringstream)temp >> arr[i].age;
    }
}

void question4() {
    cout << "Q4 - struct student" << endl;

    student studentA;   // creates a struct object
    initialize_student(studentA);
    incrementAge(&studentA);
    display(studentA);

    int size = 3;
    student* studentArray = new student[size];  // array of struct
    fillArray(studentArray,size);

    cout << "Q4(d) Display entered array of struct: " << endl;
    for (int i = 0; i < size; i++) {
        display(studentArray[i]);
    }

    // avoid memory leaks by freeing (deleting) the dynamic memory
    delete[] studentArray;
    studentArray = nullptr;

}

void question3() {
    cout << "Question 3 - calling bounce(3):";
    bounce(3);
}

int main() {
    std::cout << "OOP Practical Examination - CA1 - March 2022" << std::endl;
    //question1();
    //question2();
    //question3();
    //question4();

    return 0;
}

