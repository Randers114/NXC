using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace Rubix_Operations
{
    class AlgorithmTranslator
    {
        private string InputAlgorithmCharacter { get; set; }
        private List<List<string>> Cube { get; set; }

        public CubeColour Colours = new CubeColour();

        public Dictionaries LookUp = new Dictionaries();

        private string TopPosition { get; set; }
        private string FrontPosition { get; set; }

        public AlgorithmTranslator(List<List<string>> cube)
        {
            Cube = cube;
            Colours.TopColour = Cube[0][4];
            Colours.BottomColour = Cube[5][4];
            Colours.FrontColour = Cube[2][4];
            Colours.BackColour = Cube[3][4];
            Colours.RightColour = Cube[1][4];
            Colours.LeftColour = Cube[4][4];
        }

        public string StartUp(string inputAlgorithmCharater, List<List<string>> cube)
        {
            InputAlgorithmCharacter = inputAlgorithmCharater;
            Cube = cube;
            TopPosition = FindFace(Colours.TopColour);
            FrontPosition = FindFace(Colours.FrontColour);

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

            if (Regex.IsMatch(InputAlgorithmCharacter, @"[MEdrluf]"))
            {
                return CenterRotations();
            }

            LookUp.AllRelations.TryGetValue(TopPosition + FrontPosition, out currentRelation);
            currentRelation.TryGetValue(InputAlgorithmCharacter.First().ToString(), out translation);

            if (InputAlgorithmCharacter.Contains('i'))
            {
                translation += "i";
            }

            return translation;
        }

        private string CenterRotations()
        {
            string translation = string.Empty;

            // No Doublelayers
            if (InputAlgorithmCharacter == "M")
            {
                ChangeColourXInverted();
                translation = "R Ti";
            }
            else if(InputAlgorithmCharacter == "f"){
                ChangeColourZ();
                InputAlgorithmCharacter = "B";
                translation = Translate();
            }
            else if(InputAlgorithmCharacter == "fi"){
                ChangeColourZInverted();
                InputAlgorithmCharacter = "Bi";
                translation = Translate();
            }
            else if (InputAlgorithmCharacter == "E")
            {
                ChangeColourYInverted();
                translation = "Di T";
            }
            if (InputAlgorithmCharacter == "Mi")
            {
                ChangeColourX();
                translation = "Ri T";
            }
            else if (InputAlgorithmCharacter == "Ei")
            {
                ChangeColourY();
                translation = "D Ti";
            }

            // Doublelayers left and right
            else if (InputAlgorithmCharacter == "r")
            {
                ChangeColourX();
                InputAlgorithmCharacter = "L";
                translation = Translate();
            }
            else if (InputAlgorithmCharacter == "ri")
            {
                ChangeColourXInverted();
                InputAlgorithmCharacter = "Li";
                translation = Translate();
            }
            else if (InputAlgorithmCharacter == "l")
            {
                ChangeColourX();
                InputAlgorithmCharacter = "R";
                translation = Translate();
            }
            else if (InputAlgorithmCharacter == "li")
            {
                ChangeColourXInverted();
                InputAlgorithmCharacter = "Ri";
                translation = Translate();
            }

            // Doublelayers top and bottom
            else if (InputAlgorithmCharacter == "t")
            {
                ChangeColourY();
                InputAlgorithmCharacter = "D";
                translation = Translate();
            }
            else if (InputAlgorithmCharacter == "ti")
            {
                ChangeColourYInverted();
                InputAlgorithmCharacter = "Di";
                translation = Translate();
            }
            else if (InputAlgorithmCharacter == "d")
            {
                ChangeColourY();
                InputAlgorithmCharacter = "T";
                translation = Translate();
            }
            else if (InputAlgorithmCharacter == "di")
            {
                ChangeColourYInverted();
                InputAlgorithmCharacter = "Ti";
                translation = Translate();
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
            Colours.ChangeY();
            FrontPosition = FindFace(Colours.FrontColour);
        }

        private void ChangeColourYInverted()
        {
            Colours.ChangeYInverted();
            FrontPosition = FindFace(Colours.FrontColour);
        }

        private void ChangeColourX()
        {
            Colours.ChangeX();
            FrontPosition = FindFace(Colours.FrontColour);
            TopPosition = FindFace(Colours.TopColour);

        }

        private void ChangeColourXInverted()
        {
            Colours.ChangeXInverted();
            FrontPosition = FindFace(Colours.FrontColour);
            TopPosition = FindFace(Colours.TopColour);
        }
        private void ChangeColourZ()
        {
            Colours.ChangeZ();
            TopPosition = FindFace(Colours.TopColour);
        }
        private void ChangeColourZInverted()
        {
            Colours.ChangeZInverted();
            TopPosition = FindFace(Colours.TopColour);
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
