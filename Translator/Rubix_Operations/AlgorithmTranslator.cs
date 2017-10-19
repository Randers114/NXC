using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Rubix_Operations
{
    class AlgorithmTranslator
    {
        private string InputAlgorithmCharacter { get; set; }
        private List<List<string>> Cube { get; set; }

        public Dictionaries LookUp = new Dictionaries();

        private string TopPosition { get; set; }
        private string FrontPosition { get; set; }

        public AlgorithmTranslator(List<List<string>> cube, string frontColour)
        {
            Cube = cube;
            CubeColour.TopColour = "Yellow";
            CubeColour.FrontColour = frontColour;
        }

        public string StartUp(string inputAlgorithmCharater, List<List<string>> cube)
        {
            InputAlgorithmCharacter = inputAlgorithmCharater;
            Cube = cube;
            TopPosition = FindFace(CubeColour.TopColour);
            FrontPosition = FindFace(CubeColour.FrontColour);

            return Translate();
        }

        private string Translate()
        {
            string translation = string.Empty;
            Dictionary<string, string> currentRelation = new Dictionary<string, string>();

            if (CheckForRotations(InputAlgorithmCharacter))
            {
                return string.Empty;
            }

            LookUp.AllRelations.TryGetValue(TopPosition + FrontPosition, out currentRelation);
            currentRelation.TryGetValue(InputAlgorithmCharacter.First().ToString(), out translation);

            if (InputAlgorithmCharacter.Contains('i'))
            {
                translation += "i";
            }

            return translation;
        }

        private bool CheckForRotations(string inputCharacter)
        {
            bool rotated = false;
            if (inputCharacter == "x")
            {
                ChangeColourX();
                rotated = true;
            }
            else if (inputCharacter == "xi")
            {
                ChangeColourXInverted();
                rotated = true;
            }
            else if (inputCharacter == "y")
            {
                ChangeColourY();
                rotated = true;
            }
            else if (inputCharacter == "yi")
            {
                ChangeColourYInverted();
                rotated = true;
            }

            return rotated;
        }

        private void ChangeColourY()
        {
            FrontPosition = FindFace((Cube[1])[4]);
            CubeColour.FrontColour = (Cube[1])[4];
        }

        private void ChangeColourYInverted()
        {
            FrontPosition = FindFace((Cube[4])[4]);
            CubeColour.FrontColour = (Cube[4])[4];
        }

        private void ChangeColourX()
        {
            TopPosition = FindFace((Cube[2])[4]);
            CubeColour.TopColour = (Cube[2])[4];
            FrontPosition = FindFace((Cube[5])[4]);
            CubeColour.FrontColour = (Cube[5])[4];

    }

        private void ChangeColourXInverted()
        {
            TopPosition = FindFace((Cube[3])[4]);
            CubeColour.TopColour = (Cube[3])[4];
            FrontPosition = FindFace((Cube[0])[4]);
            CubeColour.FrontColour = (Cube[0])[4];
        }

        private string FindFace(string colour)
        {
            int faceCounter = 0;
            string position = string.Empty;
            foreach (var face in Cube)
            {
                if (face[4].Equals(colour))
                {
                    switch (faceCounter)
                    {
                        case 0:
                            position = "Top";
                            break;
                        case 1:
                            position = "Right";
                            break;
                        case 2:
                            position = "Front";
                            break;
                        case 3:
                            position = "Back";
                            break;
                        case 4:
                            position = "Left";
                            break;
                        case 5:
                            position = "Bottom";
                            break;
                        default:
                            break;
                    }
                }

                faceCounter++;
            }

            return position;
        }
    }
}
