using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _07_28
{
    class Q20
    {
        static void Main(string[] args)
        {
            List<string> list = new List<string>();
            for (int i = 0; i < 3; i++)
            {
                Console.Write("string"+(i+1)+" : ");
                list.Add(Console.ReadLine());
            }
            Console.Write("num : ");
            int n = int.Parse(Console.ReadLine());
            Console.WriteLine();

            Solution(list, n);
        }

        static void Solution(List<string> sList, int n)
        {
            int[] nArr = new int[sList.Count];
            var list = sList.OrderBy(x => x[n]);

            foreach (var item in list)
            {
                Console.Write(item + " ");
            }
        }
    }
}