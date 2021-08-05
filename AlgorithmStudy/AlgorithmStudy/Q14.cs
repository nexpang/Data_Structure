using System;
using System.Collections.Generic;
using System.Text;

namespace _07_28
{
    class Q14
    {
        static void Main(string[] args)
        {
            Console.Write("string : ");
            string s = Console.ReadLine();
            if(s.Length<1||s.Length > 5) { Console.WriteLine("잘못된 값를 입력했습니다."); return; }
            Console.WriteLine();

            Console.WriteLine(Solution(s));
        }

        static int Solution(string s)
        {
            char[] cArr = s.ToCharArray();
            string result = "";

            for (int i = 0; i < cArr.Length; i++)
            {
                result += (cArr[i]+0);
            }
            
            return int.Parse(result);
        }
    }
}