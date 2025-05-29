#include <iostream>
#include <iomanip>

using namespace std;

#include "phone_subscription.h"
#include "file_reader.h"
#include "constants.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "  8. GIT\n";
    cout << " 0.  \n";
    cout << ":  \n\n";
    phone_subscription* subscriptions[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", subscriptions, size);
        cout << "*****   *****\n\n";
        for (int i = 0; i < size; i++)
        {
            /**********   **********/
            cout << "........: ";
            //  
            cout << subscriptions[i]->number << " ";
            cout << '\n';
            cout << " .....: ";
            cout << setw(4) << setfill('0') << subscriptions[i]->dt.day << '-';
            //  
            cout << setw(2) << setfill('0') << subscriptions[i]->dt.month << '-';
            //  
            cout << setw(2) << setfill('0') << subscriptions[i]->dt.day;
            cout << '\n';
            /**********    **********/
            //  
            cout << " ...: ";
            cout << setw(4) << setfill('0') << subscriptions[i]->tm.year << '-';
            //  
            cout << setw(2) << setfill('0') << subscriptions[i]->tm.month << '-';
            //  
            cout << setw(2) << setfill('0') << subscriptions[i]->tm.day;
            cout << '\n';
            cout << " ...: ";
            cout << setw(4) << setfill('0') << subscriptions[i]->period.year << '-';
            //  
            cout << setw(2) << setfill('0') << subscriptions[i]->period.month << '-';
            //  
            cout << setw(2) << setfill('0') << subscriptions[i]->period.day;
            cout << '\n';
            /**********   **********/
            cout << "   ...........: ";
            //   
            cout << subscriptions[i]->tarif << " ";
            //     
            cout << subscriptions[i]->pay << ". ";
            //     
            cout << '\n';
            /**********    **********/
            //  


            cout << '\n';
        }
        for (int i = 0; i < size; i++)
        {
            delete subscriptions[i];
        }
    }
    catch (const char* error)
    {
        cout << error << '\n';
    }
    return 0;
}
