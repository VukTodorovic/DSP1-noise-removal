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
#define Ntap 77

#define DCgain 32768

__int16 fir(__int16 NewSample) {
    __int16 FIRCoef[Ntap] = { 
          302,
         -498,
         -241,
          -27,
         -704,
         -547,
          449,
          347,
          -35,
          728,
          843,
         -339,
         -474,
           97,
         -716,
        -1205,
          137,
          627,
         -154,
          659,
         1677,
          213,
         -817,
          203,
         -533,
        -2373,
         -864,
         1086,
         -240,
          264,
         3710,
         2394,
        -1622,
          263,
          594,
        -8925,
        -11181,
         6493,
        19564,
         6493,
        -11181,
        -8925,
          594,
          263,
        -1622,
         2394,
         3710,
          264,
         -240,
         1086,
         -864,
        -2373,
         -533,
          203,
         -817,
          213,
         1677,
          659,
         -154,
          627,
          137,
        -1205,
         -716,
           97,
         -474,
         -339,
          843,
          728,
          -35,
          347,
          449,
         -547,
         -704,
          -27,
         -241,
         -498,
          302
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
