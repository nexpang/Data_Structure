using System;
using System.Collections.Generic;
using System.Text;

namespace _07_28
{
    class Q12
    {
        static void Main(string[] args)
        {
            Console.Write("num1 : ");
            int num1 = int.Parse(Console.ReadLine());
            Console.Write("num2 : ");
            int num2 = int.Parse(Console.ReadLine());
            Console.WriteLine();

            Console.WriteLine(Solution(num1, num2));
        }

        static int Solution(int num1, int num2)
        {
            int result = 0;

            for (int i = num1; i <= num2; i++)
            {
                result += i;
            }

            return result;
        }
    }
}