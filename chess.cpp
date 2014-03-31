/*  just for git test*/
#include <iostream>
#include <vector>
#include <assert.h>
#include <ctime>

using namespace std;

const int height = 7;
const int width = 7;
const int InitialMaze[height][width] =
{
    {8, 8, 1, 1, 1, 8, 8},
    {8, 8, 1, 1, 1, 8, 8},
    {1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1},
    {8, 8, 1, 1, 1, 8, 8},
    {8, 8, 1, 1, 1, 8, 8}
};


inline bool ifMovable(int **CurrentMaze, int idx_width, int idx_height, int direction)
{
    assert(CurrentMaze != NULL && idx_width >= 0 && idx_width < width && idx_height >= 0 && idx_height < height && direction >= 0 && direction < 4 && CurrentMaze[idx_height][idx_width] == 1);
    switch (direction)
    {
        //left
        case (0):
        {
            if(idx_width >= 2 && CurrentMaze[idx_height][idx_width - 1] == 1 && CurrentMaze[idx_height][idx_width - 2] == 0) return true;
            break;
        }
        //up
        case (1):
        {
            if(idx_height >= 2 && CurrentMaze[idx_height - 1][idx_width] == 1 && CurrentMaze[idx_height - 2][idx_width] == 0) return true;
            break;
        }
        //right
        case (2):
        {
            if(idx_width <= width - 3 && CurrentMaze[idx_height][idx_width + 1] == 1 && CurrentMaze[idx_height][idx_width + 2] == 0) return true;
            break;
        }
        //down
        case (3):
        {
            if(idx_height <= height - 3 && CurrentMaze[idx_height + 1][idx_width] == 1 && CurrentMaze[idx_height + 2][idx_width] == 0) return true;
            break;
        }
	}
    return false;
}


inline void MakeMove(int **CurrentMaze, int idx_width, int idx_height, int direction)
{
    assert(CurrentMaze != NULL && idx_width >= 0 && idx_width < width && idx_height >= 0 && idx_height < height && direction >= 0 && direction < 4 && CurrentMaze[idx_height][idx_width] == 1);
    
	CurrentMaze[idx_height][idx_width] = 0;
    switch(direction)
    {
        //left
        case(0):
        {
            CurrentMaze[idx_height][idx_width - 1] = 0;
            CurrentMaze[idx_height][idx_width - 2] = 1;
            return;
        }
        //up
        case(1):
        {
            CurrentMaze[idx_height - 1][idx_width] = 0;
            CurrentMaze[idx_height - 2][idx_width] = 1;
            return;
        }
        //right
        case(2):
        {
            CurrentMaze[idx_height][idx_width + 1] = 0;
            CurrentMaze[idx_height][idx_width + 2] = 1;
            return;
        }
        //down
        case(3):
        {
            CurrentMaze[idx_height + 1][idx_width] = 0;
            CurrentMaze[idx_height + 2][idx_width] = 1;
            return;
        }
    }
}

inline void UndoMove(int **CurrentMaze, int idx_width, int idx_height, int direction)
{
    assert(CurrentMaze != NULL && idx_width >= 0 && idx_width < width && idx_height >= 0 && idx_height < height && direction >= 0 && direction < 4 && CurrentMaze[idx_height][idx_width] == 0);
    
	CurrentMaze[idx_height][idx_width] = 1;
    switch(direction)
    {
        //left
        case(0):
        {
            CurrentMaze[idx_height][idx_width - 1] = 1;
            CurrentMaze[idx_height][idx_width - 2] = 0;
            return;
        }
        //up
        case(1):
        {
            CurrentMaze[idx_height - 1][idx_width] = 1;
            CurrentMaze[idx_height - 2][idx_width] = 0;
            return;
        }
        //right
        case(2):
        {
            CurrentMaze[idx_height][idx_width + 1] = 1;
            CurrentMaze[idx_height][idx_width + 2] = 0;
            return;
        }
        //down
        case(3):
        {
            CurrentMaze[idx_height + 1][idx_width] = 1;
            CurrentMaze[idx_height + 2][idx_width] = 0;
            return;
        }
    }
}

int **MazeCopy(int **CurrentMaze)
{
    //assert(CurrentMaze != NULL);
    int **MazeMirror = new int*[height];
    for(int i = 0 ; i < height ; i ++)
        MazeMirror[i] = new int[width];
    for(int i = 0 ; i < height ; i ++)for(int j = 0 ; j < width ; j ++)
    {
        MazeMirror[i][j] = CurrentMaze[i][j];
    }
    return MazeMirror;
}

void MazeDelete(int **CurrentMaze)
{
    for(int i = 0 ; i < height ; i ++) delete[] CurrentMaze[i];
    delete[] CurrentMaze;
}

void MazePrint(int **CurrentMaze)
{
    assert(CurrentMaze != NULL);
    for(int i = 0 ; i < height ; i ++)
    {
        for(int j = 0 ; j < width ; j ++)
        {
            cout<<CurrentMaze[i][j]<<" ";
        }
        cout<<endl;
    }
	cout<<"============="<<endl;
}

bool MazeSolver_RecursionHelper(int **CurrentMaze, vector<int**> &Solution)
{
    assert(CurrentMaze != NULL);
    
    //Exit Case
    int NumOfChess = 0;
    for(int idx_height = 0 ; idx_height < height ; idx_height ++)for(int idx_width = 0 ; idx_width < width ; idx_width ++)
    {
		if(CurrentMaze[idx_height][idx_width] == 1) {NumOfChess ++;}
    }
    if(NumOfChess == 1)
    {
        Solution.push_back(MazeCopy(CurrentMaze));
        return true;
    }
    
    //Normal Procedure
    for(int idx_height = 0 ; idx_height < height ; idx_height ++)for(int idx_width = 0 ; idx_width < width ; idx_width ++)
    {
        if(CurrentMaze[idx_height][idx_width] == 1)
        {
            for(int direction = 0 ; direction < 4 ; direction ++)
            {
                if(ifMovable(CurrentMaze, idx_width, idx_height, direction))
                {
                    MakeMove(CurrentMaze, idx_width, idx_height, direction);
                    bool SuccessRet = MazeSolver_RecursionHelper(CurrentMaze, Solution);
                    UndoMove(CurrentMaze, idx_width, idx_height, direction);
                    if(SuccessRet)
                    {
                        Solution.push_back(MazeCopy(CurrentMaze));
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

void MazeSolver()
{
    //Initial
    int **CurrentMaze = new int*[height];
    for(int i = 0 ; i < height ; i ++)
	{
		CurrentMaze[i] = new int[width];
	}
    for(int i = 0 ; i < height ; i ++)for(int j = 0 ; j < width ; j ++)
	{
		CurrentMaze[i][j] = InitialMaze[i][j];
	}
    vector<int**> Solution;
    
    //Main Function
    if(MazeSolver_RecursionHelper(CurrentMaze, Solution))
    {
		cout<<"Solution("<<Solution.size()<<" Moves): "<<endl;
		for(vector<int**>::reverse_iterator riter = Solution.rbegin() ; riter != Solution.rend() ; riter ++)
        {
            MazePrint(*riter);
            MazeDelete(*riter);
            *riter = NULL;
        }
    }
    else
    {
        cout<<"Maze Unsolvable"<<endl;
    }
    
    //Clean Up
    MazeDelete(CurrentMaze);
    CurrentMaze = NULL;
}


int main()
{
	clock_t start = clock();
    MazeSolver();
	clock_t finish = clock();
	cout<<"Time Used: "<<(double)(finish - start) / CLOCKS_PER_SEC<<" seconds"<<endl;

    return 0;
}

