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

            dictFirstTranslation.Add("u", "");
            dictFirstTranslation.Add("l", "");
            dictFirstTranslation.Add("f", "");
            dictFirstTranslation.Add("r", "");
            dictFirstTranslation.Add("b", "");
            dictFirstTranslation.Add("d", "");

            dictFirstTranslation.Add("ui", "");
            dictFirstTranslation.Add("li", "");
            dictFirstTranslation.Add("fi", "");
            dictFirstTranslation.Add("ri", "");
            dictFirstTranslation.Add("bi", "");
            dictFirstTranslation.Add("di", "");
        }


    }
}
