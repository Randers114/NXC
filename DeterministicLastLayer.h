
/* STRATEGY:

Gå igennem øverste layer på cuben, ved at force toppen af cuben til at være gul.
Find ud af hvilke pieces der skal byttes, og smid dem ind i et array af integers. Brug opsætningen nedenfor til at finde den rigtige algoritme.

	1 2 3
	4 x 5
	6 7 8

For eksempel vil man gå igennem øverste layer og derved få et array af integers i form af: 1, 3, 4, 7, 7, 5.
Arrayet vil være sat op så input 0 og 1, 2 og 3, 4 og 5 osv. er kombineret. I array-eksemplet viser dette at 1 skal bytte plads med 3, 4 skal bytte plads med 7
og 7 skal bytte plads med 5. Derefter sammenligner man dette array med løsningerne fra Ruwix-hjemmesiden, dog hvor løsningerne også er omskrevet så det
passer med array-formen.


*/




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