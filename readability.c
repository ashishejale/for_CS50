#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
float formula(int letter, int word, int sentence);

int main(void)
{
    string text = get_string("Text: ");
    int letter = count_letters(text);
    int word = count_words(text);
    int sentence = count_sentences(text);
    float index = formula(letter, word, sentence);
//    printf("%i Word(s)\n", word);
//    printf("%i Sentence(s)\n", sentence);
// To print result
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %.f\n", index);
    }
}

//To count letters
int count_letters(string text)
{
    int letters = 0;
    int space = 0;
    int digit = 0;
    int punct = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        letters = i + 1;
        if (isspace(text[i]))
        {
            space++;
        }
        if (isdigit(text[i]))
        {
            digit++;
        }
        if (ispunct(text[i]))
        {
            punct++;
        }
    }
    return letters - space - digit - punct;
}

//To count words
int count_words(string text)
{
    int space = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isspace(text[i]))
        {
            space++;
        }
    }
    return space + 1;
}

//To count sentences
int count_sentences(string text)
{
    int sentence = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentence++;
        }
    }
    return sentence;
}

//To calculate Grade
float formula(int letter, int word, int sentence)
{
    float l = letter * 100.0 / word;
    float s = sentence * 100.0 / word;
    float index = 0.0588 * l - 0.296 * s - 15.8;
    return round(index);
}