#include <iostream>
#include <cmath>

int main()
{
	//set seed of randomizer to time
	srand(time(NULL));

	//the size of the grid is pushed into an array and has to be constant as a result of array assignments.
	const int gridSizeX = 16;
	const int gridSizeY = 30;

	bool grid[gridSizeX][gridSizeY];

	//amount of mines to generate
	int mines = 99;

	//Check the amount of mines, and place them into the grid using random generation.
	int minesLeft = mines;
	while (minesLeft > 0)
	{
		int randomx = 0;
		int randomy = 0;

		randomx = (rand() % gridSizeX);
		randomy = (rand() % gridSizeY);

		for (int i = 0; i < gridSizeX; i++)
		{
			for (int j = 0; j < gridSizeY; j++)
			{
				if (grid[i][j] != true)
				{
					if (randomx == i && randomy == j)
					{
						grid[i][j] = true;
						minesLeft--;
					}
				}
			}
		}
	}

	//generate numbers for Mines
	for (int i = 0; i < gridSizeX; i++)
	{
		for (int j = 0; j < gridSizeY; j++)
		{
			int MineCount = 0;
			if (grid[i][j] == true)
			{
				std::cout << "x";
			}
			else
			{
				//right hand bounds checking
				if (j != gridSizeY - 1)
				{
					//top right check
					if (grid[i + 1][j + 1] == true)
						MineCount++;
					//right check
					if (grid[i][j + 1] == true)
						MineCount++;
					//bottom right check
					if (grid[i - 1][j + 1] == true)
						MineCount++;
				}

				//left hand bounds checking
				if (j != 0)
				{
					//top left check
					if (grid[i + 1][j - 1] == true)
						MineCount++;
					//left check
					if (grid[i][j - 1] == true)
						MineCount++;
					//bottom left check
					if (grid[i - 1][j - 1] == true)
						MineCount++;
				}

				//these don't cause problems due to wrapping.
				//top check
				if (grid[i + 1][j] == true)
					MineCount++;
				//bottom check
				if (grid[i - 1][j] == true)
					MineCount++;

				if (MineCount > 0)
				{
					std::cout << MineCount;
				}
				else
				{
					std::cout << ".";
				}

			}
		}
		std::cout << std::endl;
	}

	return 0;

}