using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HandSolve_Translator
{
    public class LoadDictionaries
    {
        public void FirstTranslation()
        {
            Dictionary<string, string> dictFirstTranslation = new Dictionary<string, string>();
            dictFirstTranslation.Add("M", "R Li Xi");
            dictFirstTranslation.Add("Mi", "Ri L X");
            dictFirstTranslation.Add("E", "U Di Yi");
            dictFirstTranslation.Add("Ei", "Ui D Y");
            dictFirstTranslation.Add("S", "Fi B Z");
            dictFirstTranslation.Add("Si", "F Bi Zi");

            dictFirstTranslation.Add("u", "D y");
            dictFirstTranslation.Add("l", "R Xi");
            dictFirstTranslation.Add("f", "B Z");
            dictFirstTranslation.Add("r", "L X");
            dictFirstTranslation.Add("b", "F Zi");
            dictFirstTranslation.Add("d", "U Yi");

            dictFirstTranslation.Add("ui", "Di Yi");
            dictFirstTranslation.Add("li", "Ri X");
            dictFirstTranslation.Add("fi", "Bi Zi");
            dictFirstTranslation.Add("ri", "Li Xi");
            dictFirstTranslation.Add("bi", "Fi Z");
            dictFirstTranslation.Add("di", "Ui Y");
        }


    }
}
