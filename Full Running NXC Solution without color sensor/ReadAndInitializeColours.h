#include "CubeOperations.h"

#define CENTER_SQUARE -155 //Degrees to rotate the motor controlling the sensor
#define RAW_COLOUR_DIFFERENCE 30

void ResetColourSensor()
{
    // Resets the position of the color sensor.
    OnFwd(OUT_A, 30);
    Wait(2000);
    Off(OUT_A);
}

void WaitForButtonPress()
{
    bool isPressed = false;
    while(!isPressed)
    {
        isPressed = ButtonPressed(BTNCENTER , false);
    }
    ClearScreen();
}

void PressButtonToResetCube()
{
    TextOut(0, LCD_LINE1, "Error, during");
    TextOut(0, LCD_LINE2, "colour scan.");
    TextOut(0, LCD_LINE3, "Replace cube");
    TextOut(0, LCD_LINE4, "with white");
    TextOut(0, LCD_LINE5, "centerpiece");
    TextOut(0, LCD_LINE6, "on top.");
    TextOut(0, LCD_LINE8, "Press enter...");

    PlaySound(SOUND_DOWN);
    
    WaitForButtonPress();
}

void ManuallyPlaceCube()
{
    TextOut(0, LCD_LINE1, "Place cube");
    TextOut(0, LCD_LINE2, "correctly.");
    TextOut(0, LCD_LINE5, "Press enter...");

    WaitForButtonPress();
}

void ManuallyPlaceCubeWithWhiteCenterPieceOnTop()
{
    TextOut(0, LCD_LINE1, "Mix the cube,");
    TextOut(0, LCD_LINE2, "and place");
    TextOut(0, LCD_LINE3, "with white");
    TextOut(0, LCD_LINE4, "centerpiece");
    TextOut(0, LCD_LINE5, "on top.");
    TextOut(0, LCD_LINE7, "Press enter...");

    WaitForButtonPress();
}

bool CheckCubeColours(int &amountOfColours [])
{
    for(int i = 0; i < 6; i++)
    {
        if(amountOfColours[i] > 9)
        {
            TextOut(0, LCD_LINE1, "Too many colours");
            TextOut(0, LCD_LINE2, "of one kind.");
            TextOut(0, LCD_LINE5, "Resetting...");
             
            PlaySound(SOUND_DOWN);
            Wait(5000);
             
            ClearScreen();
            return false;
        }
    }

    return true;
}

void ScanSquareOnCube(int degreesToTurnSensor, int &rawData[])
{
    // Places the color sensor, reads the color of a given sub-square, and stores the raw colours in rawData.
    RotateMotorPID(OUT_A, 40, degreesToTurnSensor, 20, 40, 100);
    Wait(100);
    SetSensor(S4, _SENSOR_CFG(SENSOR_TYPE_COLORFULL, SENSOR_MODE_RAW));
    ReadSensorColorRaw(S4, rawData);
}

char FindColourFromRawValues(int degreesToTurnSensor, int &rawColourValues[], int &amountOfColours[])
{
    ClearScreen();

    int rawData[]; // [0] red, [1] green, [2] blue
    ScanSquareOnCube(degreesToTurnSensor, rawData);

    char tempColour;
    
    bool isColourDetected = false;
    int amountOfTriesToDetect = 0;
    
    if(amountOfColours[5] == 0)
    {
        isColourDetected = true;
        tempColour = 'w';
        amountOfColours[5]++;
        TextOut(0, LCD_LINE1, "White");
        NumOut(0, LCD_LINE2, amountOfColours[5]);
    }

    int rawColourDifference = RAW_COLOUR_DIFFERENCE;

    while(!isColourDetected)
    {
        // Red
        if((rawData[0] >= rawColourValues[0] - rawColourDifference && rawData[0] <= rawColourValues[0] + rawColourDifference) &&
           (rawData[1] >= rawColourValues[1] - rawColourDifference && rawData[1] <= rawColourValues[1] + rawColourDifference) &&
           (rawData[2] >= rawColourValues[2] - rawColourDifference && rawData[2] <= rawColourValues[2] + rawColourDifference) &&
            rawData[1] < rawColourValues[7] - (rawColourValues[7] - rawColourValues[1]) / 2 + amountOfTriesToDetect)
        {
            isColourDetected = true;
            tempColour = 'r';
            amountOfColours[0]++;
            TextOut(0, LCD_LINE1, "Red");
            NumOut(0, LCD_LINE2, amountOfColours[0]);
        }
        // Blue
        else if ((rawData[0] >= rawColourValues[3] - rawColourDifference && rawData[0] <= rawColourValues[3] + rawColourDifference) &&
                 (rawData[1] >= rawColourValues[4] - rawColourDifference && rawData[1] <= rawColourValues[4] + rawColourDifference) &&
                 (rawData[2] >= rawColourValues[5] - rawColourDifference && rawData[2] <= rawColourValues[5] + rawColourDifference))
        {
            isColourDetected = true;
            tempColour = 'b';
            amountOfColours[1]++;
            TextOut(0, LCD_LINE1, "Blue");
            NumOut(0, LCD_LINE2, amountOfColours[1]);
        }
        // Orange
        else if ((rawData[0] >= rawColourValues[6] - rawColourDifference && rawData[0] <= rawColourValues[6] + rawColourDifference) &&
                 (rawData[1] >= rawColourValues[7] - rawColourDifference && rawData[1] <= rawColourValues[7] + rawColourDifference) &&
                 (rawData[2] >= rawColourValues[8] - rawColourDifference && rawData[2] <= rawColourValues[8] + rawColourDifference) &&
                  rawData[1] > rawColourValues[7] - (rawColourValues[7] - rawColourValues[1]) / 2 - amountOfTriesToDetect)
        {
            isColourDetected = true;
            tempColour = 'o';
            amountOfColours[2]++;
            TextOut(0, LCD_LINE1, "Orange");
            NumOut(0, LCD_LINE2, amountOfColours[2]);
        }
        // Green
        else if ((rawData[0] >= rawColourValues[9] - rawColourDifference && rawData[0] <= rawColourValues[9] + rawColourDifference) &&
                 (rawData[1] >= rawColourValues[10] - rawColourDifference && rawData[1] <= rawColourValues[10] + rawColourDifference) &&
                 (rawData[2] >= rawColourValues[11] - rawColourDifference && rawData[2] <= rawColourValues[11] + rawColourDifference))
        {
            isColourDetected = true;
            tempColour = 'g';
            amountOfColours[3]++;
            TextOut(0, LCD_LINE1, "Green");
            NumOut(0, LCD_LINE2, amountOfColours[3]);
        }
        // Yellow
        else if ((rawData[0] >= rawColourValues[12] - rawColourDifference * 2 && rawData[0] <= rawColourValues[12] + rawColourDifference * 2) &&
                 (rawData[1] >= rawColourValues[13] - rawColourDifference * 2 && rawData[1] <= rawColourValues[13] + rawColourDifference * 2) &&
                 (rawData[2] >= rawColourValues[14] - rawColourDifference * 2 && rawData[2] <= rawColourValues[14] + rawColourDifference * 2) )
        {
            isColourDetected = true;
            tempColour = 'y';
            amountOfColours[4]++;
            TextOut(0, LCD_LINE1, "Yellow");
            NumOut(0, LCD_LINE2, amountOfColours[4]);
        }
        // White
        else if ((rawData[0] >= rawColourValues[15] - rawColourDifference && rawData[0] <= rawColourValues[15] + rawColourDifference) &&
                 (rawData[1] >= rawColourValues[16] - rawColourDifference && rawData[1] <= rawColourValues[16] + rawColourDifference) &&
                 (rawData[2] >= rawColourValues[17] - rawColourDifference && rawData[2] <= rawColourValues[17] + rawColourDifference) )
        {
            isColourDetected = true;
            tempColour = 'w';
            amountOfColours[5]++;
            TextOut(0, LCD_LINE1, "White");
            NumOut(0, LCD_LINE2, amountOfColours[5]);
        }
        else if(amountOfTriesToDetect < 10)
        {
			
            amountOfTriesToDetect++;
            TextOut(0, LCD_LINE1, "Scanning again");
            NumOut(0, LCD_LINE2, amountOfTriesToDetect);
            
            ScanSquareOnCube(0, rawData);
            
            rawColourDifference = rawColourDifference + 10;

            ClearScreen();
			
        }
        else
        {
			
            isColourDetected = true;
            tempColour = 'w';
            amountOfColours[5]++;
            TextOut(0, LCD_LINE1, "White");
            NumOut(0, LCD_LINE2, amountOfColours[5]);

            TextOut(0, LCD_LINE4, "Couldn't read");
            TextOut(0, LCD_LINE5, "colour.");
            TextOut(0, LCD_LINE6, "Set to white");
            TextOut(0, LCD_LINE7, "as default.");

            PlaySound(SOUND_CLICK);
            Wait(5000);
            ClearScreen();
        }
    }

    return tempColour;
}

void ColourReadFace(int face, int &rawColourValues[], int &amountOfColours[], int &counter)
{
    // 1 - first square to be scanned, the fifth element on the given face in the array
    myCube[face][4] = FindColourFromRawValues(-150, rawColourValues, amountOfColours);
    Wait(500);

    // 2
    myCube[face][7] = FindColourFromRawValues(55, rawColourValues, amountOfColours);
    Wait(500);

    // 3
    TurnCube(-37);
    myCube[face][6] = FindColourFromRawValues(13, rawColourValues, amountOfColours);
    Wait(500);

    //4
    TurnCube(-34);
    myCube[face][3] = FindColourFromRawValues(-10, rawColourValues, amountOfColours);
    Wait(500);

    //5
    TurnCube(-46);
    myCube[face][0] = FindColourFromRawValues(5, rawColourValues, amountOfColours);
    Wait(500);

    //6
    TurnCube(-39);
    myCube[face][1] = FindColourFromRawValues(-17, rawColourValues, amountOfColours);
    Wait(500);

    //7
    TurnCube(-62);
    myCube[face][2] = FindColourFromRawValues(9, rawColourValues, amountOfColours);
    Wait(500);

    //8
    TurnCube(-49);
    myCube[face][5] = FindColourFromRawValues(-14, rawColourValues, amountOfColours);
    Wait(500);

    //9
    TurnCube(-48);
    myCube[face][8] = FindColourFromRawValues(17, rawColourValues, amountOfColours);
    Wait(500);

    if(counter % 2 == 0)
    {
        TurnCube(-45); // to reach exactly one 360 degrees rotation
    }
    else
    {
        TurnCube(-43); // to reach exactly one 360 degrees rotation
    }
    
    counter++;
}

void MapRawColourValues(int &rawColourValues[], int &tmpRawColour[], int &numberOfSidesScanned)
{
    rawColourValues[numberOfSidesScanned] = tmpRawColour[0];
    rawColourValues[numberOfSidesScanned + 1] = tmpRawColour[1];
    rawColourValues[numberOfSidesScanned + 2] = tmpRawColour[2];
    
    numberOfSidesScanned = numberOfSidesScanned + 3; // Incrementet by 3 each time, as each colour has three raw values in the rawColourValues array
}

int MapFace(int placement)
{
    // Returns the face in the representation that corresponds to the current face in the sequence of reading the colours.
    // 0 Top; 1 Right; 2 Front; 3 Back; 4 Left; 5 Buttom;
    int tmpPlacement = 0;
    switch(placement)
    {
        case 0:
            tmpPlacement = 0;
            break;
        case 1:
            tmpPlacement = 2;
            break;
        case 2:
            tmpPlacement = 5;
            break;
        case 3:
            tmpPlacement = 3;
            break;
        case 4:
            tmpPlacement = 4;
            break;
        case 5:
            tmpPlacement = 1;
            break;
        default:
            break;
    }

    return tmpPlacement;
}

bool ReadLeftThenRight(int &rawColourValues[], int &amountOfColours[], int &counter)
{
    // Left face
    ResetColourSensor();

    TurnCube(-90);
    FlipCube(1);
    UnlockCube();
    
    ManuallyPlaceCube();
    
    ColourReadFace(MapFace(4), rawColourValues, amountOfColours, counter);

    if(!CheckCubeColours(amountOfColours))
    {
        return false;
    }

    //Right face
    ResetColourSensor();

    FlipCube(2);
    UnlockCube();
    
    ManuallyPlaceCube();
    
    ColourReadFace(MapFace(5), rawColourValues, amountOfColours, counter);

    if(!CheckCubeColours(amountOfColours))
    {
        return false;
    }

    //Place cube in the right position, so it matches myCube
    ResetColourSensor();
    FlipCube(1);
    UnlockCube();
    TurnCube(-270);
    UnlockCube();

    return true;
}

bool ReadAndCheckCubeColours(int &rawColourValues[])
{
    int amountOfColours[6]; //To register the scanned colours, and check if there is 9 of each colour
    int counter = 0;
    
    ResetColourSensor();

    ManuallyPlaceCubeWithWhiteCenterPieceOnTop();

    //Read colours of all squares on 3 sides of the cube
    for (int i = 0; i < 4; i++)
    {
        ManuallyPlaceCube();
        
        ColourReadFace(MapFace(i), rawColourValues, amountOfColours, counter);

        ResetColourSensor();
        
        if(!CheckCubeColours(amountOfColours))
        {
            return false;
        }
        
        FlipCube(1);
        UnlockCube();
    }

    if(!CheckCubeColours(amountOfColours))
    {
        return false;
    }

    //Read colours of all squares on the 2 remaining sides of the cube
    if(!ReadLeftThenRight(rawColourValues, amountOfColours, counter))
    {
        return false;
    }
    
    return true;
}

bool IsTheseRawColoursDecideable(int higestRaw, int lowestRaw)
{
    if(higestRaw - lowestRaw < RAW_COLOUR_DIFFERENCE)
    {
        return false;
    }

    return true;
}

void FindHighestAndLowestValue(int rawColourValues[], int counter1, int counter2, int &highestValue, int &lowestValue)
{
    if(rawColourValues[counter1] >= rawColourValues[counter2])
    {
        highestValue = rawColourValues[counter1];
        lowestValue = rawColourValues[counter2];
    }
    else
    {
        highestValue = rawColourValues[counter2];
        lowestValue = rawColourValues[counter1];
    }
}

bool IsRawColoursDecideable(int rawColourValues[])
{
    int highestRaw, lowestRaw;

    for(int counter = 0; counter < 18;)
    {
        int nextColourIndexToCompare = counter;

        for(int j = 0; j < 5; j++)
        {
            if(nextColourIndexToCompare + 3 < 18)
            {
                nextColourIndexToCompare = nextColourIndexToCompare + 3;
            }
            else
            {
                nextColourIndexToCompare = 0;
            }

            bool decideable = false;
            int k = 0;

            do
            {
                FindHighestAndLowestValue(rawColourValues, counter + k, nextColourIndexToCompare + k, highestRaw, lowestRaw);
                decideable = IsTheseRawColoursDecideable(highestRaw, lowestRaw);

                if(decideable)
                {
                    k = 3;
                }
                else if(!decideable && k >= 2)
                {
                    PressButtonToResetCube();
                    return false;
                }
                else
                {
                    k = k + 1;
                }
            } while(!decideable && k < 3)
        }

        counter = counter + 3;
    }

    return true;
}

void ConfigureRawColours(int &rawColourValues[])
{
    int tmpRawColour[5];
    int numberOfSidesScanned = 0;

    ResetColourSensor();
    UnlockCube();

    ManuallyPlaceCube();

    //Colours red, blue and orange
    for (int i = 0; i < 3; i++)
    {
        ScanSquareOnCube(CENTER_SQUARE, tmpRawColour);
        MapRawColourValues(rawColourValues, tmpRawColour, numberOfSidesScanned);
        ResetColourSensor();

        FlipCube(1);
        UnlockCube();

        ManuallyPlaceCube();
    }

    //Colour green
    ScanSquareOnCube(CENTER_SQUARE, tmpRawColour);
    MapRawColourValues(rawColourValues, tmpRawColour, numberOfSidesScanned);
    ResetColourSensor();

    //Colour yellow
    TurnCube(-90);
    FlipCube(1);
    UnlockCube();

    ManuallyPlaceCube();

    ScanSquareOnCube(CENTER_SQUARE, tmpRawColour);
    MapRawColourValues(rawColourValues, tmpRawColour, numberOfSidesScanned);
    ResetColourSensor();

    //Colour white
    FlipCube(2);
    UnlockCube();

    ManuallyPlaceCube();

    ScanSquareOnCube(CENTER_SQUARE + 60, tmpRawColour); // CENTER_SQUARE + 'somehting', as the white center square isn't all white
    MapRawColourValues(rawColourValues, tmpRawColour, numberOfSidesScanned);
    ResetColourSensor();
}

bool FindSixRawValues(int &rawColourValues[])
{
    do
    {
        ConfigureRawColours(rawColourValues);
    } while(!IsRawColoursDecideable(rawColourValues));
}

void ReadCubeColours()
{
    int rawColourValues[18];
    
    FindSixRawValues(rawColourValues);
    
    bool isScannedCorrectly = false;
    do
    {
        isScannedCorrectly = ReadAndCheckCubeColours(rawColourValues);
    } while (!isScannedCorrectly);
    
    TextOut(0, LCD_LINE1, "Succesful");
    TextOut(0, LCD_LINE2, "scanning.");
    PlaySound(SOUND_FAST_UP);
    Wait(4000);
    ClearScreen();
}