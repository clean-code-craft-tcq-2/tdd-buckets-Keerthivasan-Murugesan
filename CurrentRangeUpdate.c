int CurrentRangeUpdate (int* CurrentValues, int samples){
    int CurrentRange_Count = 0;
    int CurrentRange_prev = 0, CurrentRange_curr = 0;
    for(int i =0; i<samples; i++){
        CurrentRange_curr = CurrentValues[i];
        if((CurrentRange_curr == CurrentRange_prev) || 
           (CurrentRange_curr+1 == CurrentRange_prev))
           {


           }
        else{
            CurrentRange_Count++;
        }
        CurrentRange_prev = CurrentRange_curr;
    }
    return CurrentRange_Count;
}