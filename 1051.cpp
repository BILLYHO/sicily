#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int revolution, count;
    double diameter, time;

    count = 1;
    cin >> diameter >> revolution >> time;
    while(revolution != 0)
    {
        double dis = 3.1415927 * diameter * revolution / 12 / 5280;
        double mph = dis / time * 3600;
        printf("Trip #%d: %.2lf %.2lf\n",count++,dis,mph);
        cin >> diameter >> revolution >> time;
    }
    return 0;
}
