#pragma once

struct Colour
{
    int R;
    int G;
    int B;
    int A;

    Colour(int R, int G, int B, int A)
    {
        this->R=R;
        this->G=G;
        this->B=B;
        this->A=A;
    }

    Colour(float R, float G, float B, float A)
    {
        this->R= (int)(R * 255);
        this->G= (int)(G * 255);
        this->B= (int)(B * 255);
        this->A= (int)(A * 255);
    }
};
