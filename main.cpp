#include <iostream>
#include <vector>

using namespace std;

int main()
{
    const int m = 4;
    const int n = 3;

    vector<vector<int> >V_v(m, vector<int>(n));
    vector<vector<int> > ::iterator it_2;
    vector<int>::iterator it;
    int c = 0, a = 1;

    for (it_2 = V_v.begin(); it_2 < V_v.end(); it_2++)
    {

        vector<int> v(n);
        for(it = v.begin(); it < v.end(); it++)
        {
            *it = rand ()%9 + 1;
        }

        *it_2 = v;
        v.clear();
    }


    vector<int> ans(m*n);
    vector<int>::iterator it_3 = ans.begin();

    for (it_2 = V_v.begin(); it_2 < V_v.end(); it_2++)
    {
        for(it = (*it_2).begin(); it < (*it_2).end(); it++)
        {
            cout << (*it) << " ";;
        }
        cout << endl;
    }


    for (it_2 = V_v.begin(); it_2 < V_v.end();it_2++)
    {
        for (it = (*it_2).begin(); it < (*it_2).end(); it++)
        {

            it_3 = (it_2-V_v.begin())*n + (it-(*it_2).begin()) + ans.begin();
            *(it_3) = (*it);

        }
    }

    for (it_3 = ans.begin(); it_3 < ans.end(); it_3++)
    {
        cout << (*it_3)<<" ";
    }

    vector<vector<int> >ans2(m, vector<int>(n));
    vector<vector<int> > ::iterator it_4 = ans2.begin();
    vector<int>::iterator it_5;

    for (it_3 = ans.begin(); it_3 != ans.end(); it_3++)
    {
        it_4 = ans2.begin() + (it_3-ans.begin())/n;
        it_5 = (*it_4).begin() + (it_3-ans.begin())%n;
       *(it_5) = (*it_3);
    }

    cout << endl;
    for (it_4 = ans2.begin(); it_4 < ans2.end(); it_4++)
    {
        for (it_5 = (*it_4).begin(); it_5 < (*it_4).end(); it_5++)
            cout << (*it_5)<<" ";
        cout << endl;
    }
    return 0;
}
