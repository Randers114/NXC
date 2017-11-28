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
		string finalMoveset;
        List<string> moveset = new List<string>();
        List<string> translatedMoves = new List<string>();
		List<int> machineMoves = new List<int>();


        public void ReadInput()
        {
            Console.Write("Write the set of moves to be translated. Separate each move with a space: ");
            inputMoveset = Console.ReadLine();
        }

        public void PrintMoveset()
        {
			ReplaceMovesToMachineMoves();
            Console.Write("Final Moveset:");
            foreach (string move in translatedMoves)
            {
                Console.Write(move + " ");
            }
			Console.WriteLine("\nTranslated to MachineMoveset:");
			foreach(int move in machineMoves)
			{
				Console.ForegroundColor = ConsoleColor.Green;
				Console.Write(move + " ");
				Console.ResetColor();
			}

		}

        public void TranslateMoves()
        {
            LoadDictionaries LoadDic = new LoadDictionaries();
            LoadDic.AddTranslationsToDictionaries();
            Dictionary<string, string> dictFromMove = new Dictionary<string, string>();
            List<string> tempMoveset = new List<string>();
            List<string> movesetWithoutXYZ = new List<string>();
            string translatedMove = "";

            ReplaceMovesInMoveset();  // Replaces Middle-turns and Double-layer turns with corresponding single-layer and orientation turns.

            Console.WriteLine("Replaced Moveset: " + inputMoveset);

            var moveset = inputMoveset.Split(' ').ToList();
            int movesetLength = moveset.Count;

            movesetLength = moveset.Count;

            for (int j = 0; j < movesetLength; j++) 
            {
                if (moveset.Count != 0) // Translate XYZ orientation-changes.
                {
                    if (moveset.First() == "X" || moveset.First() == "Xi" || moveset.First() == "Y" || moveset.First() == "Yi" || moveset.First() == "Z" || moveset.First() == "Zi")
                    {
                        LoadDic.dictFirstTranslation.TryGetValue(moveset.First(), out dictFromMove);
                        moveset.Remove(moveset.First());

                        foreach (string move in moveset)
                        {
                            dictFromMove.TryGetValue(move, out translatedMove);
                            tempMoveset.Add(translatedMove);
                        }

                        moveset = tempMoveset.ToList();
                        tempMoveset.Clear();
                    }

                    else // Translate robot-moves.
                    {
                        LoadDic.dictFirstTranslation.TryGetValue(moveset.First(), out dictFromMove);
                        translatedMoves.Add(moveset.First());
                    

                        Console.WriteLine("\nAdded to translatedMoves: " + moveset.First());

                        moveset.Remove(moveset.First());

                        if (moveset.Count != 0)
                        {
                            foreach (string move in moveset)
                            {
                                dictFromMove.TryGetValue(move, out translatedMove);

                                tempMoveset.Add(translatedMove);
                            }

                            moveset = tempMoveset.ToList();

                            foreach (string strPrint in moveset)
                            {
                                Console.Write(strPrint + " ");
                            }

                            Console.WriteLine("\n");

                            tempMoveset.Clear();
                        }
                    }
                }
            }
        }

		public void ReplaceMovesToMachineMoves()
		{
			int[] i;
			foreach (string move in translatedMoves)
			{

				switch(move)
				{
					case "R":
						machineMoves.Add(1);
						break;
						
					case "Ri":
						machineMoves.Add(2);
						break;

					case "L":
						machineMoves.Add(3);
						break;

					case "Li":
						machineMoves.Add(4);
						break;

					case "T":
						machineMoves.Add(5);
						break;

					case "Ti":
						machineMoves.Add(6);
						break;

					case "D":
						machineMoves.Add(7);
						break;

					case "Di":
						machineMoves.Add(8);
						break;

					case "F":
						machineMoves.Add(9);
						break;

					case "Fi":
						machineMoves.Add(10);
						break;

					case "B":
						machineMoves.Add(11);
						break;

					case "Bi":
						machineMoves.Add(12);
						break;


				}
		
			}

		}

        public void ReplaceMovesInMoveset()
        {
            inputMoveset = inputMoveset.Replace("U2'", "U2")
                .Replace("L2'", "L2")
                .Replace("F2'", "F2")
                .Replace("R2'", "R2")
                .Replace("B2'", "B2")
                .Replace("D2'", "D2")
                .Replace("'", "i")
                .Replace("x", "X")
                .Replace("y", "Y")
                .Replace("z", "Z"); 
			
                
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
