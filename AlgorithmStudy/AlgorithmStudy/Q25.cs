using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _07_28
{
    class Q25
    {
        static void Main(string[] args)
        {
            Random rand = new Random();
            int n = rand.Next(2, 11);
            int[] lost = new int[rand.Next(1, n+1)];
            int[] reserve = new int[rand.Next(1, n+1-lost.Length)];
            for (int i = 0; i < lost.Length; i++)
            {
                bool overlap;
                do
                {
                    overlap = false;
                    lost[i] = rand.Next(1, n+1);
                    for (int j = 0; j < i; j++)
                    {
                        if(lost[i] == lost[j])
                        {
                            overlap = true;
                        }
                    }
                } while (overlap);
            }
            for (int i = 0; i < reserve.Length; i++)
            {
                bool overlap;
                do
                {
                    overlap = false;
                    reserve[i] = rand.Next(1, n+1);
                    for (int k = 0; k < lost.Length; k++)
                    {
                        if (lost[k] == reserve[i])
                        {
                            overlap = true;
                            break;
                        }
                    }
                    for (int j = 0; j < i; j++)
                    {
                        if (reserve[i] == reserve[j])
                        {
                            overlap = true;
                        }
                    }
                } while (overlap);
            }
            Console.WriteLine("n: "+ n);
            Console.Write("lost: ");
            foreach (var item in lost)
            {
                Console.Write(item+" ");
            }
            Console.WriteLine();
            Console.Write("reserve: ");
            foreach (var item in reserve)
            {
                Console.Write(item+ " ");
            }
            Console.WriteLine();

            Console.WriteLine(Solution(n, lost, reserve));
        }

        static int Solution(int n, int[] lost, int[] reserve)
        {
            int result = 0;
            bool[] have = new bool[n];
            for (int i = 0; i < n; i++)
            {
                bool bLost = false;
                for (int j = 0; j < lost.Length; j++)
                {
                    if(i == lost[j]-1)
                    {
                        bLost = true;
                    }
                }
                have[i] = !bLost;
            }

            Console.WriteLine("before");
            for (int i = 0; i < n; i++)
            {
                bool b = false;
                for (int j = 0; j < reserve.Length; j++)
                {
                    if (i == reserve[j]-1)
                    {
                        Console.Write("◎");
                        b = true;
                        break;
                    }
                }
                if(!b)
                {
                    if (have[i])
                    {
                        Console.Write("○");
                    }
                    else
                    {
                        Console.Write("※");
                    }
                }
            }

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < reserve.Length; j++)
                {
                    if(i == reserve[j]-1)
                    {
                        if(i<1)
                        {
                            if(!have[i + 1])
                            {
                                have[i + 1] = true;
                                reserve[j] = -1;
                            }
                        }
                        else if (i > n-2)
                        {
                            if (!have[i - 1])
                            {
                                have[i - 1] = true;
                                reserve[j] = -1;
                            }
                        }
                        else
                        {
                            if (!have[i - 1])
                            {
                                have[i - 1] = true;
                                reserve[j] = -1;
                            }
                            else if (!have[i + 1])
                            {
                                have[i + 1] = true;
                                reserve[j] = -1;
                            }
                        }
                        break;
                    }
                }
            }

            Console.WriteLine();
            Console.WriteLine("after");
            for (int i = 0; i < n; i++)
            {
                if (have[i])
                {
                    Console.Write("○");
                    result++;
                }
                else
                {
                    Console.Write("※");
                }
            }
            Console.WriteLine();

            return result;
        }
    }
}