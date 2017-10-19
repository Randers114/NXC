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
            InitializeSide top = new InitializeSide("White", "Green", "White", "White", "Yellow", "Yellow", "Orange", "Blue", "Red");
            InitializeSide right = new InitializeSide("Yellow", "Orange", "Green", "Yellow", "Orange", "White", "Green", "White", "Blue");
            InitializeSide front = new InitializeSide("White", "Red", "Green", "Green", "Green", "Blue", "Blue", "Blue", "Orange");
            InitializeSide back = new InitializeSide("White", "Orange", "Orange", "Red", "Blue", "Green", "Red", "Yellow", "Red");
            InitializeSide left = new InitializeSide("Red", "Green", "Orange", "Orange", "Red", "Yellow", "Green", "Red", "Blue");
            InitializeSide bottom = new InitializeSide("Yellow", "White", "Yellow", "Red", "White", "Orange", "Blue", "Blue", "Yellow");

            Cube = new TheCube(top.Side, right.Side, front.Side, back.Side, left.Side, bottom.Side).cube;
        }
    }
}
