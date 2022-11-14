#include <stack>
#include <vector>
#include <cmath>
#include <string>
#include <iostream>
#include <functional>

using namespace std;

class GoStack
{

private:
	stack<long> arr;
	bool onError;

private:
	void error()
	{
		onError = false;
	}
	// Get value passed by parameter and pop them.
	void getFirstWithSecond(long& first, long& second)
	{
		first = arr.top();
		arr.pop();
		second = arr.top();
		arr.pop();
	}
	
public:
	GoStack()
	{
		onError = true;
	}
	~GoStack()
	{
		
	}

	void NUM(long value)
	{
		if (value < 0 || value > pow(10, 9)) { return error(); }

		arr.push(value);
	}
	void POP()
	{
		if (arr.empty()) { return error(); }
		
		arr.pop();
	}
	void INV()
	{
		if (arr.empty()) { return error(); }

		arr.top() *= -1;
	}
	void DUP()
	{
		if (arr.empty()) { return error(); }

		arr.push(arr.top());
	}
	void SWP()
	{
		if (arr.size() < 2) { return error(); }

		long value1, value2;

		getFirstWithSecond(value1, value2);
		arr.push(value1);
		arr.push(value2);
	}
	void ADD()
	{
		if (arr.size() < 2) { return error(); }

		long value1, value2;

		getFirstWithSecond(value1, value2);
		arr.push(value1 + value2);
	}
	void SUB()
	{
		if (arr.size() < 2) { return error(); }

		long value1, value2;

		getFirstWithSecond(value1, value2);
		arr.push(value2 - value1);
	}
	void MUL()
	{
		if (arr.size() < 2) { return error(); }

		long value1, value2;

		getFirstWithSecond(value1, value2);
		arr.push(value1 * value2);
	}
	void DIV()
	{
		if (arr.size() < 2) { return error(); }

		long value1, value2;
		bool onFlag; // Notify changing sign

		onFlag = false;
		getFirstWithSecond(value1, value2);
		if (value1 == 0) { return error(); }
		if (value1 < 0)
		{
			value1 *= -1;
			onFlag = true;
		}
		if (value2 < 0)
		{
			value2 *= -1;
			onFlag = true;
		}

		onFlag ? arr.push(-(value2 / value1)) :
				 arr.push(value2 / value1);
	}
	void MOD()
	{
		if (arr.size() < 2) { return error(); }

		long value1, value2;
		bool onFlag;

		onFlag = false;
		getFirstWithSecond(value1, value2);
		if (value1 == 0) { return error(); }
		if (value1 < 0)
		{
			value1 *= -1;
			onFlag = true;
		}
		if (value2 < 0)
		{
			value2 *= -1;
			onFlag = true;
		}
		onFlag ? arr.push(-(value2 % value1)) :
				 arr.push(value2 % value1);
	}
	bool CheckOnError()
	{
		return onError;
	}

	size_t GetSize()
	{
		return arr.size();
	}
	void Read()
	{
		int size;

		size = arr.size();
		for (int i = 0; i < size; i++)
		{
			cout << arr.top() << endl;
			arr.pop();
		}
	}
	void Clear()
	{
		int size;

		size = arr.size();
		for (int i = 0; i < size; i++)
		{
			arr.pop();
		}
	}
};

class System
{
	struct Program
	{
		vector<function<void()>> process;
		vector<long> unit;
	};

public:
	System()
	{
		run = true;
	}
	~System()
	{
		for (int i = 0; i < programs.size(); i++)
		{
			programs[i]->process.clear();
			vector<function<void()>>().swap(programs[i]->process);

			programs[i]->unit.clear();
			vector<long>().swap(programs[i]->unit);

			delete programs[i];
		}
		programs.clear();
		vector<Program*>().swap(programs);
	}

	void Frame()
	{
		while (run)
		{
			Program* current = createProgram();

			handleMessage(current, run);
			handleInput(current, run);
		}

		print();
	}

private:
	Program* createProgram()
	{
		programs.push_back(new Program);

		return programs.back();
	}
	void handleMessage(Program* program, bool& run)
	{

		while (1)
		{
			string msg;
			cin >> msg;

			if (msg == "NUM")
			{
				cin >> msg;
				program->process.push_back(stack.NUM(stol(msg)));
				continue;	
			}
			if (msg == "POP")
			{
				program->process.push_back(stack.POP());
				continue;
			}
			if (msg == "INV")
			{
				program->process.push_back(stack.INV());
				continue;
			}
			if (msg == "DUP")
			{
				program->process.push_back(stack.DUP());
				continue;
			}
			if (msg == "SWP")
			{
				program->process.push_back(stack.SWP());
				continue;	
			}
			if (msg == "ADD")
			{
				program->process.push_back(stack.ADD());
				continue;
			}
			if (msg == "SUB")
			{
				program->process.push_back(stack.SUB());
				continue;
			}
			if (msg == "MUL")
			{
				program->process.push_back(stack.MUL());
				continue;
			}
			if (msg == "DIV")
			{
				program->process.push_back(stack.DIV());
				continue;
			}
			if (msg == "MOD")
			{
				program->process.push_back(stack.MOD());
				continue;
			}
			if (msg == "END")
			{
				break;
			}
			if (msg == "QUIT")
			{
				run = false;
				break;
			}
		}

	}
	void handleInput(Program* program, bool& run)
	{
		if (!run) { return; }

		int count;
		cin >> count;
		for (int i = 0; i < count; i++)
		{
			long value;
			
			cin >> value;
			program->unit.push_back(value);
		}
	}
	void setEnter()
	{
		while (1)
		{
			string msg;
			cin >> msg;

			if (msg == "\n")
			{
				break;
			}
			else
			{
				continue;
			}
		}
	}
	void print()
	{
		for (int i = 0; i < programs.size(); i++)
		{
			for (int x = 0; x < programs[i]->unit.size(); x++)
			{
				stack.NUM(programs[i]->unit[x]);

				// process work
				for (int y = 0; y < programs[i]->process.size(); y++)
				{
					programs[i]->process[y];
				}

				if (stack.CheckOnError())
				{
					cout << "ERROR";
					stack.Clear();
				}
				else if (stack.GetSize() != 1)
				{
					cout << "ERROR";
					stack.Clear();
				}
				else
				{
					stack.Read();
					stack.Clear();
				}
			}
		}

		cout << endl;
	}

private:
	GoStack stack;
	vector<Program*> programs;

	bool run;
};

int main()
{
	System system;

	system.Frame();

	return 0;
}