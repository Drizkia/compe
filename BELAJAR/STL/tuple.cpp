#include <iostream>
#include <tuple>
using namespace std;

void tuple_cat() { // Tuple didalam Tuple
    // Initializing 1st tuple
    tuple<int, char, float> tup1(20, 'g', 17.5);

    // Initializing 2nd tuple
    tuple<int, char, float> tup2(30, 'f', 10.5);
    
    // Concatenating 2 tuples to return a new tuple
    auto tup3 = tuple_cat(tup1, tup2);
    
    // Displaying new tuple elements
    cout << "The new tuple elements in order are: ";
    cout << get<0>(tup3) << " " << get<1>(tup3) << " " 
         << get<2>(tup3) << " " << get<3>(tup3) << " " 
         << get<4>(tup3) << " " << get<5>(tup3) << endl;
}


void tie() {
    // Initializing variables for unpacking
    int i_val;
    char ch_val;
    float f_val;   
    
    // Initializing tuple
    tuple<int, char, float> tup1(20, 'g', 17.5);

    // Use of tie() without ignore
    tie(i_val, ch_val, f_val) = tup1;
    
    // Displaying unpacked tuple elements without ignore
    cout << "The unpacked tuple values (without ignore) are: ";
    cout << i_val << " " << ch_val << " " << f_val;
    cout << endl;
    
    // Use of tie() with ignore
    // ignores char value
    tie(i_val, ignore, f_val) = tup1;
    
    // Displaying unpacked tuple elements with ignore
    cout << "The unpacked tuple values (with ignore) are: ";
    cout << i_val << " " << f_val;
    cout << endl;
}

int main() {
  
    // Declaring tuple
    tuple<char, int, float> geek;

    // Assigning values to tuple using make_tuple()
    geek = make_tuple('a', 10, 15.5);

    // Printing initial tuple values using get()
    cout << "The initial values of tuple are: ";
    cout << get<0>(geek) << " " << get<1>(geek);
    cout << " " << get<2>(geek) << endl;

    // Use of get() to change values of tuple
    get<0>(geek) = 'b';
    get<2>(geek) = 20.5;

    // Printing modified tuple values
    cout << "The modified values of tuple are: ";
    cout << get<0>(geek) << " " << get<1>(geek);
    cout << " " << get<2>(geek) << endl;

    return 0;
}