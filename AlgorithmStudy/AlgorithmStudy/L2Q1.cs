using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _07_28
{
    class L2Q1
    {
        static void Main(string[] args)
        {
            string s = "hLow aSd asd";

            Console.WriteLine(Solution(s));
        }

        static string Solution(string s)
        {
            string[] sArr = s.Split(' ');

            for (int i = 0; i < sArr.Length; i++)
            {
                for (int j = 0; j < sArr[i].Length; j++)
                {
                    if(j==0)
                    {
                        sArr[i] = sArr[i].Replace(sArr[i][j], char.Parse(sArr[i][j].ToString().ToUpper()));
                    }
                    else
                    {
                        sArr[i] = sArr[i].Replace(sArr[i][j], char.Parse(sArr[i][j].ToString().ToLower()));
                    }
                }
            }

            return string.Join("", sArr);
        }
    }
}