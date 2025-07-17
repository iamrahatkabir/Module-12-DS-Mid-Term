#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

int main()
{
    list<string> website;

    string address;
    while(cin >> address && address != "end")
    {
        website.push_back(address);
    }

    auto current = website.begin();
    // cout << "Hello from current" << *current << endl;

    int q;
    cin >> q;
    while(q--)
    {
        string cmd;
        cin >> cmd;

        if(cmd == "visit")
        {
            string webName; cin >> webName;

            auto isfound = find(website.begin(), website.end(), webName);
            if(isfound != website.end())
            {
                cout << *isfound << endl;
                current = isfound;
            }
            else
            {
                cout << "Not Available" << endl;
            }

        }
        else if(cmd == "next")
        {
            // cout << "Hello from Next" << endl;
            if(next(current) != website.end())
            {
                current = next(current);
                cout << *current << endl;
            }
            else
            {
                cout << "Not Available" << endl;
            }
        }
        else if(cmd == "prev")
        {
            
            if(current == website.begin())
            {
                cout << "Not Available" << endl;
            }
            else
            {
                auto it = prev(current);
                current = it;
                cout << *current << endl;
            }

        }


    }

    // for(string s : website)
    // {
    //     cout << s << " ";
    // }


    return 0;
}