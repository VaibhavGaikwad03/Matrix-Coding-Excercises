/*

Write a program which  accept matrix and one number from user and return frequency of that number.

Input : 9

3   2   5   9
4   3   2   2
8   4   1   9
3   9   7   5

Output : 3

*/

#include<iostream>
using namespace std;

class Matrix
{
    public:
    
    int **iMatrix;                                                              //matrix (two dimensional array)
    int iRowCnt;
    int iColumnCnt;
    Matrix(int, int);
    ~Matrix();
    void accept();
    void display();
};

Matrix::Matrix(int iRows, int iColumns)                                         //to allocating the resources
{
    int i = 0;
    iRowCnt = iRows;
    iColumnCnt = iColumns;

    iMatrix = new int* [iRows];

    for(i = 0; i < iRows; i++)
    {
        iMatrix[i] = new int [iColumns];
    }
}

Matrix::~Matrix()                                                               //to deallocating the resources
{
    int i = 0; 

    for(i = 0; i < iRowCnt; i++)
    {
        delete []iMatrix[i];
    }

    delete []iMatrix;

    iMatrix = NULL;
}

void Matrix::accept()                                                           //to accept data into the matrix
{
    int i = 0, j = 0;

    cout<<"Enter the data into matrix : "<<endl;

    for(i = 0; i < iRowCnt; i++)
    {
        for(j = 0; j < iColumnCnt; j++)
        {
            cin>>iMatrix[i][j];
        }
    }
}

void Matrix::display()                                                          //to display data from matrix
{
    int i = 0, j = 0;

    cout<<"Data from the matrix : "<<endl;

    for(i = 0; i < iRowCnt; i++)
    {
        for(j = 0; j < iColumnCnt; j++)
        {
            cout<<iMatrix[i][j]<<"  ";
        }
        cout<<endl;
    }
}

class Solution : public Matrix                                                  
{
    public:

    Solution(int, int);
    int countFrequency(int);
};

Solution::Solution(int iRows, int iColumns) : Matrix(iRows, iColumns){}         //passing arguments to the base class 

int Solution::countFrequency(int iNo)                                           //to count frequency of a number
{
    int i = 0, j = 0, iCount = 0;

    for(i = 0; i < iRowCnt; i++)
    {
        for(j = 0; j < iColumnCnt; j++)
        {
            if(iMatrix[i][j] == iNo)
            {
                iCount++;
            }
        }
    }

    return iCount;
}

int main()                                                                      //entry point function
{   
    int iRows = 0, iColumns = 0, iNo = 0, iFrequency = 0;

    cout<<"Enter the number of rows : "<<endl;
    cin>>iRows;

    cout<<"Enter the number of columns : "<<endl;
    cin>>iColumns;

    Solution obj(iRows, iColumns);

    obj.accept();
    obj.display();

    cout<<"Enter the number to count frequency of that number : "<<endl;
    cin>>iNo;

    iFrequency = obj.countFrequency(iNo);

    cout<<"Frequency of "<<iNo<<" is : "<<iFrequency<<endl;

    return 0;
}