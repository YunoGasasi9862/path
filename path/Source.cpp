#include <iostream>
#include <vector>

bool flag = false;
void dfs(std::vector<std::vector<int>>& grid, int size, int i, int j, std::vector<std::vector<bool>>& visited)
{
	if (i > size - 1 || i < 0 || j < 0 || j > size - 1 || visited[i][j] == true
		|| grid[i][j] == 0)

	  //if any one of these conditions are met: that is if i or j exceed the bounds, or if the vertex is true,
		//which means it's looping, or if the 0 us encountered
	{
		return; //return nothing
	} //the moment one of the conditions will be met, it will try to exit the function, but since it's recursive, it will jump to the
	//next statement in the list
	//return ; just exits the function

	if (grid[i][j] == 2)  //if 2->> destination is found, return the flag
	{
		flag = true;
		return; //EXIT THE FUCNTION, stop it
	}

	visited[i][j] = true; //this is a must. Why? Because you have visited that ith and jth location through recursion
	//so marked them visited.
	//so if the fucntion tries accessing it, it will enter the first if statement
	dfs(grid, size, i + 1, j, visited); //up
	dfs(grid, size, i -1, j, visited); //down
	dfs(grid, size, i, j+1, visited);  //right
	dfs(grid, size, i, j -1, visited); //left

	

}

bool is_Possible(std::vector<std::vector<int>>& grid)
{
	int size = grid.size();
	std::vector<std::vector<bool>> visited(size, std::vector<bool>(size, false)); //this is how you initialize all the elements in a 2D vector to false WTF!

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (grid[i][j] == 1)
			{
			  dfs(grid, size, i, j, visited);
			}
		}
	}

	return flag;

}
int main(void)
{

	std::vector<std::vector<int>> grid = { {1,3},{3,2} };

	bool answer = is_Possible(grid);

	return 0;
}