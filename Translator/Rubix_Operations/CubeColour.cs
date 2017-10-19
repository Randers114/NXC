using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Rubix_Operations
{
    class CubeColour
    {
        public string TopColour { get; set; }

        public string FrontColour { get; set; }

        public string BottomColour { get; set; }

        public string BackColour { get; set; }

        public string RightColour { get; set; }

        public string LeftColour { get; set; }

        public void ChangeY()
        {
            string _tempColour;

            _tempColour = FrontColour;
            FrontColour = RightColour;
            RightColour = BackColour;
            BackColour = LeftColour;
            LeftColour = _tempColour; 
        }

        public void ChangeYInverted()
        {
            string _tempColour;

            _tempColour = FrontColour;
            FrontColour = LeftColour;
            LeftColour = BackColour;
            BackColour = RightColour;
            RightColour = _tempColour;
        }

        public void ChangeX()
        {
            string _tempColour;

            _tempColour = FrontColour;
            FrontColour = BottomColour;
            BottomColour = BackColour;
            BackColour = TopColour;
            TopColour = FrontColour;
        }

        public void ChangeXInverted()
        {
            string _tempColour;

            _tempColour = FrontColour;
            FrontColour = TopColour;
            TopColour = BackColour;
            BackColour = BottomColour;
            BottomColour = _tempColour;
        }
    }
}
