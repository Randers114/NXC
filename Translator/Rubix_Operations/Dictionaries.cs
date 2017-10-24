using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Rubix_Operations
{
    class Dictionaries
    {
        public Dictionary<string, Dictionary<string, string>> AllRelations = new Dictionary<string, Dictionary<string, string>>();

        Dictionary<string, string> TopFront = new Dictionary<string, string>();
        Dictionary<string, string> TopBack = new Dictionary<string, string>();
        Dictionary<string, string> TopLeft = new Dictionary<string, string>();
        Dictionary<string, string> TopRight = new Dictionary<string, string>();

        Dictionary<string, string> BottomFront = new Dictionary<string, string>();
        Dictionary<string, string> BottomBack = new Dictionary<string, string>();
        Dictionary<string, string> BottomLeft = new Dictionary<string, string>();
        Dictionary<string, string> BottomRight = new Dictionary<string, string>();

        Dictionary<string, string> FrontTop = new Dictionary<string, string>();
        Dictionary<string, string> FrontBottom = new Dictionary<string, string>();
        Dictionary<string, string> FrontLeft = new Dictionary<string, string>();
        Dictionary<string, string> FrontRight = new Dictionary<string, string>();

        Dictionary<string, string> BackTop = new Dictionary<string, string>();
        Dictionary<string, string> BackBottom = new Dictionary<string, string>();
        Dictionary<string, string> BackLeft = new Dictionary<string, string>();
        Dictionary<string, string> BackRight = new Dictionary<string, string>();

        Dictionary<string, string> LeftFront = new Dictionary<string, string>();
        Dictionary<string, string> LeftBack = new Dictionary<string, string>();
        Dictionary<string, string> LeftBottom = new Dictionary<string, string>();
        Dictionary<string, string> LeftTop = new Dictionary<string, string>();

        Dictionary<string, string> RightFront = new Dictionary<string, string>();
        Dictionary<string, string> RightBack = new Dictionary<string, string>();
        Dictionary<string, string> RightBottom = new Dictionary<string, string>();
        Dictionary<string, string> RightTop = new Dictionary<string, string>();

        public Dictionaries()
        {
            InitializeDictionaries();
        }

        private void InitializeDictionaries()
        {

            InitializeTopAsTop();
            InitializeTopAsBottom();
            InitializeTopAsBack();
            InitializeTopAsFront();
            InitializeTopAsLeft();
            InitializeTopAsRight();

            AddAllRelations();

            
        }

        private void AddAllRelations()
        {
            AllRelations.Add("TopFront", TopFront);
            AllRelations.Add("TopBack", TopBack);
            AllRelations.Add("TopRight", TopRight);
            AllRelations.Add("TopLeft", TopLeft);

            AllRelations.Add("BottomFront", BottomFront);
            AllRelations.Add("BottomBack", BottomBack);
            AllRelations.Add("BottomRight", BottomRight);
            AllRelations.Add("BottomLeft", BottomLeft);

            AllRelations.Add("FrontTop", FrontTop);
            AllRelations.Add("FrontBottom", FrontBottom);
            AllRelations.Add("FrontRight", FrontRight);
            AllRelations.Add("FrontLeft", FrontLeft);

            AllRelations.Add("BackTop", BackTop);
            AllRelations.Add("BackBottom", BackBottom);
            AllRelations.Add("BackRight", BackRight);
            AllRelations.Add("BackLeft", BackLeft);

            AllRelations.Add("RightTop", RightTop);
            AllRelations.Add("RightBottom", RightBottom);
            AllRelations.Add("RightBack", RightBack);
            AllRelations.Add("RightFront", RightFront);

            AllRelations.Add("LeftTop", LeftTop);
            AllRelations.Add("LeftBottom", LeftBottom);
            AllRelations.Add("LeftBack", LeftBack);
            AllRelations.Add("LeftFront", LeftFront);
        }

        private void InitializeTopAsTop()
        {
            TopFront.Add("F", "F");
            TopFront.Add("B", "B");
            TopFront.Add("T", "T");
            TopFront.Add("D", "D");
            TopFront.Add("L", "L");
            TopFront.Add("R", "R");

            TopBack.Add("F", "B");
            TopBack.Add("B", "F");
            TopBack.Add("T", "T");
            TopBack.Add("D", "D");
            TopBack.Add("L", "R");
            TopBack.Add("R", "L");

            TopLeft.Add("F", "L");
            TopLeft.Add("B", "R");
            TopLeft.Add("T", "T");
            TopLeft.Add("D", "D");
            TopLeft.Add("L", "B");
            TopLeft.Add("R", "F");

            TopRight.Add("F", "R");
            TopRight.Add("B", "L");
            TopRight.Add("T", "T");
            TopRight.Add("D", "D");
            TopRight.Add("L", "F");
            TopRight.Add("R", "B");
        }

        private void InitializeTopAsBottom()
        {
            BottomFront.Add("F", "F");
            BottomFront.Add("B", "B");
            BottomFront.Add("T", "D");
            BottomFront.Add("D", "T");
            BottomFront.Add("L", "R");
            BottomFront.Add("R", "L");

            BottomBack.Add("F", "B");
            BottomBack.Add("B", "F");
            BottomBack.Add("T", "D");
            BottomBack.Add("D", "T");
            BottomBack.Add("L", "L");
            BottomBack.Add("R", "R");

            BottomLeft.Add("F", "L");
            BottomLeft.Add("B", "R");
            BottomLeft.Add("T", "D");
            BottomLeft.Add("D", "T");
            BottomLeft.Add("L", "F");
            BottomLeft.Add("R", "B");

            BottomRight.Add("F", "R");
            BottomRight.Add("B", "L");
            BottomRight.Add("T", "D");
            BottomRight.Add("D", "T");
            BottomRight.Add("L", "B");
            BottomRight.Add("R", "F");
        }

        private void InitializeTopAsBack()
        {
            BackTop.Add("F", "T");
            BackTop.Add("B", "D");
            BackTop.Add("T", "B");
            BackTop.Add("D", "F");
            BackTop.Add("L", "L");
            BackTop.Add("R", "R");

            BackBottom.Add("F", "D");
            BackBottom.Add("B", "T");
            BackBottom.Add("T", "B");
            BackBottom.Add("D", "F");
            BackBottom.Add("L", "R");
            BackBottom.Add("R", "L");

            BackLeft.Add("F", "L");
            BackLeft.Add("B", "R");
            BackLeft.Add("T", "B");
            BackLeft.Add("D", "F");
            BackLeft.Add("L", "D");
            BackLeft.Add("R", "T");

            BackRight.Add("F", "R");
            BackRight.Add("B", "L");
            BackRight.Add("T", "B");
            BackRight.Add("D", "F");
            BackRight.Add("L", "T");
            BackRight.Add("R", "D");
        }

        private void InitializeTopAsFront()
        {
            FrontTop.Add("F", "T");
            FrontTop.Add("B", "D");
            FrontTop.Add("T", "F");
            FrontTop.Add("D", "B");
            FrontTop.Add("L", "R");
            FrontTop.Add("R", "L");

            FrontBottom.Add("F", "D");
            FrontBottom.Add("B", "T");
            FrontBottom.Add("T", "F");
            FrontBottom.Add("D", "B");
            FrontBottom.Add("L", "L");
            FrontBottom.Add("R", "R");

            FrontLeft.Add("F", "L");
            FrontLeft.Add("B", "R");
            FrontLeft.Add("T", "F");
            FrontLeft.Add("D", "B");
            FrontLeft.Add("L", "D");
            FrontLeft.Add("R", "T");

            FrontRight.Add("F", "R");
            FrontRight.Add("B", "L");
            FrontRight.Add("T", "F");
            FrontRight.Add("D", "B");
            FrontRight.Add("L", "D");
            FrontRight.Add("R", "T");
        }

        private void InitializeTopAsRight()
        {
            RightBottom.Add("F", "B");
            RightBottom.Add("B", "T");
            RightBottom.Add("T", "R");
            RightBottom.Add("D", "L");
            RightBottom.Add("L", "F");
            RightBottom.Add("R", "B");

            RightFront.Add("F", "F");
            RightFront.Add("B", "B");
            RightFront.Add("T", "R");
            RightFront.Add("D", "L");
            RightFront.Add("L", "T");
            RightFront.Add("R", "D");

            RightBack.Add("F", "B");
            RightBack.Add("B", "F");
            RightBack.Add("T", "R");
            RightBack.Add("D", "L");
            RightBack.Add("L", "D");
            RightBack.Add("R", "T");

            RightTop.Add("F", "T");
            RightTop.Add("B", "D");
            RightTop.Add("T", "R");
            RightTop.Add("D", "L");
            RightTop.Add("L", "B");
            RightTop.Add("R", "F");
        }

        private void InitializeTopAsLeft()
        {
            LeftBottom.Add("F", "B");
            LeftBottom.Add("B", "T");
            LeftBottom.Add("T", "L");
            LeftBottom.Add("D", "R");
            LeftBottom.Add("L", "B");
            LeftBottom.Add("R", "R");

            LeftFront.Add("F", "F");
            LeftFront.Add("B", "B");
            LeftFront.Add("T", "L");
            LeftFront.Add("D", "R");
            LeftFront.Add("L", "D");
            LeftFront.Add("R", "T");

            LeftBack.Add("F", "B");
            LeftBack.Add("B", "F");
            LeftBack.Add("T", "L");
            LeftBack.Add("D", "R");
            LeftBack.Add("L", "T");
            LeftBack.Add("R", "D");

            LeftTop.Add("F", "T");
            LeftTop.Add("B", "D");
            LeftTop.Add("T", "L");
            LeftTop.Add("D", "R");
            LeftTop.Add("L", "F");
            LeftTop.Add("R", "B");
        }

    }
}
