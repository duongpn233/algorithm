#include <iostream>

using namespace std;

void egyptian_fraction(int a, int b)
{
    if (a == 0 || b == 0)
        return;

    if (b % a == 0)
    {
        cout << 1 << ' ' << b / a;
        return;
    }
	
    int x = b / a + 1;
    cout << 1 << ' ' << x << endl;
	
    egyptian_fraction(a * x - b, b * x);
}

int main()
{
    int a, b;
    cin >> a >> b;
	
    egyptian_fraction(a, b);
    return 0;
}