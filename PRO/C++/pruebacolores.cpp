#include <iostream>
#include <conio.h>
#ifdef _WIN32
#include <windows.h>
#endif
#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"

using std::cout; using std::endl;

int main()
{
    
    cout << CYN "Some cyan colored text" << endl;
    cout << REDB "Add red background" NC << endl;
    cout << "reset to default colors with NC" << endl;
getch();
    return EXIT_SUCCESS;
}