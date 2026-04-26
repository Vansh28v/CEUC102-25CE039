#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void display(vector<int> &v)
{
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
        cout << *it << " ";
    cout << endl;
}

void manualReverse(vector<int> &v)
{
    vector<int>::iterator start = v.begin();
    vector<int>::iterator end = v.end() - 1;

    while(start < end)
    {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main()
{
    int n, x;
    vector<int> v;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(x);
    }

    cout << "Original: ";
    display(v);

    vector<int> v1 = v;
    reverse(v1.begin(), v1.end());
    cout << "Using std::reverse: ";
    display(v1);

    vector<int> v2 = v;
    manualReverse(v2);
    cout << "Manual reverse: ";
    display(v2);

    return 0;
}