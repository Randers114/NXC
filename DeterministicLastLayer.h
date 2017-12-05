
sub EvaluateFaceColors(char faceColors[])
{
	// Saves the colours of the Front, Right, Back, and Left faces in an array, respectively. Is used to determine the correct algorithm to run.

}

sub EvaluateLastLayerConfiguration(int lastLayerConfigurationArray[])
{
    // Checks each square in the last unsolved layer of the cube. If a square is yellow, a value of 1 is saved. If a square isn't yellow, a value of 0 is saved.
    // The values are placed in an array of int's, where the first entry in the array corresponds to the leftmost square in the front face.
    // The faces are evaluated in the following sequence: Front, Right, Back, Left. The squares on each face are all evaluated in the sequence: Left, Middle, Right.
    // The array is then as follows: [F0, F1, F2, R8, R7, R6, B8, B7, B6, L0, L1, L2] taking the representation into account.
    int arrayCounter = 0, pieceCounterFront = 0, pieceCounterRight = 8, pieceCounterBack = 8, pieceCounterLeft = 0; 


    for (int amount = 0; amount < 3; amount++) // Front face configuration
    {
        if (myCube[FRONT_FACE][pieceCounterFront] == 'y')
        {
            lastLayerConfigurationArray[arrayCounter] = 1;
        }
        else
        {
            lastLayerConfigurationArray[arrayCounter] = 0;
        }
        pieceCounterFront++;
        arrayCounter++;
    }

    for (int amount = 0; amount < 3; amount++) // Right face configuration
    {
        if (myCube[RIGHT_FACE][pieceCounterRight] == 'y')
        {
            lastLayerConfigurationArray[arrayCounter] = 1;
        }
        else
        {
            lastLayerConfigurationArray[arrayCounter] = 0;
        }
        pieceCounterRight--;
        arrayCounter++;
    }

    for (int amount = 0; amount < 3; amount++) // Back face configuration
    {
        if (myCube[BACK_FACE][pieceCounterBack] == 'y')
        {
            lastLayerConfigurationArray[arrayCounter] = 1;
        }
        else
        {
            lastLayerConfigurationArray[arrayCounter] = 0;
        }
        pieceCounterBack--;
        arrayCounter++;
    }

    for (int amount = 0; amount < 3; amount++) // Left face configuration
    {
        if (myCube[LEFT_FACE][pieceCounterLeft] == 'y')
        {
            lastLayerConfigurationArray[arrayCounter] = 1;
        }
        else
        {
            lastLayerConfigurationArray[arrayCounter] = 0;
        }
        pieceCounterLeft++;
        arrayCounter++;
    }
}


sub FindMoveset()
{




}