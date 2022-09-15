using System;
using System.Collections.Generic;

namespace Generic
{
    // Generic Programming
    // what : C++의 template 유사하게 데이터 유형을 정한다.
    // when : 코드의 재사용, 형식의 안정성, 다양한 유형의 데이터에 대해 동작을 정의할 때 사용한다.

    public class Tester
    {
        public static void Test()
        {
            int a = 4;
            int b = 5;

            Console.WriteLine(" a : {0}, b : {1}", a,b);

            GenericUtility.Swap<int>(ref a, ref b);

            Console.WriteLine(" a : {0}, b : {1}", a, b);
        }
    }

    public class GenericUtility
    {
        public static void Swap<T> (ref T source1, ref T source2)
        {
            T temp;
            temp = source1;
            source1 = source2;
            source2 = temp;

            return;
        }
    }
}