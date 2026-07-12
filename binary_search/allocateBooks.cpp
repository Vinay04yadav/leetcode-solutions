// Problem: Allocate Books
// Link: -
// Difficulty: Hard
// Topic: Binary Search

#include <bits/stdc++.h>
int countStudents(vector<int> &array, int pages, int n)
{
    int students = 1;
    int currentPages = 0;

    for (int i = 0; i < n; i++)
    {
        if (currentPages + array[i] <= pages)
        {
            currentPages += array[i];
        }
        else
        {
            students++;
            currentPages = array[i];
        }
    }

    return students;
}

int allocateBooks(vector<int> &pages, int n, int b)
{
    // Write your code here.

    if (b > n)
        return -1;

    int low = *max_element(pages.begin(), pages.end());
    int high = accumulate(pages.begin(), pages.end(), 0);

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        int students = countStudents(pages, mid, n);

        if (students > b)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return low;
}