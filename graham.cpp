#include <iostream>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
pair<int, int> minimum;
struct polar
{
        bool operator () (pair<int, int> a, pair<int, int> b)
        {
                int x1 = a.first-minimum.first;
                int y1 = a.second-minimum.second;
                int x2 = b.first-minimum.first;
                int y2 = b.second-minimum.second;
                return x1*y2 > x2*y1; //Return cross product of vectors treating minimum point as the origin
        }
}polar;
 
struct ymin
{
        bool operator () (pair<int, int> a, pair<int, int> b)
        {
                return a.second == b.second ? a.first < b.first : a.second < b.second; //Returns lowest point, resolving tie by left-most element
        }
}ymin;
 
int turn (pair<int, int> a, pair<int, int> b, pair<int, int> c)
{
        int x1 = a.first-b.first;
        int y1 = a.second-b.second;
        int x2 = c.first-b.first;
        int y2 = c.second-b.second;
        return x1*y2 - y1*x2; //If this quantity is positive, turn a-b-c is right.
}
 
stack<pair<int, int> > GrahamScan (vector<pair<int, int> > &v)
{
        pair<int, int> a = *min_element(v.begin(), v.end(), ymin);
        minimum = a;
        vector<pair<int, int> > newvec;
        for (int i = 0; i < v.size(); i++)
        {
                if (v[i] != minimum)
                        newvec.push_back(v[i]);
        }
        sort (newvec.begin(), newvec.end(), polar);
        stack<pair<int, int> > s;
        /*for (int i = 0; i<v.size(); i++)
                cout<<newvec[i].first<<" "<<newvec[i].second<<endl;*/
        s.push(minimum);
        s.push(newvec[0]);
        s.push(newvec[1]);
        pair<int, int> top, ntt;
        for (int i = 2; i<newvec.size(); i++)
        {
                if (!s.empty())
                {      
                        top = s.top();
                        s.pop();
                }
                if (!s.empty())
                {
                        ntt = s.top();
                        s.push(top);
                }
                pair<int, int> cur = newvec[i];
                while (turn (top, ntt, cur) <= 0)
                {
                        //While turns are non-left, pop.
                        if (!s.empty())
                        {
                                s.pop();
                        }
                        if (!s.empty())
                        {
                                top = s.top();
                                s.pop();
                        }
                        if (!s.empty())
                        {
                                ntt = s.top();
                                s.push(top);
                        }
                }
                s.push(newvec[i]);
        }
        return s;
}
 
int main(int argc, char const *argv[])
{
        vector<pair<int, int> > v;
        int cases, x, y;
        scanf("%d", &cases);
        while(cases--)
        {
                scanf("%d %d", &x, &y);
                v.push_back(make_pair(x, y));
        }      
        stack<pair<int, int> > s = GrahamScan(v); //Stack has points of convex hull in order
        pair<int, int> first = s.top();
        double distance = 0;
        vector<pair<int, int> > ch;
        while (!s.empty())
        {
                ch.push_back(s.top());
                s.pop();
        }
        for (int i =1; i < ch.size(); i++)
        {
                distance += sqrt((ch[i-1].first - ch[i].first)*(ch[i-1].first - ch[i].first) + (ch[i-1].second - ch[i].second)*(ch[i-1].second - ch[i].second));
        }
        distance += sqrt((ch[ch.size()-1].first - ch[0].first)*(ch[ch.size()-1].first - ch[0].first) + (ch[ch.size()-1].second - ch[0].second)*(ch[ch.size()-1].second - ch[0].second));
        int d = distance;
        printf("%d\n", d);
        return 0;
}
