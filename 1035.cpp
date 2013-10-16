#include <iostream>
#include <string>
#include <set>

using namespace std;

int main ()
{
    int t,n,count;
    string s,temp;
    set<string> a;
    
    cin >> t;
    while(t--)
    {
        cin >> n;
        count = 0;
        for(int i=0; i<n; i++)
        {
            cin >> s;
            temp = s;
            for(int j=0; j<s.size(); j++)
            {
                if(s[j] == 'A')
                    temp[j] = 'T';
                else if(s[j] == 'T')
                    temp[j] = 'A';
                else if(s[j] == 'G')
                    temp[j] = 'C';
                else if(s[j] == 'C')
                    temp[j] = 'G';
            }
            set<string>::iterator iter = a.find(temp);
            if(iter == a.end())
                a.insert(s);
            else
            {
                count++;
                a.erase(iter);
            }
        }
        cout << count << endl;
    }
}
