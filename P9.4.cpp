#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
    map<string, vector<string>> directory;
    int choice;

    do
    {
        cout << "\n1. Add Folder\n2. Add File\n3. Display Directory\n4. Exit\nEnter choice: ";
        cin >> choice;

        if(choice == 1)
        {
            string folder;
            cout << "Enter folder name: ";
            cin >> folder;

            if(directory.find(folder) == directory.end())
                directory[folder] = vector<string>();
            else
                cout << "Folder already exists\n";
        }
        else if(choice == 2)
        {
            string folder, file;
            cout << "Enter folder name: ";
            cin >> folder;

            if(directory.find(folder) != directory.end())
            {
                cout << "Enter file name: ";
                cin >> file;

                bool exists = false;
                for(int i = 0; i < directory[folder].size(); i++)
                {
                    if(directory[folder][i] == file)
                        exists = true;
                }

                if(!exists)
                    directory[folder].push_back(file);
                else
                    cout << "File already exists in folder\n";
            }
            else
                cout << "Folder not found\n";
        }
        else if(choice == 3)
        {
            cout << "\nDirectory Contents:\n";
            for(map<string, vector<string>>::iterator it = directory.begin(); it != directory.end(); it++)
            {
                cout << it->first << ":\n";
                for(int i = 0; i < it->second.size(); i++)
                {
                    cout << "  " << it->second[i] << endl;
                }
            }
        }

    } while(choice != 4);

    return 0;
}