
/*
Write a program which accepts matrix from user and check whether the matix is identity matrix or not.

Identity matrix is a square matrix with 1's along the diagonal from upper left to lower right and 0's in all other positions.
If it satisfies the structure as explained before then the matrix is called as identity matrix.

Input : 

1   0   0   0
0   1   0   0
0   0   1   0
0   0   0   1

Output : TRUE

*/

#include<iostream>
using namespace std;

class Array
{
    public:

    int **Arr;                                          //pointer pointing to the pointer
    int iRowCnt;
    int iColumnCnt;
    Array(int, int);
    ~Array();
    void accept();
    void display();
};

Array::Array(int iRows, int iColumns)                   //to allocating the resources 
{
    iRowCnt = iRows;
    iColumnCnt = iColumns;

    Arr = new int* [iRows];
    for(int i = 0; i < iRowCnt; i++)
    {
        Arr[i] = new int[iColumns];
    }
}

Array::~Array()
{
    for(int i = 0; i < iRowCnt; i++)                    //to deallocating the resources
    {
        delete []Arr[i];
    }

    delete[]Arr;

    Arr = NULL;
}

void Array::accept()                                    //to accept input from user
{
    int i = 0, j = 0;

    cout<<"Enter the data : "<<endl;

    for(i = 0; i < iRowCnt; i++)
    {
        for(j = 0; j < iColumnCnt; j++)
        {
            cin>>Arr[i][j];
        }
    }
}

void Array::display()                                   //to display the elements of the matrix
{
    int i = 0, j = 0;

    cout<<"Data from the Matrix : "<<endl;

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
    bool checkIdentity();
};

Solution::Solution(int iRows, int iColumns):Array(iRows, iColumns)  //passing aruguments to the base class
{

}

bool Solution::checkIdentity()                          //to check the matrix is identity matrix or not
{
    bool bFlag1, bFlag2;

    if(iRowCnt != iColumnCnt)
    {
        return false;
    }

    for(int i = 0; i < iRowCnt; i++)
    {
        for(int j = 0; j < iColumnCnt; j++)
        { 
            if((i == j) && (Arr[i][j] == 1))
            {
                bFlag1 = true;
            }
            else if((i != j) && Arr[i][j] == 0)
            {
                bFlag2 = true;
            }
            else
            {
                bFlag1 = false;
                bFlag2 = false;
                goto Down;
            }
        }
    }
    Down:
    if((bFlag1 == true) && (bFlag2 == true))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()                                                  //entry point function
{
    bool bRet = false;
    int iRows = 0, iColumns = 0;

    cout<<"Enter the number of rows : "<<endl;
    cin>>iRows;

    cout<<"Enter the number of columns : "<<endl;
    cin>>iColumns;

    Solution obj(iRows, iColumns);

    obj.accept();
    obj.display();
    bRet = obj.checkIdentity();

    if(bRet == true)
    {
        cout<<"The matrix is identity matrix.."<<endl;
    }
    else
    {
        cout<<"The matrix is not an indentity matrix !!"<<endl;
    }

    return 0;
}