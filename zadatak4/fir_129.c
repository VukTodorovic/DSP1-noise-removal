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
#define Ntap 129

#define DCgain 32768

__int16 fir(__int16 NewSample) {
    __int16 FIRCoef[Ntap] = { 
         -168,
          344,
          294,
           -4,
          243,
          279,
         -285,
         -367,
          -11,
         -223,
         -390,
          192,
          433,
           43,
          190,
          495,
          -63,
         -484,
          -92,
         -144,
         -588,
         -102,
          513,
          159,
           89,
          665,
          309,
         -508,
         -246,
          -27,
         -718,
         -559,
          459,
          354,
          -36,
          743,
          860,
         -346,
         -484,
           99,
         -731,
        -1230,
          140,
          639,
         -157,
          673,
         1712,
          217,
         -834,
          207,
         -544,
        -2422,
         -881,
         1108,
         -245,
          269,
         3786,
         2443,
        -1655,
          268,
          606,
        -9108,
        -11410,
         6627,
        19966,
         6627,
        -11410,
        -9108,
          606,
          268,
        -1655,
         2443,
         3786,
          269,
         -245,
         1108,
         -881,
        -2422,
         -544,
          207,
         -834,
          217,
         1712,
          673,
         -157,
          639,
          140,
        -1230,
         -731,
           99,
         -484,
         -346,
          860,
          743,
          -36,
          354,
          459,
         -559,
         -718,
          -27,
         -246,
         -508,
          309,
          665,
           89,
          159,
          513,
         -102,
         -588,
         -144,
          -92,
         -484,
          -63,
          495,
          190,
           43,
          433,
          192,
         -390,
         -223,
          -11,
         -367,
         -285,
          279,
          243,
           -4,
          294,
          344,
         -168
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
