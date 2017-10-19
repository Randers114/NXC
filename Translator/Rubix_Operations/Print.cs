using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Rubix_Operations
{
    class Print
    {
        public static void Run(List<List<string>> cube)
        {
            int a = 0, i = 1;
            foreach (var item in cube)
            {

                switch (i)
                {
                    case 1:
                        Console.WriteLine("Top");
                        break;
                    case 2:
                        Console.WriteLine("Right");
                        break;
                    case 3:
                        Console.WriteLine("Front");
                        break;
                    case 4:
                        Console.WriteLine("Back");
                        break;
                    case 5:
                        Console.WriteLine("Left");
                        break;
                    case 6:
                        Console.WriteLine("Bottom");
                        break;
                    default:
                        break;
                }
                foreach (var itema in item)
                {
                    a++;

                    if (a % 3 == 0 && a % 9 == 0)
                    {
                        Console.WriteLine(itema);
                        Console.WriteLine();
                    }
                    else if (a % 3 == 0)
                    {
                        Console.WriteLine(itema);
                    }
                    else
                    {
                        Console.Write(itema + " ");
                    }

                }
                i++;
            }

            Console.ReadKey();
        }
    }
}
