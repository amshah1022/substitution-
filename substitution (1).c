#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

string decipher(string plaintext, string temp);

int main(int argc, string argv[])
{

    //check # CL argumemnts
    if(argc != 2)
    {
        printf("Usage: ./program key\n");
        return 1;
    }
    //check char # error
    int count = 0;
    for(int i = 0, n=strlen(argv[1]); i < n; i++)
    {
        if(isalpha(argv[1][i]))
        {
            count++;
        }
        for(int k = i, l = strlen(argv[1]); k < l - 1; k++)
        {
            if(argv[1][k] == argv[1][k+1])
            {
                printf("Key must contain 26 different characters");
                return 1;
            }
        }
       // if(usage[i] == )
    }
    if (count != 26)
    {
        printf("Key must contain 26 different characters");
        return 1;
    }

    //string usage = get_string("Usage: /n");
    string temp = argv[1];
    string plaintext = get_string("plaintext: ");
    string ciphertext = decipher(plaintext, temp);
    printf("ciphertext: %s\n", ciphertext);

}

string decipher(string plaintext, string temp)
{
    string alphaUpper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string alphaLower = "abcdefghijklmnopqrstuvwxyz";
    string temp2 = plaintext;
    //int index;
    for(int j = 0, n = strlen(plaintext); j < n; j++)
    {
        for(int m = 0, o = strlen(temp); m < o; m++)
        {
            if(plaintext[j] == alphaUpper[m])
            {
                temp2[j] = toupper(temp[m]);
            }
        }
    }
    for(int p = 0, q = strlen(temp2); p < q; p++)
    {
        for(int r = 0, s = strlen(alphaUpper); r < s; r++)
        {
           // printf("plaintext[p]: %c", plaintext[p]);
           // printf("alphaLower[r]: %c", alphaLower[r]);
            if(plaintext[p] == alphaLower[r])
            {
                temp2[p] = tolower(temp[r]);
            }
        }
    }
    return temp2;
}
