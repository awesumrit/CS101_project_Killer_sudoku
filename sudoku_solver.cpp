#include <iostream>
using namespace std;

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
void print_board(cell[][9]);
bool isCageFilled(cage);
bool isCageSumSatisfied(cage);

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

    print_board(Board);
	return 0;
}



void print_board(cell board[][9])
{
    for(int row=0 ; row<9 ; row++)
    {
        for(int col=0 ; col<9 ; col++)
            cout<<board[row][col].value <<" " ;
        cout<<"\n" ;
    }
}

/* Checks whether all the cells in a particular cage are filled.
 * returns true if they are filled
 * else returns false
 */
bool isCageFilled(cage Cage) {
	for (int cell=0; cell<Cage.capacity; cell++) {
		if (Cage.cells[cell] == 0)
			return false;
	}
	return true;
}

/* checks whether the sum of all the cells in a cage 
 * equals the cage sum and returns true if it is.
 * Returns true if the cage is not yet filled.
 * else returns false
 */
bool isCageSumSatisfied(cage Cage) {
	if (!isCageFilled(Cage)) return true;
	int sum = 0;
	for (int cell=0; cell<Cage.capacity; cell++) {
		sum += Cage.cells[cell];
	}
	if (sum == Cage.sum)
		return true;
	else
		return false;
}
