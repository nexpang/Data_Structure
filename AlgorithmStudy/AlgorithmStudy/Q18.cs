using System;
using System.Collections.Generic;
using System.Text;

namespace _07_28
{
    class Q18
    {
        static void Main(string[] args)
        {
            Console.Write("string : ");
            string s = Console.ReadLine();
            Console.WriteLine();

            Console.WriteLine(Solution(s));
        }

        static string Solution(string s)
        {
            char[] cArr = s.ToCharArray();

            return s.Length % 2 == 0 ? cArr[(s.Length / 2) - 1] + "" + cArr[(s.Length / 2)] : cArr[(s.Length) / 2] + "";
        }
    }
}