/**************************************************************
WinFilter version 0.8
http://www.winfilter.20m.com
akundert@hotmail.com

Filter type: Low Pass
Filter model: Butterworth
Filter order: 4
Sampling Frequency: 10 KHz
Cut Frequency: 0.020000 KHz
Coefficents Quantization: float

Z domain Zeros
z = -1.000000 + j 0.000000
z = -1.000000 + j 0.000000
z = -1.000000 + j 0.000000
z = -1.000000 + j 0.000000

Z domain Poles
z = 0.988394 + j -0.004731
z = 0.988394 + j 0.004731
z = 0.995187 + j -0.011593
z = 0.995187 + j 0.011593
***************************************************************/
#define NCoef 4
float iir(float NewSample) {
    float ACoef[NCoef+1] = {
        0.00000000142236927842,
        0.00000000568947711369,
        0.00000000853421567053,
        0.00000000568947711369,
        0.00000000142236927842
    };

    float BCoef[NCoef+1] = {
        1.00000000000000000000,
        -3.96716259594884860000,
        5.90202586149087870000,
        -3.90255878482324010000,
        0.96769554381313738000
    };

    static float y[NCoef+1]; //output samples
    static float x[NCoef+1]; //input samples
    int n;

    //shift the old samples
    for(n=NCoef; n>0; n--) {
       x[n] = x[n-1];
       y[n] = y[n-1];
    }

    //Calculate the new output
    x[0] = NewSample;
    y[0] = ACoef[0] * x[0];
    for(n=1; n<=NCoef; n++)
        y[0] += ACoef[n] * x[n] - BCoef[n] * y[n];
    
    return y[0];
}
