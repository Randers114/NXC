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
            dictFirstTranslation.Add("D", downTranslation);
            dictFirstTranslation.Add("Di", downTranslation);

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

        }


    }
}
