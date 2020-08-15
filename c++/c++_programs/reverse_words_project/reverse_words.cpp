#include <iostream>
#include <map>
#include <string>
#include <utility> 
using namespace std;

void reverse_words(char* sentence, char* reverse_sentence)
{
	int length = strlen(sentence);
	int i;
	int j;
	int last_index;
	int reverse_sentence_index = 0;

	last_index = length;
	for (i = length-1 ; i>=0 ; i--)
	{
		if (i==0 || sentence[i-1]==' ')
		{
			for (j=i ; j<last_index ; j++)
			{
				reverse_sentence[reverse_sentence_index] = sentence[j];
				reverse_sentence_index++;
			}
			reverse_sentence[reverse_sentence_index] = ' ';
			reverse_sentence_index++;
			last_index = i-1;
		}
	}
	reverse_sentence[reverse_sentence_index] = '\0';
}

void reverse_each_word(char* sentence, char* reverse_sentence)
{
	int length = strlen(sentence);
	int i;
	int j;
	int first_index;
	int reverse_sentence_index = 0;

	first_index = -1;
	for (i = 0 ; i<length ; i++)
	{
		if (sentence[i+1]=='\0' || sentence[i+1]==' ')
		{
			for (j=i ; j>first_index ; j--)
			{
				reverse_sentence[reverse_sentence_index] = sentence[j];
				reverse_sentence_index++;
			}
			reverse_sentence[reverse_sentence_index] = ' ';
			reverse_sentence_index++;
			first_index = i+1;
		}
	}
	reverse_sentence[reverse_sentence_index] = '\0';
}

void Reverse(char *pBegin, char *pEnd)
{
    if(pBegin == NULL || pEnd == NULL)
        return;

    while(pBegin < pEnd)
    {
        char temp = *pBegin;
        *pBegin = *pEnd;
        *pEnd = temp;

        pBegin ++, pEnd --;
    }
}

char* ReverseSentence(char *pData)
{
    if(pData == NULL)
        return NULL;

    char *pBegin = pData;

    char *pEnd = pData;
    while(*pEnd != '\0')
        pEnd ++;
    pEnd--;

    // Reverse the whole sentence
    Reverse(pBegin, pEnd);

    // Reverse every word in the sentence
    pBegin = pEnd = pData;
    while(*pBegin != '\0')
    {
        if(*pBegin == ' ')
        {
            pBegin ++;
            pEnd ++;
        }
        else if(*pEnd == ' ' || *pEnd == '\0')
        {
            Reverse(pBegin, --pEnd);
            pBegin = ++pEnd;
        }
        else
        {
            pEnd ++;
        }
    }

    return pData;
}
 
int main()
{
	char sentence[] = "hi there how are you";
	char reverse_sentence[100];
	//char* reverse_sentence;
	char* return_sentence;

	//reverse_words(sentence, reverse_sentence);
	reverse_each_word(sentence, reverse_sentence);

	return_sentence = ReverseSentence(sentence);

	printf("original sentence = %s\n", sentence);

	//for (int i=0 ; i<strlen(sentence) ; i++)
	//{
	//	printf("reverse sentence[%d] = %c\n", i, reverse_sentence[i]);
	//}
	//printf("reverse sentence  = %s\n", reverse_sentence);
	printf("reverse sentence  = %s\n", return_sentence);

    system("PAUSE");
 	return 0;       
}