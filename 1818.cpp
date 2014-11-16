/*=============================================================================
#
# Author: BILLY HO 
# Email: billyho0906@gmail.com
#
# Established:      2012-12-16 14:16
# Last modified:	2012-12-16 18:34
#
# Filename:		1818.cpp
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
    int m,n,t,g;
    string s,b;

    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        multimap<string,int> a;
        for(int i=0; i<n; i++)
        {
            cin >> s >> g;
            a.insert(make_pair(s,g));
        }
        for(int i=0; i<m; i++)
        {
            cin >> b;
            multimap<string,int>::size_type k = a.count(b);
            multimap<string,int>::iterator iter = a.find(b);
           
            for(int i=1; i<k; iter++,i++);
            int j = iter->second;
    
                    if(j>100 || j<0)
                        cout << "Score is error!" << endl;
                    else if (j>=90)
                        cout << "A" << endl;
                    else if (j>=80)
                        cout << "B" << endl;
                    else if (j>=70)
                        cout << "C" << endl;
                    else if (j>=60)
                        cout << "D" << endl;
                    else
                        cout << "E" << endl;
            
            }
        }
    return 0;
}
