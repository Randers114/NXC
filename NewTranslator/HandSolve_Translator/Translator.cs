using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HandSolve_Translator
{
    public class Translator
    {
        string inputMoveset;
        List<string> moveset = new List<string>();
        List<string> translatedMoves = new List<string>();


        public void ReadInput()
        {
            Console.Write(" Write the set of moves to be translated. Separate each move with a space: ");
            inputMoveset = Console.ReadLine();
        }

        public void TranslateMoves()
        {
            ReplaceMovesInMoveset();

            var moveset = inputMoveset.Split(' ').ToList();

            int movesetLength = moveset.Count;

            

            /*
            for (int i = 0; i < movesetLength; i++)
            {
                string move = moveset.First();
                translatedMoves.Add(move);
                moveset.Remove(move);

                foreach (string f in moveset)
                {
                    
                }
            }
            */

        }

        public void ReplaceMovesInMoveset()
        {
            inputMoveset = inputMoveset.Replace("Mi", "Ri L X")
                .Replace("M", "R Li Xi")
                .Replace("Ei", "Ui D Y")
                .Replace("E", "U Di Yi")
                .Replace("Si", "F Bi Zi")
                .Replace("S", "Fi B Z")
                .Replace("ui", "Di Yi")
                .Replace("li", "Ri X")
                .Replace("fi", "Bi Zi")
                .Replace("ri", "Li Xi")
                .Replace("bi", "Fi Z")
                .Replace("di", "Ui Y")
                .Replace("u", "D Y")
                .Replace("l", "R Xi")
                .Replace("f", "B Z")
                .Replace("r", "L X")
                .Replace("b", "F Zi")
                .Replace("d", "U Yi");
        }

    }
}
