// This is a faster implementation of finding the approximate square root of a given number

float Q_sqrt(float number, float nearest)
{
    float j = nearest * nearest;                    // Nearest perfect square
    float k = 1 / (2 * nearest);                    // Inverse of 2 * nearest perfect square
    float x = nearest + ((number - j) * k);         // Math magic that gets the approximate square root

    return x;
}