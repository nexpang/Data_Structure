using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _07_28
{
    class Q21
    {
        static void Main(string[] args)
        {
            int[] numbers = { 0, 1, 3 };

            Console.WriteLine(Solution(numbers));
        }

        static int Solution(int[] numbers)
        {
            Random rand = new Random();
            int randN1 = rand.Next(0, numbers.Length);
            int randN2 = rand.Next(0, numbers.Length);

            while(randN1 == randN2)
            {
                randN2 = rand.Next(0, numbers.Length);
            }

            return numbers[randN1] + numbers[randN2];
        }
    }
}