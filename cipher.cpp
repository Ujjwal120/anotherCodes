#include<bits/stdc++.h>
using namespace std;
 
// This function generates the key in
// a cyclic manner until it's length isi'nt
// equal to the length of original text

string encryptRailFence(string text, int key)
{
    // create the matrix to cipher plain text
    // key = rows , length(text) = columns
    char rail[key][(text.length())];
 
    // filling the rail matrix to distinguish filled
    // spaces from blank ones
    for (int i=0; i < key; i++)
        for (int j = 0; j < text.length(); j++)
            rail[i][j] = '\n';
 
    // to find the direction
    bool dir_down = false;
    int row = 0, col = 0;
 
    for (int i=0; i < text.length(); i++)
    {
        // check the direction of flow
        // reverse the direction if we've just
        // filled the top or bottom rail
        if (row == 0 || row == key-1)
            dir_down = !dir_down;
 
        // fill the corresponding alphabet
        rail[row][col++] = text[i];
 
        // find the next row using direction flag
        dir_down?row++ : row--;
    }
 
    //now we can construct the cipher using the rail matrix
    string result;
    for (int i=0; i < key; i++)
        for (int j=0; j < text.length(); j++)
            if (rail[i][j]!='\n')
                result.push_back(rail[i][j]);
 
  
    return result;
}

string generateKey(string str, string key)
{
    int x = str.size();
 
    for (int i = 0; ; i++)
    {
        if (x == i)
            i = 0;
        if (key.size() == str.size())
            break;
        key.push_back(key[i]);
    }
    return key;
}
 
// This function returns the encrypted text
// generated with the help of the key
string cipherText(string str, string key)
{
    string cipher_text;
 
    for (int i = 0; i < str.size(); i++)
    {
        // converting in range 0-25
        char x = (str[i] + key[i]) %26;
 
        // convert into alphabets(ASCII)
        x += 'A';
 
        cipher_text.push_back(x);
    }
    return cipher_text;
}
// Driver program to test the above function
int main()
{
    cout<<"Text: VIGENERE"<< endl;
    cout<<"Rail Key: 3"<<endl;
    cout <<"Rail Cipher: "<<encryptRailFence("VIGENERE", 3) << endl;
    
    string str = encryptRailFence("VIGENERE", 3);
    string keyword = "RAIL";
    cout<<"Vigenere Key: "<< keyword;
    string key = generateKey(str, keyword);
    string cipher_text = cipherText(str, key);
 
    cout << "\nCiphertext: "<< cipher_text << "\n";
 
    return 0;
}
