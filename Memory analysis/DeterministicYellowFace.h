#include "Heuristic.h"

#define NUM_OF_FACES 6
#define NUM_OF_PIECES 9


sub EvaluateYellowFaceConfiguration(int yellowConfigurationArray[])
{
    // Checks each square on the yellow face. If a square is yellow, a value of 1 is saved. If a square isn't yellow, a value of 0 is saved.
    // These values are placed in an array of int's, where the first entry in the array corresponds to the square noted as the first square in the representation.
    // An example of an int array would be: 1 0 0 1 1 1 0 0 1, which would correspond to the configuration:
    //      y 0 y
    //      y y y
    //      y 0 y

    for (int face = 0; face < NUM_OF_FACES; face++)
    {
        if (myCube[face][4] == 'y')
        {
            for (int piece = 0; piece < NUM_OF_PIECES; piece++)
            {
                if (myCube[face][piece] == 'y')
                {
                    yellowConfigurationArray[piece] = 1;
                }
                else
                {
                    yellowConfigurationArray[piece] = 0;
                }
            }
        }
    }
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

bool CmpArray(int a[], int b[])
{
	for(int i = 0; i < ArrayLen(a); i++)
	{
		if(a[i] != b[i])
		{
			return FALSE;
		}
	}
	return TRUE;
}


sub FindCorrectMoveset(int &finalMoveset[])
{
    // Switches on the configuration of the yellow face. Thereafter, if necessary, switch on the cases for the same yellow-face configuration.
    int numOfTurns = 0;
    bool configurationFound = FALSE;
    int yellowConfigurationArray[], lastLayerConfigurationArray[];
    int yellowFaceMoveset[], turnsMoveset[];
	int yellowFaceComparisonArray[], lastLayerComparisonArray[];


    while(!configurationFound)
    {
        EvaluateYellowFaceConfiguration(yellowConfigurationArray);
        EvaluateLastLayerConfiguration(lastLayerConfigurationArray);

        // Dot
        ArrayBuild(yellowFaceComparisonArray, 0, 0, 0, 0, 1, 0, 0, 0, 0);
        if (CmpArray(yellowConfigurationArray, yellowFaceComparisonArray))
        { // Centrum
            ArrayBuild(lastLayerComparisonArray, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1);
			if (CmpArray(lastLayerConfigurationArray, lastLayerComparisonArray))
            {
                ArrayBuild(yellowFaceMoveset, 1, 11, 4, 3, 9, 12, 8, 4, 10, 1, 9, 12);
                configurationFound = TRUE;
            }
            
            ArrayBuild(lastLayerComparisonArray, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0);
            if (CmpArray(lastLayerConfigurationArray, lastLayerComparisonArray))
            {
                ArrayBuild(yellowFaceMoveset, 2, 1, 9, 12, 3, 7, 4, 3, 9, 11, 7, 3, 7, 9);
                configurationFound = TRUE;
            }

            
        }


        ArrayBuild(yellowFaceComparisonArray, 0, 0, 0, 0, 1, 0, 0, 0, 1);
        if (CmpArray(yellowConfigurationArray, yellowFaceComparisonArray))
        { // Centrum og et hjørne - hjørne mod højre ned
            ArrayBuild(lastLayerComparisonArray, 0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1);
            if (CmpArray(lastLayerConfigurationArray, lastLayerComparisonArray))
            {
                ArrayBuild(yellowFaceMoveset, 10, 7, 3, 10, 11, 11, 1, 7, 10, 1, 12);
                configurationFound = TRUE;
            }

            
        }


        ArrayBuild(yellowFaceComparisonArray, 0, 0, 1, 0, 1, 0, 0, 0, 0);
        if (CmpArray(yellowConfigurationArray, yellowFaceComparisonArray))
        { // Centrum og et hjørne - hjørne mod højre op
            ArrayBuild(lastLayerComparisonArray, 1, 1, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0);
            if (CmpArray(lastLayerConfigurationArray, lastLayerComparisonArray))
            {
                ArrayBuild(yellowFaceMoveset, 2, 11, 7, 10, 1, 9, 12, 4, 10, 12, 9, 12, 3);
                configurationFound = TRUE;
            }

            
        }


        ArrayBuild(yellowFaceComparisonArray, 1, 0, 0, 0, 1, 0, 0, 0, 1);
        if (CmpArray(yellowConfigurationArray, yellowFaceComparisonArray))
        { // Skrå linje
            ArrayBuild(lastLayerComparisonArray, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1);
            if (CmpArray(lastLayerConfigurationArray, lastLayerComparisonArray))
            {
                ArrayBuild(yellowFaceMoveset, 1, 11, 10, 11, 10, 1, 9, 12, 3, 7, 4, 3, 9, 12);
                configurationFound = TRUE;
            }

            
        }


        ArrayBuild(yellowFaceComparisonArray, 1, 0, 1, 0, 1, 0, 1, 0, 1);
        if (CmpArray(yellowConfigurationArray, yellowFaceComparisonArray))
        { // Skrå kryds
            ArrayBuild(lastLayerComparisonArray, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0);
            if (CmpArray(lastLayerConfigurationArray, lastLayerComparisonArray))
            {
                ArrayBuild(yellowFaceMoveset, 2, 1, 7, 11, 1, 7, 12, 3, 11, 1, 7, 12, 3, 7, 11);
                configurationFound = TRUE;
            }

            
        }


        ArrayBuild(yellowFaceComparisonArray, 1, 0, 1, 0, 1, 0, 0, 0, 0);
        if (CmpArray(yellowConfigurationArray, yellowFaceComparisonArray))
        { // Centrum og to hjørner ved siden af hinanden - Vender opad
            ArrayBuild(lastLayerComparisonArray, 0, 1, 0, 1, 1, 0, 0, 1, 0, 0, 1, 1);
            if (CmpArray(lastLayerConfigurationArray, lastLayerComparisonArray))
            {
                ArrayBuild(yellowFaceMoveset, 2, 11, 7, 1, 1, 1, 10, 12, 1, 7, 9, 7, 11, 1);
                configurationFound = TRUE;
            }

            
        }


        ArrayBuild(yellowFaceComparisonArray, 0, 0, 0, 0, 1, 0, 1, 0, 1);
        if (CmpArray(yellowConfigurationArray, yellowFaceComparisonArray))
        { // Centrum og to hjørner ved siden af hinanden - Vender nedad
            ArrayBuild(lastLayerComparisonArray, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0);
            if (CmpArray(lastLayerConfigurationArray, lastLayerComparisonArray))
            {
                ArrayBuild(yellowFaceMoveset, 9, 1, 1, 10, 11, 2, 9, 7, 12, 3, 9, 12);
                configurationFound = TRUE;
            }

            
        }



        // Line
        ArrayBuild(yellowFaceComparisonArray, 0, 1, 0, 0, 1, 0, 0, 1, 0);
        if (CmpArray(yellowConfigurationArray, yellowFaceComparisonArray))
        { // Lige linje - lodret
            ArrayBuild(lastLayerComparisonArray, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0);
            if (CmpArray(lastLayerConfigurationArray, lastLayerComparisonArray))
            {
                ArrayBuild(yellowFaceMoveset, 2, 12, 2, 9, 12, 3, 9, 12, 9, 9);
                configurationFound = TRUE;
            }
            
            ArrayBuild(lastLayerComparisonArray, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1);
            if (CmpArray(lastLayerConfigurationArray, lastLayerComparisonArray))
            {
                ArrayBuild(yellowFaceMoveset, 1, 12, 3, 7, 11, 10, 9, 7, 11, 12, 9, 7, 9, 4);
                configurationFound = TRUE;
            }

            
        }


        ArrayBuild(yellowFaceComparisonArray, 0, 0, 0, 1, 1, 1, 0, 0, 0);
        if (CmpArray(yellowConfigurationArray, yellowFaceComparisonArray))
        { // Lige linje - vandret
            ArrayBuild(lastLayerComparisonArray, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0);
            if (CmpArray(lastLayerConfigurationArray, lastLayerComparisonArray))
            {
                ArrayBuild(yellowFaceMoveset, 9, 9, 1, 10, 12, 9, 11, 10, 12, 4);
                configurationFound = TRUE;
            }
            
            ArrayBuild(lastLayerComparisonArray, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1);
            if (CmpArray(lastLayerConfigurationArray, lastLayerComparisonArray))
            {
                ArrayBuild(yellowFaceMoveset, 4, 2, 9, 4, 12, 9, 11, 10, 12, 9, 11, 1, 9);
                configurationFound = TRUE;
            }

            
        }
        


        // Cross
        ArrayBuild(yellowFaceComparisonArray, 0, 1, 0, 1, 1, 1, 0, 1, 0);
        if (CmpArray(yellowConfigurationArray, yellowFaceComparisonArray))
        { // Lige kryds
            ArrayBuild(lastLayerComparisonArray, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0);
            if (CmpArray(lastLayerConfigurationArray, lastLayerComparisonArray))
            {
                ArrayBuild(yellowFaceMoveset, 3, 12, 12, 9, 10, 11, 11, 9, 12, 9, 11);
                configurationFound = TRUE;
            }
            
            ArrayBuild(lastLayerComparisonArray, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1);
            if (CmpArray(lastLayerConfigurationArray, lastLayerComparisonArray))
            {
                ArrayBuild(yellowFaceMoveset, 1, 11, 10, 11, 9, 12, 10, 11, 9, 11, 7, 10);
                configurationFound = TRUE;
            }

            
        }


        ArrayBuild(yellowFaceComparisonArray, 0, 1, 0, 1, 1, 1, 0, 1, 1);
        if (CmpArray(yellowConfigurationArray, yellowFaceComparisonArray))
        { // Lige kryds med et hjørne (FISKEN)
            ArrayBuild(lastLayerComparisonArray, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0);
            if (CmpArray(lastLayerConfigurationArray, lastLayerComparisonArray))
            {
                ArrayBuild(yellowFaceMoveset, 4, 11, 11, 10, 9, 11, 12);
                configurationFound = TRUE;
            }
            
            ArrayBuild(lastLayerComparisonArray, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1);
            if (CmpArray(lastLayerConfigurationArray, lastLayerComparisonArray))
            {
                ArrayBuild(yellowFaceMoveset, 2, 11, 7, 9, 11, 10, 11, 9);
                configurationFound = TRUE;
            }

            
        }


        ArrayBuild(yellowFaceComparisonArray, 1, 1, 0, 1, 1, 1, 1, 1, 0);
        if (CmpArray(yellowConfigurationArray, yellowFaceComparisonArray))
        { // Lige kryds med to hjørner ved siden af hinanden - 2 ikke-gule mod højre
            ArrayBuild(lastLayerComparisonArray, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0);
            if (CmpArray(lastLayerConfigurationArray, lastLayerComparisonArray))
            {
                ArrayBuild(yellowFaceMoveset, 2, 2, 11, 9, 9, 12, 12, 9);
                configurationFound = TRUE;
            }

            
        }


        ArrayBuild(yellowFaceComparisonArray, 1, 1, 1, 1, 1, 1, 0, 1, 0);
        if (CmpArray(yellowConfigurationArray, yellowFaceComparisonArray))
        { // Lige kryds med to hjørner ved siden af hinanden - 2 ikke-gule mod ned
            ArrayBuild(lastLayerComparisonArray, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0);
            if (CmpArray(lastLayerConfigurationArray, lastLayerComparisonArray))
            {
                ArrayBuild(yellowFaceMoveset, 1, 7, 9, 12, 11, 7, 9, 10, 12, 11, 7, 10);
                configurationFound = TRUE;
            }

            
        }


        ArrayBuild(yellowFaceComparisonArray, 1, 1, 0, 1, 1, 1, 0, 1, 1);
        if (CmpArray(yellowConfigurationArray, yellowFaceComparisonArray))
        { // Lige kryds med modsatte hjørner
            ArrayBuild(lastLayerComparisonArray, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
            if (CmpArray(lastLayerConfigurationArray, lastLayerComparisonArray))
            {
                ArrayBuild(yellowFaceMoveset, 2, 2, 12, 9, 9, 12, 11, 9);
                configurationFound = TRUE;
            }

            
        }



        // 4 CORNERS
        ArrayBuild(yellowFaceComparisonArray, 1, 0, 1, 1, 1, 0, 1, 1, 1);
        if (CmpArray(yellowConfigurationArray, yellowFaceComparisonArray))
        { // Skrå kryds med to kanter ved siden af hinanden
            ArrayBuild(lastLayerComparisonArray, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0);
            if (CmpArray(lastLayerConfigurationArray, lastLayerComparisonArray))
            {
                ArrayBuild(yellowFaceMoveset, 2, 2, 11, 1, 7, 12, 4, 11);
                configurationFound = TRUE;
            }

            
        }


        ArrayBuild(yellowFaceComparisonArray, 1, 0, 1, 1, 1, 1, 1, 0, 1);
        if (CmpArray(yellowConfigurationArray, yellowFaceComparisonArray))
        { // Skrå kryds med modsatte kanter
            ArrayBuild(lastLayerComparisonArray, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0);
            if (CmpArray(lastLayerConfigurationArray, lastLayerComparisonArray))
            {
                ArrayBuild(yellowFaceMoveset, 4, 9, 12, 10, 9, 3, 9, 12);
                configurationFound = TRUE;
            }

            
        }



        // SHAPE _|
        ArrayBuild(yellowFaceComparisonArray, 0, 1, 0, 1, 1, 0, 1, 0, 0);
        if (CmpArray(yellowConfigurationArray, yellowFaceComparisonArray))
        { // Z-form drejet mod venstre
            ArrayBuild(lastLayerComparisonArray, 0, 1, 1, 0, 1, 1, 0, 0, 1, 0, 0, 0);
            if (CmpArray(lastLayerConfigurationArray, lastLayerComparisonArray))
            {
                ArrayBuild(yellowFaceMoveset, 3, 3, 12, 9, 11, 9, 7, 10);
                configurationFound = TRUE;
            }

            
        }


        ArrayBuild(yellowFaceComparisonArray, 1, 1, 0, 1, 1, 0, 0, 0, 1);
        if (CmpArray(yellowConfigurationArray, yellowFaceComparisonArray))
        { // Firkant i hjørnet med det modsatte hjørne - Firkant mod venstre op
            ArrayBuild(lastLayerComparisonArray, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0);
            if (CmpArray(lastLayerConfigurationArray, lastLayerComparisonArray))
            {
                ArrayBuild(yellowFaceMoveset, 9, 2, 10, 11, 1, 9, 12, 10);
                configurationFound = TRUE;
            }

            
        }


        ArrayBuild(yellowFaceComparisonArray, 0, 1, 0, 1, 1, 0, 0, 0, 1);
        if (CmpArray(yellowConfigurationArray, yellowFaceComparisonArray))
        { // L form mod venstre op med det modsatte hjørne
            ArrayBuild(lastLayerComparisonArray, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0);
            if (CmpArray(lastLayerConfigurationArray, lastLayerComparisonArray))
            {
                ArrayBuild(yellowFaceMoveset, 2, 12, 9, 1, 10, 12, 3, 9, 3, 10);
                configurationFound = TRUE;
            }

            
        }


        ArrayBuild(yellowFaceComparisonArray, 0, 1, 0, 1, 1, 0, 1, 0, 1);
        if (CmpArray(yellowConfigurationArray, yellowFaceComparisonArray))
        { // Z-form drejet mod venstre med en i modsatte hjørne af det isolerede ikke-gule hjørne
            ArrayBuild(lastLayerComparisonArray, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0);
            if (CmpArray(lastLayerConfigurationArray, lastLayerComparisonArray))
            {
                ArrayBuild(yellowFaceMoveset, 1, 9, 7, 12, 10, 11, 10, 11, 7, 4, 4, 9, 11, 3);
                configurationFound = TRUE;
            }

            
        }


        ArrayBuild(yellowFaceComparisonArray, 0, 1, 0, 1, 1, 0, 0, 0, 0);
        if (CmpArray(yellowConfigurationArray, yellowFaceComparisonArray))
        { // L form mod venstre op
            ArrayBuild(lastLayerComparisonArray, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1);
            if (CmpArray(lastLayerConfigurationArray, lastLayerComparisonArray))
            {
                ArrayBuild(yellowFaceMoveset, 9, 1, 1, 10, 12, 9, 11, 10, 12, 2);
                configurationFound = TRUE;
            }
            
            ArrayBuild(lastLayerComparisonArray, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0);
            if (CmpArray(lastLayerConfigurationArray, lastLayerComparisonArray))
            {
                ArrayBuild(yellowFaceMoveset, 3, 4, 10, 11, 1, 7, 1, 7, 3, 9, 12, 9);
                configurationFound = TRUE;
            }

            
        }



        // SHAPE |_
        ArrayBuild(yellowFaceComparisonArray, 0, 1, 0, 0, 1, 1, 1, 0, 1);
        if (CmpArray(yellowConfigurationArray, yellowFaceComparisonArray))
        { // Omvendt Z form mod højre med en i modsatte hjørne af det isolerede ikke-gule hjørne
            ArrayBuild(lastLayerComparisonArray, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0);
            if (CmpArray(lastLayerConfigurationArray, lastLayerComparisonArray))
            {
                ArrayBuild(yellowFaceMoveset, 2, 9, 7, 11, 9, 12, 9, 11, 7, 1, 1, 10, 12, 2);
                configurationFound = TRUE;
            }

            
        }


        ArrayBuild(yellowFaceComparisonArray, 0, 1, 1, 0, 1, 1, 0, 0, 0);
        if (CmpArray(yellowConfigurationArray, yellowFaceComparisonArray))
        { // Firkant i hjørnet - mod højre op
            ArrayBuild(lastLayerComparisonArray, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0);
            if (CmpArray(lastLayerConfigurationArray, lastLayerComparisonArray))
            {
                ArrayBuild(yellowFaceMoveset, 3, 3, 7, 12, 10, 11, 10, 10);
                configurationFound = TRUE;
            }

            
        }


        ArrayBuild(yellowFaceComparisonArray, 0, 1, 1, 0, 1, 1, 1, 0, 0);
        if (CmpArray(yellowConfigurationArray, yellowFaceComparisonArray))
        { // Firkant i hjørnet med det modsatte hjørne - firkant mod højre op
            ArrayBuild(lastLayerComparisonArray, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0);
            if (CmpArray(lastLayerConfigurationArray, lastLayerComparisonArray))
            {
                ArrayBuild(yellowFaceMoveset, 2, 11, 7, 9, 7, 4, 10, 11, 10, 1, 7, 9);
                configurationFound = TRUE;
            }

            
        }


        ArrayBuild(yellowFaceComparisonArray, 0, 1, 0, 0, 1, 1, 0, 0, 0);
        if (CmpArray(yellowConfigurationArray, yellowFaceComparisonArray))
        { // L form
            ArrayBuild(lastLayerComparisonArray, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0);
            if (CmpArray(lastLayerConfigurationArray, lastLayerComparisonArray))
            {
                ArrayBuild(yellowFaceMoveset, 10, 4, 4, 9, 11, 10, 12, 9, 11, 3);
                configurationFound = TRUE;
            }
            
            ArrayBuild(lastLayerComparisonArray, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1);
            if (CmpArray(lastLayerConfigurationArray, lastLayerComparisonArray))
            {
                ArrayBuild(yellowFaceMoveset, 2, 1, 10, 12, 9, 7, 3, 7, 4, 3, 9, 12);
                configurationFound = TRUE;
            }
            
            ArrayBuild(lastLayerComparisonArray, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0);
            if (CmpArray(lastLayerConfigurationArray, lastLayerComparisonArray))
            {
                ArrayBuild(yellowFaceMoveset, 2, 1, 9, 12, 3, 7, 3, 7, 2, 10, 11, 10);
                configurationFound = TRUE;
            }
        }


        //       _
        // SHAPE  |
        ArrayBuild(yellowFaceComparisonArray, 0, 0, 1, 1, 1, 0, 0, 1, 0);
        if (CmpArray(yellowConfigurationArray, yellowFaceComparisonArray))
        { // L form mod venstre ned med det modsatte hjørne
            ArrayBuild(lastLayerComparisonArray, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1);
            if (CmpArray(lastLayerConfigurationArray, lastLayerComparisonArray))
            {
                ArrayBuild(yellowFaceMoveset, 1, 11, 10, 4, 9, 11, 2, 10, 2, 9);
                configurationFound = TRUE;
            }
        }


        ArrayBuild(yellowFaceComparisonArray, 1, 0, 0, 1, 1, 0, 0, 1, 0);
        if (CmpArray(yellowConfigurationArray, yellowFaceComparisonArray))
        { // Omvendt Z form mod venstre
            ArrayBuild(lastLayerComparisonArray, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0);
            if (CmpArray(lastLayerConfigurationArray, lastLayerComparisonArray))
            {
                ArrayBuild(yellowFaceMoveset, 4, 2, 9, 4, 12, 9, 11, 1, 9);
                configurationFound = TRUE;
            }
        }


        ArrayBuild(yellowFaceComparisonArray, 0, 0, 0, 1, 1, 0, 0, 1, 1);
        if (CmpArray(yellowConfigurationArray, yellowFaceComparisonArray))
        { // Z form mod ned
            ArrayBuild(lastLayerComparisonArray, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0);
            if (CmpArray(lastLayerConfigurationArray, lastLayerComparisonArray))
            {
                ArrayBuild(yellowFaceMoveset, 7, 3, 7, 2, 9, 12, 10, 11, 7, 9, 12, 9);
                configurationFound = TRUE;
            }
        }


        ArrayBuild(yellowFaceComparisonArray, 1, 0, 1, 1, 1, 0, 0, 1, 0);
        if (CmpArray(yellowConfigurationArray, yellowFaceComparisonArray))
        { // Omvendt Z form mod venstre med en i modsatte hjørne af det isolerede ikke-gule hjørne
            ArrayBuild(lastLayerComparisonArray, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1);
            if (CmpArray(lastLayerConfigurationArray, lastLayerComparisonArray))
            {
                ArrayBuild(yellowFaceMoveset, 12, 1, 10, 11, 7, 3, 9, 11, 10, 12, 9, 3, 7);
                configurationFound = TRUE;
            }
        }


        //        _
        // SHAPE |
        ArrayBuild(yellowFaceComparisonArray, 0, 0, 0, 0, 1, 1, 0, 1, 0);
        if (CmpArray(yellowConfigurationArray, yellowFaceComparisonArray))
        { // L form mod højre ned
            ArrayBuild(lastLayerComparisonArray, 0, 0, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1);
            if (CmpArray(lastLayerConfigurationArray, lastLayerComparisonArray))
            {
                ArrayBuild(yellowFaceMoveset, 3, 12, 4, 9, 7, 12, 9, 11, 10, 11, 9, 7, 11, 10, 4);
                configurationFound = TRUE;
            }
        }
 

        ArrayBuild(yellowFaceComparisonArray, 0, 0, 0, 0, 1, 1, 1, 1, 0);
        if (CmpArray(yellowConfigurationArray, yellowFaceComparisonArray))
        { // Omvendt Z form mod ned
            ArrayBuild(lastLayerComparisonArray, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0);
            if (CmpArray(lastLayerConfigurationArray, lastLayerComparisonArray))
            {
                ArrayBuild(yellowFaceMoveset, 7, 2, 7, 3, 10, 11, 9, 11, 7, 10, 11, 11);
                configurationFound = TRUE;
            }
        }


        ArrayBuild(yellowFaceComparisonArray, 1, 0, 1, 0, 1, 1, 0, 1, 0);
        if (CmpArray(yellowConfigurationArray, yellowFaceComparisonArray))
        { // Z form mod højre med en i modsatte hjørne af det isolerede ikke-gule hjørne
            ArrayBuild(lastLayerComparisonArray, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1);
            if (CmpArray(lastLayerConfigurationArray, lastLayerComparisonArray))
            {
                ArrayBuild(yellowFaceMoveset, 1, 7, 11, 10, 4, 9, 2, 9, 7, 11, 9, 3, 10);
                configurationFound = TRUE;
            }
        }
    

        ArrayBuild(yellowFaceComparisonArray, 0, 0, 0, 0, 1, 1, 0, 1, 1);
        if (CmpArray(yellowConfigurationArray, yellowFaceComparisonArray))
        { // Firkant i hjørnet mod højre ned
            ArrayBuild(lastLayerComparisonArray, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1);
            if (CmpArray(lastLayerConfigurationArray, lastLayerComparisonArray))
            {
                ArrayBuild(yellowFaceMoveset, 4, 1, 7, 11, 9, 12, 9, 9);
                configurationFound = TRUE;
            }   
        }



        // C-form
        ArrayBuild(yellowFaceComparisonArray, 1, 1, 0, 0, 1, 0, 1, 1, 0);
        if (CmpArray(yellowConfigurationArray, yellowFaceComparisonArray))
        { // C form mod venstre
            ArrayBuild(lastLayerComparisonArray, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0);
            if (CmpArray(lastLayerConfigurationArray, lastLayerComparisonArray))
            {
                ArrayBuild(yellowFaceMoveset, 1, 11, 9, 4, 10, 11, 2, 2);
                configurationFound = TRUE;
            }
        }


        ArrayBuild(yellowFaceComparisonArray, 0, 0, 0, 1, 1, 1, 1, 0, 1);
        if (CmpArray(yellowConfigurationArray, yellowFaceComparisonArray))
        { // C form mod ned
            ArrayBuild(lastLayerComparisonArray, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0);
            if (CmpArray(lastLayerConfigurationArray, lastLayerComparisonArray))
            {
                ArrayBuild(yellowFaceMoveset, 1, 11, 10, 12, 4, 4, 11, 9, 12);
                configurationFound = TRUE;
            }
        }



        // Lang L-form
        ArrayBuild(yellowFaceComparisonArray, 0, 0, 0, 1, 1, 1, 0, 0, 1);
        if (CmpArray(yellowConfigurationArray, yellowFaceComparisonArray))
        { // Lang L med bunden mod højre
            ArrayBuild(lastLayerComparisonArray, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0);
            if (CmpArray(lastLayerConfigurationArray, lastLayerComparisonArray))
            {
                ArrayBuild(yellowFaceMoveset, 2, 1, 9, 3, 10, 2, 9, 11, 4, 10);
                configurationFound = TRUE;
            }
            
            ArrayBuild(lastLayerComparisonArray, 0, 1, 0, 0, 0, 1, 0, 1, 1, 0, 0, 1);
            if (CmpArray(lastLayerConfigurationArray, lastLayerComparisonArray))
            {
                ArrayBuild(yellowFaceMoveset, 4, 2, 9, 4, 9, 11, 12, 3, 9);
                configurationFound = TRUE;
            }
        }


        ArrayBuild(yellowFaceComparisonArray, 0, 0, 0, 1, 1, 1, 1, 0, 0);
        if (CmpArray(yellowConfigurationArray, yellowFaceComparisonArray))
        { // Lang L med bunden mod venstre
            ArrayBuild(lastLayerComparisonArray, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0);
            if (CmpArray(lastLayerConfigurationArray, lastLayerComparisonArray))
            {
                ArrayBuild(yellowFaceMoveset, 3, 4, 10, 2, 9, 3, 10, 12, 1, 9);
                configurationFound = TRUE;
            }
            
            ArrayBuild(lastLayerComparisonArray, 0, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 0);
            if (CmpArray(lastLayerConfigurationArray, lastLayerComparisonArray))
            {
                ArrayBuild(yellowFaceMoveset, 1, 3, 10, 1, 10, 12, 11, 2, 10);
                configurationFound = TRUE;
            }
        }



        // P-form
        ArrayBuild(yellowFaceComparisonArray, 1, 1, 0, 1, 1, 0, 1, 0, 0);
        if (CmpArray(yellowConfigurationArray, yellowFaceComparisonArray))
        { // P med ryggen mod venstre
            ArrayBuild(lastLayerComparisonArray, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0);
            if (CmpArray(lastLayerConfigurationArray, lastLayerComparisonArray))
            {
                ArrayBuild(yellowFaceMoveset, 9, 9, 1, 10, 12, 4);
                configurationFound = TRUE;
            }
            
            ArrayBuild(lastLayerComparisonArray, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0);
            if (CmpArray(lastLayerConfigurationArray, lastLayerComparisonArray))
            {
                ArrayBuild(yellowFaceMoveset, 3, 11, 4, 10, 4, 9, 11, 1, 10);
                configurationFound = TRUE;
            } 
        }


        ArrayBuild(yellowFaceComparisonArray, 0, 1, 1, 0, 1, 1, 0, 0, 1);
        if (CmpArray(yellowConfigurationArray, yellowFaceComparisonArray))
        { // P med ryggen mod højre
            ArrayBuild(lastLayerComparisonArray, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0);
            if (CmpArray(lastLayerConfigurationArray, lastLayerComparisonArray))
            {
                ArrayBuild(yellowFaceMoveset, 2, 12, 1, 9, 1, 10, 12, 4, 9);
                configurationFound = TRUE;
            }
            
            ArrayBuild(lastLayerComparisonArray, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1);
            if (CmpArray(lastLayerConfigurationArray, lastLayerComparisonArray))
            {
                ArrayBuild(yellowFaceMoveset, 10, 10, 4, 9, 11, 1);
                configurationFound = TRUE;
            }   
        }



        // Liggende T-form
        ArrayBuild(yellowFaceComparisonArray, 0, 0, 1, 1, 1, 1, 0, 0, 1);
        if (CmpArray(yellowConfigurationArray, yellowFaceComparisonArray))
        { // Liggende T-form
            ArrayBuild(lastLayerComparisonArray, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1);
            if (CmpArray(lastLayerConfigurationArray, lastLayerComparisonArray))
            {
                ArrayBuild(yellowFaceMoveset, 9, 1, 1, 10, 12, 2);
                configurationFound = TRUE;
            }
            
            ArrayBuild(lastLayerComparisonArray, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0);
            if (CmpArray(lastLayerConfigurationArray, lastLayerComparisonArray))
            {
                ArrayBuild(yellowFaceMoveset, 1, 11, 10, 12, 10, 1, 9, 12);
                configurationFound = TRUE;
            }
        }



        // W-form
        ArrayBuild(yellowFaceComparisonArray, 0, 0, 1, 0, 1, 1, 1, 1, 0);
        if (CmpArray(yellowConfigurationArray, yellowFaceComparisonArray))
        { // W-form med isoleret ikke-gult hjørne mod højre
            ArrayBuild(lastLayerComparisonArray, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 0);
            if (CmpArray(lastLayerConfigurationArray, lastLayerComparisonArray))
            {
                ArrayBuild(yellowFaceMoveset, 3, 11, 10, 11, 9, 12, 10, 12, 10, 1, 9, 12);
                configurationFound = TRUE;
            }   
        }


        ArrayBuild(yellowFaceComparisonArray, 1, 0, 0, 1, 1, 0, 0, 1, 1);
        if (CmpArray(yellowConfigurationArray, yellowFaceComparisonArray))
        { // W-form med isoleret ikke-gult hjørne mod venstre
            ArrayBuild(lastLayerComparisonArray, 1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0);
            if (CmpArray(lastLayerConfigurationArray, lastLayerComparisonArray))
            {
                ArrayBuild(yellowFaceMoveset, 2, 12, 9, 12, 10, 11, 9, 11, 9, 4, 10, 11);
                configurationFound = TRUE;
            }   
        }



        // Lang og lige Z-form
        ArrayBuild(yellowFaceComparisonArray, 1, 0, 0, 1, 1, 1, 0, 0, 1);
        if (CmpArray(yellowConfigurationArray, yellowFaceComparisonArray))
        { // Omvendt langt Z
            ArrayBuild(lastLayerComparisonArray, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1);
            if (CmpArray(lastLayerConfigurationArray, lastLayerComparisonArray))
            {
                ArrayBuild(yellowFaceMoveset, 2, 1, 9, 3, 10, 12, 2, 9, 1);
                configurationFound = TRUE;
            } 
        }


        ArrayBuild(yellowFaceComparisonArray, 0, 0, 1, 1, 1, 1, 1, 0, 0);
        if (CmpArray(yellowConfigurationArray, yellowFaceComparisonArray))
        { // Langt Z
            ArrayBuild(lastLayerComparisonArray, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0);
            if (CmpArray(lastLayerConfigurationArray, lastLayerComparisonArray))
            {
                ArrayBuild(yellowFaceMoveset, 3, 4, 10, 2, 9, 11, 3, 10, 4);
                configurationFound = TRUE;
            }
        }


        if (configurationFound != TRUE)
        {
        	TurnCubeOperation(); // TURN 90 DEGREES

        	turnsMoveset[numOfTurns] = 13;

        	numOfTurns++;
        }
    }

    if (numOfTurns == 0)
    {
    	ArrayBuild(finalMoveset, yellowFaceMoveset);
    }
    else 
    {
    	ArrayBuild(finalMoveset, turnsMoveset, yellowFaceMoveset);
    }

}


sub YellowFaceSolution(int &finalMoveset[])
{
	FindCorrectMoveset(finalMoveset);

}
