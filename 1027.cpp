/*=============================================================================
#
# Author: BILLY HO 
# Email: billyho0906@gmail.com
#
# Established:      2013-01-20 11:10
# Last modified:	2013-01-20 11:32
#
# Filename:		1027.cpp
#
# Description: 
#
=============================================================================*/

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main ()
{
    int n;
    while(cin>>n, n!=0)
    {
        string a[n],b[n];
        for(int i=0; i<n; i++)
            cin >> a[i] >> b[i];


        map<string,string> m;
        for(int i=0; i<n; i++)
            for(int j=i+1; j<n; j++)
                if(b[i] == b[j])
                    m.insert(make_pair(a[i],a[j]));

        for(map<string,string>::iterator iter=m.begin(); iter != m.end(); iter++)
            cout << iter->second << " is the MaJia of " << iter->first << endl;
 		cout << endl;
    }
}
