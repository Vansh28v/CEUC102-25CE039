#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main()
{
    int n, x;
    vector<int> v;
    set<int> s;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(x);
        s.insert(x);
    }

    cout << "\nUnique elements (set): ";
    for(set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }

    vector<int> uniqueVec(s.begin(), s.end());

    cout << "\n\nConverted to vector: ";
    for(int i = 0; i < uniqueVec.size(); i++)
    {
        cout << uniqueVec[i] << " ";
    }

    cout << "\n\nDuplicates removed: " << v.size() - s.size() << endl;

    return 0;
}