 #include<iostream>
 #include<stack>
 #include "checker.h"
 using namespace std;

 int check_position( int i,int j,int sudoku[9][9] ){

        if ( check_row( i, sudoku ) )
        return 1;
        if ( check_column( j,sudoku ) )
        return 1;
        if ( check_box( i,j,sudoku ) )
        return 1;

   return 0;
 }

 int main(){

//input your sudoku here

/*
Perfect Sudoku :
{
4,3,5,2,6,9,7,8,1,
6,8,2,5,7,1,4,9,3,
1,9,7,8,3,4,5,6,2,
8,2,6,1,9,5,3,4,7,
3,7,4,6,8,2,9,1,5,
9,5,1,7,4,3,6,2,8,
5,1,9,3,2,6,8,7,4,
2,4,8,9,5,7,1,3,6,
7,6,3,4,1,8,2,5,9
};

*/

   int sudoku[9][9]=
{
4,3,5,2,6,9,7,8,1,
6,8,2,5,7,1,4,9,3,
1,9,7,8,3,4,5,6,2,
8,2,6,1,9,5,3,4,7,
3,7,4,6,8,2,9,1,5,
9,5,1,7,4,3,6,2,8,
5,1,9,3,2,6,8,7,4,
2,4,8,9,5,7,1,0,6,
7,6,3,4,1,8,2,5,9
};

std::cout << sudoku_checker( sudoku ) << '\n';
std::cout << check_position(6,7,sudoku) << '\n';


   return 0;
 }
