#define K_i 0.0075
#define K_p 0.3

double pi_controller(double u)
{
    static double u_p, y_p;

    double y = (K_p + K_i) * u - K_p * u_p + y_p;
    y_p = y;
    u_p = u;
    return y;
}

