/*

Write a program which accepts matrix from user and check whether the matix is sparse matrix or not.

Sparse matrix is a matrix with the majority of its elements equal to zero.

Input : 

1   0   3   0
0   6   0   0
0   0   1   0
9   0   0   9

Output : true

*/

#include<iostream>
using namespace std;

class Array
{
    public:
    int **Arr;                                                          //two dimensional array
    int iRowCnt;
    int iColumnCnt;
    Array(int, int);
    ~Array();
    void accept();
    void display();
};

Array::Array(int iRows, int iColumns)                                   //to allocating the resources
{
    int i = 0;
    iRowCnt = iRows;
    iColumnCnt = iColumns;

    Arr = new int*[iRows];

    for(i = 0; i < iRows; i++)
    {
        Arr[i] = new int [iColumns];
    }
}

Array::~Array()                                                         //to deallocating the resources
{
    int i = 0;

    for(i = 0; i < iRowCnt; i++)
    {
        delete [] Arr[i];
    }

    delete []Arr;

    Arr = NULL;
}

void Array::accept()                                                    //to accept the data into matrix
{
    int i = 0, j = 0;

    cout<<"Enter the data into matrix : "<<endl;

    for(i = 0; i < iRowCnt; i++)
    {
        for(j = 0; j < iColumnCnt; j++)
        {
            cin>>Arr[i][j];
        }
    }
}

void Array::display()                                                   //to display the data from matrix
{
    int i = 0, j = 0;

    cout<<"Data from the matrix : "<<endl;

    for(i = 0; i < iRowCnt; i++)
    {
        for(j = 0; j < iColumnCnt; j++)
        {
            cout<<Arr[i][j]<<"  ";
        }
        cout<<endl;
    }
}

class Solution : public Array                                           
{
    public:

    Solution(int, int);
    bool checkSparse();
};

Solution::Solution(int iRows, int iColumns):Array(iRows, iColumns){}    //passing arguments to the base class

bool Solution::checkSparse()                                            //to check the matrix is sparse matrix or not
{
    int i = 0, j = 0, iCountZeros = 0;

    for(i = 0; i < iRowCnt; i++)
    {
        for(j = 0; j < iColumnCnt; j++)
        {
            if(Arr[i][j] == 0)
            {
                iCountZeros++;
            }
        }
    }

    if(iCountZeros > ((iRowCnt * iColumnCnt) / 2))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()                                                              //entry point funtion
{
    int iRows = 0, iColumns = 0;
    bool bRet = false;

    cout<<"Enter the number of rows : "<<endl;
    cin>>iRows;

    cout<<"Enter the number of columns : "<<endl;
    cin>>iColumns;

    Solution obj(iRows, iColumns);

    obj.accept();
    obj.display();
    bRet = obj.checkSparse();

    if(bRet == true)
    {
        cout<<"The matrix is sparse matrix..."<<endl;
    }
    else
    {
        cout<<"The matrix is not a sparse matrix..."<<endl;
    }

    return 0;
}