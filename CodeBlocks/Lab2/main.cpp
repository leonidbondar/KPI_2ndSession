// 1. У заданому рядку символів визначити кількість слів, довжина яких більша за вказану користувачем.
/*
1. Початок.

2. Вивести початковий текст, прийняти інпут юзера (довжина слів менше якої не виводити)

3. Обробити раніше заданий рядок.

3.1 Визначити перелік і кількість слів у рядку

3.1.1 Цикл визначення лексем рядка:

3.1.1.1 Виділити поточну лексему.

3.1.1.2 Зберегти поточну лексему у масиві слів.

3.1.1.3 Вивести поточну лексему.

3.1.1.4 Збільшити значення лічильника лексем на 1.

3.1.1.5 Якщо виділені усі лексеми рядка, то кінець цик-лу; інакше перейти до виділення наступної лексеми.

3.1.2 Вивести визначену кількість слів у рядку.

3.2 Відфільтрувати слова за фільтром (довжина):

3.2.1 Цикл перегляду усіх слів рядка (відповідних елементів ма-сиву):

3.2.1.1 Якщо довжина поточного слова більша за вказану юзером, то воно виводиться.

3.2.1.2 Якщо переглянуті усі слова, то кінець циклу; ін-акше перейти до наступного слова.

4. Кінець (пауза).
*/

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

char rowToProcess[] = "Sample row for processing: sorting words by length.";
typedef char array[100][100];
array wordArray= {0};
array wordAfterFilterArray;
size_t length;
size_t numberOfWords = 0;

void init();
void pause();
void createWords(char rowToProcess[], array wordArray);
void filterWordsByLength(array wordArray, array wordAfterFilterArray, size_t length);

int main()
{
    init();
    createWords(rowToProcess, wordArray);
    filterWordsByLength(wordArray, wordAfterFilterArray, length);
    pause();
    return 0;
}

void init()
{
    cout << "Enter the length of words to count" << endl;
    cin >> length;
}

void pause()
{
    cin.sync();
    cin.ignore();
}

void createWords(char rowToProcess[], array wordArray)
{
    cout << "parsing string" << endl << endl;
    char *delimiter="., ";
    char *p;
    p=strtok(rowToProcess,delimiter);
    while (p!=NULL)
    {
        strcpy(wordArray[numberOfWords], p);
        puts(p);
        numberOfWords++;
        p=strtok(NULL, delimiter);
    }
    cout << "number of words=" << numberOfWords << endl << endl;
}

void filterWordsByLength(array wordArray, array wordAfterFilterArray, size_t length)
{
    cout << "size of words to filter entered is " << length << endl << endl;
    size_t currentLength = 0;
    for (unsigned i = 0; i < numberOfWords; i++)
    {
        currentLength = strlen(wordArray[i]);
        if (currentLength > length)
        {
            strcpy(wordAfterFilterArray[i], wordArray[i]);
            cout << "word " << '"' << wordArray[i] << '"' << " is " << currentLength << " characters long" << endl;
        }
    }
}

