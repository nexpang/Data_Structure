using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _07_28
{
    class Q22
    {
        static void Main(string[] args)
        {
            string s = Console.ReadLine();

            Console.WriteLine(Solution(s));
        }

        static string Solution(string s)
        {
            char[] cArr = s.ToCharArray();
            string[] result = new string[s.Length];
            int idx = 0;
            bool nextWord = false;

            for (int i = 0; i < cArr.Length; i++)
            {
                if(cArr[i]==' ')
                {
                    nextWord = true;
                    result[i] = " ";
                }
                else
                {
                    if (nextWord)
                    {
                        nextWord = false;
                        idx++;
                    }

                    result[i] = idx % 2 == 0 ? cArr[i].ToString().ToUpper() : cArr[i].ToString().ToLower();
                }
            }

            return string.Join("", result);
        }
    }
}