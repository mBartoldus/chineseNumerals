#include <iostream>
#include <string>
using namespace std;

string to_kanji(string input);

int main()
{
    cout << "Enter numbers:" << endl << endl;
    string user_input;
    do
    {
        getline(cin, user_input);
        cout << to_kanji(user_input) << endl << endl;
    }
    while (user_input != "");
    return 0;
}



string to_kanji(string input)
{
    string integer;
    string output("");
    
    try
    {
        // if the first character isn't an integer, return empty string
        input[0] > '9' || input[0] < '0' ? throw invalid_argument("") : integer = input[0];
    }
    catch(invalid_argument)
    {
        return output;
    }
    
    // this will represent the length of the number in digits, growing as we check how many digits there are
    int length = 1;
    
    // this variable is initially used to crawl through the input string (including commas and extraneous zeroes)
    // it's later used to crawl through the reinterpreted string (commas/extra zeroes removed)
    int i = 1;
    
    // ignoring zeroes at the beginning of the number, and being respectful of the null terminator
    while(integer[0] == '0' && input[i] != '\0')
    {
        integer[0] = input[i++];
    }
    
    // straightforward
    bool looping = true;
    
    // the index should now be pointing just past the first nonzero digit
    // we now collect all the digits into interpreted_input, skipping commas and stopping when we hit a nonnumeric character
    do
    {
        if (input[i] <= '9' && input[i] >= '0')
        {
            integer += input[i];
            length++;
        }
        else if (input[i] != ',') looping = false;
        i++;
    }while(looping);
    
    // here i go reusing that i, shame on me
    for(i = 0; i < length; i++)
    {
        int digit = length - i;
        
        // this bool is for checking if the current digit is a zero, though it does much more than that
        // i originally named it zeroPlace, but it's MOSTLY for skipping over semantically negligible digits
        bool skip = digit == 1;
        
        switch (integer[i])
        {
                // the "一" character isn't really used unless it's in the ones place
            case '1': if(skip) output.append("一"); break;
            case '2': output.append("二"); break;
            case '3': output.append("三"); break;
            case '4': output.append("四"); break;
            case '5': output.append("五"); break;
            case '6': output.append("六"); break;
            case '7': output.append("七"); break;
            case '8': output.append("八"); break;
            case '9': output.append("九"); break;
                
                // mostly ignore zeros unless they're in the 10,000's place ("万", or myriad)
                // further details in the following switch statement
            default: if (length == 1)output.append("零"); else if (digit != 5) skip = true; break;
        }
        
        if(!skip)
        {
            // the magnitude past 10,000 is represented as "十万", or "ten myriad"
            // after that is a hundred myriad and a thousand myriad, so modulo comes in handy
            // at a myriad myriad this system ceases to be accurate
            switch(digit % 4)
            {
                case 2: output.append("十"); break; // ten
                case 3: output.append("百"); break; // hundred
                case 0: output.append("千"); break; // thousand
                case 1: output.append("万"); break; // myriad
            }
        }
    }
    
    return output;
}
