# Interactive Mandelbrot Set Explorer with SFML

This is an interactive Mandelbrot set explorer implemented in C++ using SFML (Simple and Fast Multimedia Library) for graphical rendering. The Mandelbrot set is a set of complex numbers for which the function f(z)=z2+cf(z)=z2+c does not diverge when iterated from z=0z=0, i.e., the sequence z0=0,z1=f(z0),z2=f(z1),…z0​=0,z1​=f(z0​),z2​=f(z1​),… remains bounded.

# Features

Renders the Mandelbrot set with interactive graphical output using SFML. 
Allows users to zoom in, zoom out, and navigate across the Mandelbrot set.

# Prerequisites

CMake (version 3.0 or higher)
SFML (version 2.5 or higher)

# Instructions

    Zoom In: Press 'Z'
    Zoom Out: Press 'X'
    Pan:
        Up: Press up arrow
        Down: Press down arrow
        Left: Press left arrow
        Right: Press right arrow
    Increase Number of Iterations: Press Space
