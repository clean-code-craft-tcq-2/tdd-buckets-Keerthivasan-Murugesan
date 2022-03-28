extern int CurrentRangesWithCount[][3];

int CurrentRangeUpdate (int* CurrentValues, int samples);
int* Sort_CurrentValues(int* CurrentValues, int samples);
void PrintonConsole(int CurrentRange_Count);

int BinaryToDecimalConverter(unsigned long long int A2D12bit);
int* ConvertCurrentValuestoDecimal(unsigned long long int* CurrentValues, int samples);
int CurrentRangeUpdate_Binary (unsigned long long int* CurrentValues, int samples);
int A2DinputScaler(int currentvalue);