using System;
using System.Collections.Generic;
using System.Text;

namespace _07_28
{
    class Q17
    {
        static void Main(string[] args)
        {
            Console.Write("string : ");
            string s = Console.ReadLine();
            Console.WriteLine();

            Console.WriteLine(Solution(s));
        }

        static bool Solution(string s)
        {
            if(s.Length != 4 && s.Length!=6)
            {
                return false;
            }
            else
            {
                char[] cArr = s.ToCharArray();
                for (int i = 0; i < cArr.Length; i++)
                {
                    if(cArr[i] < '0' || cArr[i] > '9')
                    {
                        Console.WriteLine("asd");
                        return false;
                    }
                }
            }

            return true;
        }
    }
}