using System;
using System.Collections.Generic;
using System.Text;

namespace _07_28
{
    class Q11
    {
        static void Main(string[] args)
        {
            Console.Write("num : ");
            int num = int.Parse(Console.ReadLine());
            Console.WriteLine();

            Console.WriteLine(Solution(num));
        }

        static int Solution(int num)
        {
            int result = 0;
            char[] cArrNum = num.ToString().ToCharArray();

            for (int i = 0; i < cArrNum.Length; i++)
            {
                result += cArrNum[i] - '0';
            }

            return result;
        }
    }
}