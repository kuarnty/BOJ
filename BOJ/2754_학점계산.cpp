#include <iostream>
#include <string>

using namespace std;

int main()
{
    string grade;
    cin >> grade;
    double g;
    if (grade == "F")
        g = 0.0;
    else if (grade == "A+")
        g = 4.3;
    else if (grade == "A0")
        g = 4.0;
    else if (grade == "A-")
        g = 3.7;
    else if (grade == "B+")
        g = 3.3;
    else if (grade == "B0")
        g = 3.0;
    else if (grade == "B-")
        g = 2.7;
    else if (grade == "C+")
        g = 2.3;
    else if (grade == "C0")
        g = 2.0;
    else if (grade == "C-")
        g = 1.7;
    else if (grade == "D+")
        g = 1.3;
    else if (grade == "D0")
        g = 1.0;
    else if (grade == "D-")
        g = 0.7;

    cout << fixed;
    cout.precision(1);

    cout << g;
}