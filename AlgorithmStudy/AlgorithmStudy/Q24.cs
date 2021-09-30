using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _07_28
{
    class Q24
    {
        static void Main(string[] args)
        {
            Random rand = new Random();
            int[] answers = new int[rand.Next(1, 10001)];
            for (int i = 0; i < answers.Length; i++)
            {
                answers[i] = rand.Next(1, 6);
            }
            Console.WriteLine();

            foreach (string item in Solution(answers))
            {
                Console.WriteLine(item);
            }
        }

        static string[] Solution(int[] answers)
        {
            int one = 0, two = 0, three = 0;
            for (int i = 0; i < answers.Length; i++)
            {
                if (answers[i]== (i%5)+1)
                {
                    one++;
                }
                if (answers[i] == (i % 2 == 0 ? 2 : i + 1))
                {
                    two++;
                }
                if(answers[i] == (i % 10 <= 1 ? 3 : i % 10 <= 3 ? 1 : i % 10 <= 5 ? 2 : i % 10 <= 7 ? 4 : 5))
                {
                    three++;
                }
            }

            float max = MathF.Max(one, MathF.Max(two, three));
            string[] result = new string[3];
            int count = 0;

            if(max == one)
            {
                result[count] = "1번 수포자";
                count++;
            }
            if (max == two)
            {
                result[count] = "2번 수포자";
                count++;
            }
            if (max == three)
            {
                result[count] = "3번 수포자";
                count++;
            }


            return result;
        }
    }
}