using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HandSolve_Translator
{
    class Program
    {
        static void Main(string[] args)
        {
            Translator translator = new Translator();

            translator.ReadInput();
            translator.TranslateMoves();
            translator.PrintMoveset();
            

            Console.ReadKey();
        }
    }
}
