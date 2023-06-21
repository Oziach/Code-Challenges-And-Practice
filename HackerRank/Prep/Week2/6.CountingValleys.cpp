/*Question:

Given the sequence of up and down steps during a hike, find and print the number of valleys walked through. 
*/

//Solution

/*
 * Complete the 'countingValleys' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER steps
 *  2. STRING path
 */

int countingValleys(int steps, string path) {
    int altitude = 0;
    int prevAltitude = 0;
    int count = 0;
    
    for(int i = 0; i < steps; i++){
        int addFactor = path[i] == 'U' ? 1 : -1; 
        prevAltitude = altitude;
        altitude += addFactor;
        if(altitude >= 0 && prevAltitude < 0){
            count++;
        }   
    }
