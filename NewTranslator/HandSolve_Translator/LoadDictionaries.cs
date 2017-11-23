using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HandSolve_Translator
{
    public class LoadDictionaries
    {
		Dictionary<string, Dictionary<string, string>> dictFirstTranslation = new Dictionary<string, Dictionary<string, string>>();
		Dictionary<string, string> upperTranslation = new Dictionary<string, string>();
		Dictionary<string, string> rightTranslation = new Dictionary<string, string>();
		Dictionary<string, string> frontTranslation = new Dictionary<string, string>();
		Dictionary<string, string> backTranslation = new Dictionary<string, string>();
		Dictionary<string, string> leftTranslation = new Dictionary<string, string>();
		Dictionary<string, string> xTranslation = new Dictionary<string, string>();
		Dictionary<string, string> xInvertedTranslation = new Dictionary<string, string>();
		Dictionary<string, string> yTranslation = new Dictionary<string, string>();
		Dictionary<string, string> yInvertedTranslation = new Dictionary<string, string>();
		Dictionary<string, string> zTranslation = new Dictionary<string, string>();
		Dictionary<string, string> zInvertedTranslation = new Dictionary<string, string>();

        public void FirstTranslation()
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

            dictFirstTranslation.Add("X", xTranslation);
            dictFirstTranslation.Add("Xi", xInvertedTranslation);
            dictFirstTranslation.Add("Y", yTranslation);
            dictFirstTranslation.Add("Yi", yInvertedTranslation);
            dictFirstTranslation.Add("Z", zTranslation);
            dictFirstTranslation.Add("Zi", zInvertedTranslation);


			// upperTranslation
			upperTranslation.Add("U", "test");
			upperTranslation.Add("Ui",);
			upperTranslation.Add("R",);
			upperTranslation.Add("Ri",);
			upperTranslation.Add("F", );
			upperTranslation.Add("Fi", );

			upperTranslation.Add("B", );
			upperTranslation.Add("Bi", );
			upperTranslation.Add("L", );
			upperTranslation.Add("Li", );
			upperTranslation.Add("D", );
			upperTranslation.Add("Di", );

			upperTranslation.Add("X", );
			upperTranslation.Add("Xi", );
			upperTranslation.Add("Y", );
			upperTranslation.Add("Yi", );
			upperTranslation.Add("Z", );
			upperTranslation.Add("Zi", );

			// rightTranslation
			rightTranslation.Add("U", "");
			rightTranslation.Add("Ui", "");
			rightTranslation.Add("R", "");
			rightTranslation.Add("Ri",);
			rightTranslation.Add("F",);
			rightTranslation.Add("Fi",);

			rightTranslation.Add("B",);
			rightTranslation.Add("Bi",);
			rightTranslation.Add("L",);
			rightTranslation.Add("Li",);
			rightTranslation.Add("D",);
			rightTranslation.Add("Di",);

			rightTranslation.Add("X",);
			rightTranslation.Add("Xi",);
			rightTranslation.Add("Y",);
			rightTranslation.Add("Yi",);
			rightTranslation.Add("Z",);
			rightTranslation.Add("Zi",);

			// frontTranslation
			frontTranslation.Add("U", "");
			frontTranslation.Add("Ui", "");
			frontTranslation.Add("R", "");
			frontTranslation.Add("Ri",);
			frontTranslation.Add("F",);
			frontTranslation.Add("Fi",);

			frontTranslation.Add("B",);
			frontTranslation.Add("Bi",);
			frontTranslation.Add("L",);
			frontTranslation.Add("Li",);
			frontTranslation.Add("D",);
			frontTranslation.Add("Di",);

			frontTranslation.Add("X",);
			frontTranslation.Add("Xi",);
			frontTranslation.Add("Y",);
			frontTranslation.Add("Yi",);
			frontTranslation.Add("Z",);
			frontTranslation.Add("Zi",);

			// backTranslation

			backTranslation.Add("U", "");
			backTranslation.Add("Ui", "");
			backTranslation.Add("R", "");
			backTranslation.Add("Ri",);
			backTranslation.Add("F",);
			backTranslation.Add("Fi",);

			backTranslation.Add("B",);
			backTranslation.Add("Bi",);
			backTranslation.Add("L",);
			backTranslation.Add("Li",);
			backTranslation.Add("D",);
			backTranslation.Add("Di",);

			backTranslation.Add("X",);
			backTranslation.Add("Xi",);
			backTranslation.Add("Y",);
			backTranslation.Add("Yi",);
			backTranslation.Add("Z",);
			backTranslation.Add("Zi",);

			// leftTranslation

			leftTranslation.Add("U", "");
			leftTranslation.Add("Ui", "");
			leftTranslation.Add("R", "");
			leftTranslation.Add("Ri",);
			leftTranslation.Add("F",);
			leftTranslation.Add("Fi",);

			leftTranslation.Add("B",);
			leftTranslation.Add("Bi",);
			leftTranslation.Add("L",);
			leftTranslation.Add("Li",);
			leftTranslation.Add("D",);
			leftTranslation.Add("Di",);

			leftTranslation.Add("X",);
			leftTranslation.Add("Xi",);
			leftTranslation.Add("Y",);
			leftTranslation.Add("Yi",);
			leftTranslation.Add("Z",);
			leftTranslation.Add("Zi",);

			// xTranslation

			xTranslation.Add("U", "");
			xTranslation.Add("Ui", "");
			xTranslation.Add("R", "");
			xTranslation.Add("Ri",);
			xTranslation.Add("F",);
			xTranslation.Add("Fi",);

			xTranslation.Add("B",);
			xTranslation.Add("Bi",);
			xTranslation.Add("L",);
			xTranslation.Add("Li",);
			xTranslation.Add("D",);
			xTranslation.Add("Di",);

			xTranslation.Add("X",);
			xTranslation.Add("Xi",);
			xTranslation.Add("Y",);
			xTranslation.Add("Yi",);
			xTranslation.Add("Z",);
			xTranslation.Add("Zi",);

			// xInvetedTranslation

			xInvertedTranslation.Add("U", "");
			xInvertedTranslation.Add("Ui", "");
			xInvertedTranslation.Add("R", "");
			xInvertedTranslation.Add("Ri",);
			xInvertedTranslation.Add("F",);
			xInvertedTranslation.Add("Fi",);

			xInvertedTranslation.Add("B",);
			xInvertedTranslation.Add("Bi",);
			xInvertedTranslation.Add("L",);
			xInvertedTranslation.Add("Li",);
			xInvertedTranslation.Add("D",);
			xInvertedTranslation.Add("Di",);

			xInvertedTranslation.Add("X",);
			xInvertedTranslation.Add("Xi",);
			xInvertedTranslation.Add("Y",);
			xInvertedTranslation.Add("Yi",);
			xInvertedTranslation.Add("Z",);
			xInvertedTranslation.Add("Zi",);

			// yTranslation

			yTranslation.Add("U", "");
			yTranslation.Add("Ui", "");
			yTranslation.Add("R", "");
			yTranslation.Add("Ri",);
			yTranslation.Add("F",);
			yTranslation.Add("Fi",);

			yTranslation.Add("B",);
			yTranslation.Add("Bi",);
			yTranslation.Add("L",);
			yTranslation.Add("Li",);
			yTranslation.Add("D",);
			yTranslation.Add("Di",);

			yTranslation.Add("X",);
			yTranslation.Add("Xi",);
			yTranslation.Add("Y",);
			yTranslation.Add("Yi",);
			yTranslation.Add("Z",);
			yTranslation.Add("Zi",);

			// yInvertedTranslation

			yInvertedTranslation.Add("U", "");
			yInvertedTranslation.Add("Ui", "");
			yInvertedTranslation.Add("R", "");
			yInvertedTranslation.Add("Ri",);
			yInvertedTranslation.Add("F",);
			yInvertedTranslation.Add("Fi",);

			yInvertedTranslation.Add("B",);
			yInvertedTranslation.Add("Bi",);
			yInvertedTranslation.Add("L",);
			yInvertedTranslation.Add("Li",);
			yInvertedTranslation.Add("D",);
			yInvertedTranslation.Add("Di",);

			yInvertedTranslation.Add("X",);
			yInvertedTranslation.Add("Xi",);
			yInvertedTranslation.Add("Y",);
			yInvertedTranslation.Add("Yi",);
			yInvertedTranslation.Add("Z",);
			yInvertedTranslation.Add("Zi",);

			// zTranslation

			zTranslation.Add("U", "");
			zTranslation.Add("Ui", "");
			zTranslation.Add("R", "");
			zTranslation.Add("Ri",);
			zTranslation.Add("F",);
			zTranslation.Add("Fi",);

			zTranslation.Add("B",);
			zTranslation.Add("Bi",);
			zTranslation.Add("L",);
			zTranslation.Add("Li",);
			zTranslation.Add("D",);
			zTranslation.Add("Di",);

			zTranslation.Add("X",);
			zTranslation.Add("Xi",);
			zTranslation.Add("Y",);
			zTranslation.Add("Yi",);
			zTranslation.Add("Z",);
			zTranslation.Add("Zi",);

			// zInvertedTranslation

			zInvertedTranslation.Add("U", "");
			zInvertedTranslation.Add("Ui", "");
			zInvertedTranslation.Add("R", "");
			zInvertedTranslation.Add("Ri",);
			zInvertedTranslation.Add("F",);
			zInvertedTranslation.Add("Fi",);

			zInvertedTranslation.Add("B",);
			zInvertedTranslation.Add("Bi",);
			zInvertedTranslation.Add("L",);
			zInvertedTranslation.Add("Li",);
			zInvertedTranslation.Add("D",);
			zInvertedTranslation.Add("Di",);

			zInvertedTranslation.Add("X",);
			zInvertedTranslation.Add("Xi",);
			zInvertedTranslation.Add("Y",);
			zInvertedTranslation.Add("Yi",);
			zInvertedTranslation.Add("Z",);
			zInvertedTranslation.Add("Zi",);


        }


    }
}
