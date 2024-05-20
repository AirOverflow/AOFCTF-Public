using System.Diagnostics;
namespace LOL
{
    using System;
    using System.Security.Cryptography;
    using System.Text;
    class Delirium
    {
        static void Main()
        {
            int randomnum = 0;
            Console.Write("Enter The Flag: ");
            string inputString = Console.ReadLine();
            Console.WriteLine("");
            if (inputString.Length != 36)
            {
                return;
            }
            string xorKey = "AIR";
            int[,] matrixA = new int[6, 6];
            int[,] matrixB = {
            {2, 1, 3, 9, 8, 9},
            {9, 1, 3, 2, 3, 2},
            {7, 0, 8, 0, 8, 9},
            {8, 0, 4, 8, 9, 1},
            {7, 4, 4, 1, 8, 8},
            {7, 6, 9, 5, 4, 7}
        };
            int[,] resultMatrix = new int[6, 6];

            for (int i = 0; i < 36; i++)
            {
                int row = i / 6;
                int col = i % 6;
                matrixA[row, col] = (int)inputString[i] ^ xorKey[i % xorKey.Length];
                randomnum += 1;
            }
            for (int i = 0; i < 6; i++)
            {
                for (int j = 0; j < 6; j++)
                {
                    for (int k = 0; k < 6; k++)
                    {
                        resultMatrix[i, j] += matrixA[i, k] * matrixB[k, j];
                    }
                }
            }
            int[,] checkMatrix = {
            {553, 242, 482, 157, 508, 566},
            {2832, 529, 1736, 1921, 2469, 1651},
            {2833, 1273, 2233, 2177, 3031, 2995},
            {2479, 647, 1432, 1559, 2626, 1723},
            {2131, 627, 1697, 1294, 2043, 1898},
            {4082, 919, 2766, 2020, 3868, 3039}
        };
            bool isEqual = true;
            for (int i = 0; i < 6; i++)
            {
                for (int j = 0; j < 6; j++)
                {
                    if (resultMatrix[i, j] != checkMatrix[i, j])
                    {
                        isEqual = false;
                        break;
                    }
                }
                if (!isEqual)
                    break;
            }
            if (isEqual)
            {
                Console.WriteLine("Not so delirious now, are you?\n");
            }
            if (randomnum == 0)
            {
                string RealHash = "75170fc230cd88f32e475ff4087f81d9";
                string calculatedHash = CalculateMD5(inputString);

                if (calculatedHash == RealHash)
                {
                    Console.WriteLine("Correct");
                }
            }
            return;

        }
        static string CalculateMD5(string input)
        {
            using (MD5 md5 = MD5.Create())
            {
                byte[] inputBytes = Encoding.UTF8.GetBytes(input);
                byte[] hashBytes = md5.ComputeHash(inputBytes);

                StringBuilder sb = new StringBuilder();
                for (int i = 0; i < hashBytes.Length; i++)
                {
                    sb.Append(hashBytes[i].ToString("x2"));
                }
                return sb.ToString();
            }
        }
    }
}