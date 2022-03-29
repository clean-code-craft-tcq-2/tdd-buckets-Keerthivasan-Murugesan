#include <stdio.h>
#include <math.h>
#include "CurrentRangeUpdate.h"


int A2DinputScaler(int currentvalue){
    float currentconverted;
    int Scaledvalue;

    currentconverted = (currentvalue * 10.0) / 4094;
    Scaledvalue = (int)(currentconverted < 0 ? (currentconverted-0.5) : (currentconverted+0.5));
    return Scaledvalue;
}

int* ConvertCurrentValuestoDecimal(int* CurrentValues, int samples){
    for(int i = 0; i<samples; i++)
    {
        if(CurrentValues[i] != 4095){
            CurrentValues[i] = A2DinputScaler(CurrentValues[i]);
        }
    }
    return CurrentValues;
}

int CurrentRangeUpdate_A2D (int* CurrentValues, int samples){
    int CurrentRangeCount;

    ConvertCurrentValuestoDecimal(CurrentValues, samples);
    CurrentRangeCount = CurrentRangeUpdate(CurrentValues, samples);
    return CurrentRangeCount;
}