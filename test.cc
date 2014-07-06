#include <iostream>
#include <string>

using namespace std;

int main()
{
    {
        const string s = "a";
        cout << s << endl;

    {
        const string s = "another";
        cout << s <<endl;
    } ;
    }
    return 0;
}

