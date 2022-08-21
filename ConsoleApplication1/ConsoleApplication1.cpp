#include <iostream>
#include <calculator.h>
#include <scientific.h>
#include <iomanip>

using namespace std;


Calculator::Calculator() : result(0.0), mem(0.0) {}

void Calculator::add()
{
    string a, b;
    cout << "Enter the first number: ";
    cin >> a;
    cout << "Enter the second number: ";
    cin >> b;
    result = parseInput(a) + parseInput(b);
    cout << "The result is " << result;
}
void Calculator::subtract()
{
    string a, b;
    cout << "Enter the first number: ";
    cin >> a;
    cout << "Enter the second number: ";
    cin >> b;
    result = parseInput(a) - parseInput(b);
    cout << "The result is " << result;
}
void Calculator::multiply()
{
    string a, b;
    cout << "Enter the first number: ";
    cin >> a;
    cout << "Enter the second number: ";
    cin >> b;
    result = parseInput(a) * parseInput(b);
    cout << "The result is " << result;
}
void Calculator::divide()
{
    string a, b;
    cout << "Enter the first number: ";
    cin >> a;
    cout << "Enter the second number: ";
    cin >> b;
    result = parseInput(a) / parseInput(b);
    cout << "The result is " << result;
}
void Calculator::square()
{
    string a;
    cout << "Enter a number: ";
    cin >> a;
    double parsedA = parseInput(a);
    result = parsedA * parsedA;
    cout << "The result is " << result;
}
void Calculator::sqrt()
{
    string a;
    cout << "Enter a number: ";
    cin >> a;
    result = std::sqrt(parseInput(a));
    cout << "The result is " << result;
}
void Calculator::setMem()
{
    string a;
    cout << "Enter a number: ";
    cin >> a;
    mem = parseInput(a);
    cout << "The mem is " << mem;
}
void Calculator::printMem() const
{
    cout << "The mem is " << mem;
}

double Calculator::parseInput(const string& input) const
{
    if (input == "result")
    {
        return result;
    }
    else if (input == "mem")
    {
        return mem;
    }
    else
    {
        return stod(input);
    }
}
void Calculator::welcome() const
{
    cout << "\n\nEnter an operation (+, -, /, *, sqrt, square, change, setmem, printmem) or exit\n";
}

void Calculator::parseOperation(const string& input)
{
    if (input == "+" || input == "add" || input == "addition" || input == "sum")
    {
        add();
    }
    else if (input == "-" || input == "sub" || input == "subtraction" || input == "minus")
    {
        subtract();
    }
    else if (input == "/" || input == "divide" || input == "div")
    {
        divide();
    }
    else if (input == "*" || input == "mul" || input == "multiply" || input == "times")
    {
        multiply();
    }
    else if (input == "sqrt")
    {
        sqrt();
    }
    else if (input == "square")
    {
        square();
    }
    else if (input == "setmem")
    {
        setMem();
    }
    else if (input == "printmem")
    {
        printMem();
    }
}

Scientific::Scientific() : Calculator() {}

void Scientific::welcome() const
{
    cout << "\n\nEnter one of:\n"
        << "+, -, /, *, sqrt, square, change, setmem, printmem, sin, cos, log, tan, ln, abs, pow\n"
        << "or exit\n";
}

void Scientific::parseOperation(const string& input)
{
    Calculator::parseOperation(input);

    if (input == "sin")
    {
        sin();
    }
    else if (input == "cos")
    {
        cos();
    }
    else if (input == "tan")
    {
        cos();
    }
    else if (input == "ln")
    {
        ln();
    }
    else if (input == "log")
    {
        log();
    }
    else if (input == "abs")
    {
        abs();
    }
    else if (input == "pow")
    {
        pow();
    }
}
void Scientific::sin()
{
    string a;
    cout << "Enter a number: ";
    cin >> a;
    result = (parseInput(a));
    cout << "The result is " << result;
}
void Scientific::cos()
{
    string a;
    cout << "Enter a number: ";
    cin >> a;
    result = cos(parseInput(a));
    cout << "The result is " << result;
}
void Scientific::tan()
{
    string a;
    cout << "Enter a number: ";
    cin >> a;
    result = tan(parseInput(a));
    cout << "The result is " << result;
}
void Scientific::ln()
{
    string a;
    cout << "Enter a number: ";
    cin >> a;
    result = log(parseInput(a));
    cout << "The result is " << result;
}
void Scientific::log()
{
    string a, b;
    cout << "Enter the base: ";
    cin >> a;
    cout << "Enter a number: ";
    cin >> b;
    result = log(parseInput(b)) / log(parseInput(a));
    cout << "The result is " << result;
}
void Scientific::abs()
{
    string a;
    cout << "Enter a number: ";
    cin >> a;
    result = abs(parseInput(a));
    cout << "The result is " << result;
}
void Scientific::pow()
{
    string a, b;
    cout << "Enter the base: ";
    cin >> a;
    cout << "Enter the exponent: ";
    cin >> b;
    result = pow(parseInput(a), parseInput(b));
    cout << "The result is " << result;
}

int main()
{

    Calculator calc;
    Scientific sci;
    Calculator* calcPtr = &calc;

    bool sciActive = false;

    cout << "Welcome to my Calculator App\n\n"
        << "This calculator has 2 modes, normal and scientific.\n"
        << "You can change it using the 'change' keyword.\n\n"
        << "This app has 2 other special keywords, result and mem.\n"
        << "result stores the result of the previous calculation.\n"
        << "mem allows you to store and access a number.\n"
        << "Both can be used instead of numbers during calculations.\n"
        << "They are both local to the mode you are using.\n";

    calcPtr->welcome();

    cout << setprecision(15);

    string input = "";
    while (cin >> input && input != "exit")
    {
        if (input == "change")
        {
            if (sciActive)
            {
                calcPtr = &calc;
                sciActive = false;
                cout << "\nSimple Calculator Activated";
            }
            else 
            {
                calcPtr = &sci;
                sciActive = true;
                cout << "\nScientific Calculator Activated";
            }
        }
        calcPtr->parseOperation(input);
        calcPtr->welcome();
    }

    return 0;
}