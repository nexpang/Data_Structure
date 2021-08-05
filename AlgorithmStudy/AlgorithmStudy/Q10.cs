using System;
using System.Collections.Generic;
using System.Text;

namespace _07_28
{
    class Q10
    {
        static void Main(string[] args)
        {
            Console.Write("num : ");
            long num = long.Parse(Console.ReadLine());
            Console.WriteLine();

            foreach (int item in solution(num))
            {
                Console.Write(item + " ");
            }

            int[] solution(long num)
            {
                char[] cArrNum = num.ToString().ToCharArray();
                Array.Reverse(cArrNum);

                int[] arr = new int[cArrNum.Length];
                for (int i = 0; i < cArrNum.Length; i++)
                {
                    arr[i] = cArrNum[i]-'0';
                }

                return arr;
            }
        }
    }
}