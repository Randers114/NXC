#include "CubeOperations.h"

#define CENTERPIECE 4


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


SØRG FOR AT GUL ER TOP FACE

*/

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

int FindFaceFromColor(char color)
{
	int colorFace;
	
	for(int face = 0; face < 6; face++)
	{
		if(myCube[face][CENTER_PIECE] == color)
		{
			colorFace = face;
		}
	}
	
	return colorFace;
}

sub CheckEdgeCorrectness(int &incorrectEdges[])
{
	int complementingPiece = 0, complementingFace = 0, edgeNumber = 0;
	
	for(int piece = 1; piece < 8; piece = piece + 2)
	{
		FindComplementingEdge(TOP_FACE, piece, complementingFace, complementingPiece);
		
		if(myCube[complementingFace][CENTER_PIECE] == myCube[complementingFace][complementingPiece])
		{
			incorrectEdges[edgeNumber] = 0;
		}
		else
		{
			incorrectEdges[edgeNumber] = piece;
		}

		edgeNumber++;
	}
}

sub CheckCornerCorrectness(int &incorrectCorners[])
{
	int complementingPiece = 0, complementingFace = 0, complementingPiece2 = 0, complementingFace2 = 0, cornerNumber = 0;
	
	for(int piece = 0; piece < 9; piece = piece + 2)
	{
		FindComplementingCorners(TOP_FACE, piece, complementingFace, complementingPiece, complementingFace2, complementingPiece2);
		
		if(!(myCube[complementingFace][CENTER_PIECE] == myCube[complementingFace][complementingPiece]))
		{
			incorrectCorners[cornerNumber] = piece;
		} 
		else if(!(myCube[complementingFace2][CENTER_PIECE] == myCube[complementingFace2][complementingPiece2]))
		{
			incorrectCorners[cornerNumber] = piece;
		}
		else
		{
			incorrectCorners[cornerNumber] = 0;
		}
		
		cornerNumber++;	

		if(piece == 2)
		{
			piece += 2;
		}
	}
}



int EvaluateLastLayer(int &solutionArray[])
{
	int incorrectEdges[4], incorrectCorners[4], solvedArray[4] = {0, 0, 0, 0};
	int complementingEdgeFace = 0, complementingEdgePiece = 0;
	int complementingCornerFace = 0, complementingCornerPiece = 0, complementingCornerFace2 = 0, complementingCornerPiece2 = 0;
	int solutionArrayIndex = 0, correctEdgeFace, correctCornerFace1, correctCornerFace2;

	for (int edge = 0; edge < 4; edge++)
	{
		if (incorrectEdges[edge] != 0)
		{
			solutionArray[solutionArrayIndex] = incorrectEdges[edge];

			FindComplementingEdge(TOP_FACE, incorrectEdges[edge], complementingEdgeFace, complementingEdgePiece);
			correctEdgeFace = FindFaceFromColor(myCube[complementingEdgeFace][complementingEdgePiece]);
			
			solutionArrayIndex++;

			switch (correctEdgeFace)
			{
				case FRONT_FACE:
					solutionArray[solutionArrayIndex] = 7;
					break;

				case RIGHT_FACE:
					solutionArray[solutionArrayIndex] = 5;
					break;

				case BACK_FACE:
					solutionArray[solutionArrayIndex] = 1;
					break;

				case LEFT_FACE:
					solutionArray[solutionArrayIndex] = 3;
					break;
			}

			solutionArrayIndex ++;
		}
	}

	for (int corner = 0; corner < 4; corner++)
	{
		if (incorrectCorners[corner] != 0)
		{
			solutionArray[solutionArrayIndex] = incorrectCorners[corner];

			FindComplementingCorners(TOP_FACE, incorrectCorners[corner], complementingCornerFace,
			  complementingCornerPiece, complementingCornerFace2, complementingCornerPiece2);

			correctCornerFace1 = FindFaceFromColor(myCube[complementingCornerFace][complementingCornerPiece]);
			correctCornerFace2 = FindFaceFromColor(myCube[complementingCornerFace2][complementingCornerPiece2]);

			solutionArrayIndex++;

			switch(correctCornerFace1)
			{
				case FRONT_FACE:
					if (correctCornerFace2 == RIGHT_FACE)
						solutionArray[solutionArrayIndex] = 8;
					else
						solutionArray[solutionArrayIndex] = 6;
					break;

				case RIGHT_FACE: 
					if (correctCornerFace2 == BACK_FACE)
						solutionArray[solutionArrayIndex] = 2;
					else
						solutionArray[solutionArrayIndex] = 8;
					break;

				case BACK_FACE:
					if (correctCornerFace2 == LEFT_FACE)
						solutionArray[solutionArrayIndex] = 0;
					else
						solutionArray[solutionArrayIndex] = 2;
					break;

				case LEFT_FACE:
					if (correctCornerFace2 == FRONT_FACE)
						solutionArray[solutionArrayIndex] = 6;
					else
						solutionArray[solutionArrayIndex] = 0;
					break;
			}

			solutionArrayIndex++;
		}
	}
}


sub FindMoveset(int finalMoveset[])
{
	bool configurationFound = FALSE;
	int numOfTurns = 0;
	int solutionArray[], lastLayerMoveset[], turnsMoveset[], comparisonArray[];


	while(!configurationFound)
	{
		EvaluateLastLayer(solutionArray);

		if (!configurationFound)
			ArrayBuild(comparisonArray, 0, 2, 2, 8, 8, 0);  // A1
		if (CmpArray(solutionArray, comparisonArray))
		{
			ArrayBuild(lastLayerMoveset, 2, 1, 10, 9, 7, 11, 12, 10, 9, 7, 11, 7);
			configurationFound = TRUE;
		}

		if (!configurationFound)
			ArrayBuild(comparisonArray, 2, 6, 6, 8, 8, 2);  // A2
		if (CmpArray(solutionArray, comparisonArray))
		{
			ArrayBuild(lastLayerMoveset, 1, 4, 9, 9, 7, 12, 11, 9, 9, 7, 11, 7);
			configurationFound = TRUE;
		}

		if (!configurationFound)
			ArrayBuild(comparisonArray, 3, 5, 5, 7, 7, 3);  // U1
		if (CmpArray(solutionArray, comparisonArray))
		{
			ArrayBuild(lastLayerMoveset, 1, 7, 11, 9, 11, 10, 12, 10, 12, 10, 11, 10);
			configurationFound = TRUE;
		}

		if (!configurationFound)
			ArrayBuild(comparisonArray, 3, 7, 5, 3, 7, 5);  // U2
		if (CmpArray(solutionArray, comparisonArray))
		{
			ArrayBuild(lastLayerMoveset, 1, 12, 9, 11, 9, 11, 9, 12, 10, 12, 9, 7);
			configurationFound = TRUE;
		}

		if (!configurationFound)
			ArrayBuild(comparisonArray, 1, 7, 3, 5, 5, 3, 7, 1);  // H
		if (CmpArray(solutionArray, comparisonArray))
		{
			ArrayBuild(lastLayerMoveset, 1, 6, 5, 6, 11, 11, 6, 5, 6, 9, 7, 9, 6, 5, 6, 11, 11, 6, 5, 6);
			configurationFound = TRUE;
		}

		if (!configurationFound)
			ArrayBuild(comparisonArray, 3, 5, 5, 3, 2, 8, 8, 2);  // T
		if (CmpArray(solutionArray, comparisonArray))
		{
			ArrayBuild(lastLayerMoveset, 1, 11, 10, 12, 10, 1, 9, 7, 4, 10, 12, 9, 11, 10, 2);
			configurationFound = TRUE;
		}

		if (!configurationFound)
			ArrayBuild(comparisonArray, 1, 3, 3, 1, 0, 2, 2, 0);  // J1
		if (CmpArray(solutionArray, comparisonArray))
		{
			ArrayBuild(lastLayerMoveset, 2, 11, 12, 9, 7, 9, 12, 10, 11, 7, 9, 5, 10);
			configurationFound = TRUE;
		}

		if (!configurationFound)
			ArrayBuild(comparisonArray, 5, 7, 7, 5, 2, 8, 8, 2);  // J2
		if (CmpArray(solutionArray, comparisonArray))
		{
			ArrayBuild(lastLayerMoveset, 1, 11, 10, 2, 9, 3, 10, 12, 10, 1, 9, 7, 4, 10, 12);
			configurationFound = TRUE;
		}

		if (!configurationFound)
			ArrayBuild(comparisonArray, 3, 7, 7, 3, 0, 2, 2, 0);  // R1
		if (CmpArray(solutionArray, comparisonArray))
		{
			ArrayBuild(lastLayerMoveset, 3, 11, 7, 10, 11, 7, 9, 4, 10, 2, 9, 11, 9, 3, 9, 7, 1);
			configurationFound = TRUE;
		}

		if (!configurationFound)
			ArrayBuild(comparisonArray, 5, 7, 7, 5, 0, 2, 2, 0);  // R2
		if (CmpArray(solutionArray, comparisonArray))
		{
			ArrayBuild(lastLayerMoveset, 2, 11, 7, 9, 11, 7, 10, 1, 9, 3, 10, 12, 10, 2, 9, 7, 4);
			configurationFound = TRUE;
		}

		if (!configurationFound)
			ArrayBuild(comparisonArray, 1, 5, 5, 1, 0, 8, 8, 0);  // V
		if (CmpArray(solutionArray, comparisonArray))
		{
			ArrayBuild(lastLayerMoveset, 2, 11, 10, 12, 4, 4, 9, 7, 4, 10, 11, 10, 1, 9, 11);
			configurationFound = TRUE;
		}

		if (!configurationFound)
			ArrayBuild(comparisonArray, 1, 3, 3, 5, 5, 1, 0, 2, 2, 6, 6, 0);  // G1
		if (CmpArray(solutionArray, comparisonArray))
		{
			ArrayBuild(lastLayerMoveset, 1, 7, 9, 4, 11, 10, 12, 9, 10, 1, 7, 2, 3, 9);
			configurationFound = TRUE;
		}

		if (!configurationFound)
			ArrayBuild(comparisonArray, 1, 7, 3, 1, 7, 3, 0, 6, 6, 8, 8, 0);  // G2
		if (CmpArray(solutionArray, comparisonArray))
		{
			ArrayBuild(lastLayerMoveset, 2, 12, 9, 3, 7, 3, 2, 11, 9, 12, 9, 10, 1, 7);
			configurationFound = TRUE;
		}

		if (!configurationFound)
			ArrayBuild(comparisonArray, 3, 5, 5, 7, 7, 3, 0, 6, 6, 8, 8, 0);  // G3
		if (CmpArray(solutionArray, comparisonArray))
		{
			ArrayBuild(lastLayerMoveset, 1, 7, 10, 1, 12, 9, 11, 10, 9, 3, 7, 3, 2, 10);
			configurationFound = TRUE;
		}

		if (!configurationFound)
			ArrayBuild(comparisonArray, 1, 3, 3, 7, 7, 1, 0, 2, 2, 6, 6, 0);  // G4
		if (CmpArray(solutionArray, comparisonArray))
		{
			ArrayBuild(lastLayerMoveset, 1, 11, 10, 1, 7, 2, 3, 12, 10, 11, 10, 9, 3, 7);
			configurationFound = TRUE;
		}

		if (!configurationFound)
			ArrayBuild(comparisonArray, 3, 5, 5, 3, 6, 8, 8, 6);  // F
		if (CmpArray(solutionArray, comparisonArray))
		{
			ArrayBuild(lastLayerMoveset, 2, 11, 7, 10, 12, 4, 4, 9, 7, 4, 10, 11, 10, 1, 9, 4, 1);
			configurationFound = TRUE;
		}

		if (!configurationFound)
			ArrayBuild(comparisonArray, 1, 3, 3, 1, 5, 7, 7, 5);  // Z
		if (CmpArray(solutionArray, comparisonArray))
		{
			ArrayBuild(lastLayerMoveset, 1, 6, 5, 6, 11, 11, 6, 5, 6, 9, 10, 5, 1, 7, 11, 6, 5, 6, 9, 7, 10, 5, 1, 7);
			configurationFound = TRUE;
		}

		if (!configurationFound)
			ArrayBuild(comparisonArray, 1, 3, 3, 1, 0, 8, 8, 0);  // Y
		if (CmpArray(solutionArray, comparisonArray))
		{
			ArrayBuild(lastLayerMoveset, 9, 1, 2, 10, 12, 9, 11, 10, 2, 9, 3, 10, 12, 10, 1, 9, 12);
			configurationFound = TRUE;
		}

		if (!configurationFound)
			ArrayBuild(comparisonArray, 1, 7, 7, 1, 0, 8, 8, 0);  // N1
		if (CmpArray(solutionArray, comparisonArray))
		{
			ArrayBuild(lastLayerMoveset, 3, 12, 11, 9, 7, 10, 11, 12, 5, 12, 11, 9, 7, 10, 11, 12, 9);
			configurationFound = TRUE;
		}

		if (!configurationFound)
			ArrayBuild(comparisonArray, 1, 7, 7, 1, 2, 6, 6, 2);  // N2
		if (CmpArray(solutionArray, comparisonArray))
		{
			ArrayBuild(lastLayerMoveset, 2, 11, 12, 9, 7, 9, 12, 11, 6, 11, 12, 9, 7, 9, 12, 11, 10);
			configurationFound = TRUE;
		}

		if (!configurationFound)
			ArrayBuild(comparisonArray, 0, 6, 2, 8, 6, 0, 8, 2);  // E
		if (CmpArray(solutionArray, comparisonArray))
		{
			ArrayBuild(lastLayerMoveset, 1, 4, 10, 9, 11, 11, 10, 9, 7, 10, 9, 11, 11, 10, 10, 11);
			configurationFound = TRUE;
		}

	}

}


sub LastLayerSolution(int finalMoveset[])
{
	FindMoveset(finalMoveset);

}