#include "CurrentRangeUpdate.h"
#include <stdio.h>

int CurrentRangesWithCount[][3] = {0};

int CurrentRangeUpdate (int* CurrentValues, int samples){
    int CurrentRange_Count = 0;
    int CurrentRange_prev = 0, CurrentRange_curr = 0;
    int* CurrentValues_sorted;

    CurrentValues_sorted = Sort_CurrentValues(CurrentValues, samples);

    for(int i =0; i<samples; i++){
        CurrentRange_curr = *(CurrentValues_sorted+i);
        if((CurrentRange_curr == CurrentRange_prev) || 
           (CurrentRange_curr == CurrentRange_prev+1))
           {
                CurrentRangesWithCount[CurrentRange_Count - 1][1] = CurrentRange_curr;
                CurrentRangesWithCount[CurrentRange_Count - 1][2]++;
           }
        else{
            CurrentRangesWithCount[CurrentRange_Count][0] = CurrentRange_curr;
            CurrentRangesWithCount[CurrentRange_Count][1] = CurrentRange_curr;
            CurrentRangesWithCount[CurrentRange_Count][2] = 1;
            CurrentRange_Count++;
        }
        CurrentRange_prev = CurrentRange_curr;
    }

    PrintonConsole(CurrentRange_Count, CurrentRangesWithCount);
    return CurrentRange_Count;
}

int* Sort_CurrentValues(int* CurrentValues, int samples){
    int temp;

    for(int i = 0; i<samples; i++)
    {
        for(int j = 0; j<samples; j++)
        {
            if(CurrentValues[j] > CurrentValues[j+1])
            {
                temp = CurrentValues[j];
                CurrentValues[j] = CurrentValues[j+1];
                CurrentValues[j+1] = temp;
            }
        }
    }
    return CurrentValues;
}

void PrintonConsole(int CurrentRange_Count, int (*CurrentRangesWithCount)[3]){
    printf("***********************************\n");
    printf("Current values range count = %d\n", CurrentRange_Count);
    printf("Range, Readings\n");
    for(int j = 0; j<CurrentRange_Count; j++){
        printf("%d - %d, %d\n", CurrentRangesWithCount[j][0], CurrentRangesWithCount[j][1], CurrentRangesWithCount[j][2]);
    }
}