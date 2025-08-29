#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

/*To do:
1. Solve issue with reading and writing files. (Fixed - Elder)
2. Implement decryption option.
3. Insert key in front of encryption and decryption functions.
*/

//Function to encrypt the file using a simple substitution cipher(for testing purposes). - Elder
void encrypt_file(ifstream& in, ofstream& out, string k)
{  
    char ch;
    string reverse_alpha = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
    while (in.get(ch))
    {

        if (isalpha(ch))
        {
            if (isupper(ch))
            {
                out << reverse_alpha[ch - 'A'];
            }
            else
            {
                out << (char)tolower(reverse_alpha[ch - 'a']);
            }
        }
        else
        {
            out << ch;
        }
    }
    in.close();
    out.close();

}

int main(int argc, char* argv[])
{  
   
   int file_count = 0; 
   ifstream in_file;
   ofstream out_file;
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
            // encryption, needs to conform to project specs. - Elder
            file_count++;
            if (file_count == 1) 
            {  
                in_file.open(arg, ios::in);
                if (in_file.fail()) 
                { 
                    cout << "Error opening input file " << arg << endl;
                    return 1;
                }
            }
            else if (file_count == 2) 
            {
                out_file.open(arg, ios::out);
                if (out_file.fail()) 
                { 
                    cout << "Error opening output file " << arg << endl;
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
    cout << "Please enter a key:" << endl;
    string key;
    cin >> key;
    encrypt_file(in_file, out_file, key);
    return 0;
}