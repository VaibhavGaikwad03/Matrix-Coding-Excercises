/*
Write a program which accepts matrix from the user and display addition of elements of each column.

Input :

3   2   5   9
4   3   2   2
8   4   1   9
3   9   7   5

Output :

18  18  15  25

*/

#include<iostream>
using namespace std;

class Array                                     //base class
{
    public:
    int **Arr;
    int RowCnt;
    int ColumnCnt;
    Array(int, int);
    ~Array();
    void accept();
    void display();
};

Array::Array(int iRows ,int iColumns)           //to allocating the resources 
{
    RowCnt = iRows;
    ColumnCnt = iColumns;
    Arr = new int* [iRows];
}

Array::~Array()                                 //to deallocating the resources
{
    for(int i = 0; i < RowCnt; i++)
    {
        delete []Arr[i];
    }
    delete []Arr;
}

void Array::accept()                            //to accept the input form user
{
    int i = 0, j = 0;

    for(i = 0; i < RowCnt; i++)
    {
        Arr[i] = new int[ColumnCnt];
    }
    cout<<"Enter the data : "<<endl;

    for(i = 0; i < RowCnt; i++)
    {
        for(j = 0; j < ColumnCnt; j++)
        {
            cin>>Arr[i][j];
        }
    }
}

void Array::display()                           //to display accepted data by user
{

    int i = 0, j = 0;

    cout<<"Data from the array : "<<endl;

    for(i = 0; i < RowCnt; i++)
    {
        for(j = 0; j < ColumnCnt; j++)
        {
            cout<<Arr[i][j]<<"  ";
        }
        cout<<endl;
    }
}

class Solution: public Array                    //derived class
{
    public:

    Solution(int, int);
    void addColumns();
};

Solution::Solution(int iRows, int iColumns):Array(iRows, iColumns)  //passing arguments to the base class constructor to allocating the resources 
{
    
}

void Solution::addColumns()                     //to display addition of each column
{
    int i = 0, j = 0, iSum = 0;

    for(i = 0; i < ColumnCnt; i++)
    {
        iSum = 0;
        for(j = 0; j < RowCnt; j++)
        {
            iSum = iSum + Arr[j][i];
        }
        cout<<"Addition of column "<<i+1<<" is : "<<iSum<<endl;
    }
}

int main()                                      //entry point function
{
    system("cls");
    int iRows = 0, iColumns = 0;

    cout<<"Enter the number of rows : "<<endl;
    cin>>iRows;

    cout<<"Enter the number of columns : "<<endl;
    cin>>iColumns;

    Solution obj(iRows, iColumns);

    obj.accept();
    obj.display();
    obj.addColumns();

    return 0;
}