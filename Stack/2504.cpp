// BOJ 백준 2504번 괄호의 값

#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

string st;
stack<char> mySt;
long long temp = 1;
long long sum = 0;

int main()
{
	cin >> st;

    // (()[[]]) -> 2x(2+3x3) => (2x2)+(2x3x3)
	for (int i = 0; i < st.length(); i++)
	{
		if (st[i] == '(')
		{
			mySt.push(st[i]);
            temp*=2;
		}

		else if (st[i] == '[')
		{
			mySt.push(st[i]);
            temp*=3;
		}

		else if (st[i] == ')')
		{
            if( mySt.empty() || mySt.top()!='(')
            {
                sum=0;
                break;
            }

			else if ((i-1>=0) & st[i-1]=='(')
			{
				// () 모양
                sum+=temp;
                mySt.pop();
                temp/=2;
			}
            else
            {
                mySt.pop();
                temp/=2;
            }
		
		}

		else if (st[i] == ']')
		{
			if (mySt.empty() || mySt.top() != '[')
			{
				sum=0;
				break;
			}

            else if(i-1>=0 && st[i-1]=='[')
            {
                sum+=temp;
                temp/=3;
                mySt.pop();
            }

            else
            {
                temp/=3;
                mySt.pop();
            }
	
		}
	}

    if(!mySt.empty())
    {
        sum=0;
    }

	cout << sum;
	
	return 0;
}