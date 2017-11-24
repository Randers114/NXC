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
			upperTranslation.Add("D", "F");
			upperTranslation.Add("Di", "Fi");

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
			leftTranslation.Add("Y", "Z");
			leftTranslation.Add("Yi", "Zi");
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

            // xTranslation

            xTranslation.Add("U", "B");
			xTranslation.Add("Ui", "Bi");
			xTranslation.Add("R", "R");
			xTranslation.Add("Ri", "Ri");
			xTranslation.Add("F", "U");
			xTranslation.Add("Fi", "Ui");

			xTranslation.Add("B", "D");
			xTranslation.Add("Bi", "Di");
			xTranslation.Add("L", "L");
			xTranslation.Add("Li", "Li");
			xTranslation.Add("D", "F");
			xTranslation.Add("Di", "Fi");

			xTranslation.Add("X", "X");
			xTranslation.Add("Xi", "Xi");
			xTranslation.Add("Y", "Zi");
			xTranslation.Add("Yi", "Z");
			xTranslation.Add("Z", "Y");
			xTranslation.Add("Zi", "Yi");

			// xInvetedTranslation

			xInvertedTranslation.Add("U", "F");
			xInvertedTranslation.Add("Ui", "Fi");
			xInvertedTranslation.Add("R", "R");
			xInvertedTranslation.Add("Ri", "Ri");
			xInvertedTranslation.Add("F", "D");
			xInvertedTranslation.Add("Fi", "Di");

			xInvertedTranslation.Add("B", "U");
			xInvertedTranslation.Add("Bi", "Ui");
			xInvertedTranslation.Add("L", "L");
			xInvertedTranslation.Add("Li", "Li");
			xInvertedTranslation.Add("D", "B");
			xInvertedTranslation.Add("Di", "Bi");

			xInvertedTranslation.Add("X", "X");
			xInvertedTranslation.Add("Xi", "Xi");
			xInvertedTranslation.Add("Y", "Z");
			xInvertedTranslation.Add("Yi", "Zi");
			xInvertedTranslation.Add("Z", "Yi");
			xInvertedTranslation.Add("Zi", "Y");

			// yTranslation

			yTranslation.Add("U", "U");
			yTranslation.Add("Ui", "Ui");
			yTranslation.Add("R", "F");
			yTranslation.Add("Ri", "Fi");
			yTranslation.Add("F", "L");
			yTranslation.Add("Fi", "Li");

			yTranslation.Add("B", "R");
			yTranslation.Add("Bi", "Ri");
			yTranslation.Add("L", "B");
			yTranslation.Add("Li", "Bi");
			yTranslation.Add("D", "D");
			yTranslation.Add("Di", "Di");

			yTranslation.Add("X", "Z");
			yTranslation.Add("Xi", "Zi");
			yTranslation.Add("Y", "Y");
			yTranslation.Add("Yi", "Yi");
			yTranslation.Add("Z", "Xi");
			yTranslation.Add("Zi", "X");

			// yInvertedTranslation

			yInvertedTranslation.Add("U", "U");
			yInvertedTranslation.Add("Ui", "Ui");
			yInvertedTranslation.Add("R", "B");
			yInvertedTranslation.Add("Ri", "Bi");
			yInvertedTranslation.Add("F", "R");
			yInvertedTranslation.Add("Fi", "Ri");

			yInvertedTranslation.Add("B", "L");
			yInvertedTranslation.Add("Bi", "Li");
			yInvertedTranslation.Add("L", "F");
			yInvertedTranslation.Add("Li", "Fi");
			yInvertedTranslation.Add("D", "D");
			yInvertedTranslation.Add("Di", "Di");

			yInvertedTranslation.Add("X", "Zi");
			yInvertedTranslation.Add("Xi", "Z");
			yInvertedTranslation.Add("Y", "Y");
			yInvertedTranslation.Add("Yi", "Yi");
			yInvertedTranslation.Add("Z", "X");
			yInvertedTranslation.Add("Zi", "Xi");

			// zTranslation

			zTranslation.Add("U", "R");
			zTranslation.Add("Ui", "Ri");
			zTranslation.Add("R", "D");
			zTranslation.Add("Ri", "Di");
			zTranslation.Add("F", "F");
			zTranslation.Add("Fi", "Fi");

			zTranslation.Add("B", "B");
			zTranslation.Add("Bi", "Bi");
			zTranslation.Add("L", "U");
			zTranslation.Add("Li", "Ui");
			zTranslation.Add("D", "L");
			zTranslation.Add("Di", "Li");

			zTranslation.Add("X", "Yi");
			zTranslation.Add("Xi", "Y");
			zTranslation.Add("Y", "X");
			zTranslation.Add("Yi", "Xi");
			zTranslation.Add("Z", "Z");
			zTranslation.Add("Zi", "Zi");

			// zInvertedTranslation

			zInvertedTranslation.Add("U", "L");
			zInvertedTranslation.Add("Ui", "Li");
			zInvertedTranslation.Add("R", "U");
			zInvertedTranslation.Add("Ri", "Ui");
			zInvertedTranslation.Add("F", "F");
			zInvertedTranslation.Add("Fi", "Fi");

			zInvertedTranslation.Add("B", "B");
			zInvertedTranslation.Add("Bi", "Bi");
			zInvertedTranslation.Add("L", "D");
			zInvertedTranslation.Add("Li","Di");
			zInvertedTranslation.Add("D", "R");
			zInvertedTranslation.Add("Di", "Ri");

			zInvertedTranslation.Add("X", "Y");
			zInvertedTranslation.Add("Xi", "Yi");
			zInvertedTranslation.Add("Y", "Xi");
			zInvertedTranslation.Add("Yi", "X");
			zInvertedTranslation.Add("Z", "Z");
			zInvertedTranslation.Add("Zi", "Zi");


        }


    }
}
