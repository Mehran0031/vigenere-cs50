#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

 int main(int argc, string argv[])
{
    //deklareer variabellen

    string p=NULL;
    int lastChar = 0;
    int counter = 0;


    // valideer argumenten
    if (argc !=2)
     {
        // print dat command een singel command line moet zijn
        printf("enter a single command line.\n");
        // retrun omdat her programma moet stoppen
        return 1;
     }
// hier zet ik second argument command-line gelijk aan string key
string key = argv[1];

     // met deze loop command op alphabetisch wordt gecontroleerd
     for ( int n = 0; n < strlen(key); n++)
       {
        // cotroleer om argv alfabetisch is
        if (!isalpha(argv[1][n]))
        {
         // if false dan
          printf("enter alfabeteish karakters en geen special karakters.\n");
          return 1;

        }
      }

        //loop
 printf("plaintext: ");
        do
        {
          // sla plaintxt op in p
          p = get_string();
        }
          while(p == '\0');

          //print ciphertext na key in command-line
          printf("ciphertext: ");

          // loop en gebruik nieuwe functies
          for (int i = 0, n = strlen(p); i < n; i++)
        { //for in

         // controleer input met if
         if (isalpha(p[i]))
        {
         //regel teller in counter
         counter = lastChar % strlen(key);

         // hoofdletter cotrole
         if (islower(p[i]))
           {
             if (islower(key[counter]))
             {
              p[i] = ((p[i] - 'a' + key[counter] - 97) % 26) + 97;
              printf("%c", p[i]);
             }
            }

              else
            {
              p[i] = ((p[i] - 'A' + key[counter] - 65) % 26) + 65;
              printf("%c", p[i]);
            }

            if (isupper(p[i]))
            {
              if(islower(key[counter]))
              {
                p[i]=(((p[i]) - 'A' +key[counter] - 97) % 26) + 65;

                printf("%c", p[i]);
              }
            // else if(isupper(key[counter]))
            // {
            //     p[i]=(((p[i]) - 'A' +key[counter] - 65) % 26) +65;
            //     printf("%c", p[i]);
            // }

            }

              lastChar++;
              counter++;
            }
             else
             {
              //print massage
              printf("%c", p[i]);
             }
       }

             printf("\n");

 return 0;

 }