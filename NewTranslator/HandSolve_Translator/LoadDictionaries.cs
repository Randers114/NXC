using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HandSolve_Translator
{
    public class LoadDictionaries
    {
        public Dictionary<string, Dictionary<string, string>> dictFirstTranslation = new Dictionary<string, Dictionary<string, string>>();
        public Dictionary<string, string> upperTranslation     = new Dictionary<string, string>();
        public Dictionary<string, string> rightTranslation     = new Dictionary<string, string>();
        public Dictionary<string, string> frontTranslation     = new Dictionary<string, string>();
		public Dictionary<string, string> backTranslation      = new Dictionary<string, string>();
        public Dictionary<string, string> leftTranslation      = new Dictionary<string, string>();
        public Dictionary<string, string> downTranslation      = new Dictionary<string, string>();
        public Dictionary<string, string> xTranslation         = new Dictionary<string, string>();
        public Dictionary<string, string> xInvertedTranslation = new Dictionary<string, string>();
        public Dictionary<string, string> yTranslation         = new Dictionary<string, string>();
        public Dictionary<string, string> yInvertedTranslation = new Dictionary<string, string>();
        public Dictionary<string, string> zTranslation         = new Dictionary<string, string>();
        public Dictionary<string, string> zInvertedTranslation = new Dictionary<string, string>();

        public void AddTranslationsToDictionaries()
        {
			// dictFirstTranslation
            dictFirstTranslation.Add("U", upperTranslation);
            dictFirstTranslation.Add("Ui", upperTranslation);
            dictFirstTranslation.Add("R", rightTranslation);
            dictFirstTranslation.Add("Ri",rightTranslation);
            dictFirstTranslation.Add("F", frontTranslation);
            dictFirstTranslation.Add("Fi", frontTranslation);

            dictFirstTranslation.Add("B", backTranslation);
            dictFirstTranslation.Add("Bi", backTranslation);
            dictFirstTranslation.Add("L", leftTranslation);
            dictFirstTranslation.Add("Li", leftTranslation);
            dictFirstTranslation.Add("D", downTranslation);
            dictFirstTranslation.Add("Di", downTranslation);

            dictFirstTranslation.Add("X", xTranslation);
            dictFirstTranslation.Add("Xi", xInvertedTranslation);
            dictFirstTranslation.Add("Y", yTranslation);
            dictFirstTranslation.Add("Yi", yInvertedTranslation);
            dictFirstTranslation.Add("Z", zTranslation);
            dictFirstTranslation.Add("Zi", zInvertedTranslation);


			// upperTranslation
			upperTranslation.Add("U", "D");
			upperTranslation.Add("Ui", "Di");
			upperTranslation.Add("R", "R");
			upperTranslation.Add("Ri", "Ri");
			upperTranslation.Add("F", "B");
			upperTranslation.Add("Fi", "Bi");

			upperTranslation.Add("B", "F");
			upperTranslation.Add("Bi", "Fi");
			upperTranslation.Add("L", "L");
			upperTranslation.Add("Li", "Li");
			upperTranslation.Add("D", "U");
			upperTranslation.Add("Di", "Ui");

			upperTranslation.Add("X", "X");
			upperTranslation.Add("Xi", "Xi");
			upperTranslation.Add("Y", "Yi");
			upperTranslation.Add("Yi", "Y");
			upperTranslation.Add("Z", "Zi");
			upperTranslation.Add("Zi", "Z");

			// rightTranslation
			rightTranslation.Add("U", "B");
			rightTranslation.Add("Ui", "Bi");
			rightTranslation.Add("R", "D");
			rightTranslation.Add("Ri", "Di");
			rightTranslation.Add("F", "R");
			rightTranslation.Add("Fi", "Ri");

			rightTranslation.Add("B", "L");
			rightTranslation.Add("Bi", "Li");
			rightTranslation.Add("L", "U");
			rightTranslation.Add("Li", "Ui");
			rightTranslation.Add("D", "F");
			rightTranslation.Add("Di", "Fi");

			rightTranslation.Add("X", "Yi");
			rightTranslation.Add("Xi", "Y");
			rightTranslation.Add("Y", "Zi");
			rightTranslation.Add("Yi", "Z");
			rightTranslation.Add("Z", "X");
			rightTranslation.Add("Zi", "Xi");

			// frontTranslation
			frontTranslation.Add("U", "F");
			frontTranslation.Add("Ui", "Fi");
			frontTranslation.Add("R", "R");
			frontTranslation.Add("Ri", "Ri");
			frontTranslation.Add("F", "D");
			frontTranslation.Add("Fi", "Di");

			frontTranslation.Add("B", "U");
			frontTranslation.Add("Bi", "Ui");
			frontTranslation.Add("L", "L");
			frontTranslation.Add("Li", "Li");
			frontTranslation.Add("D", "B");
			frontTranslation.Add("Di", "Bi");

			frontTranslation.Add("X", "X");
			frontTranslation.Add("Xi", "Xi");
			frontTranslation.Add("Y", "Z");
			frontTranslation.Add("Yi", "Zi");
			frontTranslation.Add("Z", "Yi");
			frontTranslation.Add("Zi", "Y");

			// backTranslation

			backTranslation.Add("U", "B");
			backTranslation.Add("Ui", "Bi");
			backTranslation.Add("R", "R");
			backTranslation.Add("Ri", "Ri");
			backTranslation.Add("F", "U");
			backTranslation.Add("Fi", "Ui");

			backTranslation.Add("B", "D");
			backTranslation.Add("Bi", "Di");
			backTranslation.Add("L", "L");
			backTranslation.Add("Li", "Li");
			backTranslation.Add("D", "F");
			backTranslation.Add("Di", "Fi");

			backTranslation.Add("X", "X");
			backTranslation.Add("Xi", "Xi");
			backTranslation.Add("Y", "Zi");
			backTranslation.Add("Yi", "Z");
			backTranslation.Add("Z", "Y");
			backTranslation.Add("Zi", "Yi");

			// leftTranslation

			leftTranslation.Add("U", "B");
			leftTranslation.Add("Ui", "Bi");
			leftTranslation.Add("R", "U");
			leftTranslation.Add("Ri", "Ui");
			leftTranslation.Add("F", "L");
			leftTranslation.Add("Fi", "Li");

			leftTranslation.Add("B", "R");
			leftTranslation.Add("Bi", "Ri");
			leftTranslation.Add("L", "D");
			leftTranslation.Add("Li", "Di");
			leftTranslation.Add("D", "F");
			leftTranslation.Add("Di", "Fi");

			leftTranslation.Add("X", "Y");
			leftTranslation.Add("Xi", "Yi");
			leftTranslation.Add("Y", "Zi");
			leftTranslation.Add("Yi", "Z");
			leftTranslation.Add("Z", "Xi");
			leftTranslation.Add("Zi", "X");

            // downTranslation

            downTranslation.Add("U", "U");
            downTranslation.Add("Ui", "Ui");
            downTranslation.Add("R", "R");
            downTranslation.Add("Ri", "Ri");
            downTranslation.Add("F", "F");
            downTranslation.Add("Fi", "Fi");

            downTranslation.Add("B", "B");
            downTranslation.Add("Bi", "Bi");
            downTranslation.Add("L", "L");
            downTranslation.Add("Li", "Li");
            downTranslation.Add("D", "D");
            downTranslation.Add("Di", "Di");

            downTranslation.Add("X", "X");
            downTranslation.Add("Xi", "Xi");
            downTranslation.Add("Y", "Y");
            downTranslation.Add("Yi", "Yi");
            downTranslation.Add("Z", "Z");
            downTranslation.Add("Zi", "Zi");

            // xInvertedTranslation

            xInvertedTranslation.Add("U", "B");
            xInvertedTranslation.Add("Ui", "Bi");
            xInvertedTranslation.Add("R", "R");
			xInvertedTranslation.Add("Ri", "Ri");
			xInvertedTranslation.Add("F", "U");
			xInvertedTranslation.Add("Fi", "Ui");

			xInvertedTranslation.Add("B", "D");
			xInvertedTranslation.Add("Bi", "Di");
			xInvertedTranslation.Add("L", "L");
			xInvertedTranslation.Add("Li", "Li");
			xInvertedTranslation.Add("D", "F");
			xInvertedTranslation.Add("Di", "Fi");

			xInvertedTranslation.Add("X", "X");
			xInvertedTranslation.Add("Xi", "Xi");
			xInvertedTranslation.Add("Y", "Zi");
			xInvertedTranslation.Add("Yi", "Z");
			xInvertedTranslation.Add("Z", "Y");
			xInvertedTranslation.Add("Zi", "Yi");

			// xTranslation

			xTranslation.Add("U", "F");
			xTranslation.Add("Ui", "Fi");
			xTranslation.Add("R", "R");
			xTranslation.Add("Ri", "Ri");
			xTranslation.Add("F", "D");
			xTranslation.Add("Fi", "Di");

			xTranslation.Add("B", "U");
			xTranslation.Add("Bi", "Ui");
			xTranslation.Add("L", "L");
			xTranslation.Add("Li", "Li");
			xTranslation.Add("D", "B");
			xTranslation.Add("Di", "Bi");

			xTranslation.Add("X", "X");
			xTranslation.Add("Xi", "Xi");
			xTranslation.Add("Y", "Z");
			xTranslation.Add("Yi", "Zi");
			xTranslation.Add("Z", "Yi");
			xTranslation.Add("Zi", "Y");

            // yInvertedTranslation

            yInvertedTranslation.Add("U", "U");
            yInvertedTranslation.Add("Ui", "Ui");
            yInvertedTranslation.Add("R", "F");
            yInvertedTranslation.Add("Ri", "Fi");
            yInvertedTranslation.Add("F", "L");
            yInvertedTranslation.Add("Fi", "Li");

            yInvertedTranslation.Add("B", "R");
            yInvertedTranslation.Add("Bi", "Ri");
            yInvertedTranslation.Add("L", "B");
            yInvertedTranslation.Add("Li", "Bi");
            yInvertedTranslation.Add("D", "D");
            yInvertedTranslation.Add("Di", "Di");

            yInvertedTranslation.Add("X", "Z");
            yInvertedTranslation.Add("Xi", "Zi");
            yInvertedTranslation.Add("Y", "Y");
            yInvertedTranslation.Add("Yi", "Yi");
            yInvertedTranslation.Add("Z", "Xi");
            yInvertedTranslation.Add("Zi", "X");

			// yTranslation

			yTranslation.Add("U", "U");
			yTranslation.Add("Ui", "Ui");
			yTranslation.Add("R", "B");
			yTranslation.Add("Ri", "Bi");
			yTranslation.Add("F", "R");
			yTranslation.Add("Fi", "Ri");

			yTranslation.Add("B", "L");
			yTranslation.Add("Bi", "Li");
			yTranslation.Add("L", "F");
			yTranslation.Add("Li", "Fi");
			yTranslation.Add("D", "D");
			yTranslation.Add("Di", "Di");

			yTranslation.Add("X", "Zi");
			yTranslation.Add("Xi", "Z");
			yTranslation.Add("Y", "Y");
			yTranslation.Add("Yi", "Yi");
			yTranslation.Add("Z", "X");
			yTranslation.Add("Zi", "Xi");

			// zInvertedTranslation

			zInvertedTranslation.Add("U", "R");
			zInvertedTranslation.Add("Ui", "Ri");
			zInvertedTranslation.Add("R", "D");
			zInvertedTranslation.Add("Ri", "Di");
			zInvertedTranslation.Add("F", "F");
			zInvertedTranslation.Add("Fi", "Fi");

			zInvertedTranslation.Add("B", "B");
			zInvertedTranslation.Add("Bi", "Bi");
			zInvertedTranslation.Add("L", "U");
			zInvertedTranslation.Add("Li", "Ui");
			zInvertedTranslation.Add("D", "L");
			zInvertedTranslation.Add("Di", "Li");

			zInvertedTranslation.Add("X", "Yi");
			zInvertedTranslation.Add("Xi", "Y");
			zInvertedTranslation.Add("Y", "X");
			zInvertedTranslation.Add("Yi", "Xi");
			zInvertedTranslation.Add("Z", "Z");
			zInvertedTranslation.Add("Zi", "Zi");

			// zTranslation

			zTranslation.Add("U", "L");
			zTranslation.Add("Ui", "Li");
			zTranslation.Add("R", "U");
			zTranslation.Add("Ri", "Ui");
			zTranslation.Add("F", "F");
			zTranslation.Add("Fi", "Fi");

			zTranslation.Add("B", "B");
			zTranslation.Add("Bi", "Bi");
			zTranslation.Add("L", "D");
			zTranslation.Add("Li","Di");
			zTranslation.Add("D", "R");
			zTranslation.Add("Di", "Ri");

			zTranslation.Add("X", "Y");
			zTranslation.Add("Xi", "Yi");
			zTranslation.Add("Y", "Xi");
			zTranslation.Add("Yi", "X");
			zTranslation.Add("Z", "Z");
			zTranslation.Add("Zi", "Zi");


        }


    }
}
