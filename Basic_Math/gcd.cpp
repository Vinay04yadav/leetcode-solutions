// Problem: GCD of Two numbers
// Difficulty: Medium
// Topic: Basic Math

// logic : Euclidean algorithm says: GCD(a,b) = GCD(a-b, b) where a > b;
// this algo can be narrowed down to: GCD(a,b) = GCD(a%b, b) where a > b;
// we have to keep doing this until one of the number becomes zero, the other one is the GCD

#include <iostream>

using namespace std;

int gcdOfNumbers(int a, int b)
{
    int gcd = 1;

    while (a > 0 && b > 0)
    {
        if (a > b)
            a = a % b;
        else
            b = b % a;
    }

    if (a == 0)
        return b;
    else
        return a;
}

int main()
{

    int t;
    cout << "Enter the number of test cases you want: ";
    cin >> t;

    while (t)
    {
        int a, b;
        cout << "Enter first number: ";
        cin >> a;

        cout << "Enter second number: ";
        cin >> b;

        int answer = gcdOfNumbers(a, b);
        cout << "The GCD of the numbers is: " << answer << endl;

        t--;
    }

    return 0;
}