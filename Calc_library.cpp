#include <cstring> 
#include <cstdlib>

enum Operation { PLUS, MINUS, MULTIPLY, DIVIDE, NONE };

Operation getOperation(char c) {
	if (c == '+')
		return PLUS;
	else if (c == '-')
		return MINUS;
	else if (c == '*')
		return MULTIPLY;
	else if (c == '/')
		return DIVIDE;
	return NONE;
}

bool parse(char* expression, double& a, double& b, Operation& c) {
	char* space = strpbrk(expression, "+-*/");
	if (space == nullptr)
		return false;

	a = atof(expression);
	c = getOperation(*space);
	
	space++;
	b = atof(space);
	return true;
}

double plus(double a, double b) {
	return a + b;
}

double minus(double a, double b) {
	return a - b;
}

double multiply(double a, double b) {
	return a * b;
}

double divide(double a, double b) {
	return a / b;
}

double calculate(char* expression) {
	double (*action[])(double, double) = {
		plus, minus, multiply, divide  
	};

	double a;
	double b;
	Operation c;

	bool parse_correct = parse(expression, a, b, c);
	if (!parse_correct) {
		return 0;
	}

	return action[c](a, b);
}