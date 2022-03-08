int CurrentRangeUpdate (int* CurrentValues, int samples){
    int CurrentRange_Count = 0;
    int CurrentRange_prev = 0, CurrentRange_curr = 0;
    int CurrentRangesWithCount[][3] = {{0,0,0}, {0,0,0}};
    for(int i =0; i<samples; i++){
        CurrentRange_curr = CurrentValues[i];
        if((CurrentRange_curr == CurrentRange_prev) || 
           (CurrentRange_curr == CurrentRange_prev+1))
           {
                CurrentRangesWithCount[CurrentRange_Count - 1][1] = CurrentRange_curr;
                CurrentRangesWithCount[CurrentRange_Count][2] += 1;
           }
        else{
            CurrentRangesWithCount[CurrentRange_Count][0] = CurrentRange_curr;
            CurrentRangesWithCount[CurrentRange_Count][2] = 1;
            CurrentRange_Count++;
        }
        CurrentRange_prev = CurrentRange_curr;
    }
    printf("***********************************\n");
    printf("Range, Readings\n");
    for(int j = 0; j<CurrentRange_Count; j++){
        printf("%d - %d, %d\n", CurrentRangesWithCount[CurrentRange_Count][0], CurrentRangesWithCount[CurrentRange_Count][1], CurrentRangesWithCount[CurrentRange_Count][2]);
    } 
    return CurrentRange_Count;
}