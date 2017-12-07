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

sub CheckEdgeCorrectness(int &correctEdges[])
{
	int complementingPiece = 0, complementingFace = 0, edgeNumber = 0;
	
	for(int piece = 1; piece < 8; piece = piece + 2)
	{
		FindComplementingEdge(TOP_FACE, piece, complementingFace, complementingPiece);
		
		if(myCube[complementingFace][CENTER_PIECE] == myCube[complementingFace][complementingPiece])
		{
			correctEdges[edgeNumber] = 0;
		}
		else
		{
			correctEdges[edgeNumber] = 1;
		}

		edgeNumber++;
	}
}

sub CheckCornerCorrectness(int &correctCorners[])
{
	int complementingPiece = 0, complementingFace = 0, complementingPiece2 = 0, complementingFace2 = 0, cornerNumber = 0;
	
	for(int piece = 0; piece < 9; piece = piece + 2)
	{
		FindComplementingCorners(TOP_FACE, piece, complementingFace, complementingPiece, complementingFace2, complementingPiece2);
		
		if(!(myCube[complementingFace][CENTER_PIECE] == myCube[complementingFace][complementingPiece]))
		{
			correctCorners[cornerNumber] = 1;
		} 
		else if(!(myCube[complementingFace2][CENTER_PIECE] == myCube[complementingFace2][complementingPiece2]))
		{
			correctCorners[cornerNumber] = 1;
		}
		else
		{
			correctCorners[cornerNumber] = 0;
		}
		
		cornerNumber++;	

		if(piece == 2)
		{
			piece += 2;
		}
	}
}

sub FindMoveset()
{




}

int EvaluateLastLayer()
{
	int correctEdges[4], correctCorners[4], solvedConfiguration[4] = {0, 0, 0, 0};

	CheckEdgeCorrectness(correctEdges);
	CheckCornerCorrectness(correctCorners);

	if ()
}




sub LastLayerSolutio()
{


}