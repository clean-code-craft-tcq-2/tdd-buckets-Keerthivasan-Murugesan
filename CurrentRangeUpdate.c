#include "CurrentRangeUpdate.h"
#include <stdio.h>

int CurrentRangesWithCount[5][3] = {0};

int CurrentRangeUpdate (int* CurrentValues, int samples){
    int CurrentRange_Count = 0;
    int CurrentRange_prev, CurrentRange_curr;
    int* CurrentValues_sorted;

    CurrentValues_sorted = Sort_CurrentValues(CurrentValues, samples);
    CurrentRange_prev = *(CurrentValues_sorted+(samples-1));

    for(int i =0; i<samples; i++){
        CurrentRange_curr = *(CurrentValues_sorted+i);

        if(CurrentRange_curr != 4095)
        {
            if((CurrentRange_curr == CurrentRange_prev) || 
                (CurrentRange_curr == CurrentRange_prev+1))
            {
                CurrentRangesWithCount[CurrentRange_Count - 1][1] = CurrentRange_curr;
                CurrentRangesWithCount[CurrentRange_Count - 1][2]++;
            }
            else
            {
                CurrentRangesWithCount[CurrentRange_Count][0] = CurrentRange_curr;
                CurrentRangesWithCount[CurrentRange_Count][1] = CurrentRange_curr;
                CurrentRangesWithCount[CurrentRange_Count][2] = 1;
                CurrentRange_Count++;
            }
        }
        CurrentRange_prev = CurrentRange_curr;
    }

    PrintonConsole(CurrentRange_Count);
    return CurrentRange_Count;
}

int* Sort_CurrentValues(int* CurrentValues, int samples){
    int temp;

    for(int i = 0; i<samples; i++)
    {
        for(int j = i+1; j<samples; j++)
        {
            if(CurrentValues[i] > CurrentValues[j])
            {
                temp = CurrentValues[i];
                CurrentValues[i] = CurrentValues[j];
                CurrentValues[j] = temp;
            }
        }
    }
    return CurrentValues;
}

void PrintonConsole(int CurrentRange_Count){
    printf("***********************************\n");
    printf("Current values range count = %d\n", CurrentRange_Count);
    printf("Range, Readings\n");
    for(int j = 0; j<CurrentRange_Count; j++){
        printf("%d - %d, %d\n", CurrentRangesWithCount[j][0], CurrentRangesWithCount[j][1], CurrentRangesWithCount[j][2]);
    }
}
