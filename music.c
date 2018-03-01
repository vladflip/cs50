#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int duration(string fraction)
{
    float numerator = fraction[0] - '0';
    float denumerator = fraction[2] - '0';
    int result = numerator / denumerator * 8;

    return result;
}

int count_semitones(char note)
{
    switch (note)
    {
        case 'B':
            return 2;
        case 'C':
            return -9;
        case 'D':
            return -7;
        case 'E':
            return -5;
        case 'F':
            return -4;
        case 'G':
            return -2;
    }
}

int frequency(string note)
{
    char letter = note[0];
    int sharp = note[1] == '#' ? 1 : 0;
    int flat = note[1] == 'b' ? 1 : 0;
    int octave = note[strlen(note) - 1] - '0';

    float frequency = 440 * pow(2, octave - 4);
    int semitones = count_semitones(note[0]);
    float semitone = pow(2, (float)1 / (float)12);

    if (letter != 'A')
    {
        frequency = frequency * pow((float)2, (float)semitones / (float)12);
    }

    if (sharp)
    {
        frequency = frequency * semitone;
    }
    else if (flat)
    {
        frequency = frequency / semitone;
    }

    return (int)round(frequency);
}

int main(void)
{
    printf("%i\n", frequency("Ab3"));
    
    return 0;
}
