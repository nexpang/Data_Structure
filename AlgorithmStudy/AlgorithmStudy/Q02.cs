using System;
using System.Collections.Generic;
using System.Text;

namespace _07_28
{
    class Q02
    {
        static void Main(string[] args)
        {
            Console.Write("num :");
            int num = int.Parse(Console.ReadLine());
            Console.WriteLine(ABS(num));

            string ABS(int num)
            {
                if(num % 2 == 0)
                {
                    return "Even";
                }
                else
                {
                    return "Odd";
                }
            }
        }
    }
}
