using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Rubix_Operations
{
    class Program
    {
        static void Main(string[] args)
        {
            InitializeCube rubix = new InitializeCube();
            rubix.InitCube();

            RunTranslate(rubix);
            
        }

        private static void RunTranslate(InitializeCube rubix)
        {
            string inputAlgorithm = "F (R U R' U') F' f (R U R' U') f'";
            inputAlgorithm = inputAlgorithm.Replace('\'', 'i').Replace('U', 'T').Replace("(", "").Replace(")", "");
            Console.WriteLine(inputAlgorithm);
            Print.Run(rubix.Cube);
            Console.Clear();
            string[] inputCharacter = inputAlgorithm.Split(' ');
            List<string> translatedAlgoritm = new List<string>();

            AlgorithmTranslator translator = new AlgorithmTranslator(rubix.Cube);

            foreach (string character in inputCharacter)
            {
                translatedAlgoritm.Add(translator.StartUp(character, rubix.Cube));

                if (translatedAlgoritm.Last().Contains(' '))
                {
                    foreach (string operation in translatedAlgoritm.Last().Split(' '))
                    {
                        RunOperations(rubix, operation);
                    }

                }
                else
                {
                    RunOperations(rubix, translatedAlgoritm.Last());
                }
            }

            Console.WriteLine(inputAlgorithm);

            foreach (string character in translatedAlgoritm)
            {
                if (!(character == string.Empty))
                {
                    Console.Write(character + " ");
                }
            }
            Console.WriteLine();
            Print.Run(rubix.Cube);
        }

        private static void RunOperations(InitializeCube rubix, string operation)
        {
            switch (operation)
            {
                case "R":
                    Operation.RotateRightFace(rubix.Cube);
                    break;
                case "D":
                    Operation.RotateBottomFace(rubix.Cube);
                    break;
                case "T":
                    Operation.RotateTopFace(rubix.Cube);
                    break;
                case "L":
                    Operation.RotateLeftFace(rubix.Cube);
                    break;
                case "B":
                    Operation.RotateBackFace(rubix.Cube);
                    break;
                case "F":
                    Operation.RotateFrontFace(rubix.Cube);
                    break;

                // Inverteds
                case "Ri":
                    Operation.RotateRightFaceInverted(rubix.Cube);
                    break;
                case "Di":
                    Operation.RotateBottomFaceInverted(rubix.Cube);
                    break;
                case "Ti":
                    Operation.RotateTopFaceInverted(rubix.Cube);
                    break;
                case "Li":
                    Operation.RotateLeftFaceInverted(rubix.Cube);
                    break;
                case "Bi":
                    Operation.RotateBackFaceInverted(rubix.Cube);
                    break;
                case "Fi":
                    Operation.RotateFrontFaceInverted(rubix.Cube);
                    break;
                default:
                    break;
            }
        }
       
        private static void Run(InitializeCube rubix)
        {
            Operation.RotateRightFace(rubix.Cube);
            Operation.RotateTopFace(rubix.Cube);

            Print.Run(rubix.Cube);
        }
    }
}
