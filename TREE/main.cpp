#include <iostream>
using namespace std;
#include "tree.h"
int main()
{
        Tree<int> t;
        t.AddChild(10);
        t.AddChild(6);
        t.AddChild(2);
        t.AddChild(8);
        t.AddChild(15);
        t.AddChild(11);
        t.AddChild(13);
        t.AddChild(9);
        t.AddChild(19);
        t.AddChild(7);
        t.InOrder();
        t.PreOrder();
        t.PostOrder();
        cout<<t.Height()<<endl;
        //cout<<t.Seach(9);
        //cout<<t.Seach_Max()<<endl;
        return 0;
}
