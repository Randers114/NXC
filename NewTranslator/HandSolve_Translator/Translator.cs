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
            Console.Write("Write the set of moves to be translated. Separate each move with a space: ");
            inputMoveset = Console.ReadLine();
        }

        public void PrintMoveset()
        {
            foreach (string f in translatedMoves)
            {
                Console.WriteLine(f);
            }
            
        }

        public void TranslateMoves()
        {
            LoadDictionaries LD = new LoadDictionaries();
            LD.AddTranslationsToDictionaries();
            Dictionary<string, string> dictFromMove = new Dictionary<string, string>();
            List<string> tempMoveset = new List<string>();
            string translatedMove = "";

            ReplaceMovesInMoveset();  // Replaces Middle-turns and Double-layer turns with corresponding single-layer and orientation turns.

            Console.WriteLine(inputMoveset);

            var moveset = inputMoveset.Split(' ').ToList();
            int movesetLength = moveset.Count;

            
            for (int i = 0; i < movesetLength; i++)
            {
                if (moveset.Count != 0)
                {
                    LD.dictFirstTranslation.TryGetValue(moveset.First(), out dictFromMove);
                    translatedMoves.Add(moveset.First());
                    moveset.Remove(moveset.First());
                    

                    if (moveset.Count != 0)
                    {
                        foreach (string move in moveset)
                        {
                            dictFromMove.TryGetValue(move, out translatedMove);

                            tempMoveset.Add(translatedMove);
                        }

                        moveset = tempMoveset.ToList();
                        tempMoveset.Clear();
                    }
                }
            }
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
                .Replace("d", "U Yi")
                .Replace("U2", "U U")
                .Replace("L2", "L L")
                .Replace("F2", "F F")
                .Replace("R2", "R R")
                .Replace("B2", "B B")
                .Replace("D2", "D D");
        }

    }
}
