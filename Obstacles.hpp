#pragma once
#include "Background.hpp"
#include "Object.hpp"

class Obstacles : public Object
{
private:
    // Coordinates and distances for managing obstacle positions
    int distance1 = 0;
    int distance2 = 805;
    int pipeDistance1 = 700;
    int pipeDistance2 = 900;
    int pipeDistance3 = 1100;
    int incY1 = 0;
    int incY2 = 0;
    int incY3 = 0;

public:
    // Function to update the position of the first upper pipe obstacle
    // Parameters:
    //   incY: Incremental value for adjusting the pipe's vertical position
    //   score: Reference to the score variable to update based on obstacle position
    // Returns:
    //   True if the obstacle requires a score update, false otherwise
    bool Pipe_Above1Update(int incY, int& score);

    // Function to update the position of the first lower pipe obstacle
    // Parameters:
    //   incY: Incremental value for adjusting the pipe's vertical position
    // Returns:
    //   True if the obstacle requires further updates, false otherwise
    bool Pipe_Below1Update(int incY);

    // Functions for updating the positions of the second set of pipes (similar structure)
    bool Pipe_Above2Update(int incY, int& score);
    bool Pipe_Below2Update(int incY);

    // Functions for updating the positions of the third set of pipes (similar structure)
    bool Pipe_Above3Update(int incY, int& score);
    bool Pipe_Below3Update(int incY);

    // Function to reset the obstacle positions
    void Reset();

    // Getter functions to retrieve the coordinates of each pipe obstacle
    int getPipe1X() const;
    int getPipe1Y() const;
    int getPipe2X() const;
    int getPipe2Y() const;
    int getPipe3X() const;
    int getPipe3Y() const;

    // Function to render the obstacle on the provided renderer
    // Parameters:
    //   ren: The SDL_Renderer used for rendering
    void Render(SDL_Renderer* ren);
};
