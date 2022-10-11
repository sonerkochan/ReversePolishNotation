#include <iostream>
#include <stack>
#include <string>

using namespace std;

void main()
{
    int jo;
    std::string input;
    std::string result = "";

    cout << "Input: ";
    cin >> input;
    input = "(" + input + ")";
    cout << input << endl;

    stack<char> signs;

    for (int i = 0; i < input.length(); i++)
    {
        char c = input[i];
        switch (c)
        {
        case '(':
            signs.push(input[i]);
            break;
        case')':
            while (true)
            {
                if (signs.top() != '(')
                {
                    result.push_back(signs.top());
                    signs.pop();
                }
                else
                {
                    signs.pop();
                    break;
                }
            }
            break;
        case '*':
            signs.push(input[i]);
            break;
        case'/':
            signs.push(input[i]);
            break;
        case'+':
            if (signs.top() == '*' || signs.top() == '/')
            {
                result.push_back(signs.top());
                signs.pop();
                signs.push(input[i]);
            }
            else
            {
                signs.push(input[i]);
            }
            break;
        case'-':
            if (signs.top() == '*' || signs.top() == '/')
            {
                result.push_back(signs.top());
                signs.pop();
                signs.push(input[i]);
            }
            else
            {
                signs.push(input[i]);
            }
            break;
        default:
            result.push_back(input[i]);
            break;
        }
    }

    cout << "Result: " << result << "\n"; //(a*b-c)*b+c*(b-a)

    int count;
    cout << "Count of variables: ";
    cin >> count;
    int variables[100];

    for (int i = 0; i < count; i++)
    {
        cout << (char)(i+97) << " = ";
        cin >> variables[i];
    }

    stack<int> calculated;

    for (int i = 0; i < result.length(); i++)
    {
        if (result[i] >= 'a' && result[i] <= 'z')
        {
            calculated.push(variables[result[i]-97]);
        }

        if (result[i] == '+')
        {
            int k = calculated.top();
            calculated.pop();
            int j = calculated.top();
            calculated.pop();
            int sum = j + k;
            calculated.push(sum);
        }
        if (result[i] == '-')
        {
            int k = calculated.top();
            calculated.pop();
            int j = calculated.top();
            calculated.pop();
            int sum = j - k;
            calculated.push(sum);
        }
        if (result[i] == '*')
        {
            int k = calculated.top();
            calculated.pop();
            int j = calculated.top();
            calculated.pop();
            int sum = j * k;
            calculated.push(sum);
        }
        if (result[i] == '/')
        {
            int k = calculated.top();
            calculated.pop();
            int j = calculated.top();
            calculated.pop();
            int sum = j / k;
            calculated.push(sum);
        }

    }

    cout << input << " = " << calculated.top() << endl;
    calculated.pop();
}