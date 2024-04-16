#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b) 
{
    string num1 = to_string(a) + to_string(b);
    string num2 = to_string(b) + to_string(a);
    return num1 > num2;
}

string solution(vector<int> &numbers) 
{
    string answer = "";
    
    sort(numbers.begin(), numbers.end(), compare);
    
    if (numbers[0] == 0) return "0";
    
    for (int num : numbers) 
    {
        answer += to_string(num);
    }
    
    return answer;
}

int main()
{
    vector<int> numbers={3,30,34,5,9};
    cout<<solution(numbers);

    return 0;
}