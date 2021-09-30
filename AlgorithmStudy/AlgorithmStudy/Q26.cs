using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _07_28
{
    class Q26
    {
        static void Main(string[] args)
        {
            string s = "onetwo3fourseven12nine3";
            Console.WriteLine();

            Console.WriteLine(Solution(s));
        }

        static string Solution(string s)
        {
            Dictionary<string, string> dic = new Dictionary<string, string>()
            {
                {"one", "1"},
                {"two", "2"},
                {"three", "3"},
                {"four", "4"},
                {"five", "5"},
                {"six", "6"},
                {"seven", "7"},
                {"eight", "8"},
                {"nine", "9"},
                {"zero", "0"}
            };

            string result = "";
            char cTemp;
            string sTemp = "";
            string sValue;

            for (int i = 0; i < s.Length; i++)
            {
                cTemp = s[i];
                sTemp += cTemp;
                if (s[i] >= '0' && s[i] <= '9')
                {
                    result += cTemp;
                    sTemp = "";
                }
                else if (dic.TryGetValue(sTemp, out sValue))
                {
                    //Console.WriteLine(temp);
                    result += sValue;
                    sTemp = "";
                }
            }

            return result;
        }
    }
}