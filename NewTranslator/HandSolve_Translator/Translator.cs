using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HandSolve_Translator
{
    public class Translator
    {
        private string inputMoveset;
        List<string> moveset = new List<string>();
        List<string> translatedMoves = new List<string>();


        public void ReadInput()
        {
            Console.Write(" Write the set of moves to be translated. Separate each move with a space: ");
            inputMoveset = Console.ReadLine();
        }

        public void TranslateMoves()
        {
            var moveset = inputMoveset.Split(' ').ToList();

            foreach (string str in moveset)
            {

            }

            int movesetLength = moveset.Count;

            for (int i = 0; i < movesetLength; i++)
            {
                string move = moveset.First();
                translatedMoves.Add(move);
                moveset.Remove(move);

                foreach (string f in moveset)
                {
                    ReplaceInMoveset(move, f);
                }
            }


        }

        public void ReplaceInMoveset(string move, string nextMove)
        {
            if (move == "R" | move == "Ri")
            {
                switch (nextMove)
                {
                    default:
                }
            }
        }

    }
}
