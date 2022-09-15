using System;
using Class;
using Delegate;
using Generic;

namespace Program
{
    internal class Program
    {
        public static void Main()
        {
            //// test inheritance class
            //Transportation mount = new Car();

            //mount.Move();
            //Console.WriteLine(mount.Metric);

            //// test interface, abstract class inheritance class
            //IPolygon shape = new Triangle();

            //// cant tessellationcount() 
            //Console.WriteLine(shape.GetArea());

            //Shape shape1 = new Rectangle();

            //// cant getarea()
            //Console.WriteLine(shape1.TessellationCount());

            //// test delegate
            //Calculator calculator = new Calculator();
            //calculator.printValue(calculator.MinXY, 2, 4);

            Generic.Tester.Test();

            return;
        }
    }
}
