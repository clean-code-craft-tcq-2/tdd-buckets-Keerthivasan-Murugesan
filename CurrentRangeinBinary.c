#include <stdio.h>
#include <math.h>
#include "CurrentRangeUpdate.h"


int BinaryToDecimalConverter(unsigned long long int A2D12bit){
    int dec, i, rem;
    dec = 0;
    i = 0;

    while(A2D12bit != 0){
        rem = A2D12bit % 10;
        A2D12bit /= 10;
        dec += rem*pow(2, i);
        i++;
    }
    return dec;
}

int A2DinputScaler(int currentvalue){
    float currentconverted;
    int Scaledvalue;

    currentconverted = (currentvalue * 10) / 4094;
    Scaledvalue = (int)(currentconverted < 0 ? (currentconverted-0.5) : (currentconverted+0.5));
    return Scaledvalue;
}

int* ConvertCurrentValuestoDecimal(unsigned long long int* CurrentValues, int samples){
    int temp;
    static int CurrentValues_dec[] = {0};
    for(int i = 0; i<samples; i++)
    {
        temp = BinaryToDecimalConverter(CurrentValues[i]);
        CurrentValues_dec[i] = A2DinputScaler(temp);
    }
    return CurrentValues_dec;
}

int CurrentRangeUpdate_Binary (unsigned long long int* CurrentValues, int samples){
    int* CurrentValues_converted;
    int CurrentRangeCount;

    CurrentValues_converted = ConvertCurrentValuestoDecimal(CurrentValues, samples);
    CurrentRangeCount = CurrentRangeUpdate(CurrentValues_converted, samples);
    return CurrentRangeCount;
}