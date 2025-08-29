#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <vector>
using namespace std;

/*To do:
1. Solve issue with reading and writing files.
2. Implement decryption option.
3. Insert key in front of encryption and decryption functions.
*/

//Function to encrypt the file using a simple substitution cipher(for testing purposes). - Elder
void encrypt(ifstream& in_file, ofstream& out_file, string k)
{
    char ch;
    string reverse_alpha = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
    while (in_file.get(ch))
    {

        if (isalpha(ch))
        {
            if (isupper(ch))
            {
                out_file << reverse_alpha[ch - 'A'];
            }
            else
            {
                out_file << (char)tolower(reverse_alpha[ch - 'a']);
            }
        }
        else
        {
            out_file << ch;
        }
    }

    in_file.close();
    out_file.close();
}


int main(int argc, char* argv[])
{
    ifstream in_file;
    ofstream out_file;
    string key;
    int file_count = 0;

    for (int i = 1; i < argc; i++) 
    {
        string arg = argv[i]; 
        
        if (arg == "-d")
        {
            // decryption, needs to be implemented. - Elder
            cout << "Decryption mode is not implemented yet." << endl;
        }
        else
        {
            // encryption, currently stuck on getting files to open properly. - Elder
            file_count++;
            if (file_count == 1)
            {
                in_file.open(arg, ios::in);
                if (in_file.fail())
                {
                    cout << "Error opening input file." << endl;
                    return 1;
                }
            }
            else if (file_count == 2)
            {
                out_file.open(arg, ios::out);
                if (out_file.fail())
                {
                    cout << "Error opening output file." << endl;
                    return 1;
                }
            }
        }
    }
    if (file_count != 2)
    {
        cout << "Usage: " << argv[0] << " [-d] infile outfile" << endl;
        return 1;
    }
    cout << "Enter encryption key: ";
    cin >> key;
    encrypt(in_file, out_file, key);
    return 0;
}
