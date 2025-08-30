#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

/*To do:
1. Solve issue with reading and writing files. (Fixed - Elder)
2. Implement decryption option. (Fixed - Elder)
3. Insert key in front of encryption and decryption functions.(Completed for encryption - Elder)
4. Encryption conforms to project specs. - Elder
*/

//Function to encrypt the file 
void encrypt_file(ifstream& in, ofstream& out, string k)
{  
    char ch;
    string reverse_alpha = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // Preparing the key
    for (int i = 0; i < k.length(); i++)
    {    
        if(k[i] == alpha[i])
        {
            continue;
        }
        else
        {
            for (int j = i + 1; j < k.length(); j++)
            {
                if (k[i] == k[j])
                {
                    k.erase(j, 1);
                    j--;
                }
            }
        }
    }
    for (int i = 0; i < k.length(); i++)
    {
        k[i] = toupper(k[i]);
    }
    // Preparing the key continued
    for (int i = 0; i < reverse_alpha.length(); i++)
    {
        
        if(k.find(reverse_alpha[i]) == string::npos)
        {
            k += reverse_alpha[i];
        }
        if (k.length() == 26)
        {
            break;
        }
    }
    k += reverse_alpha;    
    // Encrypting the file
    while (in.get(ch))
    {

        if (isalpha(ch))
        {
            if (isupper(ch))
            {
                out << k[ch - 'A'];
            }
            else
            {
                out << (char)tolower(k[ch - 'a']);
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
//Function to decrypt the file
void decrypt_file(ifstream& in, ofstream& out, string k)
{
    char ch;
    string reverse_alpha = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    // Preparing the key
    for (int i = 0; i < k.length(); i++)
    {    
        if(k[i] == alpha[i])
        {
            continue;
        }
        else
        {
            for (int j = i + 1; j < k.length(); j++)
            {
                if (k[i] == k[j])
                {
                    k.erase(j, 1);
                    j--;
                }
            }
        }
    }
    for (int i = 0; i < k.length(); i++)
    {
        k[i] = toupper(k[i]);
    }
    // Preparing the key continued
    for (int i = 0; i < reverse_alpha.length(); i++)
    {
        
        if(k.find(reverse_alpha[i]) == string::npos)
        {
            k += reverse_alpha[i];
        }
        if (k.length() == 26)
        {
            break;
        }
    }
    // Filling a string with the input file contents
    string input = "";
    while (in.get(ch))
    {
        input += ch;
    }

    for ( int i = 0; i < input.length(); i++)
    {
        input[i] = toupper(input[i]);
    }
    // Decrypting the file
    for (int i = 0; i < k.length(); i++)
    {
        if (input[i] == k[i])
        {
            out << (char)(i + 'A');
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
        // Check for decryption flag 
        if (arg == "-d") 
        { 
            for (int j = 1; j < argc; j++)
            {
                arg = argv[j];
                file_count++;
                // Open files based on their position
                if (file_count == 2) 
                {  
                    in_file.open(arg, ios::in);
                    if (in_file.fail()) 
                    { 
                        cout << "Error opening input file " << arg << endl;
                        return 1;
                    }
                }
                
                else if (file_count == 3) 
                {
                    out_file.open(arg, ios::out);
                    if (out_file.fail()) 
                    { 
                        cout << "Error opening output file " << arg << endl;
                        return 1;
                    }
                }
            }
            // Ensure correct number of files for decryption
            if (file_count != 3) 
            { 
                cout << "Usage: " << argv[0] << " [-d] infile outfile" << endl;
                return 1;
            }
            // Decryption process in main
            cout << "Please enter the key for decryption:" << endl;
            string key;
            cin >> key;
            decrypt_file(in_file, out_file, key);
            return 0;
        }
        else 
        {  
            file_count++;
            // Open files based on their position
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
    // Ensure correct number of files for encryption
    if (file_count != 2) 
    { 
        cout << "Usage: " << argv[0] << " [-d] infile outfile" << endl;
        return 1;
    }
    // Encryption process in main
    cout << "Please enter a key:" << endl;
    string key;
    cin >> key;
    encrypt_file(in_file, out_file, key);
    return 0;
}