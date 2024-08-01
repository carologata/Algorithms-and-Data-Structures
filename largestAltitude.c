int largestAltitude(int* gain, int gainSize) {
    
    int altitude = 0;
    int highest = 0;

    for(int i = 0; i < gainSize; i++)
    {
        altitude += gain[i];
        if(altitude > highest)
            highest = altitude;
    }
    return (highest);
}