#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>
#include <ctype.h>
#include <windows.h>

// Mert Eren Kekьз
// 210229005

int PalatalHarmony(char word[]);
int LabialHarmony(char word[]);
int Connexion(char word1[], char word2[], char sentence[]);
int Plural(char word[]);
int softConsonant(char word[]);
int hardConsonant(char word[]);
int Findindex(char word[], char sentence[]);


int main()
{
    setlocale(LC_ALL, "Turkish_turkish.1254");
    SetConsoleCP(1254);
    SetConsoleOutputCP(1254);

    int lettercount = 0, sentencecount = 0;
    int pluralcount = 0, palatalCount = 0, labialCount = 0, ConnexionCount = 0;
    int hardconsonantCount = 0, softconsonantCount = 0;
    char sentence[9999];
    printf("Enter a sentence : ");
    fgets(sentence, 9999, stdin);
    char wordArray[1000][1000];

    int j = 0, wordcount = 0;
    for (int i = 0; i <= (strlen(sentence)); i++)
    {
        if (sentence[i] == ' ' || sentence[i] == '\0')
        {
            wordArray[wordcount][j] = '\0';
            wordcount++;
            j = 0;
        }
        else
        {
            // I used this as it writes the words with a dot at the end
            if (sentence[i] == '.' || sentence[i] == ':' || sentence[i] == '!' || sentence[i] == '?' || sentence[i] == ',' || sentence[i] == ';' || sentence[i] == ':' || sentence[i] == '...')
            {
                wordArray[wordcount][j] = '\0';
            }
            else
                wordArray[wordcount][j] = sentence[i];
            j++;
        }
    }

    for (int i = 0; i < strlen(sentence); i++)
    {
        if (isalpha(sentence[i]))
        {
            lettercount++;
        }
        if (sentence[i] == '.' || sentence[i] == '!' || sentence[i] == '?' || sentence[i] == ':')
        {
            sentencecount++;
        }
    }

    for (int i = 0; i < wordcount; i++)
    {
        if (Plural(wordArray[i]) == 0)
        {
            pluralcount++;
        }
    }

    for (int i = 0; i < wordcount; i++)
    {
        if (PalatalHarmony(wordArray[i]) == 0)
        {
            palatalCount++;
        }
    }

    for (int i = 0; i < wordcount; i++)
    {
        if (LabialHarmony(wordArray[i]) == 0)
        {
            labialCount++;
        }
    }
    for (int i = 0; i < wordcount - 1; i++)
    {
        if (Connexion(wordArray[i], wordArray[i + 1], sentence) == 0)
        {
            ConnexionCount++;
        }
    }

    while (true)
    {
        printf("\n0 : Logged out \n");
        printf("1 : Letter count  \n");
        printf("2 : Word count \n");
        printf("3 : Sentence count \n");
        printf("4 : Plural word count \n");
        printf("5 : Labial harmony \n");
        printf("6 : Palatal harmony \n");
        printf("7 : Connexion \n");
        printf("8 : Soft consonant count \n");
        printf("9 : Hard consonant count \n");

        int choice;
        printf("\n Choose a number : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            printf("Logged out");
            return;
        case 1:
            printf("Letter count : %d", lettercount);
            break;

        case 2:
            printf("Word count : %d", wordcount);
            break;

        case 3:
            printf("Sentence count : %d", sentencecount);
            break;

        case 4:
            printf("Plural count : %d\n", pluralcount);
            printf("Plural words : ");
            for (int i = 0; i < wordcount; i++)
            {
                if (Plural(wordArray[i]) == 0)
                {
                    printf("%s, ", wordArray[i]);
                }
            }
            break;

        case 5:
            printf("labial harmony count : %d\n", labialCount);
            printf("labial words : ");
            for (int i = 0; i < wordcount; i++)
            {
                if (LabialHarmony(wordArray[i]) == 0)
                {
                    printf("%s, ", wordArray[i]);
                }
            }
            break;

        case 6:

            printf("Palatal harmony count : %d\n", palatalCount);
            printf("Palatal words : ");
            for (int i = 0; i < wordcount; i++)
            {
                if (PalatalHarmony(wordArray[i]) == 0)
                {
                    printf("%s, ", wordArray[i]);
                }
            }
            break;

        case 7:
            printf("Connexion count : %d\n", ConnexionCount);
            printf("Connexions : ");
            for (int i = 0; i < wordcount - 1; i++)
            {
                if (Connexion(wordArray[i], wordArray[i + 1], sentence) == 0)
                {
                    printf("%s %s, ", wordArray[i], wordArray[i + 1]);
                }
            }

            break;

        case 8:
            for (int i = 0; i < wordcount; i++)
            {
                if (softConsonant(wordArray[i]) == 0)
                {
                    softconsonantCount++;
                }
            }
            printf("Soft consonant count : %d\n", softconsonantCount);

            break;

        case 9:
            for (int i = 0; i < wordcount; i++)
            {
                if (hardConsonant(wordArray[i]) == 0)
                {
                    hardconsonantCount++;
                }
            }
            printf("Hard consonant count : %d\n", hardconsonantCount);

            break;

        default:
            printf("Enter a number between(0-7)");
        }
    }
    return 0;
}

int Plural(char word[])
{
    if (strlen(word) <= 3)
    {
        return 1;
    }
    else
    {
        for (int i = 1; i < strlen(word) - 2; i++)
        {
            if ((word[i] == 'l') && ((word[i + 1] == 'a') || (word[i + 1] == 'e')) && (word[i + 2] == 'r'))
            {
                return 0;
            }
        }
    }
    return 1;
}

int PalatalHarmony(char word[])
{
    int flagFront = 0, flagBack = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        if (word[i] == 'e' || word[i] == 'i' || word[i] == 'ь' || word[i] == 'ц' || word[i] == 'E' || word[i] == 'Э' || word[i] == 'Ь' || word[i] == 'Ц')
        {
            flagFront = 1;
        }
        else if (word[i] == 'a' || word[i] == 'o' || word[i] == 'u' || word[i] == 'I' || word[i] == 'A' || word[i] == 'O' || word[i] == 'U' || word[i] == 'I')
        {
            flagBack = 1;
        }
    }
    if (flagBack == 1 && flagFront == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


int LabialHarmony(char word[])
{
    int flagunroundedvowel = 0, flagroundedvowel = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        if (word[i] == 'a' || word[i] == 'A' || word[i] == 'e' || word[i] == 'E' || word[i] == 'э' || word[i] == 'I' || word[i] == 'i' || word[i] == 'Э')
            flagunroundedvowel = 1;

        if (flagunroundedvowel == 1)
        {
            if (word[i] == 'o' || word[i] == 'O' || word[i] == 'ь' || word[i] == 'Ь' || word[i] == 'ц' || word[i] == 'Ц' || word[i] == 'u' || word[i] == 'U')
                return 1;
        }
    }
    if (flagunroundedvowel == 0)
    {
        for (int i = 0; i < strlen(word); i++)
        {
            if (word[i] == 'ц' || word[i] == 'Ц' || word[i] == 'o' || word[i] == 'O' || word[i] == 'u' || word[i] == 'U' || word[i] == 'ь' || word[i] == 'Ь')
                flagroundedvowel = 1;

            if (flagroundedvowel == 1)
            {
                if (word[i] == 'o' || word[i] == 'O' || word[i] == 'э' || word[i] == 'I' || word[i] == 'i' || word[i] == 'Э' || word[i] == 'ц' || word[i] == 'Ц')
                    return 1;
            }
        }
    }
    return 0;
}

int Connexion(char word1[], char word2[], char sentence[])
{
    char vowels[16] = {'a', 'A', 'e', 'E', 'o', 'O', 'ц', 'Ц', 'u', 'U', 'э', 'I', 'i', 'Э', 'ь', 'Ь'};
    char consonants[42] = {'r', 'R', 't', 'T', 'y', 'Y', 'p', 'P', 'р', 'Р', 's', 'S', 'd', 'D', 'f', 'F', 'g', 'G', 'h', 'H', 'j', 'J', 'k', 'K', 'l', 'L', 'ю', 'Ю', 'z', 'Z', 'c', 'C', 'v', 'V', 'b', 'B', 'n', 'N', 'm', 'M', 'з', 'З'};
    int flagvowels = 0, flagconsonants = 0;

    for (int i = 0; i < 42; i++)
    {
        if (word1[strlen(word1) - 1] == consonants[i])
        {
            flagconsonants = 1;
        }
    }
    for (int i = 0; i < 16; i++)
        if (word2[0] == vowels[i])
        {
            flagvowels = 1;
        }

    if (flagvowels == 1 && flagconsonants == 1)
    {
        // if two words are not in the same sentence, there is no connexion so we check if there is a dot between two words
        int index = Findindex(word1, sentence);
        if (sentence[index + 1] == '.' || sentence[index + 1] == ',' || sentence[index + 1] == ';' || sentence[index + 1] == ':' || sentence[index + 1] == '!' || sentence[index + 1] == '?' || sentence[index + 1] == '...')
        {
            return 1;
        }

        return 0;
    }
    else
    {
        return 1;
    }
}

int softConsonant(char word[])
{
    for (int i = 0; i < strlen(word); i++)
    {
        if (word[i] == 'b' || word[i] == 'c' || word[i] == 'd' || word[i] == 'g' || word[i] == 'j' || word[i] == 'l' || word[i] == 'm' || word[i] == 'n' || word[i] == 'r')
        {
            return 0;
        }
        if (word[i] == 'B' || word[i] == 'C' || word[i] == 'D' || word[i] == 'G' || word[i] == 'J' || word[i] == 'L' || word[i] == 'M' || word[i] == 'N' || word[i] == 'R')
        {
            return 0;
        }
    }
    return 1;
}

int hardConsonant(char word[])
{
    for (int i = 0; i < strlen(word); i++)
    {
        if (word[i] == 'з' || word[i] == 'f' || word[i] == 'h' || word[i] == 'k' || word[i] == 'p' || word[i] == 's' || word[i] == 'ю' || word[i] == 't')
        {
            return 0;
        }
        if (word[i] == 'З' || word[i] == 'F' || word[i] == 'H' || word[i] == 'K' || word[i] == 'P' || word[i] == 'S' || word[i] == 'Ю' || word[i] == 'T')
        {
            return 0;
        }
    }
    return 1;
}

int Findindex(char word[], char sentence[])
{
    char *result = strstr(sentence, word);
    int position = result - sentence;

    return position + strlen(word) - 1;
}
