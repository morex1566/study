#include <iostream>

class Test
{
public:
	Test(const int row_, const int colum_)
		: row(row_), colum(colum_)
	{
		allocateGrid(row_, colum_);
	}
	~Test()
	{
		clearGrid();
	}

public:
	void SetGrid(int x_, int y_, char type_)
	{
		grid[y_][x_] = type_;
	}
	void TestGrid()
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < colum; j++)
			{
				std::cout << grid[i][j];
			}
			std::cout << std::endl;
		}
	}

private:
	void allocateGrid(const int row_, const int colum_)
	{
		grid = new char* [row_];
		for (int i = 0; i < row_; i++)
		{
			grid[i] = new char[colum_];
		}
	}
	void clearGrid()
	{
		for (int i = 0; i < row; i++)
		{
			delete[] grid[i];
		}

		delete[] grid;
	}

private:
	char** grid;
	int row;
	int colum;
};

class Input
{
public:
	// Wait for character input to return. 
	static int WaitCharKeyDown()
	{
		char key;

		std::cin >> key;
		return key;
	}

	// Wait for integer input to return. 
	static int WaitIntKeyDown()
	{
		int key;

		std::cin >> key;
		return key;
	}
};

class Output
{
public:

};

class Program
{
public:
	Program() 
	{
		test = nullptr;
	}
	~Program()
	{
		delete test;
	}

public:
	// Set initializer depending on input.
	void Start()
	{
		int row;
		int colum;

		row = Input::WaitIntKeyDown();
		colum = Input::WaitIntKeyDown();

		createTest(row, colum);
		initializeTest(row, colum);
	}

	// Calculate algorithms.
	void Update()
	{
		test->TestGrid();
	}


private:
	void createTest(const int row_, const int colum_)
	{
		test = new Test(row_, colum_);
	}

	void initializeTest(const int row_, const int colum_)
	{
		for (int i = 0; i < row_; i++)
		{
			for (int j = 0; j < colum_; j++)
			{
				test->SetGrid(j, i, Input::WaitCharKeyDown());
			}
		}
	}

private:
	Test* test;
};

int main()
{
	Program program;

	program.Start();
	program.Update();

	return 0;
}