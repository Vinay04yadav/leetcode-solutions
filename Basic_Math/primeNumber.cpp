#include <iostream>

using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
    {
        return false;
    }

    int count = 0;

    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            count++;

            if (n / i != i)
            {
                count++;
            }
        }
    }

    return count == 2;
}

int main()
{

    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;

    while (t)
    {

        int n;
        cout << "Enter the number: ";
        cin >> n;

        if (isPrime(n))
        {
            cout << "Prime\n";
        }
        else
        {
            cout << "Not Prime\n";
        }

        t--;
    }

    return 0;
}