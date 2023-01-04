#include <iostream>
#include <string>
#include <thread>
using namespace std;

// The input string
string input_string;

// The reverse string
string reverse_string;

// The capitalized string
string capitalized_string;

// The shifted string
string shifted_string;

void input_thread()
{
    cout<<"Running Input Thread\n"<<endl;
    cout << "Enter a string: ";
    cin >> input_string;
}

void reverse_thread()
{
    // Reverse the input string
    cout<<"Running Reverse Thread\n"<<endl;
    reverse_string.resize(input_string.size());
    for (size_t i = 0; i < input_string.size(); ++i)
        reverse_string[i] = input_string[input_string.size() - 1 - i];

    cout << "Reversed string: " << reverse_string << endl;
}

void capital_thread()
{
    // Capitalize the input string
     cout<<"Running Capital Thread\n"<<endl;
    capitalized_string.resize(input_string.size());
    for (size_t i = 0; i < input_string.size(); ++i)
        capitalized_string[i] = toupper(input_string[i]);

    cout << "Capitalized string: " << capitalized_string << endl;
}

void shift_thread()
{
    // Shift the input string
     cout<<"Running Shift Thread\n"<<endl;
    shifted_string.resize(input_string.size());
    for (size_t i = 0; i < input_string.size(); ++i)
        shifted_string[i] = input_string[i] + 2;

 
    cout << "Shifted string: " << shifted_string << endl;
}

int main()
{
    // Create the input thread
    thread input_Thread(input_thread);

    // Wait for the input thread to finish
    input_Thread.join();
 cout<<"stop input Thread"<<endl;
    // Create the reverse, capital, and shift threads
    thread reverse_Thread(reverse_thread);
    thread capital_Thread(capital_thread);
    thread shift_Thread(shift_thread);

    // Wait for the reverse, capital, and shift threads to finish
    reverse_Thread.join();
     cout<<"stop reverse Thread"<<endl;
    capital_Thread.join();
     cout<<"stop capital Thread"<<endl;
    shift_Thread.join();
     cout<<"stop shift Thread"<<endl;

    return 0;
}
