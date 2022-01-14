// C++ program to find maximum rectangular area in
// linear time
#include <bits/stdc++.h>
using namespace std;

long long getMaxArea(long long arr[], int n)
{
    // Your code here
    //we create an empty stack here.
    stack<long> s;
    //we push -1 to the stack because for some elements there will be no previous
    //smaller element in the array and we can store -1 as the index for previous smaller.
    s.push(-1);
    long long area = arr[0];
    long long i = 0;
    //We declare left_smaller and right_smaller array of size n and initialize them with -1 and n as their default value.
    //left_smaller[i] will store the index of previous smaller element for ith element of the array.
    //right_smaller[i] will store the index of next smaller element for ith element of the array.
    vector<long long> left_smaller(n, -1), right_smaller(n, n);
    while (i < n)
    {
        while (!s.empty() && s.top() != -1 && arr[s.top()] > arr[i])
        {
            //if the current element is smaller than element with index stored on the
            //top of stack then, we pop the top element and store the current element index
            //as the right_smaller for the poped element.
            right_smaller[s.top()] = i;
            cout << "\npop " << s.top();
            s.pop();
        }
        if (i > 0 && arr[i] == arr[i - 1])
        {
            //we use this condition to avoid the unnecessary loop to find the left_smaller.
            //since the previous element is same as current element, the left_smaller will always be the same for both.
            left_smaller[i] = left_smaller[i - 1];
        }
        else
        {
            //Element with the index stored on the top of the stack is always smaller than the current element.
            //Therefore the left_smaller[i] will always be s.top().
            left_smaller[i] = s.top();
        }
        s.push(i);
        cout << "\npush " << i;
        i++;
    }
    for (int j = 0; j < n; j++)
    {
        //here we find area with every element as the smallest element in their range and compare it with the previous area.
        // in this way we get our max Area form this.
        long long maxArea = arr[j] * (right_smaller[j] - left_smaller[j] - 1);
        cout << "current-l-r-i:"
             << maxArea << " " << left_smaller[j] << " " << right_smaller[j] << " " << j << endl;
        area = max(area, maxArea);
    }
    return area;
}

// Driver program to test above function
int main()
{
    int n;
    cin >> n;
    do
    {
        long long arr[n + 1];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << getMaxArea(arr, n) << endl;
        cin >> n;
    } while (n != 0);
}