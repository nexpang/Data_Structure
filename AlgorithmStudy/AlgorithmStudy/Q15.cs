using System;
using System.Collections.Generic;
using System.Text;

namespace _07_28
{
    class Q15
    {
        static void Main(string[] args)
        {
            Console.Write("num : ");
            int n = int.Parse(Console.ReadLine());
            Console.WriteLine();

            Console.WriteLine(Solution(n));
        }

        static string Solution(int n)
        {
            string result = "";


            for (int i = 0; i < n; i++)
            {
                result += i % 2 == 0 ? "수" : "박";
            }

            return result;
        }
    }
}