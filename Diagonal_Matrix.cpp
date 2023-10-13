/*
The below code is of Diagonal Matrix. It is a matix which contains non-zero values in diagonal and remaining values are zeros.
Below i have written optimized code for Diagonal Matrix which uses less memory. 
*/

#include <iostream>
using std::cout;
using std::endl;

class Diagonal
{
private:
    int* A;
    int size;
public:
    Diagonal();
    Diagonal(int n);
    ~Diagonal();
    void set(int i, int j, int x);
    int get(int i, int j);
    void display();
};

Diagonal::Diagonal()
{
    A = new int[5];
    size = 5;
}

Diagonal::Diagonal(int n)
{
    A = new int[n];
    size = n;
}

Diagonal::~Diagonal()
{
    delete[]A;
    A = NULL;
    size = 0;
}

void Diagonal::set(int i, int j, int x)
{
    if ((i < 0 || j < 0) || (i >= size || j >= size))
        return;

    if (i == j)
        A[i] = x;
}

int Diagonal::get(int i, int j)
{
    if ((i < 0 || j < 0) || (i >= size || j >= size))
        return -1;

    if (i == j)
        return A[i];
    else
        return 0;
}

void Diagonal::display()
{
    int i, j;

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (i == j)
                cout << A[i] << " ";
            else
                cout << 0 << " ";
        }
        cout << endl;
    }
}

int main(void)
{
    Diagonal D;

    D.set(0, 0, 2);
    D.set(1, 1, 3);
    D.set(2, 2, 4);
    D.set(3, 3, 5);
    D.set(4, 4, 6);

    D.display();

    return 0;
}