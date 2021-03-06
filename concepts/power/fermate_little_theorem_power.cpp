// Iterative Function to calculate (x^y)%p in O(log y)
unsigned int power(unsigned int x, unsigned int y,
                                   unsigned int p)
{
    unsigned int res = 1;      // Initialize result

    x = x % p;  // Update x if it is more than or
                // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

// in python => pow(x, y, p)