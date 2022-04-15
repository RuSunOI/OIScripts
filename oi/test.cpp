#include <cstdio>
using namespace std;
template <class Type>
void read (Type &x)
{
    char c;
    bool flag = false;
    while ((c = getchar()) < '0' || c > '9')
        c == '-' && (flag = true);
    x = c - '0';
    while ((c = getchar()) >= '0' && c <= '9')
        x = (x << 1) + (x << 3) + c - '0';
    flag && (x = ~x + 1);
}
template <class Type>
void write (Type x)
{
    x < 0 && (putchar('-'), x = ~x + 1);
    x > 9 && (write(x / 10), 0);
    putchar('0' + x % 10);
}
int main ()
{
    
    return 0;
}
