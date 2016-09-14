#include <iostream>

using namespace std;

class Cell
{
	private:
		bool isLiving;
		bool markedForDeath;
		bool newGrowth;

		int cellRow;
		int cellColumn;

	public:
		Cell()
		{
			this->cellRow = cellRow;
			this->cellColumn = cellColumn;
			isLiving = false;
			markedForDeath = false;
		}

		void setCoordinate(int cellRow, int cellColumn)
		{
			this->cellRow = cellRow;
			this->cellColumn = cellColumn;
		}

		void setLiving()
		{
			isLiving = true;
		}

		void killCell()
		{
			isLiving = false;
		}

		void displayCell()
		{
			if (this->isLiving)
				cout << "O";
			else
				cout << "X";
		}

		int getRow()
		{
			return cellRow;
		}


		int getColumn()
		{
			return cellColumn;
		}


};
