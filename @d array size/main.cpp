#include <iostream>

using namespace std;

int main()
{
   int input[][4] = {
                         {1,1,1,0},
                         {1,1,1,1},
                         {0,1,1,0},
                         {0,1,1,1},
                         {1,0,0,1},
                         {1,1,1,1}
                    };
   int boardWidth;
   int boardHeight ;
   //createBoard(boardWidth, boardHeight);
   cout<<sizeof(input)/sizeof(input[0])<<endl;
   cout<<sizeof(input[0])/sizeof(input[0][0])<<endl;
   cout<<sizeof(input)/sizeof(input[0][0])<<endl;

}


