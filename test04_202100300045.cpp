#include <iostream>
#include <algorithm>

using namespace std;

struct eqlNode
{
    int eqlClass, size, next;
};

class unionfind
{
public:
    unionfind(int numberOfElements)
    {
        n = numberOfElements;
        node = new eqlNode[n + 1];

        for (int i = 1; i <= n; i++)
        {
            node[i].eqlClass = i;
            node[i].next = 0;
            node[i].size = 1;
        }
    };
    void unite(int classA, int classB)
    {
        if (node[classA].size > node[classB].size)
            swap(classA, classB);

        int k;
        for (k = classA; node[k].next != 0; k = node[k].next)
            node[k].eqlClass = classB;
        node[k].eqlClass = classB;

        node[classB].size += node[classA].size;

        node[k].next = node[classB].next;
        node[classB].next = classA;
    };
    int find(int theElement) { return node[theElement].eqlClass; };
    void output(){
    for (int i = 1; i <= n; i++)
        {
            if (node[i].eqlClass == i)
            {   
                int ans[node[i].size] = { 0 };
                int index = i;
                ans[0] = i;
                cout << "(";
                int t = 1;
                while (node[index].next)
                {   
                    ans[t++] = node[index].next;
                    index = node[index].next;

                }

                sort(ans,ans + node[i].size);

                for(int j = 0;j<node[i].size;j++){
                    if(j == node[i].size-1){
                        cout << ans[j];
                        break;
                    }
                    cout << ans[j] << ",";
                }
                cout << ")" << endl;
            }
    }
    };

private:
    eqlNode *node;
    int n;
};

void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
    return;
}

int main()
{
    cout << "Input" << endl;
    int n, r, a, b;
    cin >> n;
    unionfind obj(n);
    cin >> r;
    string s;
    for (int i = 0; i < r; i++)
    {
        cin >> s;
        a = s[1] - '0';
        b = s[3] - '0';
        int classA = obj.find(a);
        int classB = obj.find(b);
        if(classA != classB)
            obj.unite(classA, classB);
    }

    cout << "Output" << endl;
    obj.output();
    cout << "End" ;
    system("pause");
    return 0;
}