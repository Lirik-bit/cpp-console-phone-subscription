#include "file_reader.h"
#include "constants.h"

#include <fstream>
#include <cstring>

date convertdate(char* str)
{
    date result;
    char* context = NULL;
    char* str_number = strtok_s(str, ".", &context);
    result.day = atoi(str_number);
    str_number = strtok_s(NULL, ".", &context);
    result.month = atoi(str_number);
    str_number = strtok_s(NULL, ".", &context);
    result.year = atoi(str_number);
    return result;
}

date converttime(char* str)
{
    date result;
    char* context = NULL;
    char* str_number = strtok_s(str, ":", &context);
    result.day = atoi(str_number);
    str_number = strtok_s(NULL, ":", &context);
    result.month = atoi(str_number);
    str_number = strtok_s(NULL, ":", &context);
    result.year = atoi(str_number);
    return result;
}

void read(const char* file_name, phone_subscription* array[], int& size)
{
    std::ifstream file(file_name);
    if (file.is_open())
    {
        size = 0;
        char tmp_buffer[MAX_STRING_SIZE];
        while (!file.eof())
        {
       
            phone_subscription* item = new phone_subscription;
            file >> item->number;
            file >> tmp_buffer;
            item->dt = convertdate(tmp_buffer);
            file >> tmp_buffer;
            item->tm = converttime(tmp_buffer);
            file >> tmp_buffer;
            item->period = converttime(tmp_buffer);
            file >> item->tarif;
            file >> tmp_buffer;
            item->pay = atof(tmp_buffer);
            array[size++] = item;

        }
        file.close();
    }
    else
    {
        throw "Ошибка открытия файла";
    }
}