#include <bits/stdc++.h>
using namespace std;
int n1, n2, n3;
int a1, a2, a3;
int b1, b2, b3;
int visited[100][100][100];
struct water
{
    int dungTich;
    int hientai;
    water(int x, int y)
    {
        dungTich = x;
        hientai = y;
    }
};
struct ocean
{
    water A;
    water B;
    water C;
};
ocean moveAtoB(water a, water b, water c)
{
    if (a.hientai + b.hientai <= b.dungTich)
    {
        //cout << "chuwa day" << endl;
        b.hientai = a.hientai + b.hientai;
        a.hientai = 0;
    }
    else
    {
        //cout << "day r" << endl;
        a.hientai = a.hientai - (b.dungTich - b.hientai);
        b.hientai = b.dungTich;
    }
    ocean d = {a, b, c};
    return d;
}
bool check(ocean d)
{
}
int Solve(water binh1, water binh2, water binh3)
{
    queue<ocean> Q;
    Q.push({binh1, binh2, binh3});
    visited[binh1.hientai][binh2.hientai][binh3.hientai] = 1;
    while (!Q.empty())
    {
        water tmp1 = Q.front().A;
        water tmp2 = Q.front().B;
        water tmp3 = Q.front().C;
        //cout << "Xet " << tmp1.hientai << "---" << tmp2.hientai << "---" << tmp3.hientai << endl;
        if ((tmp1.hientai == b1 && tmp2.hientai == b2 && tmp3.hientai == b3) ||
            (tmp1.hientai == b2 && tmp2.hientai == b1 && tmp3.hientai == b3) ||
            (tmp1.hientai == b3 && tmp2.hientai == b1 && tmp3.hientai == b2) ||
            (tmp1.hientai == b1 && tmp2.hientai == b3 && tmp3.hientai == b2) ||
            (tmp1.hientai == b2 && tmp2.hientai == b3 && tmp3.hientai == b1) ||
            (tmp1.hientai == b3 && tmp2.hientai == b2 && tmp3.hientai == b1))
        {
            return visited[tmp1.hientai][tmp2.hientai][tmp3.hientai];
        }

        ocean test = {tmp1, tmp2, tmp3};
        test = moveAtoB(tmp1, tmp2, tmp3);
        if (!visited[test.A.hientai][test.B.hientai][test.C.hientai])
        {
            visited[test.A.hientai][test.B.hientai][test.C.hientai] = visited[tmp1.hientai][tmp2.hientai][tmp3.hientai] + 1;
            // cout << "push " << test.A.hientai << "---" << test.B.hientai << "---" << test.C.hientai << endl;
            Q.push(test);
        }
        test = moveAtoB(tmp1, tmp3, tmp2);
        if (!visited[test.A.hientai][test.B.hientai][test.C.hientai])
        {
            visited[test.A.hientai][test.B.hientai][test.C.hientai] = visited[tmp1.hientai][tmp2.hientai][tmp3.hientai] + 1;
            // cout << "push " << test.A.hientai << "---" << test.B.hientai << "---" << test.C.hientai << endl;
            Q.push(test);
        }
        test = moveAtoB(tmp2, tmp1, tmp3);
        if (!visited[test.A.hientai][test.B.hientai][test.C.hientai])
        {
            visited[test.A.hientai][test.B.hientai][test.C.hientai] = visited[tmp1.hientai][tmp2.hientai][tmp3.hientai] + 1;
            //cout << "push " << test.A.hientai << "---" << test.B.hientai << "---" << test.C.hientai << endl;
            Q.push(test);
        }
        test = moveAtoB(tmp2, tmp3, tmp1);
        if (!visited[test.A.hientai][test.B.hientai][test.C.hientai])
        {
            visited[test.A.hientai][test.B.hientai][test.C.hientai] = visited[tmp1.hientai][tmp2.hientai][tmp3.hientai] + 1;
            //cout << "push " << test.A.hientai << "---" << test.B.hientai << "---" << test.C.hientai << endl;
            Q.push(test);
        }
        test = moveAtoB(tmp3, tmp1, tmp2);
        if (!visited[test.A.hientai][test.B.hientai][test.C.hientai])
        {
            visited[test.A.hientai][test.B.hientai][test.C.hientai] = visited[tmp1.hientai][tmp2.hientai][tmp3.hientai] + 1;
            // cout << "push " << test.A.hientai << "---" << test.B.hientai << "---" << test.C.hientai << endl;
            Q.push(test);
        }
        test = moveAtoB(tmp3, tmp2, tmp1);
        if (!visited[test.A.hientai][test.B.hientai][test.C.hientai])
        {
            visited[test.A.hientai][test.B.hientai][test.C.hientai] = visited[tmp1.hientai][tmp2.hientai][tmp3.hientai] + 1;
            // cout << "push " << test.A.hientai << "---" << test.B.hientai << "---" << test.C.hientai << endl;
            Q.push(test);
        }
        Q.pop();
    }
}
int main()
{
    cin >> n1 >> n2 >> n3;
    cin >> a1 >> a2 >> a3;
    cin >> b1 >> b2 >> b3;
    water binh1(n1, a1);
    water binh2(n2, a2);
    water binh3(n3, a3);
    cout << Solve(binh1, binh2, binh3) - 1;
}