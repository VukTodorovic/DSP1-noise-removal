/**************************************************************
WinFilter version 0.8
http://www.winfilter.20m.com
akundert@hotmail.com

Filter type: Band Pass
Filter model: Rectangular Window
Sampling Frequency: 48 KHz
Fc1 and Fc2 Frequencies: 4.500000 KHz and 14.000000 KHz
Coefficents Quantization: 16-bit
***************************************************************/
#define Ntap 35

#define DCgain 32768

__int16 fir(__int16 NewSample) {
    __int16 FIRCoef[Ntap] = { 
          204,
         -783,
          194,
         -511,
        -2274,
         -828,
         1041,
         -230,
          253,
         3555,
         2294,
        -1555,
          252,
          569,
        -8554,
        -10716,
         6223,
        18750,
         6223,
        -10716,
        -8554,
          569,
          252,
        -1555,
         2294,
         3555,
          253,
         -230,
         1041,
         -828,
        -2274,
         -511,
          194,
         -783,
          204
    };

    static __int16 x[Ntap]; //input samples
    __int32 y=0;            //output sample
    int n;

    //shift the old samples
    for(n=Ntap-1; n>0; n--)
       x[n] = x[n-1];

    //Calculate the new output
    x[0] = NewSample;
    for(n=0; n<Ntap; n++)
        y += FIRCoef[n] * x[n];
    
    return y / DCgain;
}
