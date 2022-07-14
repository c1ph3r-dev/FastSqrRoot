// This is a faster implementation of finding the approximate square root of a given number

// Uses Quake 3 implementation (modified to use 64 bit precision) of fast inverse square root
double Q_rsqrt(double number)
{
    long long i;
    double x2, y;
    constexpr double threehalfs = 1.5;

    x2 = number * 0.5;
    y = number;
    i = * (long long * ) &y;                // evil floating point bit hack
    i = 0x5f3759df - ( i >> 1);             // what the fuck?
    y = * (double * ) &i;
    y = y * ( threehalfs - (x2 * y * y));   // 1st iteration
#ifdef IMPROVE_ACCURACY
    y = y * ( threehalfs - (x2 * y * y));   // 2nd iteration, can be removed
#endif // IMPROVE_ACCURACY
    
    return y;
}

double Q_sqrt(double number)
{
    long long i;
    while(true)
    {
        if (i * i > number)             // Get nearest perfect square
        {
            --i;
            break;
        }
        ++i;
    }
    double j = i * i;                   // Nearest perfect square
    auto k = Q_rsqrt(4 * j);            // Get Inverse of 2*i by getting the inverse square root of 2*i squared
    auto x = i + ((number - j) * k);    // Math magic that gets the approximate square root

    return x;
}