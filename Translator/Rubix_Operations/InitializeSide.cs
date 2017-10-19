using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Rubix_Operations
{
    class InitializeSide
    {
        public List<string> Side { get; set; }
        public InitializeSide(string a, string b, string c, string d, string e, string f, string g, string h, string i)
        {
            Side = new List<string>();
            Side.Add(a);
            Side.Add(b);
            Side.Add(c);
            Side.Add(d);
            Side.Add(e);
            Side.Add(f);
            Side.Add(g);
            Side.Add(h);
            Side.Add(i);
        }
    }
}
