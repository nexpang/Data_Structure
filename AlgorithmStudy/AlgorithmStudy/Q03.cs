using System;
using System.Collections.Generic;
using System.Text;

namespace _07_28
{
    class Q03
    {
        static void Main(string[] args)
        {
            string phone_number = Console.ReadLine();

            Console.WriteLine(SeceretPhoneNumber(phone_number));

            string SeceretPhoneNumber(string phone_number)
            {
                if (phone_number.Length < 4 || phone_number.Length > 20) return "잘못된 전화번호 입니다.";

                int phone_number_length = phone_number.Length - 4;

                string phone_number_back = phone_number.Substring(phone_number_length);

                string seceretPhone = "";

                for (int i = 0; i < phone_number_length; i++)
                {
                    seceretPhone+="*";
                }

                seceretPhone+=phone_number_back;

                return seceretPhone;
            }
        }
    }
}