using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Rubix_Operations
{
    class InitializeCube
    {
        public List<List<string>> Cube { get; set; }
        public void InitCube()
        {
            InitializeSide top = new InitializeSide("Blue", "Red", "Orange", "Blue", "Yellow", "Orange", "Orange", "Green", "Green");
            InitializeSide right = new InitializeSide("Red", "Red", "Red", "Red", "Red", "Red",   "Blue",    "Yellow",     "Red");
            InitializeSide front = new InitializeSide("Green", "Yellow", "Yellow", "Blue", "Blue", "Blue", "Blue", "Blue", "Blue");
            InitializeSide back = new InitializeSide("Green", "Green", "Green", "Green", "Green", "Green",    "Red", "Yellow", "Yellow");
            InitializeSide left = new InitializeSide("Yellow", "Yellow", "Yellow", "Orange", "Orange", "Orange", "Orange", "Orange", "Orange");
            InitializeSide bottom = new InitializeSide("White", "White", "White", "White", "White", "White", "White", "White", "White");

            Cube = new TheCube(top.Side, right.Side, front.Side, back.Side, left.Side, bottom.Side).cube;
        }
    }

    //"Red", "Red", "Red", "Red", "Red", "Red"
    //"Green", "Green",   "Green", "Green", "Green", "Green"
    //"Orange", "Orange", "Orange", "Orange", "Orange", "Orange"
    //"Blue", "Blue", "Blue", "Blue", "Blue", "Blue"
}
