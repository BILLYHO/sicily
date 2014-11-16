/*=============================================================================
#
# Author: BILLY HO 
# Email: billyho0906@gmail.com
#
# Established:      2012-09-25 18:37
# Last modified:	2012-09-25 20:43
#
# Filename:		1021.cpp
#
# Description: 
#
=============================================================================*/

#include <iostream>
#include <cstdlib>

using namespace std;

struct Node
{
    int data;
    Node* pre;
    Node* next;
};

Node *cur, *pre, *start, *newptr, *i;

void create (int n)
{
    start = (Node*)malloc(sizeof(Node));
    start->data = 1;
    cur = pre = start;
    for(int i=2; i<=2*n; i++)
    {
        cur->next = (Node*)malloc(sizeof(Node));
        cur = cur->next;
        cur->data = i;
        cur->pre = pre;
        pre = pre->next;
    }
    cur->next = start;
    start->pre = cur;
}

void find(int k,Node* &cur)
{
    if(start->data == k)
    {
    //    cout << start->data << endl;
        cur = start;
    //    cout << "one" << endl;
        return;
    }
    else
    {
        for(i=start->next; i!=start; i=i->next)
        {
            if(i->data == k)
            {
                cur = i;
        //        cout << "two" << endl;
                return;
            }
        }
        cur = NULL;
       // cout << "three" << endl;
        return;
    }
}

void remove(int a[], int b[],int n, int &size)
{
    for(int i=0; i<n; i++)
    {
        //cout << i << endl;
        //cout << a[i] << endl;
        if(a[i]==0)
            continue;
        find(a[i],cur);
        if(cur != NULL)
        {
        //    cout << cur->next->data << " " << cur->pre->data << endl;
            if(n==2 && (cur->next)->data == b[i])
            {
                free(cur->next);
                free(cur);
                start = NULL;
                size-=2;
            }
            else if((cur->next)->data == b[i])
            {
                pre = cur->pre;
                pre->next = (cur->next)->next;
                newptr = (cur->next)->next;
                newptr->pre = pre;
                start = pre;
                free(cur->next);
                free(cur);
                size -= 2;
                //cout << a[i] << " " << b[i] << endl;
                a[i] = 0;
                
            }
            else if((cur->pre)->data == b[i])
            {
                pre = (cur->pre)->pre;
                newptr = cur->next;
                pre->next = newptr;
                newptr->pre = pre;
                free(cur->pre);
                free(cur);
                start = pre;
                size -= 2;
           //     cout << a[i] << " " << b[i] << endl;
                a[i] = 0;
            }
        }
    }
}


int main ()
{
    int n;
    while(cin>>n ,n!=0)
    {
        create(n);      

        int a[n],b[n];
        for(int i=0; i<n; i++)
            cin >> a[i] >> b[i];
        //for(int i=0; i<n; i++)
          //  cout << a[i] << b[i] << endl;
        int size,size_pre;
        size = n*2;
//        cout << size << "  " << size_pre << endl;
       // for(int i=0; i<4; i++)
        while( size != 0)
        {
            size_pre = size;
//            cout << size << "   " << size_pre << endl;
            remove(a,b,n,size);
   //         cout << size << "   " << size_pre << endl;
            if (size == size_pre)
                break;
        }
        cout << size << endl;
        if(size == 0)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
       /* if(start!=NULL)
        {
            cout << start->data << endl;
            for(Node* j=start->next; j!=start; j = j->next)
                cout << j->data << endl;
        }
*/
    }
}
