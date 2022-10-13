#include <iostream>
#include <vector>

class Test
{
public:
	// Allocate 2 section of size and get deploy limit.
	Test(const int size_, const int limit_)
		: size(size_), limit(limit_), count(0)
	{
		section = new std::pair<int, bool>*[2];
		for (int i = 0; i < 2; i++)
		{
			section[i] = new std::pair<int, bool>[size_];
		}
	}
	~Test()
	{
		for (int i = 0; i < 2; i++)
		{
			delete[] section[i];
		}

		delete[] section;
	}

public:
	std::pair<int, bool>*& operator[](int y)
	{
		return section[y];
	}

	void Deploy()
	{

	}

	void SetSection(int i, int j, int source)
	{
		section[i][j] = std::pair<int, bool>(source, false);
	}

	// Testing method
	void TestSection()
	{
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < size; j++)
			{
				std::cout << section[i][j].first << ' ';
			}
			std::cout << std::endl;
		}
	}

private:
	std::pair<int, bool>** section;
	int size;
	int limit;
	int count;
};

class Input
{
public:
	// Wait for integer input to return. 
	static int WaitIntKeyDown()
	{
		int integer;

		std::cin >> integer;
		
		return integer;
	}
};

class Output
{
public:
	static void PrintIntArgument(const int source_)
	{
		std::cout << source_ << std::endl;
	}
};

class Program
{
public:
	Program(){}
	~Program()
	{
		destroyTest();
	}

public:
	// Set initializer depending on input.
	void Start()
	{
		int caseCount;

		caseCount = Input::WaitIntKeyDown();
		while (caseCount)
		{
			int size;
			int limit;

			size = Input::WaitIntKeyDown();
			limit = Input::WaitIntKeyDown();

			createTest(size, limit);
			initializeTest(size);


			caseCount--;
		}
	}

	// Calculate algorithms.
	void Update()
	{
		for (auto element : test)
		{
			element->TestSection();
		}
	}


private:
	void destroyTest()
	{
		for (auto element : test)
		{
			delete element;
		}

		test.clear();
		std::vector<Test*>().swap(test);
	}

	void createTest(int size_, int limit_)
	{
		test.push_back(new Test(size_, limit_));
	}

	// Deploy enemy at each section depending on input.
	void initializeTest(int size_)
	{
		Test* temp;

		temp = test.back();
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < size_; j++)
			{
				temp->SetSection(i, j, Input::WaitIntKeyDown());
			}
		}
	}

private:
	std::vector<Test*> test;
};

int main()
{
	Program program;

	program.Start();
	program.Update();

	return 0;
}