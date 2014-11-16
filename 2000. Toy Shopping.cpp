#include<iostream>
#include<algorithm>

using namespace std;

struct toy
{
    int num;
    long int joy;
    long int price;
    double ratio;
};

bool cmp (toy a, toy b)
{
    return a.ratio>b.ratio;
}

int main (void)
{
    int n;
    toy a[25001];
    cin >> n;
    for (int i=0; i<n; i++)
    {
        cin >> a[i].joy >> a[i].price;
        a[i].num = i+1;
        if(a[i].joy==0)
            a[i].ratio = 0;
        else
            a[i].ratio = double(a[i].joy) / double(a[i].price);
    }
    sort(a,a+n,cmp);
    cout << a[0].price + a[1].price + a[2].price << endl;
    cout << a[0].num << endl;
    cout << a[1].num << endl;
    cout << a[2].num << endl;
}

