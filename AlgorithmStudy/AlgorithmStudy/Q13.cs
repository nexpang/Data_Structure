using System;
using System.Collections.Generic;
using System.Text;

namespace _07_28
{
    class Q13
    {
        static void Main(string[] args)
        {
            Console.Write("string : ");
            string s = Console.ReadLine();
            if(s.Length > 8000) { Console.WriteLine("잘못된 값를 입력했습니다."); return; }
            Console.Write("num : ");
            int n = int.Parse(Console.ReadLine());
            if(n < 1||n > 25) { Console.WriteLine("잘못된 수를 입력했습니다."); return; }
            Console.WriteLine();

            Console.WriteLine(Solution(s, n));
        }

        static string Solution(string s, int n)
        {
            char[] cArr = s.ToCharArray();

            for (int i = 0; i < cArr.Length; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (cArr[i] == 'z' || cArr[i] == 'Z')
                    {
                        cArr[i] = Convert.ToChar(cArr[i] - ('z' - 'a'));
                    }
                    else if (cArr[i] != ' ')
                    {
                        cArr[i] = Convert.ToChar(cArr[i] + 1);
                    }
                }
            }
            string result = new string(cArr); // 생성자를 이용한 문자열 변환
            return result;
        }
    }
}