/*Question:

You will be given a list of 32 bit unsigned integers. Flip all the bits ( and ) and return the result as an unsigned integer. 

*/

//Solution

/*
 * Complete the 'flippingBits' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts LONG_INTEGER n as parameter.
 */

long flippingBits(long n) {
    bitset<32> b = bitset<32>(n);
    b.flip();
    return (b.to_ullong());
}
