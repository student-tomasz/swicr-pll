/**************************************************************
WinFilter version 0.8
http://www.winfilter.20m.com
akundert@hotmail.com

Filter type: Low Pass
Filter model: Butterworth
Filter order: 4
Sampling Frequency: 10 KHz
Cut Frequency: 0.025000 KHz
Coefficents Quantization: double

Z domain Zeros
z = -1.000000 + j 0.000000
z = -1.000000 + j 0.000000
z = -1.000000 + j 0.000000
z = -1.000000 + j 0.000000

Z domain Poles
z = 0.985550 + j -0.005914
z = 0.985550 + j 0.005914
z = 0.993927 + j -0.014444
z = 0.993927 + j 0.014444
***************************************************************/
#define NCoef 5
double butterworth(double newSample) {
    double ACoef[NCoef+1] = {
        0.00000000378517015213,
        0.00000001514068060852,
        0.00000002271102091279,
        0.00000001514068060852,
        0.00000000378517015213
    };

    double BCoef[NCoef+1] = {
        1.00000000000000000000,
        -3.95895331864708360000,
        5.87770027353614570000,
        -3.87853054905173390000,
        0.95978365381149922000
    };

    static double y[NCoef+1]; //output samples
    static double x[NCoef+1]; //input samples
    int n;

    //shift the old samples
    for(n=NCoef; n>0; n--) {
       x[n] = x[n-1];
       y[n] = y[n-1];
    }

    //Calculate the new output
    x[0] = newSample;
    y[0] = ACoef[0] * x[0];
    for(n=1; n<=NCoef; n++)
        y[0] += ACoef[n] * x[n] - BCoef[n] * y[n];
    
    return y[0];
}
