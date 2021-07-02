// C++ program to sizes of data types
// C++ program to demonstrate Local variables
// C++ program to demonstrate Static variables

#include <iostream>
using namespace std;

class Marks {

public:
    // This is a class variable
    static int studentNumber;

    // These variables are instance variables.
    // These variables are in a class
    // and are not inside any function
    int engMarks;
    int mathsMarks;
    int phyMarks;

    Marks()
    {

        // Modify the class variable
        ++studentNumber;
    };
};

// Setting the class variable of Marks
int Marks::studentNumber = 0;

// Driver code
int main()
{

    // object of Marks
    Marks obj1;
    obj1.engMarks = 50;
    obj1.mathsMarks = 80;
    obj1.phyMarks = 90;

    // displaying marks for first object
    cout << "Marks for object:\n";

    // Now to display the static variable,
    // it can be directly done
    // using the class name
    cout << Marks::studentNumber << endl;

    // But same is not the case
    // with instance variables
    cout << obj1.engMarks << endl;
    cout << obj1.mathsMarks << endl;
    cout << obj1.phyMarks << endl;
}
