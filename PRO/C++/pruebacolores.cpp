#include <iostream>
#include <conio.h>
#ifdef _WIN32
#include <windows.h>
#endif
#define NC "\e[0m"
#define RED "\e[0;31m"
#define SUCESSB "\e[42m"
#define CYN "\e[0;36m"
#define ERRORB "\e[41m"

using std::cout; using std::endl;

int main()
{
    
    cout << SUCESSB "Some cyan colored text" NC << endl;
    cout << ERRORB "Add red background" NC << endl;
    cout << "reset to default colors with NC" << endl;
getch();
    return EXIT_SUCCESS;
}