#include<iostream>
#include<fstream>
#include<iterator>
#include<vector>

using namespace std;

int main()
{
    ifstream is("input.txt");
    std::vector<std::string> vecOfStr;
    vector<string> vecOfStrCopy;
    vector<int> vecOfGamma;
    vector<int> vecOfEpsilon;
    vector<string> oxygenGeneratorRating;
    vector<string> co2GeneratorRating;
    std::string str;
    int k, sum = 0;
    static int val_1, val_0 = 0;
    int i, j = 0;
    int arr[5];
    int base = 1;
    int dec_val_gamma=0;
    int dec_val_epsilon=0;
    int dec_val_oxygen;
    int dec_val_co2;
    while (std::getline(is, str))
    {
        if(str.size() > 0)
        {
            vecOfStr.push_back(str);
        }
    }

    for(int i=0; i<vecOfStr.size(); i++)
    {
        vecOfStrCopy.push_back(vecOfStr[i]);
    }

    for(j=0; j<vecOfStrCopy[j].size(); j++)
    {
        val_1=0;
        val_0=0;
        for (i=0; i<vecOfStrCopy.size(); i++)
	    {
            if(vecOfStr[i][j] == '1')
            {
                val_1=val_1+1;
            }
            else if(vecOfStrCopy[i][j] == '0')
            {
                val_0=val_0+1;
            }
	    }

        if(val_1>val_0)
        {
            vecOfGamma.push_back(1);
            vecOfEpsilon.push_back(0);
        }
        else
        {
            vecOfGamma.push_back(0);
            vecOfEpsilon.push_back(1);
        }
    }
    for(int i = vecOfGamma.size()-1; i>=0; --i)
    {
        dec_val_gamma+=vecOfGamma[i]*base;
        base*=2;
    }
    base=1;
    for(int i = vecOfEpsilon.size()-1; i>=0; --i)
    {
        dec_val_epsilon+=vecOfEpsilon[i]*base;
        base*=2;
    }
    cout<<"First Part result: "<<dec_val_gamma*dec_val_epsilon<<endl;

    cout<<"--------------------------------Second Part---------------------------------------"<<endl;

    cout<<"-------------------oxygenGeneratorRating------------------------"<<endl;

    for(int i=0; i<vecOfStr.size(); i++)
    {
        vecOfStrCopy.push_back(vecOfStr[i]);
    }
    for(j=0; j<vecOfStrCopy[j].size(); j++)
    {
        val_1=0;
        val_0=0;
        oxygenGeneratorRating.clear();
        for (i=0; i<vecOfStrCopy.size(); i++)
	    {
            if(vecOfStrCopy[i][j] == '1')
            {
                val_1=val_1+1;
            }
            else if(vecOfStrCopy[i][j] == '0')
            {
                val_0=val_0+1;
            }
        }
        if(val_1>val_0)
        {
            for (i=0; i<vecOfStrCopy.size(); i++)
	        {
                if(vecOfStrCopy[i][j] == '1')
                {
                    oxygenGeneratorRating.push_back(vecOfStrCopy[i]);
                }
	        }
        }
        else if(val_0>val_1)
        {
            for (i=0; i<vecOfStrCopy.size(); i++)
	        {
                if(vecOfStrCopy[i][j] == '0')
                {
                    oxygenGeneratorRating.push_back(vecOfStrCopy[i]);
                }
	        }
        }
        else if(val_0==val_1)
        {
            for (i=0; i<vecOfStrCopy.size(); i++)
	        {
                if(vecOfStrCopy[i][j] == '1')
                {
                    oxygenGeneratorRating.push_back(vecOfStrCopy[i]);
                }
	        }    
        }

        vecOfStrCopy.clear();
        for(int i=0; i<oxygenGeneratorRating.size(); i++)
        {
            vecOfStrCopy.push_back(oxygenGeneratorRating[i]);
        }
                
    }
    base = 1;
    for(int i = oxygenGeneratorRating.size()-1; i>=0; --i)
    {
        dec_val_oxygen = stoi(oxygenGeneratorRating[i], nullptr, 2);
    }

cout<<"-------------------co2GeneratorRating------------------------"<<endl;

    for(int i=0; i<vecOfStr.size(); i++)
    {
        vecOfStrCopy.push_back(vecOfStr[i]);
    }

    for(j=0; j<(vecOfStr[j].size()-1); j++)
    {
        val_1=0;
        val_0=0;
        co2GeneratorRating.clear();
        for (i=0; i<vecOfStrCopy.size(); i++)
	    {
            if(vecOfStrCopy[i][j] == '1')
            {
                val_1=val_1+1;
            }
            else if(vecOfStrCopy[i][j] == '0')
            {
                val_0=val_0+1;
            }
        }
        if(val_1>val_0)
        {
            for (i=0; i<vecOfStrCopy.size(); i++)
	        {
                if(vecOfStrCopy[i][j] == '0')
                {
                    co2GeneratorRating.push_back(vecOfStrCopy[i]);
                }
	        }
        }
        else if(val_0>val_1)
        {
            for (i=0; i<vecOfStrCopy.size(); i++)
	        {
                if(vecOfStrCopy[i][j] == '1')
                {
                    co2GeneratorRating.push_back(vecOfStrCopy[i]);
                }
	        }
        }
        else if(val_0==val_1)
        {
            for (i=0; i<vecOfStrCopy.size(); i++)
	        {
                if(vecOfStrCopy[i][j] == '0')
                {
                    co2GeneratorRating.push_back(vecOfStrCopy[i]);
                }
	        }    
        }
        vecOfStrCopy.clear();
        for(i=0; i<co2GeneratorRating.size(); i++)
        {
            vecOfStrCopy.push_back(co2GeneratorRating[i]);
        }
        base = 1;
        for(i = co2GeneratorRating.size()-1; i>=0; --i)
        {
            dec_val_co2 = stoi(co2GeneratorRating[i], nullptr, 2);
        }
    }

    cout<<"Second Part result: "<<dec_val_oxygen*dec_val_co2<<endl;
}
