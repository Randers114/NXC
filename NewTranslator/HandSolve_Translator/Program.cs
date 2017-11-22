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
            Translator t = new Translator();

            t.ReadInput();
            t.TranslateMoves();

            Console.ReadKey();
        }
    }
}
