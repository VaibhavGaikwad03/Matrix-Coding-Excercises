#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class LowerTri
{
private:
    int *A;
    int size;

public:
    LowerTri();
    LowerTri(int n);
    ~LowerTri();
    void set(int i, int j, int x);
    int get(int i, int j);
    void display();
};

LowerTri::LowerTri()
{
    A = new int[10];
    size = 10;
}

LowerTri::LowerTri(int n)
{
    A = new int[n * (n - 1) / 2];
    size = n;
}

LowerTri::~LowerTri()
{
    delete[] A;
    A = NULL;
    size = 0;
}

void LowerTri::set(int i, int j, int x)
{
    if (i >= j)
        A[i * (i - 1) / 2 + j - 1] = x;
}

int LowerTri::get(int i, int j)
{
    if (i >= j)
        return A[i * (i - 1) / 2 + j - 1];
    return 0;
}

void LowerTri::display()
{
    int i, j;

    for (i = 1; i <= size; i++)
    {
        for (j = 1; j <= size; j++)
        {
            if (i >= j)
                cout << A[i * (i - 1) / 2 + j - 1] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}

int main(void)
{
    int data;
    int i, j, d;

    cout << "Enter size of matrix: ";
    cin >> d;

    LowerTri lt(d);

    cout << "Enter elements: \n";
    for (i = 1; i <= d; i++)
    {
        for (j = 1; j <= d; j++)
        {
            cin >> data;
            lt.set(i, j, data);
        }
    }

    lt.display();

    return 0;
}