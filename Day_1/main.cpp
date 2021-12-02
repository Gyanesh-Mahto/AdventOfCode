#include<iostream>
#include<fstream>
#include<iterator>
#include<vector>

using namespace std;

int main()
{
    ifstream is("input.txt");
    istream_iterator<int> start(is), end;
    vector<int> numbers(start, end);
    int increment = 0;
    static int sum_1 = 0;
    static int sum_2 = 0;
    for (int i = 0; i<(numbers.size()-1); i++) 
	{
		if(numbers[i+1] > numbers[i])
        {
            increment+=1;
        }
	}
    cout<<"There are "<<increment<<" measurements larger than the previous one."<<endl;

    increment = 0;

    for (int i = 3; i<numbers.size(); i++) 
	{
        sum_1 = (numbers[i-3]+numbers[i-2]+numbers[i-1]);
        sum_2 = (numbers[i-2]+numbers[i-1]+numbers[i]);
        if(sum_2>sum_1)
        {
            increment+=1;
        }
        sum_1 = 0;
        sum_2 = 0;
	}
    cout<<"There are "<<increment<<" measurements larger than the previous one."<<endl;
}
