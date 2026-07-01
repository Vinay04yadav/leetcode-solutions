// Problem: reverse integer
// Link: https://leetcode.com/problems/armstrong-number/description/
// Difficulty: Easy
// Topic: Basic Math

#include <iostream>

using namespace std;

bool isArmstrong(int n)
{

    int duplicate = n;
    int sum = 0;
    int lastDigit;

    while (n > 0)
    {
        lastDigit = n % 10;
        sum = sum + (lastDigit * lastDigit * lastDigit);
        n = n / 10;
    }

    if (sum == duplicate)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{

    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (isArmstrong(num))
    {
        cout << "Armstrong";
    }
    else
    {
        cout << "Not an Armstrong";
    }

    return 0;
}