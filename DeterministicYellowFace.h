#include "CubeOperations.h"

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
    // The array is then as follows: {F0, F1, F2, R8, R7, R6, B8, B7, B6, L0, L1, L2] taking the representation into account.
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


sub FindCorrectMoveset(int finalMoveset[])
{
    // Switches on the configuration of the yellow face. Thereafter, if necessary, switch on the cases for the same yellow-face configuration.
    int numOfTurns = 0;
    bool configurationFound = FALSE;
    int yellowConfigurationArray[20], lastLayerConfigurationArray[20];
    int yellowFaceMoveset[], turnsMoveset[20];
	int a[20] = {0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1};


    while(!configurationFound)
    {
        EvaluateYellowFaceConfiguration(yellowConfigurationArray);
        EvaluateLastLayerConfiguration(lastLayerConfigurationArray);
		
        switch(yellowConfigurationArray)
        {
            // Dot
            case {0, 0, 0, 0, 1, 0, 0, 0, 0}: // Centrum
				if (com(lastLayerConfigurationArray, a))
                {
                    ArrayBuild(yellowFaceMoveset, 1, 11, 4, 3, 9, 12, 8, 4, 10, 1, 9, 12);
                    configurationFound = TRUE;
                }
                else if (lastLayerConfigurationArray == {1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0})
                {
                    yellowFaceMoveset = {2, 1, 9, 12, 3, 7, 4, 3, 9, 11, 7, 3, 7, 9};
                    configurationFound = TRUE;
                }

                break;


            case {0, 0, 0, 0, 1, 0, 0, 0, 1}: // Centrum og et hjørne - hjørne mod højre ned
                if (lastLayerConfigurationArray == {0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1})
                {
                    yellowFaceMoveset = {10, 7, 3, 10, 11, 11, 1, 7, 10, 1, 12};
                    configurationFound = TRUE;
                }

                break;


            case {0, 0, 1, 0, 1, 0, 0, 0, 0}: // Centrum og et hjørne - hjørne mod højre op
                if (lastLayerConfigurationArray == {1, 1, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0})
                {
                    yellowFaceMoveset = {2, 11, 7, 10, 1, 9, 12, 4, 10, 12, 9, 12, 3};
                    configurationFound = TRUE;
                }

                break;


            case {1, 0, 0, 0, 1, 0, 0, 0, 1}: // Skrå linje
                if (lastLayerConfigurationArray == {0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1})
                {
                    yellowFaceMoveset = {1, 11, 10, 11, 10, 1, 9, 12, 3, 7, 4, 3, 9, 12};
                    configurationFound = TRUE;
                }

                break;


            case {1, 0, 1, 0, 1, 0, 1, 0, 1}: // Skrå kryds
                if (lastLayerConfigurationArray == {0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0})
                {
                    yellowFaceMoveset = {2, 1, 7, 11, 1, 7, 12, 3, 11, 1, 7, 12, 3, 7, 11};
                    configurationFound = TRUE;
                }

                break;


            case {1, 0, 1, 0, 1, 0, 0, 0, 0}: // Centrum og to hjørner ved siden af hinanden - Vender opad
                if (lastLayerConfigurationArray == {0, 1, 0, 1, 1, 0, 0, 1, 0, 0, 1, 1})
                {
                    yellowFaceMoveset = {2, 11, 7, 1, 1, 1, 10, 12, 1, 7, 9, 7, 11, 1};
                    configurationFound = TRUE;
                }

                break;


            case {0, 0, 0, 0, 1, 0, 1, 0, 1}: // Centrum og to hjørner ved siden af hinanden - Vender nedad
                if (lastLayerConfigurationArray == {0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0})
                {
                    yellowFaceMoveset = {9, 1, 1, 10, 11, 2, 9, 7, 12, 3, 9, 12};
                    configurationFound = TRUE;
                }

                break;



            // Line
            case {0, 1, 0, 0, 1, 0, 0, 1, 0}: // Lige linje - lodret
                if (lastLayerConfigurationArray == {1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0})
                {
                    yellowFaceMoveset = {2, 12, 2, 9, 12, 3, 9, 12, 9, 9};
                    configurationFound = TRUE;
                }
                else if (lastLayerConfigurationArray == {0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1})
                {
                	yellowFaceMoveset = {1, 12, 3, 7, 11, 10, 9, 7, 11, 12, 9, 7, 9, 4};
                    configurationFound = TRUE;
                }

                break;


            case {0, 0, 0, 1, 1, 1, 0, 0, 0}: // Lige linje - vandret
                if (lastLayerConfigurationArray == {1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0})
                {
                    yellowFaceMoveset = {9, 9, 1, 10, 12, 9, 11, 10, 12, 4};
                    configurationFound = TRUE;
                }
                else if (lastLayerConfigurationArray == {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1})
                {
                    yellowFaceMoveset = {4, 2, 9, 4, 12, 9, 11, 10, 12, 9, 11, 1, 9};
                    configurationFound = TRUE;
                }

                break;
            


            // Cross
            case {0, 1, 0, 1, 1, 1, 0, 1, 0}: // Lige kryds
                if (lastLayerConfigurationArray == {1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0})
                {
                    yellowFaceMoveset = {3, 12, 12, 9, 10, 11, 11, 9, 12, 9, 11};
                    configurationFound = TRUE;
                }
                else if (lastLayerConfigurationArray == {0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1})
                {
                    yellowFaceMoveset = {1, 11, 10, 11, 9, 12, 10, 11, 9, 11, 7, 10};
                    configurationFound = TRUE;
                }

                break;


            case {0, 1, 0, 1, 1, 1, 0, 1, 1}: // Lige kryds med et hjørne (FISKEN)
                if (lastLayerConfigurationArray == {1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0})
                {
                    yellowFaceMoveset = {4, 11, 11, 10, 9, 11, 12};
                    configurationFound = TRUE;
                }
                else if (lastLayerConfigurationArray == {0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1})
                {
                    yellowFaceMoveset = {2, 11, 7, 9, 11, 10, 11, 9};
                    configurationFound = TRUE;
                }

                break;


            case {1, 1, 0, 1, 1, 1, 1, 1, 0}: // Lige kryds med to hjørner ved siden af hinanden - 2 ikke-gule mod højre
                if (lastLayerConfigurationArray == {0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0})
                {
                    yellowFaceMoveset = {2, 2, 11, 9, 9, 12, 12, 9};
                    configurationFound = TRUE;
                }

                break;


            case {1, 1, 1, 1, 1, 1, 0, 1, 0}: // Lige kryds med to hjørner ved siden af hinanden - 2 ikke-gule mod ned
                if (lastLayerConfigurationArray == {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0})
                {
                    yellowFaceMoveset = {1, 7, 9, 12, 11, 7, 9, 10, 12, 11, 7, 10};
                    configurationFound = TRUE;
                }

                break;


            case {1, 1, 0, 1, 1, 1, 0, 1, 1}: // Lige kryds med modsatte hjørner
                if (lastLayerConfigurationArray == {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1})
                {
                    yellowFaceMoveset = {2, 2, 12, 9, 9, 12, 11, 9};
                    configurationFound = TRUE;
                }

                break;



            // 4 CORNERS
            case {1, 0, 1, 1, 1, 0, 1, 1, 1}: // Skrå kryds med to kanter ved siden af hinanden
                if (lastLayerConfigurationArray == {0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0})
                {
                    yellowFaceMoveset = {2, 2, 11, 1, 7, 12, 4, 11};
                    configurationFound = TRUE;
                }

                break;


            case {1, 0, 1, 1, 1, 1, 1, 0, 1}: // Skrå kryds med modsatte kanter
                if (lastLayerConfigurationArray == {0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0})
                {
                    yellowFaceMoveset = {4, 9, 12, 10, 9, 3, 9, 12};
                    configurationFound = TRUE;
                }

                break;



            // SHAPE _|
            case {0, 1, 0, 1, 1, 0, 1, 0, 0}: // Z-form drejet mod venstre
                if (lastLayerConfigurationArray == {0, 1, 1, 0, 1, 1, 0, 0, 1, 0, 0, 0})
                {
                    yellowFaceMoveset = {3, 3, 12, 9, 11, 9, 7, 10};
                    configurationFound = TRUE;
                }

                break;


            case {1, 1, 0, 1, 1, 0, 0, 0, 1}: // Firkant i hjørnet med det modsatte hjørne - Firkant mod venstre op
                if (lastLayerConfigurationArray == {1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0})
                {
                    yellowFaceMoveset = {9, 2, 10, 11, 1, 9, 12, 10};
                    configurationFound = TRUE;
                }

                break;


            case {0, 1, 0, 1, 1, 0, 0, 0, 1}: // L form mod venstre op med det modsatte hjørne
                if (lastLayerConfigurationArray == {1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0})
                {
                    yellowFaceMoveset = {2, 12, 9, 1, 10, 12, 3, 9, 3, 10};
                    configurationFound = TRUE;
                }

                break;


            case {0, 1, 0, 1, 1, 0, 1, 0, 1}: // Z-form drejet mod venstre med en i modsatte hjørne af det isolerede ikke-gule hjørne
                if (lastLayerConfigurationArray == {0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0})
                {
                    yellowFaceMoveset = {1, 9, 7, 12, 10, 11, 10, 11, 7, 4, 4, 9, 11, 3};
                    configurationFound = TRUE;
                }

                break;


            case {0, 1, 0, 1, 1, 0, 0, 0, 0}: // L form mod venstre op
                if (lastLayerConfigurationArray == {0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1})
                {
                    yellowFaceMoveset = {9, 1, 1, 10, 12, 9, 11, 10, 12, 2};
                    configurationFound = TRUE;
                }
                else if (lastLayerConfigurationArray == {1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0})
                {
                    yellowFaceMoveset = {3, 4, 10, 11, 1, 7, 1, 7, 3, 9, 12, 9};
                    configurationFound = TRUE;
                }

                break;



            // SHAPE |_
            case {0, 1, 0, 0, 1, 1, 1, 0, 1}: // Omvendt Z form mod højre med en i modsatte hjørne af det isolerede ikke-gule hjørne
                if (lastLayerConfigurationArray == {0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0})
                {
                    yellowFaceMoveset = {2, 9, 7, 11, 9, 12, 9, 11, 7, 1, 1, 10, 12, 2};
                    configurationFound = TRUE;
                }

                break;


            case {0, 1, 1, 0, 1, 1, 0, 0, 0}: // Firkant i hjørnet - mod højre op
                if (lastLayerConfigurationArray == {1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0})
                {
                    yellowFaceMoveset = {3, 3, 7, 12, 10, 11, 10, 10};
                    configurationFound = TRUE;
                }

                break;


            case {0, 1, 1, 0, 1, 1, 1, 0, 0}: // Firkant i hjørnet med det modsatte hjørne - firkant mod højre op
                if (lastLayerConfigurationArray == {0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0})
                {
                    yellowFaceMoveset = {2, 11, 7, 9, 7, 4, 10, 11, 10, 1, 7, 9};
                    configurationFound = TRUE;
                }

                break;


            case {0, 1, 0, 0, 1, 1, 0, 0, 0}: // L form
                if (lastLayerConfigurationArray == {1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0})
                {
                    yellowFaceMoveset = {10, 4, 4, 9, 11, 10, 12, 9, 11, 3};
                    configurationFound = TRUE;
                }
                else if (lastLayerConfigurationArray == {0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1})
                {
                    yellowFaceMoveset = {2, 1, 10, 12, 9, 7, 3, 7, 4, 3, 9, 12};
                    configurationFound = TRUE;
                }
                else if (lastLayerConfigurationArray == {1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0})
                {
                    yellowFaceMoveset = {2, 1, 9, 12, 3, 7, 3, 7, 2, 10, 11, 10};
                    configurationFound = TRUE;
                }

                break;


            //       _
            // SHAPE  |
            case {0, 0, 1, 1, 1, 0, 0, 1, 0}: // L form mod venstre ned med det modsatte hjørne
                if (lastLayerConfigurationArray == {0, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1})
                {
                    yellowFaceMoveset = {1, 11, 10, 4, 9, 11, 2, 10, 2, 9};
                    configurationFound = TRUE;
                }

                break;


            case {1, 0, 0, 1, 1, 0, 0, 1, 0}: // Omvendt Z form mod venstre
                if (lastLayerConfigurationArray == {1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0})
                {
                    yellowFaceMoveset = {4, 2, 9, 4, 12, 9, 11, 1, 9};
                    configurationFound = TRUE;
                }

                break;
 

            case {0, 0, 0, 1, 1, 0, 0, 1, 1}: // Z form mod ned
                if (lastLayerConfigurationArray == {1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0})
                {
                    yellowFaceMoveset = {7, 3, 7, 2, 9, 12, 10, 11, 7, 9, 12, 9};
                    configurationFound = TRUE;
                }

                break;


            case {1, 0, 1, 1, 1, 0, 0, 1, 0}: // Omvendt Z form mod venstre med en i modsatte hjørne af det isolerede ikke-gule hjørne
                if (lastLayerConfigurationArray == {0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1})
                {
                    yellowFaceMoveset = {12, 1, 10, 11, 7, 3, 9, 11, 10, 12, 9, 3, 7};
                    configurationFound = TRUE;
                }

                break;


            //        _
            // SHAPE |
            case {0, 0, 0, 0, 1, 1, 0, 1, 0}: // L form mod højre ned
                if (lastLayerConfigurationArray == {0, 0, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1})
                {
                    yellowFaceMoveset = {3, 12, 4, 9, 7, 12, 9, 11, 10, 11, 9, 7, 11, 10, 4};
                    configurationFound = TRUE;
                }

                break;

     
            case {0, 0, 0, 0, 1, 1, 1, 1, 0}: // Omvendt Z form mod ned
                if (lastLayerConfigurationArray == {0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0})
                {
                    yellowFaceMoveset = {7, 2, 7, 3, 10, 11, 9, 11, 7, 10, 11, 11};
                    configurationFound = TRUE;
                }

                break;


            case {1, 0, 1, 0, 1, 1, 0, 1, 0}: // Z form mod højre med en i modsatte hjørne af det isolerede ikke-gule hjørne
                if (lastLayerConfigurationArray == {0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1})
                {
                    yellowFaceMoveset = {1, 7, 11, 10, 4, 9, 2, 9, 7, 11, 9, 3, 10};
                    configurationFound = TRUE;
                }

                break;

        
            case {0, 0, 0, 0, 1, 1, 0, 1, 1}: // Firkant i hjørnet mod højre ned
                if (lastLayerConfigurationArray == {0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1})
                {
                    yellowFaceMoveset = {4, 1, 7, 11, 9, 12, 9, 9};
                    configurationFound = TRUE;
                }

                break;



            // C-form
            case {1, 1, 0, 0, 1, 0, 1, 1, 0}: // C form mod venstre
                if (lastLayerConfigurationArray == {0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0})
                {
                    yellowFaceMoveset = {1, 11, 9, 4, 10, 11, 2, 2};
                    configurationFound = TRUE;
                }

                break;


            case {0, 0, 0, 1, 1, 1, 1, 0, 1}: // C form mod ned
                if (lastLayerConfigurationArray == {0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0})
                {
                    yellowFaceMoveset = {1, 11, 10, 12, 4, 4, 11, 9, 12};
                    configurationFound = TRUE;
                }

                break;



            // Lang L-form
            case {0, 0, 0, 1, 1, 1, 0, 0, 1}: // Lang L med bunden mod højre
                if (lastLayerConfigurationArray == {1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0})
                {
                    yellowFaceMoveset = {2, 1, 9, 3, 10, 2, 9, 11, 4, 10};
                    configurationFound = TRUE;
                }
                else if (lastLayerConfigurationArray == {0, 1, 0, 0, 0, 1, 0, 1, 1, 0, 0, 1})
                {
                    yellowFaceMoveset = {4, 2, 9, 4, 9, 11, 12, 3, 9};
                    configurationFound = TRUE;
                }

                break;


            case {0, 0, 0, 1, 1, 1, 1, 0, 0}: // Lang L med bunden mod venstre
                if (lastLayerConfigurationArray == {0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0})
                {
                    yellowFaceMoveset = {3, 4, 10, 2, 9, 3, 10, 12, 1, 9};
                    configurationFound = TRUE;
                }
                else if (lastLayerConfigurationArray == {0, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 0})
                {
                    yellowFaceMoveset = {1, 3, 10, 1, 10, 12, 11, 2, 10};
                    configurationFound = TRUE;
                }

                break;



            // P-form
            case {1, 1, 0, 1, 1, 0, 1, 0, 0}: // P med ryggen mod venstre
                if (lastLayerConfigurationArray == {0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0})
                {
                    yellowFaceMoveset = {9, 9, 1, 10, 12, 4};
                    configurationFound = TRUE;
                }
                else if (lastLayerConfigurationArray == {0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0})
                {
                    yellowFaceMoveset = {3, 11, 4, 10, 4, 9, 11, 1, 10};
                    configurationFound = TRUE;
                }

                break;


            case {0, 1, 1, 0, 1, 1, 0, 0, 1}: // P med ryggen mod højre
                if (lastLayerConfigurationArray == {1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0})
                {
                    yellowFaceMoveset = {2, 12, 1, 9, 1, 10, 12, 4, 9};
                    configurationFound = TRUE;
                }
                else if (lastLayerConfigurationArray == {0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1})
                {
                    yellowFaceMoveset = {10, 10, 4, 9, 11, 1};
                    configurationFound = TRUE;
                }

                break;



            // Liggende T-form
            case {0, 0, 1, 1, 1, 1, 0, 0, 1}: // Liggende T-form
                if (lastLayerConfigurationArray == {0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1})
                {
                    yellowFaceMoveset = {9, 1, 1, 10, 12, 2};
                    configurationFound = TRUE;
                }
                else if (lastLayerConfigurationArray == {1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0})
                {
                    yellowFaceMoveset = {1, 11, 10, 12, 10, 1, 9, 12};
                    configurationFound = TRUE;
                }

                break;



            // W-form
            case {0, 0, 1, 0, 1, 1, 1, 1, 0}: // W-form med isoleret ikke-gult hjørne mod højre
                if (lastLayerConfigurationArray == {0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 0})
                {
                    yellowFaceMoveset = {3, 11, 10, 11, 9, 12, 10, 12, 10, 1, 9, 12};
                    configurationFound = TRUE;
                }

                break;


            case {1, 0, 0, 1, 1, 0, 0, 1, 1}: // W-form med isoleret ikke-gult hjørne mod venstre
                if (lastLayerConfigurationArray == {1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0})
                {
                    yellowFaceMoveset = {2, 12, 9, 12, 10, 11, 9, 11, 9, 4, 10, 11};
                    configurationFound = TRUE;
                }

                break;



            // Lang og lige Z-form
            case {1, 0, 0, 1, 1, 1, 0, 0, 1}: // Omvendt langt Z
                if (lastLayerConfigurationArray == {0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1})
                {
                    yellowFaceMoveset = {2, 1, 9, 3, 10, 12, 2, 9, 1};
                    configurationFound = TRUE;
                }

                break;


            case {0, 0, 1, 1, 1, 1, 1, 0, 0}: // Langt Z
                if (lastLayerConfigurationArray == {0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0})
                {
                    yellowFaceMoveset = {3, 4, 10, 2, 9, 11, 3, 10, 4};
                    configurationFound = TRUE;
                }

                break;
        }

        if (configurationFound != TRUE)
        {
        	TurnCubeOperation(); // TURN 90 DEGREES

        	turnsMoveset[numOfTurns] == 13;

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


sub YellowFaceSolution(int finalMoveset[])
{
	FindCorrectMoveset(finalMoveset);

}