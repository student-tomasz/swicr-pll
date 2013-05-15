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
#define NCoef 4
double butterworth(double newSample) {
    double ACoef[NCoef+1] = {
        0.00000000142236927842,
        0.00000000568947711369,
        0.00000000853421567053,
        0.00000000568947711369,
        0.00000000142236927842
    };

    double BCoef[NCoef+1] = {
        1.00000000000000000000,
        -3.96716259594884860000,
        5.90202586149087870000,
        -3.90255878482324010000,
        0.96769554381313738000
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
