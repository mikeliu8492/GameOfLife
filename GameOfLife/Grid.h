#include <iostream>
#include <vector>
#include "Cell.h"

using namespace std;

class Grid
{
	private:
		Cell ** cityBlock ;
		int numRows;
		int numColumns;

		vector<pair<int, int>>  directionsToSearch(int row, int column)
		{
			vector<pair<int, int>> coordinatesToSearch;
			if (row == 0 && column == 0)
			{
				coordinatesToSearch = { pair<int, int>(0, 1) , pair<int, int>(1, 1), pair<int, int>(1, 0)};
			}

			else if (row == numRows -1 && column == numColumns-1)
			{
				coordinatesToSearch = { pair<int, int>(0, -1) , pair<int, int>(-1, -1), pair<int, int>(-1, 0) };
			}

			else if (row == 0 && column == numColumns - 1)
			{
				coordinatesToSearch = { pair<int, int>(0, -1) , pair<int, int>(1, -1), pair<int, int>(1, 0) };
			}

			else if (row == numRows - 1 && column == 0)
			{
				coordinatesToSearch = { pair<int, int>(0, 1) , pair<int, int>(-1, 1), pair<int, int>(-1, 0) };
			}

			else if (row == 0)
			{
				coordinatesToSearch = { pair<int, int>(0, -1) , pair<int, int>(1, -1), pair<int, int>(1, 0) , pair<int, int>(1, 1), pair<int, int>(0, 1) };
			}

			else if (row == numRows - 1)
			{
				coordinatesToSearch = { pair<int, int>(0, -1) , pair<int, int>(-1, 1), pair<int, int>(-1, 0) , pair<int, int>(-1, 1), pair<int, int>(0, 1) };
			}

			else if (column == 0)
			{
				coordinatesToSearch = { pair<int, int>(-1, 0) , pair<int, int>(-1, 1), pair<int, int>(0, 1) , pair<int, int>(1, 1), pair<int, int>(1, 0) };
			}

			else if (column == numColumns - 1)
			{
				coordinatesToSearch = { pair<int, int>(-1, 0) , pair<int, int>(-1, -1), pair<int, int>(0, -1) , pair<int, int>(-1, 1), pair<int, int>(1, 0) };
			}
			else
			{
				coordinatesToSearch = { pair<int, int>(-1, -1) , pair<int, int>(-1, 0), pair<int, int>(-1, 1) , 
										pair<int, int>(0, -1), pair<int, int>(0, 1),  
										pair<int, int>(1, -1), pair<int, int>(1, 0), pair<int, int>(1, 1)};
			}



		}

	public:
		Grid()
		{
			cityBlock = new Cell*[numRows];

			for (int i = 0; i < numRows; i++)
			{
				cityBlock[i] = new Cell[numColumns];
			}



		}

		void initializeCells()
		{
			for (int row = 0; row < numRows; row++)
			{
				for (int col = 0; col < numColumns; col++)
				{
					cityBlock[row][col].setCoordinate(row, col);
					int liveOrDie = rand() % 2;
					if (liveOrDie == 0)
					{
						cityBlock[row][col].setLiving();
					}

				}
			}
		}

		void displayGrid()
		{
			for (int row = 0; row < numRows; row++)
			{
				for (int col = 0; col < numColumns; col++)
				{

					cityBlock[row][col].displayCell();

				}
				cout << endl;
			}
		}


		int countLivingNeighbors(Cell &currentCell)
		{
			int currentCellRow = currentCell.getRow();
			int currentCellColumn = currentCell.getColumn();
			int neighbors = 0;

			vector<pair<int, int>> cellsToExplore = directionsToSearch(currentCellRow, currentCellColumn);

		}



};