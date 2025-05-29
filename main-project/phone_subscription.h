#ifndef PHONE_SUBSCRIPTION_H
#define PHONE_SUBSCRIPTION_H

#include "constants.h"

struct date
{
    int day;
    int month;
    int year;
};

struct phone_subscription
{
    char number[MAX_STRING_SIZE];
    date dt;
    date tm;
    date period;
    char tarif[MAX_STRING_SIZE];
    double pay;

};

#endif