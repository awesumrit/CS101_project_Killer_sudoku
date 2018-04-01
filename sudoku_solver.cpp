#include <iostream>
using namespace std;

#define UNASSIGNED 0
#define N 9


/* each cage will be assigned a unique id.
 * the cells array for each cage will contain the id of the cells belonging to the cage.
 * capacity of the cage = no of cells
 * cell id = row*10 + col (where row is the row number and col is the column number of the cell)
 * each cell will have a unique cell id.
 * each cage will have a unique id which equals the index of the cage in the array of cages.
 */
struct cage
{
	int sum, capacity;
	int cells[];
};

/* If a cell is not assigned any number, then value = 0.
 * each cell will have cage_id, i.e. the id of the cage to which the cell belongs
 */
struct cell {
	int value;
	int cage_id;
};


void solve_sudoku(cage,cell,int);
void print_board(cell [9][9]);

void solve_sudoku(cage Cage[],cell board[9][9],int no_of_cage)
{
    int cage_id ;

    // If there is only one cell in the cage, then set its value to the sum :
    for(cage_id=0;cage_id<no_of_cage;cage_id++)
    {
        if(Cage[cage_id].capacity==1)
            {
                int row = Cage[cage_id].cells[0]/10 ;
                int col = Cage[cage_id].cells[0]%10 ;
                board[row][col].value = Cage[cage_id].sum ;
            }
    }

    for(int i=0;i<9;i++)
    {

    }

}


int main() {

	cell Board[9][9];

	//initialize board
	for (int i=0; i<9; i++)
		for (int j=0; j<9; j++)
			Board[i][j].value = 0;

	//read input
	int no_of_cages;
	cin>>no_of_cages;
	cage Cage[no_of_cages];

	for (int cage_id = 0; cage_id<no_of_cages; cage_id++) {

		int cage_sum, no_of_cells;
		cin >> no_of_cells >> cage_sum;

		Cage[cage_id].sum = cage_sum;
		Cage[cage_id].capacity = no_of_cells;

		for (int j=0; j<no_of_cells; j++) {
			int row, col;
			cin >> row >> col;

			Cage[cage_id].cells[j] = row*10 + col;
			Board[row][col].cage_id = cage_id;

		}

	}

	//solve_sudoku();

	//print_board();



    print_board(Board) ;
	return 0;
}



/* Searches the grid to find an entry that is still unassigned. If
   found, the reference parameters row, col will be set the location
   that is unassigned, and true is returned. If no unassigned entries
   remain, false is returned. */
bool FindUnassignedLocation(cell grid[N][N], int &row, int &col)
{
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (grid[row][col].value == UNASSIGNED)
                return true;
    return false;
}

/* Returns a boolean which indicates whether any assigned entry
   in the specified row matches the given number. */
bool UsedInRow(cell grid[N][N], int row, int num)
{
    for (int col = 0; col < N; col++)
        if (grid[row][col].value == num)
            return true;
    return false;
}

/* Returns a boolean which indicates whether any assigned entry
   in the specified column matches the given number. */
bool UsedInCol(cell grid[N][N], int col, int num)
{
    for (int row = 0; row < N; row++)
        if (grid[row][col].value == num)
            return true;
    return false;
}

/* Returns a boolean which indicates whether any assigned entry
   within the specified 3x3 box matches the given number. */
bool UsedInBox(cell grid[N][N], int boxStartRow, int boxStartCol, int num)
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row+boxStartRow][col+boxStartCol].value == num)
                return true;
    return false;
}

/* Returns a boolean which indicates whether it will be legal to assign
   num to the given row,col location. */
bool isSafe(cell grid[N][N], int row, int col, int num)
{
    /* Check if 'num' is not already placed in current row,
       current column and current 3x3 box */
    return !UsedInRow(grid, row, num) &&
           !UsedInCol(grid, col, num) &&
           !UsedInBox(grid, row - row%3 , col - col%3, num);
}








void print_board(cell board[9][9])
{
    for(int row=0 ; row<9 ; row++)
    {
        for(int col=0 ; col<9 ; col++)
            cout<<board[row][col].value <<" " ;
        cout<<"\n" ;
    }
}




