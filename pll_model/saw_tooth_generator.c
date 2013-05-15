#define pi 3.1415926535897932384626433
#define f_smp 10000
#define f_target 250

double saw_tooth_generator()
{
    const double dy = 2*pi / f_smp * f_target;
    static double y = -2*pi / f_smp * f_target; // == -dy
    
    y = fmod(y+dy, 2*pi);
    
    return y;
}
