/*

Write a program which  accept matrix from user and return largest number from both the diagonals.

Input : 

3   2   5   9
4   3   2   2
8   4   1   9
3   9   7   5

Output : 9

*/

#include<iostream>
using namespace  std;

class Array
{
    public:

    int **Arr;                                                              //two dimensional array (matrix)
    int iRowsCount;
    int iColumnsCount;

    Array(int, int);
    ~Array();
    void accept();
    void display();
}; 

Array::Array(int iRows, int iColumns)                                       //to allocating the resources
{
    int i = 0;

    if(iRows != iColumns)
    {
        exit(0);
    }
    iRowsCount = iRows;
    iColumnsCount = iColumns;

    Arr = new int* [iRows];

    for(i = 0; i < iRows; i++)
    {
        Arr[i] = new int [iColumns];
    }
}

Array::~Array()                                                             //to deallocating the resources
{
    int i = 0;

    for(i = 0; i < iRowsCount; i++)
    {
        delete []Arr[i];
    }

    delete []Arr;

    Arr = NULL;
}

void Array::accept()                                                        //to accept data into the matrix
{
    int i = 0, j = 0;
    cout<<"Enter the data into matrix : "<<endl;

    for(i = 0; i < iRowsCount; i++)
    {
        for(j = 0; j < iColumnsCount; j++)
        {
            cin>>Arr[i][j];
        }
    }
}

void Array::display()                                                       //to display data from the matrix
{
    int i = 0, j = 0;

    cout<<"Data from the matrix : "<<endl;
    for(i = 0; i < iRowsCount; i++)
    {
        for(j = 0; j < iColumnsCount; j++)
        {
            cout<<Arr[i][j]<<"  ";
        }
        cout<<endl;
    }
}

class Solution : public Array                                               //derived class inherits the base class
{
    public:

    Solution(int, int);
    int findMaxDiagonal();
};

Solution::Solution(int iRows, int iColumns) : Array(iRows, iColumns){}      //passing arguments to the base class

int Solution::findMaxDiagonal()                                             //to find the maximum number from both diagonals
{
    int i = 0, j = 0, iMax = **Arr;

    for(i = 0; i < iRowsCount; i++)
    {
        for(j = 0; j < iColumnsCount; j++)
        {
            if(i == j || i + j == iRowsCount - 1)
            {
                if(iMax < Arr[i][j])
                {
                    iMax = Arr[i][j];
                }
            }
        }
    }
    return iMax;
}

int main()                                                                      //entry point function
{
    Solution *obj;
    int iRows = 0, iColumns = 0, iRet = 0;

    cout<<"Enter the number of rows : "<<endl;
    cin>>iRows;

    cout<<"Enter the number of columns : "<<endl;
    cin>>iColumns;

    obj = new Solution(iRows, iColumns);

    obj->accept();
    obj->display();
    iRet = obj->findMaxDiagonal();

    cout<<"Maximum number from both diagonals is : "<<iRet<<endl;

    return 0;
}
