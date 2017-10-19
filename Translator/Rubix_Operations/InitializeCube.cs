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
            InitializeSide top = new InitializeSide("Orange", "White", "Yellow", "Yellow", "Yellow", "White", "White", "Red", "White");
            InitializeSide right = new InitializeSide("White", "Red", "White", "Red", "Green", "Orange", "Red", "Blue", "Green");
            InitializeSide front = new InitializeSide("Orange", "Blue", "Orange", "Yellow", "Red", "Blue", "Blue", "Green", "Red");
            InitializeSide back = new InitializeSide("Red", "Blue", "Red", "Orange", "Orange", "White", "Yellow", "Orange", "Green");
            InitializeSide left = new InitializeSide("Green", "Red", "Blue", "Yellow", "Blue", "Green", "Blue", "White", "Yellow");
            InitializeSide bottom = new InitializeSide("Orange", "Orange", "Blue", "Green", "White", "Green", "Yellow", "Yellow", "Green");

            Cube = new TheCube(top.Side, right.Side, front.Side, back.Side, left.Side, bottom.Side).cube;
        }
    }
}
