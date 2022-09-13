using System;

namespace Delegate
{
    // Delegate
    // What : 리턴값과 매개변수의 형식, 개수가 맞는 함수를 바인딩 하는 레퍼런스 변수.
    // When : 일반적으로 다른 메서드의 매개변수로 메서드를 보내고 싶을 때 사용, OnEventX delegate 형식의 특징을 사용함. 
    // why  : interface를 통해서, 메서드 하나를 사용하기 위해 상속된 객체 전체를 가져오는 것보다, delegate로 메서드만 레퍼런스 하는 것이 훨씬 간결하다.

    // p.s : struct도 생성자가 필요 - c#
    struct int2
    {
        public int2(int x, int y)
        {
            this.x = x;
            this.y = y;
        }

        int x, y;
    }

    class Calculator
    {
        public delegate int CalculateXY(int x, int y);
        public int AddXY(int x, int y)
        {
            return x + y;
        }
        public int MinXY(int x, int y)
        {
            return x - y;
        }
        public int MulXY(int x, int y)
        {
            return x * y;
        }
        public void printValue(CalculateXY method, int x, int y)
        {
            Console.WriteLine(method(x, y));
        }
    }
}