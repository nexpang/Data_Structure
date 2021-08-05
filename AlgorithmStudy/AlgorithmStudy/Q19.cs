using System;
using System.Collections.Generic;
using System.Text;

namespace _07_28
{
    class Q19
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
            Array.Sort(cArr);
            Array.Reverse(cArr);

            string result = new string(cArr); // 생성자를 이용한 문자열 변환

            return result;
        }
    }
}