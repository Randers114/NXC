using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Rubix_Operations
{
    class TheCube
    {
        public List<List<string>> cube = new List<List<string>>();

        public TheCube(List<string> top, List<string> right, List<string> front, List<string> back, List<string> left, List<string> bottom)
        {
            cube.Add(top);
            cube.Add(right);
            cube.Add(front);
            cube.Add(back);
            cube.Add(left);
            cube.Add(bottom);
        }
    }
}
