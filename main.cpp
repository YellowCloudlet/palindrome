#include <bits/stdc++.h>

using namespace std;

// функция для проверки простоты числа
int easyValue(unsigned long a)
{
    unsigned long i1, i2, i3, i4, i5, i6, i7, i8, bound;
    if (a == 0 || a == 1)
        return 0;
    if (a == 2 || a == 3 || a == 5 || a == 7 || a == 11 || a == 13 || a == 17 || a == 19 || a == 23 || a == 29)
        return 1;
    if (a%2 == 0 || a%3 == 0 || a%5 == 0 || a%7 == 0 || a%11 == 0 || a%13 == 0 || a%17 == 0 || a%19 == 0 || a%23 == 0 || a%29 == 0)
        return 0;
    bound = sqrt((double)a);
    i1 = 31;
    i2 = 37;
    i3 = 41;
    i4 = 43;
    i5 = 47;
    i6 = 49;
    i7 = 53;
    i8 = 59;
    while (i8 <= bound && a%i1 && a%i2 && a%i3 && a%i4 && a%i5 && a%i6 && a%i7 && a%i8)
    {
        i1 += 30;
        i2 += 30;
        i3 += 30;
        i4 += 30;
        i5 += 30;
        i6 += 30;
        i7 += 30;
        i8 += 30;
    }
    if (i8 <= bound ||
            i1 <= bound && a % i1 == 0 ||
            i2 <= bound && a % i2 == 0 ||
            i3 <= bound && a % i3 == 0 ||
            i4 <= bound && a % i4 == 0 ||
            i5 <= bound && a % i5 == 0 ||
            i6 <= bound && a % i6 == 0 ||
            i7 <= bound && a % i7 == 0)
        return 0;
    return 1;
}

// функция для нахождения транспонированного числа для последующей проверки на то, является ли число палиндромом
unsigned long long reverseFunction(unsigned long long x)
{
    unsigned long long y = 0,check=x;
    while(x)
    {
        y = y*10 + x%10;
        x /= 10;
    }
    return y==check;
}

// выделяем массив с памятью глобально что бы измежать проблем с ограничением стека
unsigned long long n = 99999;

int main()
{

    unsigned long long result = 0; //обьявяем наш
    unsigned long long v1=0; //1 q-й сомножитель
    unsigned long long v2=0;
    int step=0;
    vector<long long>a;
    a.reserve(1);
    for(int i=10000; i<=n; i++)
    {
        if(easyValue(i))
        {
            a.push_back(i);
            i++;
        }
    }

// массив для перебора по очереди значений, проверки их на простоту, перемножения и проверки результата на палиндром
    for (unsigned long long i = 0; i <= a.size()/2; ++i)
    {
        for(unsigned long long j = i+1; j <= a.size(); ++j)
        {
            unsigned long long x=a[i] * a[j];
            if(reverseFunction(x)&& x > result)
            {
                result = x;
                v1 = a[i];
                v2 = a[j];
                step++;
                cout<<"step"<<step<<endl;
                cout<<"ans= "<<result<<endl<<"v1= "<<v1<<endl<<"v2= "<<v2<<endl<<endl;
            }
        }
    }

    cout<<endl<<result<<endl<<v1<<endl<<v2;

    return 0;
}
