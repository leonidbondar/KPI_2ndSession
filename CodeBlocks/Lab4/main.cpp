/*1. Створити масив структур, що містить інформацію про книги особи-стої бібліотеки:
прізвище автора, назва книги, рік видання. З'ясувати, скі-льки і яких книг вказаного автора є в бібліотеці.
*/

/*
1. Початок
2. Початковий вивід тексту, прийняти у юзера ввід кількості книг.
3. Ініціалізація створення структури:
3.1 Цикл, поки не будуть заповнені дані по всім книгам:
3.1.1 Запропонувати юзеру ввести дані. Прийняти введення для кожної книги title, author, year....
4. Запропонувати ввести автора, книги якого треба відсортувати. Прийняти інпут.
5. Цикл, поки не будуть пройдені усі книги:
5.1 Якщо ім'я автора співпадає (без урахування регістру) з тим, що введене юзером, то книга виводиться
6. Кінець (пауза).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <iostream>

using namespace std;

struct book
{
    char title[10]; 	//назва книги
    char author[20]; 	//автор
    int year; 		//ціна
};

void sort(book mas[],int); 		 // сортування книг
void output_list(book mas[],int); 	// виведення списку книг
void input_list(book mas[],int); 		// створення масиву книг
void output_sorted(book mas [], int); //displays only books with author match
// ================= головна функція ================
main()
{
    book katalog[10]; 			//масив книги
    int kol; 					//кількість книг
    cout<<"Number of books: ";
    cin>>kol;
    input_list(katalog,kol);
    puts("List of books:");
    output_list(katalog,kol);
    puts("Sorted by author list of books:");
    output_sorted(katalog,kol);
    system("pause");
}
//============ створення масиву книг ============
void input_list(book mas[], int n)
{
    for (int i=0; i<n; i++)
    {
        cout<<"Name of book:";
        //gets(mas[i].title);
        cin>>mas[i].title;
        cout<<"Author:";
        cin>>mas[i].author;
        cout<<"Year: ";
        cin>>mas[i].year;
        cout << endl;
    }
}
//============ виведення списку книг ============
void output_list(book mas[], int n)
{
    for (int i=0; i<n; i++)
    {
        printf("%10s%10s",mas[i].title,mas[i].author);
        cout << "  " << mas[i].year << " year" << endl;
    }
    cout << endl;
}

void output_sorted(book mas[], int n)
{
    char author[100];
    cout << "input author name to search..." << endl;
    cin >> author;
    cout << endl;
    cout << "List of books (if any matches):" << endl;
    for (int i=0; i<n; i++)
    {
        if (!stricmp(mas[i].author, author))
        {
            printf("%10s%10s",mas[i].title,mas[i].author);
            cout << "  " << mas[i].year << " year" << endl;
        }
    }
}
