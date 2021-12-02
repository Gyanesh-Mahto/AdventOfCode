#include<iostream>
#include<fstream>
#include<iterator>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

int main()
{
    string line, name;
    int number;
    static int forward_count, up_count, down_count, result, depth, horizontal = 0;
    ifstream is("input.txt");

    while( getline(is,line) )
    {
        istringstream is(line);
        is >> name; 
        is >> number;
        if(name == "forward")
        {
            forward_count+=number;
        }
        else if(name == "up")
        {
            up_count+=number;
        }
        else
        {
            down_count+=number;
        }
    }
    is.close();
    cout<<forward_count<<endl;
    cout<<up_count<<endl;
    cout<<down_count<<endl;
    horizontal = forward_count;
    depth = down_count-up_count;
    cout<<horizontal*depth<<endl;

    forward_count, up_count, down_count, result = 0;
    depth, horizontal = 0;
    static int aim = 0;
    while( getline(is,line) )
    {
        istringstream is(line);
        is >> name; 
        is >> number;
        if(name == "forward")
        {
            forward_count+=number;
            depth+=(aim*number);
            cout<<"Aim: "<<aim<<endl;
            cout<<"Depth: "<<depth<<endl;
        }
        else if(name == "up")
        {
            up_count+=number;
            aim-=number;
            cout<<"Aim: "<<aim<<endl;
            cout<<"Depth: "<<depth<<endl;
        }
        else
        {
            down_count+=number;
            aim+=number;
            cout<<"Aim: "<<aim<<endl;
            cout<<"Depth: "<<depth<<endl;
        }
    }
    is.close();
    horizontal = forward_count;
    cout<<"Total value: "<<horizontal*depth<<endl;
}
